//
// Created by carmen on 24/09/2015.
//

#ifndef EXPLORING_CPP_2E_VITAL_STATS_H
#define EXPLORING_CPP_2E_VITAL_STATS_H

class vital_stats {
public:
    /// Constructor. Initialise everything to zero or other "empty" value.
    vital_stats() : height_{0}, weight_{0}, bmi_{0}, sex_{'?'}, name_{} {}

    /// Get this record, overwriting the data members.
    /// Error-checking omitted for berevity.
    /// @param in the input stream
    /// @param num a serial number, for use when prompting user
    /// @return true for success or false for eof or input failure
    bool read(std::istream& in, int num);

    /// Print this record to @p out.
    /// @param out the output stream
    /// @param threshold mark records that have a BMI >= threshold
    void print(std::ostream& out, int threshold) const;

    /// Return the BMI.
    int bmi() const { return bmi_; }
    /// Return the height in centimetres
    int height() const { return height_; }
    /// Return the weight in kilograms
    int weight() const { return weight_; }
    /// Return the sex: 'M' for mail, 'F' for female
    char sex() const { return sex_; }
    /// Return the person's name
    std::string const& name() const { return name_; }

private:
    /// Return BMI, based on height_ and weight_
    /// This is called only from read()
    int compute_bmi() const;
    int height_;
    int weight_;
    int bmi_;
    char sex_;
    std::string name_;
};
#endif //EXPLORING_CPP_2E_VITAL_STATS_H
