// PLAN
//  Data design:
//   - enum class ShapeKind { Circle, Square, Rectangle }
//   - struct Shape { ShapeKind kind; double length; double width; }
//
// Functions:
//   - area(s): returns area based on shape kind.
//   - perimeter(s): returns perimeter based on shape kind.
//   - nameOf(s): returns the shape name as a string.
//   - promptAndFill(s): asks user for measurements and fills the struct.
//   - displayAll(arr,count): prints a formatted table of all shapes.
//   - displaySummary(arr,count): prints totals, averages, and largest area.
//
// Menu logic:
//   - do-while loop showing 1) Add 2) View 3) Summary 4) Quit.
//   - Uses an array of 10 shapes and a count variable.
//
// Edge cases:
//   - If array is full, cannot add more shapes.
//   - If array is empty, View and Summary print “No shapes yet.”

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

enum class ShapeKind { Circle, Square, Rectangle };

struct Shape {
    ShapeKind kind;
    double length;
    double width;
};

double area(Shape s);
double perimeter(Shape s);
string nameOf(Shape s);
void promptAndFill(Shape& s);
void displayAll(Shape shapes[], int count);
void displaySummary(Shape shapes[], int count);

double area(Shape s) {
    switch (s.kind) {
        case ShapeKind::Circle:
            return M_PI * pow(s.length / 2.0, 2);
        case ShapeKind::Square:
            return s.length * s.length;
        case ShapeKind::Rectangle:
            return s.length * s.width;
    }
    return 0;
}

double perimeter(Shape s) {
    switch (s.kind) {
        case ShapeKind::Circle:
            return M_PI * s.length;
        case ShapeKind::Square:
            return 4 * s.length;
        case ShapeKind::Rectangle:
            return 2 * (s.length + s.width);
    }
    return 0;
}

string nameOf(Shape s) {
    switch (s.kind) {
        case ShapeKind::Circle: return "Circle";
        case ShapeKind::Square: return "Square";
        case ShapeKind::Rectangle: return "Rectangle";
    }
    return "";
}

void promptAndFill(Shape& s) {
    if (s.kind == ShapeKind::Circle) {
        cout << "Enter diameter: ";
        cin >> s.length;
        s.width = s.length;
    }
    else if (s.kind == ShapeKind::Square) {
        cout << "Enter side length: ";
        cin >> s.length;
        s.width = s.length;
    }
    else {
        cout << "Enter length: ";
        cin >> s.length;
        cout << "Enter width: ";
        cin >> s.width;

        if (s.length == s.width) {
            s.kind = ShapeKind::Square;
        }
    }
}

void displayAll(Shape shapes[], int count) {
    cout << setw(10) << "Shape"
         << setw(10) << "Length"
         << setw(10) << "Width"
         << setw(10) << "Area"
         << setw(12) << "Perimeter" << "\n";

    cout << string(52, '=') << "\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < count; i++) {
        cout << setw(10) << nameOf(shapes[i])
             << setw(10) << shapes[i].length
             << setw(10) << shapes[i].width
             << setw(10) << area(shapes[i])
             << setw(12) << perimeter(shapes[i])
             << "\n";
    }
}

void displaySummary(Shape shapes[], int count) {
    double totalArea = 0;
    double totalPerim = 0;
    int largestIndex = 0;

    for (int i = 0; i < count; i++) {
        totalArea += area(shapes[i]);
        totalPerim += perimeter(shapes[i]);
        if (area(shapes[i]) > area(shapes[largestIndex])) {
            largestIndex = i;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Total shapes:      " << count << "\n";
    cout << "Combined area:     " << totalArea << "\n";
    cout << "Average perimeter: " << (totalPerim / count) << "\n";
    cout << "Largest area:  " << nameOf(shapes[largestIndex])
         << " (" << area(shapes[largestIndex]) << ")\n";
}

int main() {
    Shape shapes[10];
    int count = 0;
    int choice;

    do {
        cout << "\nSHAPE COLLECTION\n";
        cout << "================\n";
        cout << "1. Add a shape\n";
        cout << "2. View all shapes\n";
        cout << "3. View summary\n";
        cout << "4. Quit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == 10) {
                cout << "Collection is full.\n";
            } else {
                cout << "Add: 1) Circle  2) Square  3) Rectangle: ";
                int k;
                cin >> k;

                if (k == 1) shapes[count].kind = ShapeKind::Circle;
                else if (k == 2) shapes[count].kind = ShapeKind::Square;
                else if (k == 3) shapes[count].kind = ShapeKind::Rectangle;
                else {
                    cout << "Invalid kind.\n";
                    continue;
                }

                promptAndFill(shapes[count]);
                count++;
            }
        }
        else if (choice == 2) {
            if (count == 0) cout << "No shapes yet.\n";
            else displayAll(shapes, count);
        }
        else if (choice == 3) {
            if (count == 0) cout << "No shapes yet.\n";
            else displaySummary(shapes, count);
        }
        else if (choice == 4) {
            cout << "Goodbye.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}