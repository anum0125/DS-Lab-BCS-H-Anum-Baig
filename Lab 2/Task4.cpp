#include <iostream>
using namespace std;

int* resizeArray(int* oldArray, int oldSize, int newSize) {
    int* newArray = new int[newSize]();   
    for (int i = 0; i < oldSize; i++) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;
    return newArray;
}

class Expenses {
    int size;
    int* expenses;
    
public:
    Expenses(int s) : size(s) {
        expenses = new int[size]();
    }
    
    void Resize(int newSize) {
        expenses = resizeArray(expenses, size, newSize);
        size = newSize;
        cout << "Array resized!" << endl;
    }
    
    void Add_Expenses(int i, int amount) {
        if (i > size || i <= 0) {
            cout << "Invalid Month number!" << endl;
        } else {
            expenses[i - 1] = amount;
        }
    }
    
    void total() {
        int t = 0;
        for (int i = 0; i < size; i++) {
            t += expenses[i];
        }
        cout << "The total expenses are: " << t << endl;
        cout << "The average expenses are: " << t / size << endl;
    }
    
    ~Expenses() {
        delete[] expenses;
    }
};

int main() {
    Expenses e1(3);
    e1.Add_Expenses(1, 500);
    e1.Resize(5);
    e1.total();
}
