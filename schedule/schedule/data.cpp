#include "data.h"

void cdata::cdata_set() {
    cout << "�������� �Է����ּ���: ";
    cin >> sub;

    cout << "�� �� ������ �� ���� �Է����ּ���: ";
    cin >> dc;

    for (int i = 0; i < dc; ++i) {
        cout << i + 1 << "��° ������ ���ϰ� ����, ���� �ð��� �Է����ּ���: ";
        cin >> day >> start >> end;
        if (day == "������") sd[0].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "ȭ����") sd[1].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "������") sd[2].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "�����") sd[3].push_back(make_pair(sub, make_pair(start, end)));
        else if (day == "�ݿ���") sd[4].push_back(make_pair(sub, make_pair(start, end)));
    }
}

/*
void cdata::cdata_edit(){
    cout << "�����ϰ� ���� ������� �Է����ּ���: ";
    cin >> sub;

    for(int i=0;i<sd.size();++i){
        if(sd[i].first==sub){
            sd.erase(sd.begin()+i);
        }
    }
    cout << "�����ϰ� ���� ���ϰ� ����, ���� �ð��� �Է����ּ���: ";
    cin>> day>>start>>end;
}
 */

void cdata::cdata_store() {
    ofstream out("load.txt");
    string a, b, c, d;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < sd[i].size(); ++j) {
            if (i == 0) a = "������"; // day
            else if (i == 1) a = "ȭ����";
            else if (i == 2) a = "������";
            else if (i == 3) a = "�����";
            else if (i == 4) a = "�ݿ���";
            b = sd[i][j].first; // sub
            c = to_string(sd[i][j].second.first); // start time
            d = to_string(sd[i][j].second.second); // end time
            out << a << " " << b << " " << c << " " << d << endl;
        }
    }
}