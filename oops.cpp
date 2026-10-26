#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() {
        return 3.141592653589793 * radius * radius;
    }

    double perimeter() {
        return 2 * 3.141592653589793 * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double area() {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() {
        return a + b + c;
    }
};

int main() {
    int choice;
    double r, l, w, a, b, c;

    Shape* shape = NULL;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== SHAPE AREA & PERIMETER CALCULATOR =====\n";
        cout << "1. Circle\n";
        cout << "2. Rectangle\n";
        cout << "3. Triangle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Enter radius: ";
            cin >> r;

            if (r <= 0) {
                cout << "Radius must be positive!\n";
                break;
            }

            Circle obj(r);
            shape = &obj;

            cout << "Area = " << shape->area() << endl;
            cout << "Perimeter = "
                 << shape->perimeter() << endl;
            break;
        }

        case 2: {
            cout << "Enter length and width: ";
            cin >> l >> w;

            if (l <= 0 || w <= 0) {
                cout << "Dimensions must be positive!\n";
                break;
            }

            Rectangle obj(l, w);
            shape = &obj;

            cout << "Area = " << shape->area() << endl;
            cout << "Perimeter = "
                 << shape->perimeter() << endl;
            break;
        }

        case 3: {
            cout << "Enter three sides: ";
            cin >> a >> b >> c;

            if (a <= 0 || b <= 0 || c <= 0 ||
                a + b <= c || a + c <= b ||
                b + c <= a) {
                cout << "Invalid triangle sides!\n";
                break;
            }

            Triangle obj(a, b, c);
            shape = &obj;

            cout << "Area = " << shape->area() << endl;
            cout << "Perimeter = "
                 << shape->perimeter() << endl;
            break;
        }

        case 4:
            cout << "Thank you for using the calculator!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}



