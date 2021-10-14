#include "settime.h"


settime::settime()
{
	ms = vector<int>(ndaysum[cur_month]+1, 0);
}

void settime::gettime() {
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	tyear = t->tm_year + 1900;
	temp1 = t->tm_wday;						//요일 
	temp1--;
	temp2 = t->tm_yday;
	firstday[0] = 7 + temp1 - ((temp2 - 1) % 7);
}


void settime::set_date()
{
	if (cur_month == 9)
	{
		int val = firstday[cur_month];
		for (int i = 1; i <= 30; ++i) {
			if (val == 7) val = 0;
			ms[i] = val++;
		}
	}
}

void settime::show() {
	for (int i = 1; i <= 30; ++i) {
		cout << ms[i] << " ";
	}
}

void settime::Leapyear(int tyear)			//윤년 확인 
{
	if ((tyear % 4 == 0 && tyear % 100 != 0) || (tyear % 400 == 0))
	{
		ndaysum[1] = 29;
	}
	for (int n = 1; n < 12; n++) {
		firstday[n] = ((ndaysum[n] % 7) + firstday[0]) % 7;
	}
}

int settime::totalday(int month, int date, int firstday[11])					//요일차 ,7로 나누어서 요일 계산 
{
	daysum = ((date - 1) % 7 + firstday[date]) % 7;
		return daysum;
}