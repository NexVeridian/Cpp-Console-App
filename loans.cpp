using namespace std;

#include "loans.h"
#include "items.h"
#include "helper.h"

void loans::createloans(items item)
{
    // prompt user for info, then calls addToList

    string nameItem = "", namePerson = "";
    while (true)
    {
        userInput(nameItem, "Enter name of item: ");

        vector<tuple<string, string>> itemList = item.getList();
        // check if item exists
        bool found = false;
        if (!itemList.empty())
            for (auto &i : itemList)
                if (get<0>(i) == nameItem)
                    found = true;

        // error and ask for reentry if item doesn't exist
        if (found == false)
        {
            cout << "Item does not exist, enter valid item name" << endl;
            cout << endl;
            item.listitems();
            cout << endl;
        }
        else
            break;
    }

    userInput(namePerson, "Enter name of person: ");
    addToList(nameItem, namePerson);
}

void loans::listloans()
{
    // print list of loans

    for (auto &i : list)
    {
        cout << get<0>(i) << ", " << get<1>(i) << ", "
             << get<2>(i) << ", " << get<3>(i) << endl;
    }
}

void loans::deleteloans()
{
    // prompt user for index of loan, then delete

    int userInput = 0;
    if (list.empty())
        cout << "No loans to delete" << endl;
    else
    {
        userInputIntVector4(userInput, list, "Enter index of loan to delete: ");
        list.erase(list.begin() + userInput);
    }
}

void loans::save()
{
    // saves all loans to a file

    ofstream file;
    remove("loans.csv");
    file.open("loans.csv");
    for (auto &i : list)
    {
        file << get<0>(i) << "," << get<1>(i) << ","
             << get<2>(i) << "," << get<3>(i) << endl;
    }
    file.close();
}

void loans::fromFile(string fileName)
{
    // loads all loans from a file

    if (fileName == "NULL")
        fileName = "loans";
    ifstream file(fileName + ".csv");

    if (!file.fail())
    {
        // read file to list
        string nameItem, namePerson, time, temp;
        while (getline(file, nameItem, ','))
        {
            getline(file, namePerson, ',');
            getline(file, temp, ',');
            getline(file, time);
            list.push_back(make_tuple(nameItem, namePerson, stoi(temp), time));
        }
        file.close();
    }
    else
    {
        cout << "loans.csv not found" << endl;
        cout << endl;
    }
}

void loans::addToList(string nameItem, string namePerson)
{
    // add new loan to list

    int ID = 1000 + list.size();

    // get current time as string
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    char buf[16] = {0};
    strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&now));
    auto time = string(buf);

    list.push_back(make_tuple(nameItem, namePerson, ID, time));
}
