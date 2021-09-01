#include <iostream>
#include <string>

//Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
//Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
//От этих классов наследует класс Minivan (минивэн). 
//Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
// Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
// Обратить внимание на проблему «алмаз смерти». 
// Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.

class Car {
  public:
    std::string company;
    std::string model;
    Car() {printf("Car()\n");}
    Car(std::string c, std::string m): company(c), model(m) {printf("company: %s, model: %s\n",company.c_str(),model.c_str());}
};

class PassengerCar: public Car {
    public:
        PassengerCar():Car("passengerCar","passengerCar") {printf("PassengerCar()\n");}
};

class Bus: public Car {
    public:
        Bus():Car("Bus","Bus") {printf("Bus()\n");}
};

class Minivan: virtual public PassengerCar, virtual public Bus {
    public:
        Minivan() {printf("Minivan()\n"); printf("company(PassengerCar): %s, model(Bus): %s\n", PassengerCar::company.c_str(), Bus::model.c_str());}
};

int main(int argc, char ** argv) {
    Minivan m;
    return 0;

}
