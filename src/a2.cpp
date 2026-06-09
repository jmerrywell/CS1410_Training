// PLAN
// -----------
// Stratagy: ask user for an input untill 3 values are met and user types 0
// following prompts.
// Validation: If the input is invalid it will tell user invalid and will rest
// Statistics: count, min, max, total, average, and odd inputs.
// Additional state: I will be doing count of even numbers because I like to 
// know what the even is if I know the odd without doing math in my head.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int value;
    int count;
    int max = 999;
    int min = 1;
    int total = 0;
    int over500 = 0;

    while (true) {
        cout << "Enter a number (1-999) or 0 to stop: ";
        cin >> value;

        if (value < 0 || value >= 1000){
            cout << "Invalid: enter a whole number from 1 to 999." << endl;
            continue;
        }
        if (value == 0 && count < 3) {
            cout << "Need at least 3 values. Keep going." << endl;
            continue;
        }
        if (value == 0 && count >= 3) {
            break;
        }
        count++;
        total += value;
        if (value > max) max = value;
        if (value < min) min = value;
        if (value > 500) over500++;
    }
    double average = static_cast<double>(total)/count;

    cout<< setw(5) << "Count"
        << setw(8) << "Min"
        << setw(8) << "Max"
        << setw(10) << "Total"
        << setw(10) << "Average"
        << setw(15) << "Over 500" << endl;

    cout << "======================================================" << endl;

    cout<< setw(5) << count
        << setw(8) << min
        << setw(8) << max
        << setw(10) << total
        << setw(10) << fixed << setprecision(2) << average
        << setw(15) << over500 << endl;

    return 0;
}
