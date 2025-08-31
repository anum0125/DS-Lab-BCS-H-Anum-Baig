// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr; 

public:
    SafePointer() {
        ptr = new int(0); 
    }

    ~SafePointer() {
        delete ptr;
    }

    void setValue(int value) {
        *ptr = value;
    }

    int getValue() const {
        return *ptr;
    }

    int* release() {
        int* temp = ptr;
        ptr = nullptr; 
        return temp;
    }
};

int main() {
    SafePointer students[5];  

    cout << "Enter marks of 5 students: " << endl;
    for (int i = 0; i < 5; i++) {
        int mark;
        cout << "Student " << i + 1 << ": " << endl;
        cin >> mark;
        students[i].setValue(mark);
    }

    cout << "Marks of students: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }

}

