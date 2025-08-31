// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int** seating_chart = new int*[5];
    for (int i = 0; i < 5; i++){
        seating_chart[i] = new int[10]();
    }
    int cont;
    cout << "There are 5 rows and 10 columns." << endl;
    while(true){
        int seat_row, seat_col;
        cout << "Enter the row and column of the filled seat: " << endl;
        cin >> seat_row >> seat_col;
        if (seat_row > 5 || seat_col > 10){
            cout << "Invalid seat number!" << endl;
        }
        else if( seating_chart[seat_row-1][seat_col-1] == 1){
           cout << "Seat is already filled!" << endl;
        }
        else{
            seating_chart[seat_row-1][seat_col-1] = 1;
        }
        cout << "Do you want to continue: " << endl;
        cout << "0: No " << endl;
        cout << "1: Yes " << endl;
        cin >> cont;
        if (cont == 0){
            break;
        }
    }
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 10; j++){
            cout << " | " << seating_chart[i][j];
        }
        cout << " | " << endl;
    }
    
    for (int i = 0; i < 5; i++){
        delete[] seating_chart[i];
    }
    delete[] seating_chart;
}
