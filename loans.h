#ifndef LOANS_H
#define LOANS_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <chrono>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <sstream>

using namespace std;

#include "items.h"

class loans
{
public:
    void createloans(items item);
    void listloans();
    void deleteloans();
    void save();
    void fromFile(string fileName = "NULL");

private:
    vector<tuple<string, string, int, string>> list; // <name item, name person, ID, Time>
    void addToList(string, string);
};

#endif
