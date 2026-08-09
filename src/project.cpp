#include "project.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool isValidAmount(double amount){
    if(amount >= 0)
        return true;
    return false;
}

bool isValidMenuChoice(int choice){
    if(choice >= 0 && choice <= 6){
        return true;
    }
    else{
        return false;
    }
}

void printMenu(){
    cout << endl;
    cout << "Simple Expense Tracker" << endl;
    cout << "1. Display expenses" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Find expense" << endl;
    cout << "4. Sort expenses by amount" << endl;
    cout << "5. Show total expenses" << endl;
    cout << "6. Remove expense" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

void printExpense(const Expense& expense){
    cout << fixed << setprecision(2);
    cout << expense.id << " | " << expense.category << " | $" << expense.amount << endl;
}

void insertExpense(ExpenseNode*& head, Expense expense){
    ExpenseNode* newNode = new ExpenseNode;
    newNode->data = expense;
    newNode->next = head;
    head = newNode;
}

void printExpenses(const ExpenseNode* head){
    if(head == nullptr){
        cout << "No expenses." << endl;
        return;
    }

    const ExpenseNode* current = head;
    while(current != nullptr){
        printExpense(current->data);
        current = current->next;
    }
}

ExpenseNode* findExpenseNode(ExpenseNode* head, string id){
    ExpenseNode* current = head;

    while(current != nullptr){
        if(current->data.id == id)
            return current;
        current = current->next;
    }
    return nullptr;
}

int countExpenses(const ExpenseNode* head){
    int count = 0;
    const ExpenseNode* current = head;

    while(current != nullptr){
        count = count + 1;
        current = current->next;
    }
    return count;
}

double calculateTotal(const Expense expenses[], int count){
    if(expenses == nullptr || count <= 0)
        return 0;

    double total = 0;
    for(int i = 0; i < count; i++){
        total += expenses[i].amount;
    }
    return total;
}

int copyToArray(const ExpenseNode* head, Expense expenses[], int maxItems){
    if(expenses == nullptr || maxItems <= 0){
        return 0;
    }

    int count = 0;
    const ExpenseNode* current = head;

    while(current != nullptr && count < maxItems){
        expenses[count] = current->data;
        count++;
        current = current->next;
    }
    return count;
}

int findExpenseById(const Expense expenses[], int count, string id){
    if(expenses == nullptr)
        return -1;

    for(int i = 0; i < count; i++){
        if(expenses[i].id == id){
            return i;
        }
    }
    return -1;
}

void sortExpensesByAmount(Expense expenses[], int count){
    if(expenses == nullptr || count <= 1)
        return;

    for(int i = 0; i < count - 1; i++){
        int smallest = i;

        for(int j = i + 1; j < count; j++){
            if(expenses[j].amount < expenses[smallest].amount)
                smallest = j;
        }

        if(smallest != i){
            Expense temp = expenses[i];
            expenses[i] = expenses[smallest];
            expenses[smallest] = temp;
        }
    }
}

bool removeExpense(ExpenseNode*& head, string id){
    if(head == nullptr)
        return false;

    if(head->data.id == id){
        ExpenseNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    ExpenseNode* current = head;
    while(current->next != nullptr){
        if(current->next->data.id == id){
            ExpenseNode* temp = current->next;
            current->next = temp->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    return false;
}

int loadExpensesFromFile(string filename, ExpenseNode*& head){
    ifstream file(filename);
    if(!file.is_open()){
        return 0;
    }

    int count = 0;
    Expense temp;

    while(file >> temp.id >> temp.category >> temp.amount){
        if(isValidAmount(temp.amount)){
            insertExpense(head,temp);
            count = count + 1;
        }
    }

    file.close();
    return count;
}

void clearExpenses(ExpenseNode*& head){
    while(head != nullptr){
        ExpenseNode* temp = head;
        head = head->next;
        delete temp;
    }

    // head should be empty after deleting everything
    head = nullptr;
}