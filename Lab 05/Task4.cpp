# include <iostream>
using namespace std;

int sumTail(int n, int total){
    if(n == 0){
        return total;
    }
    return sumTail(n-1, total+n);
}

int nonSumTail(int n){
    if(n == 0){
        return 0;
    }
    return n + nonSumTail(n-1);
    
}

int main(){
    cout << sumTail(5, 0) << endl;
    cout << nonSumTail(5) << endl;
}

/* Tail recursion performs computation before the recursive call and can reuse stack frames (optimsed), 
while non-tail recursion does computation after the calll and requires all stack frames to remain until
unwinding, using more memory */
