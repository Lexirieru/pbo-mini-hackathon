// 24/540550/TK/60008
// 24/545465/TK/60670
#include <iostream>
using namespace std;

class Transport {
public:
    int distance;
    
    Transport(int d) : distance(d) {}
    
    virtual int fare() = 0;
};

class Car : public Transport {
public:
    Car(int d) : Transport(d) {}
    
    int fare() override {
        return 100 + 10 * distance;
    }
};

class Bus : public Transport {
public:
    Bus(int d) : Transport(d) {}
    
    int fare() override {
        return 50 + 8 * distance;
    }
};

class Train : public Transport {
public:
    Train(int d) : Transport(d) {}
    
    int fare() override {
        if (distance <= 50) {
            return 200 + 3 * distance;
        } else {
            return 200 + 3 * 50 + 2 * (distance - 50);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q; 
    cin >> Q;
    
    while (Q--) {
        string type; 
        int d; 
        cin >> type >> d;
        
        unique_ptr<Transport> t;
        
        if (type == "CAR") {
            t = make_unique<Car>(d);
        } else if (type == "BUS") {
            t = make_unique<Bus>(d);
        } else if (type == "TRAIN") {
            t = make_unique<Train>(d);
        }
        
        cout << t->fare() << endl;
    }
    
    return 0;
}
