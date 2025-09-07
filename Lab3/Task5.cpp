# include <iostream>
using namespace std;

struct SinglyNode{
    int data;
    SinglyNode* next;

    SinglyNode(int data): data(data), next(NULL){}
};

struct DoubleNode{
    int data;
    DoubleNode* next;
    DoubleNode* previous;

    DoubleNode(int data): data(data), next(NULL), previous(NULL){}
};

void insertAthead(int data, SinglyNode*& head){ // Singly
    SinglyNode* newNode = new SinglyNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data, SinglyNode*& head){ // Singly
    SinglyNode* newNode = new SinglyNode(data);
    SinglyNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

DoubleNode* singlyToDouble(SinglyNode* head){
    SinglyNode* temp = head;
    DoubleNode* previous = NULL;
    DoubleNode* dHead = NULL;
    while(temp != NULL){
        DoubleNode* newNode = new DoubleNode(temp->data);
        newNode->next = NULL;
        newNode->previous = previous;

        if(previous != NULL){
            previous->next = newNode;
        }else{
            dHead = newNode;
        }

        previous = newNode;
        temp = temp->next;
    }

    return dHead;
}

void printList(SinglyNode* head){
    SinglyNode* temp = head;
    cout << "\nSingly list: " << endl;
    while(temp != NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printCircularList(SinglyNode *head){
    cout << "\nCircular List: " << endl;
    for(int i = 0; i < 6; i++){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void printDoubleList(DoubleNode* head){
    DoubleNode* temp = head;
    cout << "\nDouble List: " << endl;
    cout << "Forward: " << endl;
    while(temp->next != NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << temp->data << "-->";
    cout << "NULL" << endl;

    cout << "Backward: " << endl;
    while(temp != NULL){
        cout << temp->data << "-->";
        temp = temp->previous;
    }
    cout << "NULL" << endl;
}

SinglyNode* SinglyToCircular(SinglyNode* head){
    SinglyNode* CHead = head;
    if(!CHead){
        return NULL;
    }
    SinglyNode* temp = CHead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = CHead;
    return CHead;
}

int main(){
    SinglyNode* head = NULL;
    insertAthead(1, head);
    insertAtEnd(2, head);
    insertAtEnd(3, head);

    printList(head);

    DoubleNode* doubleHead = singlyToDouble(head);

    SinglyNode* circularHead = SinglyToCircular(head);

    printDoubleList(doubleHead);
    printCircularList(circularHead);
}

