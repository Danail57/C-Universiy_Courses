#include <iostream>
using namespace std;


class Rectangle {
private:
    double width, height;
public:
    Rectangle() {
        width = 1;
        height = 1;
    }
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }
    double area() {
        return width * height;
    }
    double perimeter() {
        return (width + height) * 2;
    }

};

int main()
{
    Rectangle r1; 
    Rectangle r2(5, 3);

    cout << "Area of r1: " << r1.area() << endl;
    cout << "Perimeter of r1: " << r1.perimeter() << endl;

    cout << "Area of r2: " << r2.area() << endl;
    cout << "Perimeter of r2: " << r2.perimeter() << endl;

    return 0;
}
