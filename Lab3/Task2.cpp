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
    cout << endl;
}

void insertSort(Node*& head, Node*& insertNode){
    if(head == NULL || insertNode->data < head->data){
        insertNode->next = head;
        head = insertNode;
        return;
    }
    Node* previous = NULL;
    Node* current = head;
    while(true){
        if(insertNode->data < current->data){
        previous->next = insertNode;
        insertNode->next = current;
        break;
        }
        if(current->next == NULL){
            insertNode->next = NULL;
            current->next = insertNode;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void mergeLists(Node*& head1, Node* temp /*head2*/){
    while(temp != NULL){
        Node* newNode = temp->next;
        temp->next = NULL;
        insertSort(head1, temp);
        temp = newNode;
    }
};

int main(){
    Node* list1_head = NULL;
    Node* list2_head = NULL;

    insertAtHead(10, list1_head);
    insertAtHead(7, list1_head);
    insertAtHead(5, list1_head);
    
    insertAtHead(11, list2_head);
    insertAtHead(4, list2_head);
    insertAtHead(2, list2_head);

    cout << "List A: " << endl;
    printList(list1_head);

    cout << "List B: " << endl;
    printList(list2_head);

    mergeLists(list1_head, list2_head);

    cout << "Merged List: " << endl;
    printList(list1_head);
}
