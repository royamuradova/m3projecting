#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        else return 31;
    }

    bool isValidDate(int m, int d, int y) const {
        return (y > 0 && m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth(m, y));
    }

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int m, int d, int y) {
        if (isValidDate(m, d, y))
            setDate(m, d, y);
        else {
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    void setDate(int m, int d, int y) {
        if (isValidDate(m, d, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            cout << "Invalid date: " << m << "/" << d << "/" << y << endl;
        }
    }

    Date& operator++() {
        if (day < daysInMonth(month, year)) day++;
        else {
            day = 1;
            if (month < 12) month++;
            else {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date& operator--() {
        if (day > 1) day--;
        else {
            if (month > 1) month--;
            else {
                month = 12;
                year--;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    int operator-(const Date& other) const {
        auto countDays = [](const Date& d) {
            int y = d.year, m = d.month, days = d.day;
            static const int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

            for (int i = 1; i < y; i++)
                days += ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) ? 366 : 365;

            for (int i = 1; i < m; i++)
                days += (i == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) ? 29 : monthDays[i - 1];

            return days;
        };

        return abs(countDays(*this) - countDays(other));
    }

    friend ostream& operator<<(ostream& out, const Date& date) {
        const string months[] = { "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December" };
        out << months[date.month - 1] << " " << date.day << ", " << date.year;
        return out;
    }

    friend istream& operator>>(istream& in, Date& date) {
        int m, d, y;
        char slash;
        cout << "Enter date (mm/dd/yyyy): ";
        in >> m >> slash >> d >> slash >> y;
        if (date.isValidDate(m, d, y))
            date.setDate(m, d, y);
        else
            cout << "Invalid input date." << endl;
        return in;
    }
};

int main() {
    cout << "Test 1: Default constructor\n";
    Date d1;
    cout << d1 << endl;

    cout << "\nTest 2: Parameterized constructor\n";
    Date d2(4, 18, 2018);
    cout << d2 << endl;

    cout << "\nTest 3: setDate function\n";
    d1.setDate(12, 31, 2024);
    cout << d1 << endl;

    cout << "\nTest 4: Invalid date (13/45/2018)\n";
    d1.setDate(13, 45, 2018);

    cout << "\nTest 5: Subtracting dates\n";
    Date d3(4, 10, 2014);
    Date d4(4, 18, 2014);
    cout << "Days between " << d4 << " and " << d3 << " = " << d4 - d3 << " days\n";

    cout << "\nTest 6: Pre-increment from 12/31/2024\n";
    ++d1;
    cout << d1 << endl;

    cout << "\nTest 7: Post-decrement\n";
    d1--;
    cout << d1 << endl;

    cout << "\nTest 8: Pre-decrement from 1/1/2000\n";
    Date d5(1, 1, 2000);
    --d5;
    cout << d5 << endl;

    cout << "\nTest 9: Reading date using >> operator\n";
    Date inputDate;
    cin >> inputDate;
    cout << "You entered: " << inputDate << endl;

    return 0;
}
