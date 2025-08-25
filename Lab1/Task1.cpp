#include <iostream>
using namespace std;

class BankAccount
{
    private:
        float* balance;

    public:
        BankAccount()
        {
            balance = new float(0);
        }
        BankAccount(float b)
        {
            balance = new float(b);
        }
        BankAccount(BankAccount& other)
        {
            balance = new float(*other.balance);
        }
        void printBalance()
        {
            cout << "Balance: $" << *balance << endl;
        }
        void withdraw(float amount)
        {
            if (amount > *balance)
            {
                cout << "Limit exceeded!" << endl;
            }
            else
            {
                *balance -= amount;
                cout << "Amount Withdrawn!" << endl; 
            }
        }
};

int main()
{
    BankAccount account1;

    BankAccount account2(1000);
    account1.printBalance();
    account2.printBalance();

    BankAccount account3 = account2;
    account3.withdraw(200);
    account3.printBalance();
    account2.printBalance();

}
