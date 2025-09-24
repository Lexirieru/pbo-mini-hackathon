//
// 24/540550/TK/60008

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Employee {
protected:
    std::string name;

public:
    Employee(const std::string& n) : name(n) {}

    virtual ~Employee() = default;

    std::string getName() const {
        return name;
    }

    virtual int salary() const = 0;
};

class FullTime : public Employee {
private:
    int baseSalary;
    int bonus;

public:
    FullTime(const std::string& n, int base, int b) 
        : Employee(n), baseSalary(base), bonus(b) {}

    int salary() const override {
        return baseSalary + bonus;
    }
};

class PartTime : public Employee {
private:
    int hourlyRate;
    int hours;

public:
    PartTime(const string& n, int rate, int h)
        : Employee(n), hourlyRate(rate), hours(h) {}

    int salary() const override {
        return hourlyRate * hours;
    }
};

int main() {
    int Q;
    cin >> Q;

    vector<unique_ptr<Employee>> employees;

    while (Q--) {
        string type, name;
        cin >> type;

        if (type == "FULLTIME") {
            int base, bonus;
            cin >> name >> base >> bonus;
            employees.push_back(make_unique<FullTime>(name, base, bonus));
        } else if (type == "PARTTIME") {
            int rate, hours;
            cin >> name >> rate >> hours;
            employees.push_back(make_unique<PartTime>(name, rate, hours));
        }
    }

    for (const auto& emp : employees) {
        cout << emp->getName() << ": " << emp->salary() << "\n";
    }

    return 0;
}
