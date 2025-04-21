#include <iostream>
#include "sortedtype.cpp"

// Define the TimeStamp template class
template<typename T>
class TimeStamp {
public:
    T seconds;
    T minutes;
    T hours;

    TimeStamp(T s = 0, T m = 0, T h = 0) : seconds(s), minutes(m), hours(h)  {}

    void Print() const {
        std::cout << seconds << ":" << minutes << ":" << hours << std::endl;
    }

    bool operator<(const TimeStamp& other) const {
        if (hours < other.hours)
            return true;
        else if (hours == other.hours && minutes < other.minutes)
            return true;
        else if (hours == other.hours && minutes == other.minutes && seconds < other.seconds)
            return true;
        return false;
    }

    bool operator==(const TimeStamp& other) const {
        return (seconds == other.seconds && minutes == other.minutes && hours == other.hours);
    }
};

int main() {
    // Instantiate SortedType for TimeStamp
    SortedType<TimeStamp<int>> timeList;

    // Inserting time stamps
    timeList.InsertItem(TimeStamp<int>(15, 34, 23));
    timeList.InsertItem(TimeStamp<int>(13, 13, 02));
    timeList.InsertItem(TimeStamp<int>(43, 45, 12));
    timeList.InsertItem(TimeStamp<int>(25, 36, 17));
    timeList.InsertItem(TimeStamp<int>(52, 02, 20));

    // Deleting timestamp 25:36:17
    timeList.DeleteItem(TimeStamp<int>(25, 36, 17));

    // Printing the list
    TimeStamp<int> time;
    int length = timeList.LengthIs();
    for (int i = 0; i < length; ++i) {
        timeList.GetNextItem(time);
        time.Print();
    }

    return 0;
}
