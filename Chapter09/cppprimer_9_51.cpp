#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class Date {
public:
	Date(string& s);
	void print() {
		cout << _year << "." << _month << "." << _day << endl;
	}
private:
	unsigned _year = 0;
	unsigned _month = 0;
	unsigned _day = 0;
};
Date::Date(string& s) {
	string numbers("0123456789");
	int flag = 0;
	string month;
	string year;
	string day;
	unsigned pos1, pos2;
	if (s.find('/') != string::npos) {
		flag = 2;
	}
	else if (s.find(',') != string::npos) {
		flag = 1;
	}
	else {
		flag = 3;
	}
	
	switch (flag) {
	case 1:
		
		pos1 = s.find_first_not_of(numbers);
		pos2 = s.find_first_of(numbers);
		month.append(s, pos1, pos2 - 1);
		if (month == "January")  _month = 1;
		else if (month == "February") _month = 2;
		else if (month == "March") _month = 3;
		else if (month == "April") _month = 4;
		else if (month == "May") _month = 5;
		else if (month == "June") _month = 6;
		else if (month == "July") _month = 7;
		else if (month == "August") _month = 8;
		else if (month == "September") _month = 9;
		else if (month == "October") _month = 10;
		else if (month == "November") _month = 11;
		else _month = 12;
		pos1 = s.find_last_not_of(numbers);
		day.append(s, pos2, pos1-1);
		_day = stoi(day);
		pos2 = s.find_first_of(numbers, pos1 + 1);
		year.append(s, pos2);
		_year = stoi(year);
		break;
	case 2:
		pos1 = s.find_first_of(numbers);
		pos2 = s.find_first_not_of(numbers);
		month.append(s, pos1, pos2);
		_month = stoi(month);
		pos1 = s.find_first_not_of(numbers);
		pos2 = s.find_first_of(numbers, pos1 + 1);
		pos1 = s.find_first_not_of(numbers, pos2 + 1);
		day.append(s, pos2, pos1);
		_day = stoi(day);
		year.append(s, pos1 + 1);
		_year = stoi(year);
		break;
	case 3:
		pos1 = s.find_first_not_of(numbers);
		pos2 = s.find_first_of(numbers);
		month.append(s, pos1, pos2 - 1);
		if (month == "Jan")  _month = 1;
		else if (month == "Feb") _month = 2;
		else if (month == "Mar") _month = 3;
		else if (month == "Apr") _month = 4;
		else if (month == "May") _month = 5;
		else if (month == "Jun") _month = 6;
		else if (month == "Jul") _month = 7;
		else if (month == "Aug") _month = 8;
		else if (month == "Sep") _month = 9;
		else if (month == "Oct") _month = 10;
		else if (month == "Nov") _month = 11;
		else _month = 12;
		pos1 = s.find_first_of(numbers, pos2);
		pos2 = s.find_first_of(" ", pos1);
		day.append(s, pos1, pos2);
		_day = stoi(day);
		year.append(s, pos2);
		_year = stoi(year);
		break;
	}

}
int main() {
	string str1("January 20,1900");
	string str2("12/20/1990");
	string str3("Dec 30 2018");
	Date d1(str1);
	d1.print();
	Date d2(str2);
	d2.print();
	Date d3(str3);
	d3.print();
	return 0;
}