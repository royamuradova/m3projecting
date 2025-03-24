#include <iostream>
using namespace std;

class NumberArray {
private:
    float* numbers;
    int size;

public:
    NumberArray(int s) {
        size = s;
        numbers = new float[size];
    }

    ~NumberArray() {
        delete[] numbers;
    }

    void storeNumber(int index, float value) {
        if (index >= 0 && index < size)
            numbers[index] = value;
    }

    float getNumber(int index) {
        if (index >= 0 && index < size)
            return numbers[index];
        return 0.0;
    }

    float getHighest() {
        float max = numbers[0];
        for (int i = 1; i < size; i++)
            if (numbers[i] > max)
                max = numbers[i];
        return max;
    }

    float getLowest() {
        float min = numbers[0];
        for (int i = 1; i < size; i++)
            if (numbers[i] < min)
                min = numbers[i];
        return min;
    }

    float getAverage() {
        float sum = 0;
        for (int i = 0; i < size; i++)
            sum += numbers[i];
        return sum / size;
    }
};

int main() {
    NumberArray arr(5);
    arr.storeNumber(0, 10.5);
    arr.storeNumber(1, 20.3);
    arr.storeNumber(2, 15.2);
    arr.storeNumber(3, 5.6);
    arr.storeNumber(4, 8.9);

    cout << "Highest: " << arr.getHighest() << endl;
    cout << "Lowest: " << arr.getLowest() << endl;
    cout << "Average: " << arr.getAverage() << endl;
    return 0;
}
