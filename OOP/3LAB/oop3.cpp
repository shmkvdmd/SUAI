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
	int maxday();
public:
	Date();
	~Date();
	void setDate(int, int, int);
	void showDate();
	void showDate_s();
	Date operator+(int);
	Date operator-(int);
	bool operator==(Date&);
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
int Date::maxday()
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return days[month - 1];
}

Date Date::operator+(int d)
{
	if (day + d > maxday()) {
		d -= maxday() - day;
		if (++month > 12) {
			month = 1;
			year++;
		}
		while (d / maxday()) {
			if (++month > 12) {
				month = 1;
				year++;
			}
			d -= maxday();
		}
		day = d;
	}
	else day += d;
	return *this;
}

Date Date::operator-(int d)
{
	if (day - d < 1) {
		d -= day;
		if (--month == 0) {
			month = 12;
			year--;
		}
		while (d / maxday()) {
			d -= maxday();
			if (--month == 0) {
				month = 12;
				year--;
			}
		}
		day = maxday() - d;
	}
	else day -= d;
	return *this;
}

bool Date::operator==(Date& dt)
{
	return day == dt.day && month == dt.month && year == dt.year;
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
	day = d;
	month = m;
	year = y;
}

void Date::showDate()
{
	if (valid() == 1)
	{
		cout << "\n" << day << "." << month << "." << year << endl;
	}
	else cout << "Неверный ввод\n";
}

void Date::showDate_s()
{
	if (valid() == 1)
	{
		cout << day << " " << months[month - 1] << " " << year << endl;
	}
	else cout << "Неверный ввод\n";
}
int main()
{
	int d, m, y, increase, decrease;
	setlocale(LC_ALL, "RU");
	Date d1, d2;
	cout << "Введите дату: ";
	cin >> d >> m >> y;
	d1.setDate(d, m, y);
	d1.showDate();
	d1.showDate_s();
	cout << "Сколько дней прибавить: ";
	cin >> increase;
	d1 + increase;
	d1.showDate();
	d1.showDate_s();
	cout << "Сколько дней убавить: ";
	cin >> decrease;
	d1 - decrease;
	d1.showDate();
	d1.showDate_s();
	cout << "Введите дату: ";
	cin >> d >> m >> y;
	d2.setDate(d, m, y);
	d2.showDate();
	d2.showDate_s();
	cout << "Сколько дней прибавить: ";
	cin >> increase;
	d2 + increase;
	d2.showDate();
	d2.showDate_s();
	cout << "Сколько дней убавить: ";
	cin >> decrease;
	d2 - decrease;
	d2.showDate();
	d2.showDate_s();
	if (d1 == d2)
	{
		cout << "Даты равны\n";
	}
	else cout << "Даты не равны\n";
}