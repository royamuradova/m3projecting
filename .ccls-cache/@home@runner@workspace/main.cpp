#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    string monthNames[13] = {"", "January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

    bool isValidDate(int m, int d) {
        if (m < 1 || m > 12) return false;
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return d >= 1 && d <= daysInMonth[m];
    }

public:
    Date(int m, int d, int y) {
        if (isValidDate(m, d)) {
            month = m;
            day = d;
        } else {
            cout << "Invalid date entered. Setting default date (1/1)." << endl;
            month = 1;
            day = 1;
        }
        year = y;
    }

    void printFormat1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() {
        cout << monthNames[month] << " " << day << ", " << year << endl;
    }

    void printFormat3() {
        cout << day << " " << monthNames[month] << " " << year << endl;
    }
};

int main() {
    Date myDate(12, 25, 2021);
    myDate.printFormat1();
    myDate.printFormat2();
    myDate.printFormat3();
    return 0;
}
