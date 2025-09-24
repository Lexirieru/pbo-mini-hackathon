// 24/540550/TK/60008
// 24/545465/TK/60670

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

    virtual long long salary() const = 0;
};

class FullTime : public Employee {
private:
    long long baseSalary;
    long long bonus;

public:
    FullTime(const std::string& n, long long base, long long b) 
        : Employee(n), baseSalary(base), bonus(b) {}

    long long salary() const override {
        return baseSalary + bonus;
    }
};

class PartTime : public Employee {
private:
    long long hourlyRate;
    long long hours;

public:
    PartTime(const string& n, long long rate, long long h)
        : Employee(n), hourlyRate(rate), hours(h) {}

    long long salary() const override {
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
            long long base, bonus;
            cin >> name >> base >> bonus;
            employees.push_back(make_unique<FullTime>(name, base, bonus));
        } else if (type == "PARTTIME") {
            long long rate, hours;
            cin >> name >> rate >> hours;
            employees.push_back(make_unique<PartTime>(name, rate, hours));
        }
    }

    for (const auto& emp : employees) {
        cout << emp->getName() << ": " << emp->salary() << "\n";
    }

    return 0;
}
