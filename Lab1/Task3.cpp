# include <iostream>
using namespace std;

class Box{
    int *number;
    public:
    ~Box(){
        delete number;
    }
    Box(int n){
        number = new int(n);
    }
    Box(Box &other){
        number = new int(*other.number);
    }
    Box(Box &other, bool num){
        number = other.number;
    }
    Box& operator=(Box &other){
        delete number;
        number = new int(*other.number);
        return *this;
    }
};

int main(){
    Box b1(10);
    Box b2(20);
    Box b3 = b1;
    

}
