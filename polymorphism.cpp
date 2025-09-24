// 24/540550/TK/60008
// 24/545465/TK/60670

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
    virtual string speak() = 0;
    
    string speak(int times) const {
        string result = "";
        for (int i = 0; i < times; i++) {
            if (i > 0) result += " ";
            result += const_cast<Animal*>(this)->speak();
        }
        return result;
    }
    
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    string speak() override {
        return "Woof";
    }
};

class Cat : public Animal {
public:
    string speak() override {
        return "Meow";
    }
};

class Cow : public Animal {
public:
    string speak() override {
        return "Moo";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    vector<string> results;
    
    while (Q--) {
        string t;
        cin >> t;
        int k = 1;
        
        if (cin.peek() == ' ') {
            cin >> k;
        }
        
        Animal* animal = nullptr;
        
        if (t == "DOG") {
            animal = new Dog();
        } else if (t == "CAT") {
            animal = new Cat();
        } else if (t == "COW") {
            animal = new Cow();
        }
        
        if (k == 1) {
            results.push_back(animal->speak());
        } else {
            results.push_back(animal->speak(k));
        }
        
        delete animal;
    }
    
    for (const string& result : results) {
        cout << result << "\n";
    }
    
    return 0;
}