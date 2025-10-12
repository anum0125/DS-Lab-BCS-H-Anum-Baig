#include<iostream>
#include<string>
using namespace std;

struct Job{
    int id;
    int pr;
    Job* n;
    Job(int i,int p){id=i;pr=p;n=NULL;}
};

class Q{
    Job* f;
    Job* r;
public:
    Q(){f=r=NULL;}
    bool e(){return f==NULL;}
    void enq(int i,int p){
        Job* x=new Job(i,p);
        if(e()){f=r=x;}
        else{r->n=x;r=x;}
    }
    Job* deq(){
        if(e())return NULL;
        Job* t=f;
        f=f->n;
        if(f==NULL)r=NULL;
        return t;
    }
    void show(){
        Job* t=f;
        cout<<"Queue:";
        while(t){cout<<"[ID"<<t->id<<",P"<<t->pr<<"] ";t=t->n;}
        cout<<endl;
    }
};

struct Node{
    int id;
    int pr;
    Node* n;
    Node(int i,int p){id=i;pr=p;n=NULL;}
};

class St{
    Node* t;
public:
    St(){t=NULL;}
    bool e(){return t==NULL;}
    void push(int i,int p){Node* x=new Node(i,p);x->n=t;t=x;}
    Node* pop(){
        if(e())return NULL;
        Node* x=t;
        t=t->n;
        return x;
    }
    void show(){
        Node* x=t;
        cout<<"Stack:";
        while(x){cout<<"[ID"<<x->id<<",P"<<x->pr<<"] ";x=x->n;}
        cout<<endl;
    }
};

int main(){
    Q q;
    q.enq(1,2);
    q.enq(2,5);
    q.enq(3,1);
    q.enq(4,4);
    q.enq(5,3);
    q.show();

    St s;
    cout<<"Transferring to stack in priority order..."<<endl;
    while(!q.e()){
        Job* h=q.deq();
        if(!h)break;
        if(s.e())s.push(h->id,h->pr);
        else{
            St temp;
            while(!s.e()&&s.pop()->pr>h->pr);
            s.push(h->id,h->pr);
        }
    }

    cout<<"Execution order (LIFO by priority):"<<endl;
    s.show();

    cout<<"Executing jobs:"<<endl;
    while(!s.e()){
        Node* x=s.pop();
        cout<<"Executing ID"<<x->id<<" Priority"<<x->pr<<endl;
    }
    return 0;
}
