#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <fcntl.h>
#include <stdlib.h>
#include <cwchar>

using namespace std;

class cal {
public:
	// val and val_repos // 
	int month;
	vector<int>* point;
	vector<int> day;

	// func //
	cal();

	void set_cal();
	void print_cal();

};