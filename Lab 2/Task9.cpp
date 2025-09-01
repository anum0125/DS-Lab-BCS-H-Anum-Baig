// TASK 9

# include <iostream>
using namespace std;

class sparse_matrix{
    int rows, cols;
    int** matrix;

    public:
        sparse_matrix(int r, int c): rows(r), cols(c){
            matrix = new int*[rows];
            for(int i = 0; i < rows; i++){
                matrix[i] = new int[cols]();
            }
        }

        void inputValues(){
            cout << "Input Values for three indexes: " << endl;
            int i = 0;
            while(i < 3){
                int r, c;
                cout << "Index " << i+1 << ":" << endl;
                cout << "Enter row and column: " << endl;
                cin >> r >> c;
                if(r > rows || c > cols){
                    cout << "Invalid input" << endl;
                }
                else{
                    cout << "Enter value: " << endl;
                    cin >> matrix[r-1][c-1];
                }
                i++;
            }
        }

        void display_normal(){
            cout << "\nNormal Matrix: " << endl;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << "|  " << matrix[i][j] << "  ";
                }
                cout << "|" << endl;
            }
        }

        void display_sparse(){
            cout << "\nSparse Matrix: " << endl;
            cout << "Row        Column      Value       " << endl;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(matrix[i][j] != 0){
                        cout << i+1 << "          " << j+1 << "           " << matrix[i][j] << endl;
                    }
                }
            }
        }

        ~sparse_matrix(){
            for(int i = 0; i < rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};


int main(){
    sparse_matrix m1(3,3);

    m1.inputValues();
    m1.display_normal();
    m1.display_sparse();
}
