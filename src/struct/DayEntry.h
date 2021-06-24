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
    std::string sensor_1{0}, sensor_2{0}, sensor_3{0};
    DayEntry();
    DayEntry(const std::string& date, std::string sensor1, std::string sensor2, std::string sensor3);
    std::string to_string();

    void to_file(std::ostream &ofstream, bool isGap);
    std::string date_to_string();
};


#endif //MEGANEXCELPROCESSOR_DAYENTRY_H
