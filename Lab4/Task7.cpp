#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printArray(int* array, int size){
    for(int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": " << array[i] << endl;
    }
}

int* shellSort(int* array, int size, long long& comparisons, long long& swaps){
    comparisons = swaps = 0;
    for(int gap = size / 2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            int temp = array[i];
            int j = i;
            while(j >= gap){
                comparisons++;
                if(array[j - gap] > temp){
                    array[j] = array[j - gap];
                    swaps++;
                    j -= gap;
                } else break;
            }
            array[j] = temp;
        }
    }
    return array;
}

int* insertionSort(int* array, int size, long long& comparisons, long long& swaps){
    comparisons = swaps = 0;
    for(int i = 1; i < size; i++){
        int insert = array[i];
        int j = i-1;
        while(j >= 0){
            comparisons++;
            if(array[j] > insert){
                array[j+1] = array[j];
                swaps++;
                j--;
            } else break;
        }
        array[j+1] = insert;
    }
    return array;
}

int* bubbleSort(int* array, int size, long long& comparisons, long long& swaps){
    comparisons = swaps = 0;
    bool swapFlag = true;
    int index = size-1;
    while(swapFlag){
        swapFlag = false;
        for(int i = 0; i < index; i++){
            comparisons++;
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swaps++;
                swapFlag = true;
            }
        }
        index--;
    }
    return array;
}

int main(){
    const int size = 1000;
    int arr1[size], arr2[size], arr3[size];
    srand(time(0));
    for(int i = 0; i < size; i++){
        int val = rand() % 10000;
        arr1[i] = arr2[i] = arr3[i] = val;
    }

    long long comp, swp;
    clock_t start, end;

    start = clock();
    shellSort(arr1, size, comp, swp);
    end = clock();
    cout << "Shell Sort - Time: " << double(end - start) / CLOCKS_PER_SEC 
         << "s, Comparisons: " << comp << ", Swaps: " << swp << endl;

    start = clock();
    insertionSort(arr2, size, comp, swp);
    end = clock();
    cout << "Insertion Sort - Time: " << double(end - start) / CLOCKS_PER_SEC 
         << "s, Comparisons: " << comp << ", Swaps: " << swp << endl;

    start = clock();
    bubbleSort(arr3, size, comp, swp);
    end = clock();
    cout << "Bubble Sort - Time: " << double(end - start) / CLOCKS_PER_SEC 
         << "s, Comparisons: " << comp << ", Swaps: " << swp << endl;

    return 0;
}
