#include "cal.h"


cal::cal()
{
	point = new vector<int>[184];
	for (int i = 0; i < 67; i++)
	{
		for (int j = 0; j < 184; j++)
		{
			point[i].push_back(0);
		}
	}
	day = vector<int>(31, 0);
}

void cal::set_cal()
{
	ifstream lhg;
	int num;
	lhg.open("cal_set.txt");
	for (int i = 0; i < 67; i++)
	{
		for (int j = 0; j < 184; j++)
		{
			lhg >> num;
			point[i][j] = num;
		}
	}
}

void cal::print_cal()
{
	for (int i = 0; i < 67; i++)
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

			else cout << " ";
		}
		cout << endl;
	}
}
