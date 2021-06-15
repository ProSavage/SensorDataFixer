#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <ctime>
#include "./struct/util.h"
#include "./struct/DayEntry.h"

using namespace std::chrono_literals;
namespace chrono = std::chrono;


void fillGap(DayEntry prev, DayEntry finish,  std::ofstream& ofstream);
int main() {

    std::vector<DayEntry> entries{};
    std::string line;
    std::ifstream file("C:\\Users\\prosavage\\CLionProjects\\MeganExcelProcessor\\data.csv");
    std::ofstream outFile;
    outFile.open("C:\\Users\\prosavage\\CLionProjects\\MeganExcelProcessor\\out.csv");
    auto skipFirst = false;
    DayEntry prev = {"", 0, 0, 0};
    if (file.is_open()) {
        auto start = chrono::high_resolution_clock::now();
        while (std::getline(file, line)) {
            if (!skipFirst) {
                skipFirst = true;
                std::cout << "skipping";
                continue;
            }
            auto elements = split(line, ',');
            DayEntry dayEntry{elements[0],
                              std::stoi(elements[1]),
                              std::stoi(elements[2]),
                              std::stoi(elements[3])};

            // check if we even have a previous, if not skip checking..
            if (!prev.date_raw.empty()) {


                prev.to_file(outFile);

                auto seconds = difftime(mktime(&prev.date), mktime(&dayEntry.date));
                if (prev.date.tm_hour != 23 && prev.date.tm_hour != dayEntry.date.tm_hour) {
                    if (prev.date.tm_hour + 1 != dayEntry.date.tm_hour) {
                        std::cout << "====================================================\n";
                        std::cout << "missing! difference between last and this row: " << seconds << "(s)\n";
                        std::cout << prev.to_string() << " vs " << dayEntry.to_string() << "\n";
                        fillGap(prev, dayEntry, outFile);
                    }
                }
            }
            prev = dayEntry;
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = duration_cast<chrono::milliseconds>(stop - start);
        std::cout << "finished " << duration << "\n";
    } else throw std::invalid_argument("unable to open file");


    return 0;
}

void fillGap(DayEntry prev, DayEntry finish, std::ofstream& ofstream) {
    std::vector<DayEntry> gapEntries{};
    while ((mktime(&finish.date) / 3600) - (mktime(&prev.date) / 3600) > 1) {
//        prev.date.tm_hour++;
        time_t timePrev = mktime(&prev.date);
        timePrev += (60 * 60);
        localtime_s(&prev.date, &timePrev);
        // this can just throw it into the file output stream later
        prev.to_file(ofstream);
        std::cout << "missing date was: " << prev.to_string() << "\n";
    }
}


