#include <iostream>
#include <string>
using namespace std;

string months[] = { "Января", "Февраля", "Марта", "Апреля", "Мая", "Июня",
				"Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря" };
class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	~Date();
	void setDate(int, int, int);
	void showDate();
	void showDate_s();
	void operator +(int);
	bool valid();
};

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::~Date()
{
	cout << "\nДестр\n";
}
void Date::operator +(int bonus)
{

}
bool Date::valid()
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
};

void Date::setDate(int d, int m, int y)
{
	if (m > 1 && m <12)
	{
		month = m;
	}
	else
	{
		cout << "Неверный ввод месяца\n";
		month = 1;
	}
	if (d > 1 && d <31)
	{
		day = d;
	}
	else
	{
		cout << "Неверный ввод дня\n";
		day = 1;
	}
	if (y > 0 && y < 2030)
	{
		year = y;
	}
	else
	{
		cout << "Неверный ввод года\n";
		year = 2020;
	}
}

void Date::showDate()
{
	cout << day << "." << month << "." << year << endl;
}

void Date::showDate_s()
{
	cout << day << " " << months[month - 1] << " " << year << endl;
}
int main()
{
	int d, m, y;
	setlocale(LC_ALL, "RU");
	Date d1;
	cout << "Введите дату: ";
	cin >> d >> m >> y;
	d1.setDate(d, m, y);
	d1.showDate();
	d1.showDate_s();
}