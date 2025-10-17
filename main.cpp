#include "stdafx.h"
#include "DinamicArray.h"
#include "LinkedList.h"
#include "Stack.h"
#include "SortingStation.h"
using namespace std;

void MainMenu(){
    cout << "\n=== Data Structures Testing Application ===" << endl;
    cout << "1. Linked List" << endl;
    cout << "2. Dinamic Array" << endl;
    cout << "3. Stack" << endl;
    cout << "4. Sorting Station Algorithm" << endl;
    cout << "0. Exit" << endl;
    cout << "Select option: ";
}

void LinkedListMenu() {
    cout << "\n=== Linked List ===" << endl;
    LinkedList<int> list;

    int choice, index;
    int value;

    do {
        system("cls");
        cout << "\n--- Current List ---" << endl;
        list.print();
        cout << "Size: " << list.get_size() << endl;

        cout << "\n Linked List Operations:" << endl;
        cout << "1. Push Front" << endl;
        cout << "2. Push Back" << endl;
        cout << "3. Push at Index" << endl;
        cout << "4. Pop Front" << endl;
        cout << "5. Pop Back" << endl;
        cout << "6. Pop at Index" << endl;
        cout << "7. Get Element at Index" << endl;
        cout << "8. Clear List" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Select operation: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter value to push front: ";
                cin >> value;
                list.push_front(value);
                cout << "Added '" << value << "' to front." << endl;
                getch();
                break;

            case 2:
                cout << "Enter value to push back: ";
                cin >> value;
                list.push_back(value);
                cout << "Added '" << value << "' to back." << endl;
                getch();
                break;

            case 3:
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter value: ";
                cin >> value;
                list.insert(index, value);
                cout << "Added '" << value << "' at index " << index << endl;
                getch();
                break;

            case 4:
                list.pop_front();
                cout << "Removed front element." << endl;
                getch();
                break;

            case 5:
                list.pop_back();
                cout << "Removed back element." << endl;
                getch();
                break;

            case 6:
                cout << "Enter index to pop: ";
                cin >> index;
                list.erase(index);
                cout << "Removed element at index " << index << endl;
                getch();
                break;

            case 7:
                cout << "Enter index to get: ";
                cin >> index;
                cout << "Element at index " << index << ": " << list[index] << endl;
                getch();
                break;

            case 8:
                list.clear();
                cout << "List cleared." << endl;
                getch();
                break;

            case 0:
                cout << "Returning to main menu..." << endl;
                getch();
                break;

            default:
                cout << "Invalid option!" << endl;
                getch();
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            getch();
        }

    } while (choice != 0);

}

void StackMenu() {
    cout << "\n===  Stack ===" << endl;
    Stack<double> stack;

    int choice;
    double value;

    do {
        system("cls");
        cout << "\n--- Current Stack ---" << endl;
        cout << "Size: " << stack.size() << endl;
        if (!stack.empty()) {
            cout << "Top element: " << stack.top() << endl;
        }
        else {
            cout << "Stack is empty" << endl;
        }

        cout << "\nStack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Clear" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Select operation: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                cout << "Pushed " << value << " to stack." << endl;
                getch();
                break;

            case 2:
                if (!stack.empty()) {
                    stack.pop();
                    cout << "Popped from stack." << endl;
                }
                else {
                    cout << "Stack is empty!" << endl;
                }
                getch();
                break;

            case 3:
                if (!stack.empty()) {
                    cout << "Top element: " << stack.top() << endl;
                }
                else {
                    cout << "Stack is empty!" << endl;
                }
                getch();
                break;

            case 4:
                stack.clear();
                cout << "Stack cleared." << endl;
                getch();
                break;

            case 0:
                cout << "Returning to main menu..." << endl;
                getch();
                break;

            default:
                cout << "Invalid option!" << endl;
                getch();
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            getch();
        }

    } while (choice != 0);
}

void DinamicArrayMenu() {
    cout << "\n=== Linked List ===" << endl;
    DynamicArray<int> list;

    int choice, index;
    int value;

    do {
        system("cls");
        cout << "\n--- Current Array ---" << endl;
        list.print();
        cout << "Size: " << list.get_size() << endl;
        cout << "Capacity: " << list.get_capacity() << endl;

        cout << "\nDinamic Array Operations:" << endl;
        cout << "1. Push Front" << endl;
        cout << "2. Push Back" << endl;
        cout << "3. Push at Index" << endl;
        cout << "4. Pop Front" << endl;
        cout << "5. Pop Back" << endl;
        cout << "6. Pop at Index" << endl;
        cout << "7. Get Element at Index" << endl;
        cout << "8. Clear List" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Select operation: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                cout << "Enter value to push front: ";
                cin >> value;
                list.push_front(value);
                cout << "Added '" << value << "' to front." << endl;
                getch();
                break;

            case 2:
                cout << "Enter value to push back: ";
                cin >> value;
                list.push_back(value);
                cout << "Added '" << value << "' to back." << endl;
                getch();
                break;

            case 3:
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter value: ";
                cin >> value;
                list.insert(index, value);
                cout << "Added '" << value << "' at index " << index << endl;
                getch();
                break;

            case 4:
                list.pop_front();
                cout << "Removed front element." << endl;
                getch();
                break;

            case 5:
                list.pop_back();
                cout << "Removed back element." << endl;
                getch();
                break;

            case 6:
                cout << "Enter index to pop: ";
                cin >> index;
                list.erase(index);
                cout << "Removed element at index " << index << endl;
                getch();
                break;

            case 7:
                cout << "Enter index to get: ";
                cin >> index;
                cout << "Element at index " << index << ": " << list[index] << endl;
                getch();
                break;

            case 8:
                list.clear();
                cout << "List cleared." << endl;
                getch();
                break;

            case 0:
                cout << "Returning to main menu..." << endl;
                getch();
                break;
                
            default:
                cout << "Invalid option!" << endl;
                getch();
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            getch();
        }

    } while (choice != 0);

}

void SortingStationMenu() {
    cout << "\n=== Testing Shunting Yard Algorithm ===" << endl;
    SortingStation calculator;

    string expression;

    do {
        cout << "\nEnter mathematical expression (or 'back' to return): ";
        cin.ignore();
        getline(cin, expression);

        if (expression == "back" || expression == "0") {
            break;
        }

        if (expression.empty()) {
            continue;
        }

        try {
            double result = calculator.evaluateInfix(expression);
            cout << "Result: " << result << endl;

            cout << "\nTry another expression? (y/n): ";
            char continueChoice;
            cin >> continueChoice;
            if (continueChoice == 'n' || continueChoice == 'N') {
                break;
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Please try again with a valid expression." << endl;
        }

    } while (true);
}


int main() {
    cout << "=== Data Structures ===" << endl;

    int mainChoice;

    do {
        MainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            LinkedListMenu();
            break;

        case 2:
            DinamicArrayMenu();
            break;

        case 3:
            StackMenu();
            break;

        case 4:
            SortingStationMenu();
            break;

        case 0:
            cout << "Thank you for using the application! Goodbye!" << endl;
            break;

        default:
            cout << "Invalid option! Please try again." << endl;
        }

    } while (mainChoice != 0);

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;

};
