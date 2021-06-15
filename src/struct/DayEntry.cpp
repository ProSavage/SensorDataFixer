//
// Created by prosavage on 6/13/2021.
//

#include "DayEntry.h"
#include <iostream>
#include <utility>
#include "./util.h"
#include <iomanip>
#include <fstream>

DayEntry::DayEntry(std::string date, int sensor1, int sensor2, int sensor3) {
    date_raw = date;
    this->date = format_string_to_time(date);
    sensor_1 = sensor1;
    sensor_2 = sensor2;
    sensor_3 = sensor3;

}

DayEntry::DayEntry() {

}

std::string DayEntry::date_to_string() {
    return std::to_string(date.tm_mon + 1) + "/" + std::to_string(date.tm_mday) + "/" +
           std::to_string((date.tm_year + 1900));
}

std::string DayEntry::to_string() {
    return date_to_string()  + " " + std::to_string(date.tm_hour) + ":" + std::to_string(date.tm_min);
}

void DayEntry::to_file(std::ofstream& ofstream, bool isGap) {

    if (isGap) {
        ofstream << ",,";
    } else {
        ofstream << date_raw << "," << split(date_raw, ' ')[1] << ",";
    }

    ofstream << std::to_string(date.tm_hour) << ":" << "00";
    if (isGap) {
        ofstream << ",,,";
    } else {
        ofstream << "," << sensor_1 << "," << sensor_2 << "," << sensor_3;
    }
    ofstream << "\n";
}