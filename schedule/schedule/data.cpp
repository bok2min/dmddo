#include "data.h"

void cdata::cdata_set() {
    cout << "수업명을 입력해주세요: ";
    cin >> sub;

    cout << "한 주 수업의 일 수를 입력해주세요: ";
    cin >> dc;

    for (int i = 0; i < dc; ++i) {
        cout << i + 1 << "번째 수업의 요일과 시작, 종료 시간을 입력해주세요: ";
        cin >> day >> start >> end;
        if (day == "월요일") sd[0].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "화요일") sd[1].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "수요일") sd[2].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "목요일") sd[3].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "금요일") sd[4].push_back(make_pair(sub, make_pair(start, end)));
    }
}

/*
void cdata::cdata_edit(){
    cout << "수정하고 싶은 과목명을 입력해주세요: ";
    cin >> sub;

    for(int i=0;i<sd.size();++i){
        if(sd[i].first==sub){
            sd.erase(sd.begin()+i);
        }
    }
    cout << "수정하고 싶은 요일과 시작, 종료 시간을 입력해주세요: ";
    cin>> day>>start>>end;
}
 */

void cdata::cdata_store() {
    ofstream out("load.txt");
    string a, b, c, d;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < sd[i].size(); ++j) {
            if (i == 0) a = "월요일"; // day
            else if (i == 1) a = "화요일";
            else if (i == 2) a = "수요일";
            else if (i == 3) a = "목요일";
            else if (i == 4) a = "금요일";
            b = sd[i][j].first; // sub
            c = to_string(sd[i][j].second.first); // start time
            d = to_string(sd[i][j].second.second); // end time
            out << a << " " << b << " " << c << " " << d << endl;
        }
    }
}