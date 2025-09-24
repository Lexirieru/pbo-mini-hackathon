// 24/540550/TK/60008
// 24/545465/TK/60670
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Student {
private:
    string id, nama;
    vector<int> grades;
    int sumGrades;
public:
    Student() : id(""), nama(""), sumGrades(0) {}  // default constructor
    Student(string id, string nama) : id(id), nama(nama), sumGrades(0) {}
    
    void addGrade(int grade) {      
        grades.push_back(grade);
        sumGrades += grade;
    }
    int getSumGrades() const { 
    
        return sumGrades; 
    }
    string getId() const { 
        return id; 
    }
    string getNama() const { 
        return nama; 
    }
};

class GradeManager {
private:
    map<string, Student> students;
public:
    void addStudent(const string& id, const string& nama) {
        if (students.find(id) == students.end()) {
            students[id] = Student(id, nama);
        }
    }
    void addGrade(const string& id, int grade) {
        if (students.find(id) != students.end() && grade >= 0 && grade <= 100) {
            students[id].addGrade(grade);
        }
    }
    int getSumGrades(const string& id) const {
        if (students.find(id) != students.end()) {
            return students.at(id).getSumGrades();
        }
        return -1; // Indicate student not found
    }
    void listStudents() const {
        for (const auto& pair : students) {
                cout << pair.second.getNama() << ": " << pair.second.getSumGrades() << "\n";

        }
    }
    string getStudentName(const string& id) const {
        if (students.find(id) != students.end()) {
            return students.at(id).getNama();
        }
        return "";
    }
};
// implementasikan atribut yang diperlukan
//implementasikan konstruktor dan metode yang diperlukan

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    GradeManager gm;
    for (int i = 0; i < Q; i++) {
        // 8
        // ADD 1 Alice
        // ADD 2 Bob
        // GRADE 1 85
        // GRADE 1 90
        // GRADE 2 75
        // SUM 1
        // LIST
        // SUM 3
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            string id, nama;
            cin >> id >> nama;
            gm.addStudent(id, nama);
        } else if (operation == "GRADE") {
            string id;
            int grade;
            cin >> id >> grade;
            gm.addGrade(id, grade);
        } else if (operation == "SUM") {
            string id;
            cin >> id;
            int sum = gm.getSumGrades(id);
            if (sum > 0) {
                cout << gm.getStudentName(id) << ": " << sum << "\n";
            }

        } else if (operation == "LIST") {
            gm.listStudents();
        }
    }
    return 0;
}