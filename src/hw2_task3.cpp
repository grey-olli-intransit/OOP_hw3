#include <iostream>
#include <cassert>
#include <string>

// Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
// Предусмотреть, чтобы знаменатель не был равен 0. 
// Перегрузить:
// математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
// унарный оператор (-)
// логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
// Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
// Продемонстрировать использование перегруженных операторов.

class Fraction {
    int numerator;  // числитель
    int denumerator; // знаменатель
    public:
        Fraction(int n, int d) : numerator(n),denumerator(d) { if(d==0) {assert(false);}}
	void print() {printf("%d / %d\n", numerator, denumerator);}
        int getNumerator(){return numerator;}
        int getDenumerator(){return denumerator;}
	Fraction operator+(Fraction f) {
		return Fraction( (this->numerator)*f.getDenumerator()+f.getNumerator()*(this->denumerator), (this->denumerator)*f.getDenumerator());
	}
	Fraction operator-(){return Fraction(-(this->numerator),this->denumerator);}
	Fraction operator-(Fraction f) {
		return Fraction((this->numerator)*f.getDenumerator()-f.getNumerator()*(this->denumerator), (this->denumerator)*f.getDenumerator());
	}
	Fraction operator*(Fraction f) {
		if (this->denumerator < f.getDenumerator()) {
			return Fraction((this->numerator)*(f.getDenumerator()/this->denumerator)*f.getNumerator(), (this->denumerator*(f.getDenumerator()/(this->denumerator))*f.getDenumerator()));
		}
		else { 
			return Fraction((this->numerator)*f.getNumerator()*((this->denumerator)/f.getDenumerator()), (this->denumerator)*f.getDenumerator()*((this->denumerator)/f.getDenumerator()));
		}
	}
	Fraction operator/(Fraction f) {return (*this) * Fraction(f.getDenumerator(),f.getNumerator());}
	bool operator==(Fraction f) {
	    double a=(double)this->numerator/this->denumerator;
	    double b=(double)f.getNumerator()/f.getDenumerator();
	    if(a==b) 
		    return true;
	    else
		    return false;
	
	}
	bool operator!=(Fraction f) {
            return !(*this == f);
	}
	bool operator<=(Fraction f) {
	    double a=(double)this->numerator/this->denumerator;
	    double b=(double)f.getNumerator()/f.getDenumerator();
	    if(a<=b) 
		    return true;
	    else
		    return false;
	
	}
	bool operator>(Fraction f) {
	    return ! (*this <= f);
	}
	bool operator>=(Fraction f) {
	    double a=(double)this->numerator/this->denumerator;
	    double b=(double)f.getNumerator()/f.getDenumerator();
	    if(a>=b) 
		    return true;
	    else
		    return false;
	}
	bool operator<(Fraction f) {
	    return ! (*this >= f);
	}

};
int main(int argc, char ** argv) {

    Fraction f1(1,2);
    Fraction f2(1,2);
    Fraction f3(1,4);
    f1.print();
    Fraction c = f1 + f1;
    Fraction d = f1 - f2;
    Fraction e = f1 * f2;
    Fraction f = f1 / f2;
    c.print();
    d.print();
    e.print();
    f.print();
    if (f1 == f2)
	    printf("1/2 и 1/2 равны.\n");
    if (f1 >= f3)
	    printf("1/2 больше либо равно 1/4.\n");
    if (f1 > f3)
	    printf("1/2 больше 1/4.\n");
    if (f3 <= f1)
	    printf("1/4 меньше либо равно 1/2.\n");
    if (f3 < f1)
	    printf("1/4 меньше 1/2.\n");
    f1=-f1;
    f1.print(); 
    return 0;

}
