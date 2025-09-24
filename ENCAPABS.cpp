// 24/540550/TK/60008
// 24/545465/TK/60670

#include <iostream>
using namespace std;

class FuelTank {
    private :
    long long fuel_level;

    public :
    FuelTank(long long level){
        fuel_level = level;
    }

    void refuel(long long x){
        fuel_level += x;
    }

    void travel(long long x){
        if(fuel_level >= x){
            fuel_level -= x;
        }
    }

    long long report() const {
        return fuel_level;
    }
};

int main(){
    int initial_fuel;
    int Q;

    cin >> initial_fuel >> Q;

    FuelTank tank(initial_fuel);
    for (int run = 0; run < Q; ++run){
        string command;
        int x;
        cin >> command >> x;
        if (command == "REFUEL"){
            tank.refuel(x);
        } 
        else if (command == "TRAVEL"){
            tank.travel(x);
        }
        else if (command == "REPORT"){
            cout << tank.report() << endl;
        }
    }
    return 0;
}