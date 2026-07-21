#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string dayOfTheWeek(int day, int month, int year) {
        std::vector<std::string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int days = 0;
        
        // Count days from 1971 to the year before the target year
        for (int i = 1971; i < year; ++i) {
            days += (i % 4 == 0) ? 366 : 365;
        }
        
        // Count days in prior months of the target year
        for (int i = 0; i < month - 1; ++i) {
            if (i == 1 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
                days += 29;
            } else {
                days += daysInMonth[i];
            }
        }
        
        // Add days of the current month
        days += day;
        
        // Jan 1, 1971 was a Friday. Friday is index 5 in the array.
        // (days - 1) makes it 0-indexed for the elapsed days.
        return weeks[(days + 4) % 7];
    }
};
