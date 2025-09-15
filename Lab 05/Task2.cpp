# include <iostream>
using namespace std;

void funcB(int n);
void funcA(int n);

void printNumber(int n){
    if(n == 0){
        return;
    }
    cout << n << endl;
    printNumber(n-1);
}

void funcA(int n){
    if(n == 0){
        return;
    }
    if((n % 2) == 0){
        cout << "funcA: " << n << endl;
    }
    funcB(n-1);
}

void funcB(int n){
    if(n == 0){
        return;
    }
    if((n % 2) != 0){
        cout << "funcB: " << n << endl;
    }
    funcA(n-1);
}

int main(){
    printNumber(5);

    funcA(10);
}
