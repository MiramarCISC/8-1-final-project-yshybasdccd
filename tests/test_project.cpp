#include "project.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

bool closeEnough(double a,double b){
    return fabs(a-b) < 0.001;
}

void testWeek1(){
    Expense items[2] = {
        {"E1","Food",10.50},
        {"E2","Gas",20.00}
    };

    assert(closeEnough(calculateTotal(items,2),30.50));
}

void testWeek2(){
    assert(isValidAmount(10));
    assert(isValidAmount(0));
    assert(!isValidAmount(-2));
    assert(isValidMenuChoice(3));
    assert(!isValidMenuChoice(8));
}

void testWeek3(){
    Expense items[2] = {
        {"A1","Food",5},
        {"B2","Gas",10}
    };

    double answer = calculateTotal(items,2);
    assert(closeEnough(answer,15));
}

void testWeek4(){
    Expense items[3] = {
        {"A","Food",30},
        {"B","Gas",10},
        {"C","School",20}
    };

    assert(findExpenseById(items,3,"B") == 1);
    assert(findExpenseById(items,3,"Z") == -1);

    sortExpensesByAmount(items,3);

    assert(items[0].amount == 10);
    assert(items[1].amount == 20);
    assert(items[2].amount == 30);
}

void testWeek5(){
    Expense item;
    item.id = "E100";
    item.category = "Food";
    item.amount = 12.50;

    assert(item.id == "E100");
    assert(item.category == "Food");
    assert(item.amount == 12.50);
}

void testWeek6(){
    ExpenseNode* head = nullptr;

    Expense a = {"A","Food",10};
    Expense b = {"B","Gas",20};

    insertExpense(head,a);
    insertExpense(head,b);

    assert(countExpenses(head) == 2);
    assert(findExpenseNode(head,"A") != nullptr);

    removeExpense(head,"A");
    assert(countExpenses(head) == 1);

    clearExpenses(head);
    assert(head == nullptr);
}

void testWeek7(){
    ofstream file("tests/resources/test_expenses.txt");
    file << "T1 Food 10.00" << endl;
    file << "T2 Gas 25.00" << endl;
    file.close();

    ExpenseNode* head = nullptr;
    int count = loadExpensesFromFile("tests/resources/test_expenses.txt",head);

    assert(count == 2);
    assert(findExpenseNode(head,"T1") != nullptr);
    assert(findExpenseNode(head,"T2") != nullptr);

    clearExpenses(head);
}

int main(){
    testWeek1();
    testWeek2();
    testWeek3();
    testWeek4();
    testWeek5();
    testWeek6();
    testWeek7();

    cout << "All Expense Tracker tests passed!" << endl;
    return 0;
}