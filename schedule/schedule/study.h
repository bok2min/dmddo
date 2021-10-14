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

class study {
public:
	// val and val_repos // 
	int month;
	vector<int>* point;
	vector<int> day;

	// func //
	study();

	void set_study();
	void print_study();

};