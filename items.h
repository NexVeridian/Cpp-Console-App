#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <chrono>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>

using namespace std;

class items
{
public:
    void createitems();
    void listitems();
    void deleteitems();
    void save();
    vector<tuple<string, string>> getList();
    void fromFile(string fileName = "NULL");

private:
    vector<tuple<string, string>> list; // <name item, description>
    void addToList(string, string);
};

#endif
