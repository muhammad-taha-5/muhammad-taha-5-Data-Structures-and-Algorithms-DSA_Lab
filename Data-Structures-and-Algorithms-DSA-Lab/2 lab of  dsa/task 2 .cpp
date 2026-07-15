#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;
};

class Full_T_Employee : public Employee {
private:
    double salary;

public:
    Full_T_Employee(double s) {
        salary = s;
    }

    double calculateSalary() {
        return salary;
    }
};

class Part_T_Employee : public Employee {
private:
    double hours;
    double rate;

public:
    Part_T_Employee(double h, double r) {
        hours = h;
        rate = r;
    }

    double calculateSalary() {
        return hours * rate;
    }
};

int main() {

    Full_T_Employee f(50000);
    Part_T_Employee p(40, 500);

    cout << "Full Time Salary: " << f.calculateSalary() << endl;
    cout << "Part Time Salary: " << p.calculateSalary() << endl;

    return 0;
}