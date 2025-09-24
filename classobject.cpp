// 24/540550/TK/60008
// 24/545465/TK/60670

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Student {
private:
    int id;
    string name;
    vector<int> grades;
public:
    Student(int student_id, const string& student_name)
        : id(student_id), name(student_name) {}
    
    int get_id() const {
        return id;
    }
    
    string get_name() const {
        return name;
    }
    
    void add_grade(int grade) {
        grades.push_back(grade);
    }
    
    double calculate_sum() const {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return sum;
    }
    
    bool has_grades() const {
        return !grades.empty();
    }
};

class GradeManager {
private:
    vector<Student> students;
    map<int, int> id_to_index;
    
public:
    void add_student(int id, const string& name) {
        if (id_to_index.find(id) == id_to_index.end()) {
            students.push_back(Student(id, name));
            id_to_index[id] = students.size() - 1;
        }
    }
    
    void add_grade(int id, int grade) {
        if (id_to_index.find(id) != id_to_index.end()) {
            int index = id_to_index[id];
            students[index].add_grade(grade);
        }
    }
    
    void show_sum(int id) {
        if (id_to_index.find(id) != id_to_index.end()) {
            int index = id_to_index[id];
            if (students[index].has_grades()) {
                cout << students[index].get_name() << ": " << students[index].calculate_sum() << endl;
            }
        }
    }
    
    void list_all_students() {
        for (const Student& student : students) {
            if (student.has_grades()) {
                cout << student.get_name() << ": " << student.calculate_sum() << endl;
            } else {
                cout << student.get_name() << endl;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    
    GradeManager manager;
    
    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "ADD") {
            int id;
            string name;
            cin >> id >> name;
            manager.add_student(id, name);
        }
        else if (operation == "GRADE") {
            int id, grade;
            cin >> id >> grade;
            manager.add_grade(id, grade);
        }
        else if (operation == "SUM") {
            int id;
            cin >> id;
            manager.show_sum(id);
        }
        else if (operation == "LIST") {
            manager.list_all_students();
        }
        else {
        }
    }
    
    return 0;
}
