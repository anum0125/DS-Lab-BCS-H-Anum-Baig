# include <iostream>
using namespace std;

int interpolationSearch(int* array, int size, int searchValue){
    int low = 0;
    int high = size-1;
    while(low <= high && searchValue >= array[low] && searchValue <= array[high]){

        if (array[high] == array[low]) {
            if (array[low] == searchValue) return low;
            else return -1;
        }

        int pos = low+((searchValue - array[low]) * (high - low))/(array[high] - array[low]);
        if(array[pos] == searchValue){
            return pos;
        }else if(array[pos] > searchValue){
            high = pos-1;

        }else{
            low = pos+1;
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

    int searchValue;
    cout << "\nEnter the value you want to search for: " << endl;
    cin >> searchValue;

    int found = interpolationSearch(array, size, searchValue);

    if(found >= 0){
        cout << "The value was found at index: " << found << endl;
    }else{
        cout << "The value was not found!" << endl;
    }
}
