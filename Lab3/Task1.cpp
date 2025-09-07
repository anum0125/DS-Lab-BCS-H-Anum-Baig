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

Node* reverseList(Node* head){ // returns new head
    Node* previous = NULL; // in the end it will point to new head
    Node* current = head;
    while(current != NULL){
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondhalf = reverseList(slow->next);
    Node* firsthalf = head;
    Node* tempSecond = secondhalf;

    bool palindrome = true;
    while(tempSecond != NULL){
        if(firsthalf->data != tempSecond->data){
            palindrome = false;
            break;
        }
        firsthalf = firsthalf->next;
        tempSecond = tempSecond->next;
    }

    slow->next = reverseList(secondhalf);

    return palindrome;

}

int main(){
    Node* head = NULL;

    insertAtHead(4, head);
    insertAtHead(3, head);
    insertAtHead(2, head);
    insertAtHead(1, head);

    printList(head);

    head = reverseList(head);

    printList(head);

    bool pal = isPalindrome(head);

    if(pal == true){
        cout << "it is a palindrome!" << endl;
    }
    else{
        cout << "it is not a palindrome!" << endl;
    }

}
