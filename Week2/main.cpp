#include <iostream>
#include <stdlib.h>
#include <string>
#include "InputVerification.cpp"
using namespace std;

void Task1(){
        int i = 0;
        int x;
        int smallest;
        int largest;
        while (i < 5) {
            cout << "Input number " << i + 1 << "\n";
            cin >> x;
            if (i == 0){
                smallest = x;
                largest = x;
            }
            else{
                if (x > largest) largest = x;
                if (x < smallest) smallest = x;
            }
            i++;
        }
        std::cout << smallest << " is the smallest.";
        cout << largest << " is the largest.";

    };

void Task2() {
    int i = 0;
    int nums[10] = {};
    while (i < 10) {
        cout << "Enter a number \n";
        string n;
        cin >> n;
        if (!isInteger(n)) {
            cout << "Bad inout, try a number. \n";
        } else {
            int num = atoi(n.c_str());
            nums[i] = num;
            i++;
        }
    }
    cout << nums;
    for (int x = 0; x < 10; x++) {
        int value = nums[x];
        cout << value << " squared is " << value*value <<"\n";
    }
};

void Task3(){
    bool done = false;
    double total = 0;
    while (!done){
        cout << "Enter the next value \n";
        string priceCheck;
        cin >> priceCheck;
        double price;
        if (isInteger(priceCheck)){price = atof(priceCheck.c_str());}
        else {cout << "Please enter a value. \n";}
        if (price == -1){break;}
        else {
            total += price;
            cout << "New total is " << total;
        }
    }
    cout << "Total price is " << total;
};

void Task4(){
    char op;
    double one, two, result;

    cout << "Please input calculation operation (e.g.1 + 2): \n";
    cin >> one >> op>> two;
    switch(op) {
        case '+' : result = one + two; break;
        case '-' : result = one - two; break;
        case '*' : result = one * two; break;
        case '/' : result = one / two; break;
    }
    cout << "Result = " << result;

};

void Task5(){
    while (1){
        string i;
        int j;
        cin >> i;
        if (isInteger(i)) {j = atoi(i.c_str());}
        if (j < 0) {break;}
        else if (j > 20) {cout << "ERROR : Input must be lower then 20";}
        else {
            for (int x = 0; x < j; x++){
                cout << "*";
            }
        }
    }
};

void Task6A(){
    cout << "What was the weekly salary?";
    string test;
    double salary;
    if (!isInteger(test)){cout << "Enter a value, try removing a currency symbol. \n";}
    else {
        salary = atof(test.c_str());
        cout << "Salary is " << salary << "\n";
    }
};

void Task6B(int hours){
    cout << "What was the hourly wage? \n";
    string test;
    double salary;
    if (!isInteger(test)){cout << "Enter a value, try removing a currency symbol. \n";}
    else {
        salary = atof(test.c_str());
        double pay = salary * hours;
        cout << "Weekly pay is " << pay << "\n";
    }
};

void Task6C(int hours){
    cout << "What was the hourly wage? \n";
    string test;
    double salary;
    if (!isInteger(test)){cout << "Enter a value, try removing a currency symbol. \n";}
    else {
        salary = atof(test.c_str());
        double base = 40;
        double extra = hours - 40;
        double pay = (salary * base) + ((salary*1.5)*extra);
        cout << "Weekly pay is " << pay << "\n";
    }
};

void Task6D(){
    cout << "What was their gross weekly sales? \n";
    string test;
    double sales;
    if (!isInteger(test)){cout << "Enter a value, try removing a currency symbol. \n";}
    else {
        sales = atof(test.c_str());
        sales = ((sales / 100) * 5.7);
        double pay = 250 + sales;
        cout << "Weekly pay is " << pay << "\n";
    }
};

void Task6E(){
    cout << "What if the employee's fixed pay per item? \n";
    string test;
    int value;
    int quantity;
    cin >> test;
    if (isInteger(test)){value = atoi(test.c_str());}
    cout << "How many hours did they work? \n";
    cin >> test;
    if (isInteger(test)){quantity = atoi(test.c_str()); }
    double pay = quantity * value;
    cout << "Weekly pay is " << pay << "\n";
};

void Task6(){
    cout << "What is the employee's pay code? \n";
    string test;
    int code;
    int hours;
    cin >> test;
    if (isInteger(test)){code = atoi(test.c_str());}
    cout << "How many hours did they work? \n";
    cin >> test;
    if (isInteger(test)){hours = atoi(test.c_str());}

    switch (code){
        case '1' : Task6A(); break;
        case '2' : (hours) ? Task6B(hours) : Task6C(hours); break;
        case '3' : Task6D(); break;
        case '4' : Task6E; break;
    }

};

int main() {
    cout << "Enter task number \n";
    int task;
    cin >> task;
    if (task == 1) Task1();
    if (task == 2) Task2();
    if (task == 3) Task3();
    if (task == 4) Task4();
    if (task == 5) Task5();
    if (task == 6) Task6();
    return 0;
}