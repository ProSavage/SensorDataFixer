//
// Created by prosavage on 6/13/2021.
//
#include <ctime>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

tm create_time(int year, int month, int day, int hour, int min) {
    std::tm tm {0, min, hour, day, month - 1, year - 1900 };
    return tm;
}

std::vector<std::string> split(std::string content, char delimiter) {
    std::vector<std::string> words {};
    auto pos = content.find(delimiter);
    while (pos != std::string::npos) {
        words.push_back(content.substr(0, pos));
        content = content.substr(pos + 1);
        pos = content.find(delimiter);
    }
    words.push_back(content);
    return words;
}

tm format_string_to_time(std::string content) {
    if (content.empty()) {
        return tm{0};
    }

    auto date_time_split = split(std::move(content), ' ');
    auto date = date_time_split[0];
    auto time = date_time_split[1];



    auto date_elemts = split(date, '/');
    auto time_elemts = split(time, ':');
    return create_time(std::stoi(date_elemts[2]), std::stoi(date_elemts[0]), std::stoi(date_elemts[1]), std::stoi(time_elemts[0]), std::stoi(time_elemts[1]));
}