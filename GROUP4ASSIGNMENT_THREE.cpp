// GROUP4ASSIGNMENT_THREE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>         
#include <bits/stdc++.h>    //including all the header files 
#include <vector>
#include <fstream>

using namespace std;

class Transaction {     //transaction class
public:
    double amount; //variables for transaction
    string type;

    Transaction(double amt, string kind) //constructor for transaction
    {
        amount = amt;
        type = kind;
    }
    
    string report()     //report function returnig string type of transaction details
    {
        stringstream ss;
        ss << amount;   //changing double to string
        string s = type + " - " + ss.str();
        return s;       //return string
    }
};

class Account {         //class account
public:
    double balance = 0;         //varibales for account class
    vector<Transaction> log;    //varibales for storing transaction objects
    
    Account(double init_balance) //parameterized constructor for account class
    {
        if (init_balance < 1000)    //if function if given amount <1000 to set the balance to 0
        {
            setBalance();   //calling srt balance method
        }
        else {
            balance = init_balance; //else set the given amount to balance
        }

    }

    void setBalance(void) //set balance method
    {
        balance = 0;
        cout << "Balance is invalid" << endl;

    }

    double getBalance() //get balance method
    {
        return balance;
    }

    bool deposit(double amount) //deposit method
    {
        if (amount <= 0) //if given amount <0 display a error message
        {
            return false;

        }
        else {          //else add the amount to balanee
            balance += amount;
            
            log.push_back(Transaction(amount, "Deposit"));      //call the transaction class and store the object vector
            return true;    //return true
        }
    }
    bool withdraw(double amount)    //withdraw function
    {
        
        if (amount<0 || amount>balance)     //if amount >balance or amount is negative value then display a error message and return false
        {
            return false;
        }
        else {
            balance -= amount; //else deduct the amount the amount from balance
           
            log.push_back(Transaction(amount, "withdraw"));      //call the transaction class and store the object vector
            return true;//and return true
        }
    }

    vector<string> report()     //report method of type vector string
    {
        vector<string> f;       //create a new vector string
        for (int i = 0; i < log.size(); i++)
        {
            f.push_back(log[i].report()); //now access the vector objects and transaction details in vector string
        }
        return f;   //return vector string
    }

};

class savingAccount : public Account { //creating saving accouunt and inheriting account class
public:
    float interestRate = 0;   //varibale for this class
                        
    savingAccount(double init_balance, float rate) :Account(init_balance) //calling parent class constructor for this constructor
    {

        if (rate < 0)   //if the given rate is negative value display a error message and set interestrate to 0
        {
            cout << "Negative interest" << endl;
            interestRate = 0;
        }
        else {
            interestRate = rate; //else assign the rate

        }
    }

    double calcInterest()       //calculating interest for user amount
    {
        return balance * ((interestRate / 100) / 12);   // find the interest for monthand return the value

    }

};


class chequingAccount : public Account {    //creating chequing accouunt and inheriting account class
public:
    float interestRate = 0;             //varibale for this class
                              
    chequingAccount(double init_balance, float rate) :Account(init_balance)   //calling parent class constructor for this constructor
    {

        if (rate < 0)               //if the given rate is negative value display a error message and set interestrate to 0
        {
            cout << "Negative interest" << endl;
            interestRate = 0;
        }
        else {
            interestRate = rate;        //else assign the rate

        }
    }

    double calcInterest()               //calculating interest for user amount
    {
        return balance * ((interestRate / 100) / 12);   // find the monthly interest for monthand return the value

    }
};


int main() //main fuction
{
    savingAccount save(1000, 15);       //creating object for savings account and passing parameters
    cout << "========================================" << endl;
    cout << "Savings Account Created With Initial Amount : " << 1000 << endl;
    if (save.deposit(200))                      //calling deposit method
    {
        cout << "Amount is Deposited" << endl;      //calling getbalance method
        cout << "Updated Balance After Deposit: " << save.getBalance() << endl;
    }
    if (save.withdraw(100))   //calling withdraw method
    {
        cout << "\nAmount Withdrawn" << endl;
        cout << "Updated Balance After Withdrawal : " << save.getBalance() << endl;
    }
    vector<string> g = save.report();   //calling report method
    ofstream write("user1.txt"); //opening user1 text file two write the transaction details
    cout << "\nTransacrions are :" << endl;
    for (int i = 0; i < g.size(); i++)   //displaying transactions
    {
        cout << g[i] << endl;
        write << g[i] << "\n" << endl;  //writing data to file
    }
    write.close();
    cout << "\nThe Monthly interest for interestRate " << 15 << " = " << save.calcInterest() << endl;   //calling calc intereset method
    cout << "========================================" << endl;

    chequingAccount cheq(1200, 10);     //creating object for chequing account and passing parameters
    cout << "Chequing Account Created with initial amount : " << 1200 << endl;
    if (cheq.deposit(200))             //calling deposit method
    {
        cout << "\nAmount Deposited" << endl;       //calling getbalance method
        cout << "Updated Balance After Deposit: " << cheq.getBalance() << endl;
    }
    if (cheq.withdraw(100))                 //calling withdraw method
    {
        cout << "\nAmount Withdrawn" << endl;
        cout << "Updated Balance After Withdraw : " << cheq.getBalance() << endl;
    }
    vector<string> h = cheq.report();           //calling report method
    ofstream writ("user2.txt");                 //opening user2 text file two write the transaction details
    cout << "\nTransacrions are :" << endl;
    for (int i = 0; i < h.size(); i++)
    {
        cout << h[i] << endl;               //displaying transactions
        writ << h[i] << "\n" << endl;       //writing data
    }
    writ.close();
    cout << "\nThe Monthly interest for interest Rate " << 10 << " = " << cheq.calcInterest() << endl;//calling calc intereset method
    cout << "========================================" << endl;

}
