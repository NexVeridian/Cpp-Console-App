using namespace std;

#include "helper.h"

void userInput(string &var, string prompt)
{
    // prompt user for string input, with error check for no input

    var = "";
    while (true)
    {
        if (prompt != "NULL")
            cout << prompt << endl;

        cin.clear();
        cin.sync();
        getline(cin, var);

        // check for no input
        if (var.empty() || var.find_first_not_of(" "))
        {
            cout << "Enter valid input: " << endl;
            cout << endl;
        }
        else
            break;
    }
}

void userInputInt(int &var, string prompt)
{
    // prompt user for int input, with error check for no input
    while (true)
    {
        if (prompt != "NULL")
            cout << prompt << endl;

        cin.clear();
        cin.sync();

        // error check for no input, or non-int input
        if (!(cin >> var))
        {
            cin.clear();
            cin.ignore();
            cout << "Enter valid input: ";
            cout << endl;
        }
        else
            break;
    }
}

void userInputIntVector2(int &var, vector<tuple<string, string>> list, string prompt)
{
    while (true)
    {
        if (prompt != "NULL")
            cout << prompt << endl;

        // print list of items with index
        int index = 0;
        for (auto &i : list)
        {
            cout << "[" << index++ << "] - ";
            cout << get<0>(i) << ", " << get<1>(i) << endl;
        }

        cin.clear();
        cin.sync();

        // error check for no input, or non-int input, or input not in list
        if (!(cin >> var) || var < 0 || var >= list.size())
        {
            cin.clear();
            cin.ignore();
            cout << "Enter valid input: ";
            cout << endl;
        }
        else
            break;
    }
}

void userInputIntVector4(int &var, vector<tuple<string, string, int, string>> list, string prompt)
{
    while (true)
    {
        if (prompt != "NULL")
            cout << prompt << endl;

        // print list of items with index
        int index = 0;
        for (auto &i : list)
        {
            cout << "[" << index++ << "] - ";
            cout << get<0>(i) << ", " << get<1>(i) << ", "
                 << get<2>(i) << ", " << get<3>(i) << endl;
        }
        cin.clear();
        cin.sync();

        // error check for no input, or non-int input, or input not in list
        if (!(cin >> var) || var < 0 || var >= list.size())
        {
            cin.clear();
            cin.ignore();
            cout << "Enter valid input: ";
            cout << endl;
        }
        else
            break;
    }
}
