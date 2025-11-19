# include <iostream>
using namespace std;

struct patient{
    string name;
    string arrivalTime;
    int priority;
    patient* nextPatient;

    patient(string n, string t, int p){
        name = n;
        arrivalTime = t;
        priority = p;
        nextPatient = NULL;
    }
};

class hospitalQueue{
    patient* front;

    public:

        hospitalQueue(){
            front = NULL;
        }

        void addPatient(string n, string t, int p){
            patient* newPatient = new patient(n, t, p);

            if(!front || newPatient->priority > front->priority){
                newPatient->nextPatient = front;
                front = newPatient;
            }else{
                patient* current = front;
                while(current->nextPatient && current->nextPatient->priority >= p){
                    current = current->nextPatient;
                }
                newPatient->nextPatient = current->nextPatient;
                current->nextPatient = newPatient;

            }
        }

        void treatPatient(){
            if(!front){
                cout << "No patients to treat!" << endl;
                return;
            }
            cout << "Patient to be treated: " << front->name << endl;
            patient* temp = front;
            front = front->nextPatient;
            delete temp;
        }

        void updatePriority(string name, int up){
            patient* current = front;
            patient* previous = NULL;
            while(current && current->name != name){
                previous = current;
                current = current->nextPatient;
            }
            if(!current){
                cout << "Patient record not found!" << endl;
                return;
            }
            string n = current->name;
            string t = current->arrivalTime;
            if (previous == NULL) {
                front = current->nextPatient;  
            } else {
                previous->nextPatient = current->nextPatient;
            }
            delete current;
            addPatient(n, t, up);
        }

        void displayPatients(){
            patient* current = front;
            cout << "\nWaiting Patients: \n" << endl;
            while(current){
                cout << "Patient name: " << current->name << endl;
                cout << "Priority level: " << current->priority << endl;
                cout << endl;
                current = current->nextPatient;
            }
        }
};

int main() {

    hospitalQueue h;

    h.addPatient("Alpha", "08:00", 3);
    h.addPatient("Bravo", "08:05", 5);
    h.addPatient("Charlie", "08:10", 2);

    h.displayPatients();

    h.updatePriority("Alpha", 6);

    h.displayPatients();

    h.treatPatient();
    h.treatPatient();

    h.displayPatients();

    return 0;
}


