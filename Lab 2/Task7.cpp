#include <iostream>
using namespace std;

class Company{
  int departments;
  int **company;
  int *employees;
  
  public:
    Company(int d):departments(d){
        company = new int*[departments];
        employees = new int[d];
        for(int i = 0; i < departments; i++){
            int e;
            cout << "\nEnter the number of employees for department " << i+1 << ": ";
            cin >> e;
            company[i] = new int[e];
            employees[i] = e;
        }
    }
    
    void store_Salaries(){
        for(int i = 0; i < departments; i++){
            cout << "\nStore salaries for employees of department " << i+1 << ": " << endl;
            for (int j = 0; j < employees[i]; j++){
                cout << "Employee " << j+1 << ": ";
                cin >> company[i][j];
            }
        }
    }
    
    void Calculate_highest_salary(){
        for(int i = 0; i < departments; i++){
            int highest = company[i][0];
            for(int j = 1; j < employees[i]; j++){
                if(company[i][j] > highest){
                    highest = company[i][j];
                }
            }
            cout << "Highest salary in department " << i+1 << ": $" << highest << endl;
        }
    }
    
    void highest_average(){
        float *average = new float[departments];
        for(int i = 0; i < departments; i++){
            int total = 0;
            for(int j = 0; j < employees[i]; j++){
                total += company[i][j];
            }
            average[i] = (float)total / employees[i];
        }

        int highest = 0;
        for (int i = 1; i < departments; i++){
            if(average[i] > average[highest]){
                highest = i;
            }
        }
        cout << "The department with the highest average salary is department " << highest+1 << endl;
        delete[] average;
    }
    
    ~Company(){
        delete[] employees;
        for(int i = 0; i < departments; i++){
            delete[] company[i];
        }
        delete[] company;
    }
};

int main() {
    Company c1(3);
    c1.store_Salaries();
    c1.Calculate_highest_salary();
    c1.highest_average();
}
