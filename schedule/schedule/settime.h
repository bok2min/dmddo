#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma once


class settime {
public:
	int ndate[12];
	int firstday[12];	//1~12월 1일의 요일 
	int tyear;				//올해년도 
	int temp1;
	int temp2;
	int daysum;
	int ndaysum[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };		//각 달의 일 수 
	int cur_month = 9;
	vector<int> ms;

	settime();
	void gettime();
	void Leapyear(int tyear);
	int totalday(int month, int date, int firstday[11]);
	void set_date();
	void show();
};

class timenow : public settime {
public:
	int year = tyear;
	int month;
	int day;
	int date;

};
