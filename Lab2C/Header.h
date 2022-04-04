#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>


using namespace std;
struct Client;
void AddClient();
bool CheckDoubles(Client& person);
void CheckTimeTable();
void CountFreePeriods(int &am, int &pm);