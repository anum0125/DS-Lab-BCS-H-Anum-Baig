//TASK 10

# include <iostream>
using namespace std;

class library{
    int** categories;
    int rows;
    int* cols;

    public:
        library(int r):rows(r){
            categories = new int*[rows];
            cols = new int[rows];
            for(int i = 0; i < rows; i++){
                cout << "Enter the number of columns for category " << i+1 << endl;
                cin >> cols[i];
                categories[i] = new int[cols[i]];
            }

            for(int i = 0; i < rows; i++){
                cout << "Enter Book ID's for category " << i+1 << endl;
                for(int j = 0; j < cols[i]; j++){
                    cout << "Book " << j+1 << endl;
                    cin >> categories[i][j];
                }
            }
        }

        void findBook(int id){
            bool found = false;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols[i]; j++){
                    if(categories[i][j] == id){
                        cout << "The book is available in Category " << i+1 << "!" << endl;
                        found = true;
                        break;
                    }
                }
                if(found){
                    break;
                }
            }
            if(!found){
                cout << "Book not found!" << endl;
            }
        }

        ~library(){
            for(int i = 0; i < rows; i++){
                delete[] categories[i];
            }
            delete[] categories;
            delete[] cols;
        }

};

int main(){
    library l1(3);
    l1.findBook(007);
}
