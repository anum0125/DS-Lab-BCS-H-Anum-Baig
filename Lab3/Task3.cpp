# include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val): data(val), next(NULL){}
};

void insertAtTail(int val, Node*& head){ 
    Node* newNode = new Node(val); 
    if(head == NULL){ // empty list
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(int val, Node*& head){ 
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void printList(Node* temp){ // --> starting from head
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* reverseKNodes(Node*& head, int k, Node*& nextGroupHead){
    Node* previous = NULL;
    Node* current = head;
    Node* temp = NULL;
    int count = 0;

    Node* check = head;
    for(int i = 0; i < k; i++){
        if(!check){
            nextGroupHead = head;
            return head;
        }
        check = check->next;
    }
    Node* tail = head;
    while(current && count < k){
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
        count++;
    }
    nextGroupHead = current;
    tail->next = NULL;
    return previous;
}

void reverseinKGroups(Node*& head, int k){
    if(!head || k <= 1)return;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* previous_tail = dummy;
    Node* current = head;

    while(current){
        Node* nextGroupHead = NULL;
        Node* newHead = reverseKNodes(current, k, nextGroupHead);

        if(newHead == current){
            previous_tail->next = current;
            break;
        }

        previous_tail->next = newHead;
        previous_tail = current;
        current = nextGroupHead;
    }
    head = dummy->next;
    delete dummy;
}

int main(){
    Node* head = NULL;
    insertAtHead(2, head);
    insertAtHead(3, head);
    insertAtHead(4, head);
    insertAtHead(5, head);

    reverseinKGroups(head, 2);

    printList(head);
}

/*void reverseKNodes(Node*& head, int k){
    Node* previous = NULL;
    Node* current = head;
    Node* temp = NULL;
    Node* tail = head;
    for(int i = 0; i < k; i++){
        if(current == NULL){
            break;
        }
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    head = previous;
    tail->next = current;
}*/
