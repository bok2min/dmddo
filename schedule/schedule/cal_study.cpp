#include "study.h"


study::study()
{
	point = new vector<int>[184];
	for (int i = 0; i < 62; i++)
	{
		for (int j = 0; j < 184; j++)
		{
			point[i].push_back(0);
		}
	}
	day = vector<int>(31, 0);
}

void study::set_study()
{
	ifstream lhg;
	int num;
	lhg.open("cal_study.txt");
	for (int i = 0; i < 62; i++)
	{
		for (int j = 0; j < 184; j++)
		{
			lhg >> num;
			point[i][j] = num;
		}
	}
}

void study::print_study()
{
	for (int i = 0; i < 62; i++)
	{
		for (int j = 0; j < 184; j++)
		{
			if (point[i][j] == 21) cout << "¦£";
			else if (point[i][j] == 22) cout << "¦¤";
			else if (point[i][j] == 23) cout << "¦¦";
			else if (point[i][j] == 24) cout << "¦¥";
			else if (point[i][j] == 25) cout << "¦¨";
			else if (point[i][j] == 26) cout << "¦§";
			else if (point[i][j] == 27) cout << "¦©";
			else if (point[i][j] == 28) cout << "¦ª";
			else if (point[i][j] == 29) cout << "¦«";
			else if (point[i][j] == 30) cout << "¦¡";
			else if (point[i][j] == 31) cout << "¦¢";

			else if (point[i][j] == 50) cout << "9";
			else if (point[i][j] == 51) cout << "7";
			else if (point[i][j] == 52) cout << "8";
			else if (point[i][j] == 53) cout << "0";
			else if (point[i][j] == 54) cout << "1";
			else if (point[i][j] == 55) cout << "2";
			else if (point[i][j] == 56) cout << "3";
			else if (point[i][j] == 57) cout << "4";
			else if (point[i][j] == 58) cout << "5";
			else if (point[i][j] == 59) cout << "6";

			else cout << " ";
		}
		cout << endl;
	}
}
