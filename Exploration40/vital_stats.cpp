//
// Created by carmen on 24/09/2015.
//

#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <string>

#include "vital_stats.h"

/// Skip the rest of the input line
/// @param in the input stream
void skip_line(std::istream& in) {
    in.ignore(std::numeric_limits<int>::max(), '\n');
}

int vital_stats::compute_bmi() const {
    return static_cast<int>(weight_ * 10000 / (height_ * height_) + 0.5);
}
bool vital_stats::read(std::istream& in, int num) {
    std::cout << "Name " << num << ": ";
    std::string name{};
    if (not std::getline(in, name)) {
        return false;
    }

    std::cout << "Height (cm):";
    int height{};
    if (not (in >> height)) {
        return false;
    }
    skip_line(in);

    std::cout << "Weight (kg):";
    int weight{};
    if (not (in >> weight)) {
        return false;
    }
    skip_line(in);

    std::cout << "Sex (M or F): ";
    char sex{};
    if (not (in >> sex)) {
        return false;
    }
    skip_line(in);
    sex = std::toupper(sex, std::locale());

    bmi_ = compute_bmi();
    return true;
}

/// Print this record to @p out
void vital_stats::print(std::ostream& out, int threshold) const {
    out << std::setw(6) << height_
    << std::setw(7) << weight_
    << std::setw(3) << sex_
    << std::setw(6) << bmi_;
    if (bmi_ >= threshold) {
        out << '*';
    } else {
        out << ' ';
    }
    out << ' ' << name_ << '\n';
}