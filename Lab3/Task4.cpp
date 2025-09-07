# include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val): data(val), next(NULL){}
};

class CLL{
    public:

    Node* head;
    Node* tail;

    CLL(){
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void insertAtStart(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    Node* deletion(Node*& head, Node*& tail, int k){
        if(!head){
            return NULL;
        }

        int length = 1;
        Node* lenptr = head;
        while(lenptr->next != head){
            length++;
            lenptr = lenptr->next;
        }

        k = ((k-1)%length)+1;

        Node* temp = head;
        for(int i = 0; i < k-2; i++){
            temp = temp->next;
        }
        if(temp == head){
            Node* previous_head = temp;
            temp = temp->next;
            tail->next = temp;
            head = temp;
            delete previous_head;
            return head;
        }
        Node* previous = temp->next;

        if(previous == tail){
            tail = temp;
        }
        temp->next = temp->next->next;
        delete previous;
        return head;
    }

    void Josephus(Node*& head, Node*& tail, int k){
        while(head->next != head){
            head = deletion(head, tail, k);
        }
        cout << "Survivor: " << head->data << endl;
    }

    void printList(Node* head, Node* tail){
        Node* temp = head;
        while(true){
            if(temp == tail){
                cout << temp->data << "--> NULL" << endl;
                return;
            }
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }


};

int main(){
    CLL list1;
    list1.insertAtStart(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);
    list1.insertAtEnd(6);
    list1.insertAtEnd(7);
    list1.insertAtEnd(8);
    list1.insertAtEnd(9);
    list1.insertAtEnd(10);
    list1.insertAtEnd(11);
    list1.insertAtEnd(12);
    list1.insertAtEnd(13);

    list1.printList(list1.head, list1.tail);

    list1.Josephus(list1.head, list1.tail, 3);

    list1.printList(list1.head, list1.tail);

}
