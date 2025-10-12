# include <iostream>
using namespace std;

class circularQueue{
    private:
        int* queueArray;
        int rear;
        int front;
        int capacity;

    public:
        circularQueue(int max):capacity(max){
            queueArray = new int[max];
            rear = -1;
            front = -1;
        }

        bool isEmpty(){
            return(front == -1 && rear == -1);
        }

         bool isFull(){
            return ((rear + 1) % capacity == front);
        }

        void enqueue(int element){
            if(isFull()){
                cout << "Queue overflow!" << endl;
                return;
            }
            if(isEmpty()){
                front = rear = 0;
            }else{
                rear = (rear + 1) % capacity;
            }
            queueArray[rear] = element;
            cout << "Element enqueued: " << element << endl;
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty!" << endl;
                return;
            }
            cout << "Element dequeued: " << queueArray[front] << endl;
            if(front == rear){
                front = rear = -1; 
            }else{
                front = (front + 1) % capacity;
            }
        }

        void display(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while(true){
            cout << queueArray[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

        ~circularQueue() {
            delete[] queueArray;
        }
};

int main() {
    circularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

}
