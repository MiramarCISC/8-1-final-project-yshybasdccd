#include "project.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ExpenseNode* head = nullptr;

    int loaded = loadExpensesFromFile("data/expenses.txt",head);
    cout << "Loaded " << loaded << " expense(s)." << endl;

    int choice = -1;

    while(choice != 0){
        printMenu();
        cin >> choice;

        if(!isValidMenuChoice(choice)){
            cout << "Invalid menu choice." << endl;
            continue;
        }

        if(choice == 1){
            cout << endl << "Expenses:" << endl;
            printExpenses(head);
        }

        else if(choice == 2){
            Expense expense;

            cout << "Enter expense ID: ";
            cin >> expense.id;

            cout << "Enter category: ";
            cin >> expense.category;

            cout << "Enter amount: ";
            cin >> expense.amount;

            if(isValidAmount(expense.amount)){
                insertExpense(head,expense);
                cout << "Expense added." << endl;
            }
            else
                cout << "Invalid amount." << endl;
        }

        else if(choice == 3){
            string id;
            cout << "Enter expense ID: ";
            cin >> id;

            ExpenseNode* found = findExpenseNode(head,id);

            if(found != nullptr){
                cout << "Found: ";
                printExpense(found->data);
            }
            else{
                cout << "Expense not found." << endl;
            }
        }

        else if(choice == 4){
            Expense list[MAX_EXPENSES];
            int count = copyToArray(head,list,MAX_EXPENSES);

            sortExpensesByAmount(list,count);

            cout << "Expenses sorted by amount:" << endl;
            for(int i = 0; i < count; i++)
                printExpense(list[i]);
        }

        else if(choice == 5){
            Expense expenses[MAX_EXPENSES];
            int count = copyToArray(head,expenses,MAX_EXPENSES);
            double total = calculateTotal(expenses,count);

            cout << fixed << setprecision(2);
            cout << "Total expenses: $" << total << endl;
        }

        else if(choice == 6){
            string id;

            cout << "Enter expense ID to remove: ";
            cin >> id;

            bool removed = removeExpense(head,id);

            if(removed == true)
                cout << "Expense removed." << endl;
            else
                cout << "Expense not found." << endl;
        }

        else if(choice == 0){
            cout << "Goodbye!" << endl;
        }
    }

    clearExpenses(head);
    return 0;
}