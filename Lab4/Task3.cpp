# include <iostream>
using namespace std;

int* selectionSort(int* array, int size){
    int loop = 0;
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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

    array = selectionSort(array, size);
    cout << "\nSorted Array: " << endl;
    printArray(array, size);

    delete[] array;
}
