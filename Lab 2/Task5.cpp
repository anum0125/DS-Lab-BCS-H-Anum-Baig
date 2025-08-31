// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Matrix{
    int row_matrix1, row_matrix2, col_matrix1, col_matrix2;
    int** matrix1, **matrix2;   // 
    
    public:
        Matrix(int r1, int c1, int r2, int c2){
            row_matrix1 = r1;
            col_matrix1 = c1;
            row_matrix2 = r2;
            col_matrix2 = c2;
            
            matrix1 = new int*[r1];
            matrix2 = new int*[r2];
            for (int i = 0; i < r1; i++){
                matrix1[i] = new int[c1]();
            }
            for (int i = 0; i < r2; i++){
                matrix2[i] = new int[c2]();
            }
        }
        
        void fillValues(){
            cout << "Matrix 1: " << endl;
            for (int i = 0; i < row_matrix1; i++){   
                cout << "Values for Row " << i+1 << ": " << endl;
                for (int j = 0; j < col_matrix1; j++){   
                    cout << "Column " << j+1 << ": ";
                    cin >> matrix1[i][j];   // 
                    }
            }
            
            cout << "Matrix 2: " << endl;
            for (int i = 0; i < row_matrix2; i++){   
                cout << "Values for Row " << i+1 << ": " << endl;
                for (int j = 0; j < col_matrix2; j++){   
                    cout << "Column " << j+1 << ": ";
                    cin >> matrix2[i][j];   
                }
            }
        }
        
        void Addition(){
            if (row_matrix1 == row_matrix2 && col_matrix1 == col_matrix2){
                cout << "Matrix Added: " << endl;
                for(int i = 0; i < row_matrix1; i++){
                    for(int j = 0; j < col_matrix1; j++){
                        cout << " | " << matrix1[i][j] + matrix2[i][j];
                    }
                    cout << " | " << endl;
                }
            }
            else{
                cout << "Addition is not possible!" << endl;
            }
        }
        
        void Subtraction(){
            if (row_matrix1 == row_matrix2 && col_matrix1 == col_matrix2){
                cout << "Matrix Subtracted: " << endl;
                for(int i = 0; i < row_matrix1; i++){
                    for(int j = 0; j < col_matrix1; j++){
                        cout << " | " << matrix1[i][j] - matrix2[i][j];
                    }
                    cout << " | " << endl;
                }
            }
            else{
                cout << "Subtraction is not possible!" << endl; 
            }
        }
        
        ~Matrix(){
            for(int i = 0; i < row_matrix1; i++){
                delete[] matrix1[i];
            }
            delete[] matrix1;
            
            for(int i = 0; i < row_matrix2; i++){
                delete[] matrix2[i];
            }
            delete[] matrix2;
        }
    
};
int main(){
    Matrix m1(2, 2, 2, 2);
    m1.fillValues();
    m1.Addition();
    m1.Subtraction();
}
