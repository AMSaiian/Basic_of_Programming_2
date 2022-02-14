#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void AddFile(string name, int &rowsorig);
void OutputRows(string name);
void CopyRows(string original, string copy, int& amount, int rowsorig);
void DeleteRows(string name, int& deleted);
void AddText(string name);