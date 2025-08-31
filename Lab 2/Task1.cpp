#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << endl;
    
    int* array = new int[size]();
    bool end = false;
    while(!end){
        int index, cont;
        cout << "Enter the index of the position you want to update: " << endl;
        cin >> index;
        if (index > size-1){
            cout << "Invalid index!" << endl;
        }
        else{
            cout << "Enter the updated value: " << endl;
            cin >> array[index];
        }
        cout << "Do you want to continue: " << endl;
        cout << "0: No " << endl;
        cout << "1: Yes " << endl;
        cin >> cont;
        if (cont == 0){
            end = true;
        }
    }
    
    cout << "Array values: " << endl;
    for (int i = 0; i < size; i++){
        cout << "Value at index " << i << ": " << array[i] << endl;
    }
    
    delete[] array;
    
}
