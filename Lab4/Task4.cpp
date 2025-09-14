# include <iostream>
using namespace std;

int* insertionSort(int* array, int size){
    for(int i = 1; i < size; i++){
        int insert = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > insert) {
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = insert;
    }
    return array;
}

int binarySearch(int* array, int size, int searchValue){
    int low = 0;
    int high = size-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(array[mid] == searchValue){
            return mid;
        }else if(array[mid] > searchValue){
            high = mid-1;

        }else{
            low = mid+1;
        }
    }
    return -1;
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

    array = insertionSort(array, size);

    int searchValue;
    cout << "\nEnter the value you want to search for: " << endl;
    cin >> searchValue;

    int found = binarySearch(array, size, searchValue);

    if(found >= 0){
        cout << "The value was found at index: " << found << endl;
    }else{
        cout << "The value was not found!" << endl;
    }
}
