#include <iostream>
using namespace std;

class Time
{
private:
	int day, month, year;
public:
	Time(int,int,int);
	~Time();
	bool isValid();
	void output();
};

Time::Time(int m_day,int m_month,int m_year)
{
	this->day = m_day;
	this->month = m_month;
	this->year = m_year;
}
Time::~Time()
{}

bool Time::isValid()
{
	if (year < 0) return false;
	if (month > 12 || month < 1) return false;
	if (day > 31 || day < 1) return false;
	if ((day == 31 &&
		(month == 2 || month == 4 || month == 6 || month == 9 || month == 11)))
		return false;
	if (day == 30 && month == 2) return false;
	if (year < 2000) {
		if ((day == 29 && month == 2) && !((year - 1900) % 4 == 0)) return false;
	};
	if (year > 2000) {
		if ((day == 29 && month == 2) && !((year - 2000) % 4 == 0)) return false;
	};
	return true;
}
void Time::output()
{
	if (isValid())
	{
		cout << "Дата " << day << "/" << month << "/" << year << " возможна\n";
	}
	else
	{
		cout << "Дата " << day << "/" << month << "/" << year << " невозможна\n";
	}
}
int main()
{
	system("color F1");
	setlocale(LC_ALL, "ru");
	Time time1(10,12,2022);
	time1.output();
	Time time2(50, 50, 50);
	time2.output();
}

