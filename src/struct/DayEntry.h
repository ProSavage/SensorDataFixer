//
// Created by prosavage on 6/13/2021.
//

#include <string>
#ifndef MEGANEXCELPROCESSOR_DAYENTRY_H
#define MEGANEXCELPROCESSOR_DAYENTRY_H


class DayEntry {
public:
    tm date {};
    std::string date_raw;
    double sensor_1{0}, sensor_2{0}, sensor_3{0};
    DayEntry();
    DayEntry(std::string date, int sensor1, int sensor2, int sensor3);
    std::string to_string();

    void to_file(std::ofstream &ofstream, bool isGap);
    std::string date_to_string();
};


#endif //MEGANEXCELPROCESSOR_DAYENTRY_H
