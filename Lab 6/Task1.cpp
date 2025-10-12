# include <iostream>
using namespace std;


class stack{
    private:
        int* stackArray;
        int capacity;
        int top;
    
    public: 
        stack(int size){
            stackArray = new int[size];
            capacity = size;
            top = -1;
        }

        void push(int element){
            if(top >= capacity-1){
                cout << "Stack OverFlow!" << endl;
                return;
            }
            stackArray[++top] = element;
            cout << "Element added at top!" << endl;
        }

        void pop(){
            if(top == -1){
                cout << "Stack is empty!" << endl;
                return;
            }
            cout << "Element removed: " << stackArray[top] << endl;
            top--;
        }

        void peek(){
            if(top == -1){
                cout << "Stack is empty!" << endl;
                return;
            }
            cout << "Element at top: " << stackArray[top] << endl;
        }

        void display(){
            for(int i = top; i >= 0; i--){
                pop();
            }
        }

        ~stack(){
            delete[] stackArray;
        }
};

int main() {
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.peek();
    
    s.display();
}
