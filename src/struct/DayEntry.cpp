//
// Created by prosavage on 6/13/2021.
//

#include "DayEntry.h"
#include <iostream>
#include "./util.h"
#include <string>
#include <utility>

DayEntry::DayEntry(const std::string& date, std::string sensor1, std::string sensor2, std::string sensor3) {

    date_raw = date;

    this->date = format_given_time(date);
    sensor_1 = std::move(sensor1);
    sensor_2 = std::move(sensor2);
    sensor_3 = std::move(sensor3);

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

void DayEntry::to_file(std::ostream& ofstream, bool isGap) {
    if (isGap) {
        ofstream << ",,";
    } else {
       ofstream << date_raw << ",";
       if (isSpacedDate(date_raw)) {
          ofstream << split(date_raw, ' ')[1];
       } else {
           ofstream << split(date_raw, 'T')[1];
       }
       ofstream << ",";
    }

    ofstream << std::to_string(date.tm_hour) << ":" << "00";
    if (isGap) {
        ofstream << ",,,";
    } else {
        ofstream << "," << sensor_1 << "," << sensor_2 << "," << sensor_3;
    }
    ofstream << "\n";
}