# Simple Expense Tracker

## Project Description

My final project is a simple expense tracker. The program loads expenses from a text file and stores them in a linked list.

The user can display expenses, add a new expense, search for an expense by ID, sort expenses by amount, show the total amount of expenses, and remove an expense.

## How to Compile

`make`

## How to Run

`./main`

## How to Test

`make test`

## Course Topics Integrated

### Week 1 - Program Basics
The program uses variables, data types, constants, arithmetic, input, and output. The `calculateTotal()` function adds all expense amounts together.

Code location: `src/project.cpp`

### Week 2 - Decisions and Loops
The program uses a repeating menu, if and else statements, loops, and input validation. The `isValidAmount()` and `isValidMenuChoice()` functions check user input.

Code location: `src/main.cpp` and `src/project.cpp`

### Week 3 - Functions and Program Design
The program is divided into functions with parameters and return values. Some examples are `calculateTotal()`, `findExpenseById()`, and `countExpenses()`.

Code location: `include/project.hpp` and `src/project.cpp`

### Week 4 - Arrays, Searching, and Sorting
Expenses can be copied from the linked list into an array. The program searches expenses by ID and sorts expenses by amount.

Code location: `src/project.cpp`

### Week 5 - Strings and Structures
The program uses the `Expense` structure. It stores the expense ID and category using strings and stores the amount as a double.

Code location: `include/project.hpp`

### Week 6 - Pointers, Dynamic Memory, and Linked Lists
The program stores expenses in an `ExpenseNode` linked list. New nodes are created with `new` and removed with `delete`. The `clearExpenses()` function deletes the remaining nodes before the program ends.

Code location: `src/project.cpp`

### Week 7 - File I/O and Integration
The `loadExpensesFromFile()` function uses `ifstream` to load expense records from `data/expenses.txt`. The loaded records are added to the linked list and used by the program.

Code location: `src/project.cpp`

## Unit Tests by Topic

### Week 1
`testWeek1()` tests the total expense calculation.

### Week 2
`testWeek2()` tests amount validation and menu choice validation.

### Week 3
`testWeek3()` tests a function with parameters and a return value.

### Week 4
`testWeek4()` tests searching an array by ID and sorting expenses by amount.

### Week 5
`testWeek5()` tests the `Expense` structure and its string fields.

### Week 6
`testWeek6()` tests linked list insertion, searching, removing a node, counting nodes, and cleanup.

### Week 7
`testWeek7()` creates a test file, loads expense records from it, and checks that the records were loaded correctly.

All tests are located in `tests/test_project.cpp`.

## Known Limitations

Expense categories currently need to be one word.

Expenses added while the program is running are not saved back to `expenses.txt` after the program closes.
