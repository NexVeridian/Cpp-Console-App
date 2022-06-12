using namespace std;

#include "items.h"
#include "helper.h"

void items::createitems()
{
    // prompt user for info, then calls addToList

    string name = "", description = "";

    userInput(name, "Enter name of item: ");
    userInput(description, "Enter description of item: ");
    addToList(name, description);
}

void items::listitems()
{
    // print list of items

    for (auto &i : list)
    {
        cout << get<0>(i) << ", " << get<1>(i);
    }
}

void items::deleteitems()
{
    // prompt user for index of loan then delete

    int userInput = 0;
    if (list.empty())
        cout << "No loans to delete" << endl;
    else
    {
        userInputIntVector2(userInput, list, "Enter index of item to delete: ");
        list.erase(list.begin() + userInput);
    }
}

void items::save()
{
    // saves all items to a file

    ofstream file;
    remove("items.csv");
    file.open("items.csv");
    for (auto &i : list)
    {
        file << get<0>(i) << "," << get<1>(i) << endl;
    }
    file.close();
}

void items::fromFile(string fileName)
{
    // loads all items from a file

    if (fileName == "NULL")
        fileName = "items";
    ifstream file(fileName + ".csv");

    if (!file.fail())
    {
        // read file to list
        string nameItem, description;
        while (getline(file, nameItem, ',') >> description)
        {
            addToList(nameItem, description);
        }
        file.close();
    }
    else
    {
        cout << "items.csv not found" << endl;
    }
}

void items::addToList(string nameItem, string description)
{
    // add new item to list

    list.push_back(make_tuple(nameItem, description));
}

vector<tuple<string, string>> items::getList()
{
    return list;
}
