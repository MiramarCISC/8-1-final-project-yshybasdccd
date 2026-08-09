#ifndef PROJECT_HPP
#define PROJECT_HPP
#include <string>

const int MAX_EXPENSES = 100;

struct Expense {
    std::string id;
    std::string category;
    double amount;
};

struct ExpenseNode {
    Expense data;
    ExpenseNode* next;
};

bool isValidAmount(double amount);
bool isValidMenuChoice(int choice);
void printMenu();
void printExpense(const Expense& expense);
void printExpenses(const ExpenseNode* head);

void insertExpense(ExpenseNode*& head, Expense expense);
ExpenseNode* findExpenseNode(ExpenseNode* head, std::string id);
int countExpenses(const ExpenseNode* head);
bool removeExpense(ExpenseNode*& head, std::string id);
void clearExpenses(ExpenseNode*& head);

int copyToArray(const ExpenseNode* head, Expense expenses[], int maxItems);
double calculateTotal(const Expense expenses[], int count);
int findExpenseById(const Expense expenses[], int count, std::string id);
void sortExpensesByAmount(Expense expenses[], int count);

int loadExpensesFromFile(std::string filename, ExpenseNode*& head);

#endif