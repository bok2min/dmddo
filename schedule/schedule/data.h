#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ostream>
using namespace std;

class cdata {
public:
    string sub, day;
    vector<pair<string, pair<int, int>>> sd[7]; //요일, 시작 시간, 종료 시간
    int dc;
    int start, end;

    void cdata_set();
    //void cdata_edit();
    void cdata_store();
};