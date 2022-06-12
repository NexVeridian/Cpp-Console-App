#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;

void userInput(string &var, string prompt = "NULL");
void userInputInt(int &var, string prompt = "NULL");
void userInputIntVector2(int &var, vector<tuple<string, string>> list, string prompt = "NULL");
void userInputIntVector4(int &var, vector<tuple<string, string, int, string>> list, string prompt = "NULL");

#endif
