//
// 24/540550/TK/60008

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Employee {
    protected:
    string name;

    public :
    Employee(string employeeName) {
        name = employeeName;
    }
    string getName() const {
        return name;
    }
    virtual int salary() const = 0;
};

class FullTime : public Employee {
    private :
    int baseSalary;
    int bonus;

    public :
    FullTime(string employeeName, int ba, int bo) : Employee(employeeName) {
        baseSalary = ba;
        bonus = bo;
    }
    int salary() const override {
        return baseSalary + bonus;
    }
};

class PartTime : public Employee {
    private :
    int rate;
    int hours;

    public :
    PartTime(string employeeName, int r, int h) : Employee(employeeName) {
        rate = r;
        hours = h;
    }
    int salary() const override {
        return rate * hours;
    }
};

int main(){
    int Q;
    cin >> Q;

    vector<unique_ptr<Employee>> v;
    while (Q--){
        string type, name;
        cin >> type;

        if (type == "FULLTIME"){
            int base, bonus;
            cin >> name >> base >> bonus;
            v.push_back(make_unique<FullTime>(name, base, bonus));
        }

        else if (type == "PARTTIME"){
            int rate, hours;
            cin >> name >> rate >> hours;
            v.push_back(make_unique<PartTime>(name, rate, hours));
        }
    }

    for (const auto& emp : v){
        cout << emp->getName() << ": " << emp->salary() << endl;
    }
    return 0;
}