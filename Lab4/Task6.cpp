# include <iostream>
using namespace std;

int* combSort(int* array, int size){
    int gap = size;
    bool swapped = true;
    const float shrink = 1.3;
    int swaps = 0;
    int comparisons = 0;

    while(gap > 1 || swapped){

        gap = int(gap / shrink);
        if(gap < 1){
            gap = 1;
        }
        swapped = false;

        for(int i = 0; i+gap < size; i++){
            comparisons++;
            if(array[i] > array[i+gap]){
                swap(array[i], array[i+gap]);
                swaps++;
                swapped = true;
            }
        }
    }
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

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

    array = combSort(array, size);
    cout << "\nSorted Array: " << endl;
    printArray(array, size);
}
