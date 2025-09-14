# include <iostream>
using namespace std;

int linearSearch(int* array, int size,  int searchValue){
    int index = -1;
    for(int i = 0; i < size; i++){
        if(index >= 0){
            return index;
        }
        if(array[i] == searchValue){
            index = i;
        }
    }
    return index;
}

int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* array = new int[size];
    
    cout << "\nEnter elements of the array: ";
    for(int i = 0; i < size; i++){
        cout << "\nElement " << i+1 << ": ";
        cin >> array[i];
    }

    int search;
    cout << "\nEnter the target value: " << endl;
    cin >> search;

    int index = linearSearch(array, size, search);

    if(index >= 0){
        cout << "Target value found at index: " << index << endl; 
    }else{
        cout << "Target value not found!" << endl;
    }

    delete[] array;
}
