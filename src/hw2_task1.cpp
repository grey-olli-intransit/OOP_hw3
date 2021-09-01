#include <iostream>
#define _USE_MATH_DEFINES // чтобы использовать M_PI
#include <cmath>
// Создать абстрактный класс Figure (фигура). 
// Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
// Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
// Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
// Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
class Figure {
    public:
       virtual double area() = 0;
};

class Parallelogram : public Figure {
    public:
        double area_;
        double sideA;
        double sideB;
        double angleRadians;
        Parallelogram(double a, double b, double an) 
		: sideA(a), sideB(b), angleRadians(an) {area_=sideA*sideB*sin(angleRadians);}
	double area() {return area_;}
};

class Circle : public Figure {
    double area_;
    double radius;
    public:
        Circle(double r):radius(r) {area_=M_PI*radius*radius;}
	double area() {return M_PI*radius*radius;}
};

class Rectangle : public Parallelogram {
	public:
        Rectangle(double a, double b) 
		: Parallelogram(a,b,90*M_PI/180) {}
	double area() {return sideA*sideB;}
};

class Square : public Parallelogram {
	public:
        Square(double a) 
		: Parallelogram(a,a,90*M_PI/180) {}
	double area() {return sideA*sideA;}
};

class Rombus : public Parallelogram {
	public:
        Rombus(double a, double angleRadius) 
		: Parallelogram(a,a,angleRadius) {}
        double area() {return sideA*sideA*sin(angleRadians);}
};


int main(int argc, char ** argv) {

    return 0;	

}
