#include <iostream>
using namespace std;

class linearQueue{
    private:
        int* queueArray;
        int rear;
        int front;
        int capacity;
    public:
        linearQueue(int max):capacity(max){
            queueArray = new int[max];
            rear = -1;
            front = -1;
        }
        bool isEmpty(){
            return(front == -1 || front > rear);
        }
        bool isFull(){
            return(rear == capacity - 1);
        }
        void enqueue(int element){
            if(isFull()){
                cout << "Queue overflow!" << endl;
                return;
            }
            if(front == -1)front = 0;
            queueArray[++rear] = element;
            cout << "Element enqueued!" << endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty!" << endl;
                return;
            }
            cout << "Element dequeued: " << queueArray[front] << endl;
            front++;
        }
        void display(){
            cout << endl;
            if(isEmpty()){
                cout << "Queue is empty!" << endl;
                return;
            }
            while(!isEmpty()){
                dequeue();
            }
            cout << "Queue is now empty!" << endl;
        }
        ~linearQueue(){
            display();
            delete[] queueArray;
        }
};

int main(){
    linearQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.enqueue(60);
}
