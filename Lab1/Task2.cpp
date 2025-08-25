# include <iostream>
# include <string>
#include <cstring>
using namespace std;

class Exam
{
    char* studentname;
    int score;
    string examdate;

    public:
    Exam(){
        studentname = new char[50];

      
    }
    void setDetails(char *name, int s, string d)
    {

            strcpy(studentname,name);
            score = s;
            examdate = d;
        }
    void display(){
        cout << "Name: " << studentname << endl;
        cout << "Score: " << score << endl;
        cout << " Date: " << examdate << endl;
    }
};

int main()
{
    Exam exam1;
    exam1.setDetails("NAME", 90, "5/2/25");
    exam1.display();
    Exam exam2 = exam1;
    exam2.display();
}
