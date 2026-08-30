#include <iostream>
using namespace std;

class Shape {
protected:
    int x;
    int y;

public:
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int value) {
        x = value;
    }

    void setY(int value) {
        y = value;
    }

    Shape(int x, int y) {
        this->x = x;
        this->y = y;
    }

    virtual void draw() = 0; // Abstract
};


class Triangle : public Shape { // Kalıtım
public:

    Triangle(int x, int y)
        : Shape(x, y) {
    }

    void draw() override { // Polimorfizm

        cout << "\nTriangle:\n";

        for (int i = 1; i <= y; i++) {
            for (int j = 1; j <= i && j <= x; j++) {
                cout << "* ";
            }

            cout << endl;
        }
    }
};


class Rectangle : public Shape {
public:

    Rectangle(int x, int y)
        : Shape(x, y) {
    }

    void draw() override {

        cout << "\nRectangle:\n";

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cout << "* ";
            }

            cout << endl;
        }
    }
};


class Square : public Rectangle {
public:

    Square(int x)
        : Rectangle(x, x) {
    }

    void draw() override {

        cout << "\nSquare:\n";

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                cout << "* ";
            }

            cout << endl;
        }
    }
};


int main() {

    int x, y;

    cout << "X degerini gir: ";
    cin >> x;

    cout << "Y degerini gir: ";
    cin >> y;

    Triangle triangle(x, y);
    Rectangle rectangle(x, y);
    Square square(x);

    triangle.draw();
    rectangle.draw();
    square.draw();

    return 0;
}