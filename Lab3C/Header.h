#pragma once
#include "Trains.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>

using namespace std;

void createSchedule(vector<Train>& schedule, string cities[], int size);
void showSchedule(vector<Train> schedule);
void sortSchedule(vector<Train>& schedule);
int findLatest(vector<Train> schedule, string destination, string& timeLatest);