#include <iostream>
#include <iomanip>

class timeStamp {
private:
    int seconds;
    int minutes;
    int hours;

public:
    timeStamp() : seconds(0), minutes(0), hours(0) {}
    timeStamp(int s, int m, int h) : seconds(s), minutes(m), hours(h) {}

    // Overloading the equality operator
    bool operator==(const timeStamp& other) const {
        return (seconds == other.seconds) && (minutes == other.minutes) && (hours == other.hours);
    }

    // Overloading the less than operator
    bool operator<(const timeStamp& other) const {
        if (hours != other.hours)
            return hours < other.hours;
        if (minutes != other.minutes)
            return minutes < other.minutes;
        return seconds < other.seconds;
    }

    // Function to print timeStamp object
    void print() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds;
    }
};
