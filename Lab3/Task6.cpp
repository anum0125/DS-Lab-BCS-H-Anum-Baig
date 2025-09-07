# include <iostream>
using namespace std;

struct multiLevelNode{
    int data;
    multiLevelNode* next;
    multiLevelNode* down;

    multiLevelNode(){}

    multiLevelNode(int data):data(data), next(NULL), down(NULL){}
};

multiLevelNode* insertAtHead(int data, multiLevelNode*& head){
    multiLevelNode* newNode = new multiLevelNode(data);
    newNode->next = head;
    head = newNode;
    return newNode;
}

multiLevelNode* insertAtEnd(int data, multiLevelNode*& head){
    multiLevelNode* newNode = new multiLevelNode(data);
    multiLevelNode* temp = head;
    if(temp == NULL){
        head = newNode;
        return newNode;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}

multiLevelNode* insertDownward(int data, multiLevelNode*& node){
    multiLevelNode* newNode = new multiLevelNode(data);
    multiLevelNode* temp = node->down;
    if(temp == NULL){
        node->down = newNode;
        return newNode;
    }
    while(temp->next != NULL){
        temp = temp-> next;
    }
    temp->next = newNode;
    return newNode;
}

void flatten(multiLevelNode*& head){
    multiLevelNode** store = new multiLevelNode*[100];
    multiLevelNode* temp = head;
    multiLevelNode* previous = NULL;
    int i = -1;
    while(temp != NULL || i >= 0){
        while(temp != NULL){
            if(temp->down != NULL){
                if(temp->next != NULL){
                    i++;
                    store[i] = temp->next;
                }
                temp->next = temp->down;
            previous = temp;
            temp = temp->down;
            previous->down = NULL;
            }else{
                previous = temp;
                temp = temp->next;
            }
        }
        if(i>=0){
            previous->next = store[i];
            temp = store[i];
            i--;
        }        
    }
    delete[] store;
}

void printList(multiLevelNode* head){
    while(head != NULL){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    multiLevelNode* head = NULL;
    multiLevelNode* node1 = insertAtHead(1, head);
    multiLevelNode* node2 = insertAtEnd(2, head);
    multiLevelNode* node3 = insertAtEnd(3, head);
    multiLevelNode* node10 = insertAtEnd(10, head);

    multiLevelNode* node4 = insertDownward(4, node3);
    multiLevelNode* node5 = insertDownward(5, node3);
    multiLevelNode* node9 = insertDownward(9, node3);

    multiLevelNode* node6 = insertDownward(6, node5);
    multiLevelNode* node7 = insertDownward(7, node5);
    multiLevelNode* node8 = insertDownward(8, node5);

    flatten(head);

    cout << "Flattened List: " << endl;
    printList(head);
}
