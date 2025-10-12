#include <iostream>
#include <string>
using namespace std;

struct Node{
    string url;
    Node* link;
    Node(string site) : url(site), link(NULL){}
};

class Stack{
private:
    Node* top;
public:
    Stack(){top = NULL;}
    bool isEmpty(){return top == NULL;}
    void push(string site){
        Node* newNode = new Node(site);
        newNode->link = top;
        top = newNode;
    }
    string pop(){
        if (isEmpty()) return "";
        string site = top->url;
        Node* temp = top;
        top = top->link;
        delete temp;
        return site;
    }
    string peek(){
        if (isEmpty()) return "";
        return top->url;
    }
    void clear(){
        while (!isEmpty()) pop();
    }
};

class Browser{
private:
    Stack backStack;
    Stack forwardStack;
    string currentPage;
public:
    Browser(){
        currentPage = "Home";
    }
    void visit(string site){
        if(!currentPage.empty()) backStack.push(currentPage);
        currentPage = site;
        forwardStack.clear();
        cout << "Visited: " << currentPage << endl;
    }
    void back(){
        if(backStack.isEmpty()){
            cout << "No previous page!" << endl;
            return;
        }
        forwardStack.push(currentPage);
        currentPage = backStack.pop();
        cout << "Went back to: " << currentPage << endl;
    }
    void forward(){
        if(forwardStack.isEmpty()){
            cout << "No forward page!" << endl;
            return;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.pop();
        cout << "Went forward to: " << currentPage << endl;
    }
    void showCurrentPage(){
        cout << "Current page: " << currentPage << endl;
    }
};

int main() {
    Browser browser;
    browser.showCurrentPage();
    browser.visit("www.google.com");
    browser.visit("www.youtube.com");
    browser.visit("www.github.com");
    browser.back();
    browser.back();
    browser.forward();
    browser.visit("www.wikipedia.org");
    browser.back();
    browser.showCurrentPage();
    return 0;
}
