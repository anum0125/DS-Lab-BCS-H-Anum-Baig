# include <iostream>
using namespace std;

struct node{
    node* mother; // left
    string name;
    node* father; // right

    node(string name): name(name){
        mother = NULL;
        father = NULL;
    }
};

class familyTree{
    private:
        node* youngest;

    public:
        familyTree(){
            youngest = NULL;
        }

        void sampleFamilyTree(){
            youngest = new node("Ali"); // youngest

            youngest->mother = new node("Hania");
            youngest->father = new node("Hamza");

            youngest->mother->mother = new node("Ayesha");
            youngest->mother->father = new node("Ahmed");

            youngest->father->mother = new node("Aliya");
            youngest->father->father = new node("Mustafa");

            youngest->mother->mother->mother = new node("Sara");
            youngest->mother->mother->father = new node("Abdullah");
        }

        int height(node* youngest){
            if(youngest == NULL) return 0;
            int h_left = height(youngest->mother);
            int h_right = height(youngest->father);
            return 1+(h_left > h_right ? h_left: h_right);
        }

        void Leaves(node* youngest){
            if(youngest == NULL) return;
            if(youngest->mother == NULL && youngest->father == NULL){
                cout << youngest->name << endl;
            }
            Leaves(youngest->mother);
            Leaves(youngest->father);
        }

        void Levels(node* youngest, int level){
            if(youngest == NULL) return;
            cout << youngest->name << " - Level: " << level << endl;
            Levels(youngest->mother, level+1);
            Levels(youngest->father, level+1);
        }

        void displayYoungest(){
            if(youngest != NULL){
                cout << "Youngest Person: " << youngest->name << endl;
            }
        }

        void showLeaves(){
            cout << "Ancestors with no known parents: " << endl;
            Leaves(youngest);  
        }

        void showLevels() {
            cout << "Levels of each member: " << endl;
            Levels(youngest, 0);
        }

        void showHeight() {
            cout << "Height of Tree: " << height(youngest)-1 << endl;
        }
};

int main(){
    familyTree f1;
    f1.sampleFamilyTree();

    f1.displayYoungest();
    cout << endl;
    f1.showLeaves();
    cout << endl;
    f1.showLevels();
    cout << endl;
    f1.showHeight();
}



