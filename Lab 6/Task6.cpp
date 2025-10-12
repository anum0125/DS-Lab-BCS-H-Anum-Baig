#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct Node{
    char d;
    Node* n;
    Node(char c){d=c;n=NULL;}
};

class CStack{
    Node* t;
public:
    CStack(){t=NULL;}
    bool e(){return t==NULL;}
    void push(char c){Node* x=new Node(c);x->n=t;t=x;}
    char pop(){if(e())return '\0';char c=t->d;Node* x=t;t=t->n;delete x;return c;}
    char peek(){if(e())return '\0';return t->d;}
};

struct Node2{
    int d;
    Node2* n;
    Node2(int v){d=v;n=NULL;}
};

class IStack{
    Node2* t;
public:
    IStack(){t=NULL;}
    bool e(){return t==NULL;}
    void push(int v){Node2* x=new Node2(v);x->n=t;t=x;}
    int pop(){if(e())return 0;int v=t->d;Node2* x=t;t=t->n;delete x;return v;}
};

int p(char c){
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return -1;
}

bool isalnumX(char c){
    return (c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z');
}

string rev(string s){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        char x=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=x;
    }
    return s;
}

string infixToPrefix(string s){
    s=rev(s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(')s[i]=')';
        else if(s[i]==')')s[i]='(';
    }
    CStack st;
    string r="";
    for(int i=0;s[i]!='\0';i++){
        char c=s[i];
        if(isalnumX(c))r+=c;
        else if(c=='(')st.push(c);
        else if(c==')'){
            while(!st.e()&&st.peek()!='(')r+=st.pop();
            if(!st.e())st.pop();
        }else{
            while(!st.e()&&p(st.peek())>p(c))r+=st.pop();
            st.push(c);
        }
    }
    while(!st.e())r+=st.pop();
    r=rev(r);
    return r;
}

int evalPrefix(string s){
    IStack st;
    for(int i=s.size()-1;i>=0;i--){
        char c=s[i];
        if(c>='0'&&c<='9')st.push(c-'0');
        else{
            int a=st.pop();
            int b=st.pop();
            int r=0;
            if(c=='+')r=a+b;
            else if(c=='-')r=a-b;
            else if(c=='*')r=a*b;
            else if(c=='/')r=a/b;
            else if(c=='^')r=pow(a,b);
            st.push(r);
        }
    }
    return st.pop();
}

int main(){
    string e="3+(2*4)-5";
    string pr=infixToPrefix(e);
    cout<<"Infix:"<<e<<endl;
    cout<<"Prefix:"<<pr<<endl;
    cout<<"Value:"<<evalPrefix(pr)<<endl;
    return 0;
}
