//
// Created by prosavage on 6/13/2021.
//

#include <vector>

#ifndef MEGANEXCELPROCESSOR_UTIL_H
#define MEGANEXCELPROCESSOR_UTIL_H

tm create_time(int year, int month, int day, int hour, int min);

tm format_string_to_time(std::string content);

std::vector<std::string> split(std::string content, char delimiter);

#endif //MEGANEXCELPROCESSOR_UTIL_H
