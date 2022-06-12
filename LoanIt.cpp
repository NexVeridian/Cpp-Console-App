#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <chrono>
using namespace std;

#include "loans.h"
#include "items.h"
#include "helper.h"

int main()
{
    int userInput = 0;
    items item;
    loans loan;

    // data load from file, if file exists
    item.fromFile();
    loan.fromFile();

    while (true)
    {
        cout << "Enter number to exacute command" << endl;
        cout << "[0] - Exit" << endl;
        cout << "[1] - Create items" << endl;
        cout << "[2] - List items" << endl;
        cout << "[3] - Delete items" << endl;
        cout << "[4] - Create loans" << endl;
        cout << "[5] - List loans" << endl;
        cout << "[6] - Delete loans" << endl;
        cout << "[7] - Save loans and Items" << endl;

        userInputInt(userInput);

        if (userInput == 0)
            break;
        else if (userInput == 1)
            item.createitems();
        else if (userInput == 2)
            item.listitems();
        else if (userInput == 3)
            item.deleteitems();
        else if (userInput == 4)
            loan.createloans(item);
        else if (userInput == 5)
            loan.listloans();
        else if (userInput == 6)
            loan.deleteloans();
        else if (userInput == 7)
        {
            item.save();
            loan.save();
        }
        else
            cout << "Invalid input" << endl;
        cout << endl;
        cout << endl;
    }
    return 0;
}
