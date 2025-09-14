# include <iostream>
using namespace std;

int* BubbleSort(int* array, int size){
    bool swap = true;
    int index = size-1;
    while(swap){
        swap = false;
        for(int i = 0; i < index; i++){
            if(array[i] > array[i+1]){
                swap = true;
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        index--;
    }
    return array;
}

void printArray(int* array, int size){
    for(int i = 0; i < size; i++){
        cout << "Element " << i+1 << ": " << array[i] << endl;
    }
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

    cout << "\nUnsorted Array: " << endl;
    printArray(array, size);

    array = BubbleSort(array, size);
    cout << "\nSorted Array: " << endl;
    printArray(array, size);
}
