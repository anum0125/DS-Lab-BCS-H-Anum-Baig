#include <iostream>
using namespace std;

int main() {
    int students;
    cout << "Enter the total number of students: " << endl;
    cin >> students;
    
    int** marks_array = new int*[students];
    int number_of_courses[students];
    
    for (int i = 0; i < students; i++){
        int courses;
        cout << "Enter the number of courses for student " << i+1 << ": " <<endl;
        cin >> courses;
        marks_array[i] = new int[courses];
        number_of_courses[i] = courses;
         cout << "Student " << i+1 << ": " << endl;
        for (int j = 0; j < courses; j++){
            cout << "Enter marks for course " << j+1 << ": " << endl;
            cin >> marks_array[i][j];
        }
    }
    
    cout << "Average marks: " << endl;
    for (int i = 0; i < students; i++){
        float total = 0;
        for (int j = 0; j < number_of_courses[i]; j++){
            total += marks_array[i][j];
        }
        cout << "Student " << i+1 << ": " << total/number_of_courses[i] << endl;
    }
    
    for (int i = 0; i < students; i++){
        delete[] marks_array[i];
    }
    delete[] marks_array;
}
