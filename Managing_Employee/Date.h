#pragma once
#include<iostream>

using namespace std;
class Date {
	int day, month, year;
public:
	// Cac ham lay thong tin
	int GetDay()const { return day; }
	int GetMonth()const { return month; }
	int GetYear()const { return year; }

	// Cac ham set thong tin cho Date
	void SetDate() { cin >> day; }
	void SetMonth() { cin >> month; }
	void SetYear() { cin >> year; }

	// ham gioi han 1 tham so nao day trong khoang nhat dinh
	int Limit(int v, int max, int min) {
		if (v < min) return min;
		return v < max ? max : v;
	}

	// ham lay ra so ngay trong thang
	int DayOfMonth(int a) {
		switch (a) {
		case 2: return year & 3 ? 28 : 29;
		case 4: case 9: case 11: case 6: return 30;
		default: return 31;
		}
	}
	// Constructor
	Date() { }
	Date(int d, int m, int y) {
		day = Limit(d, DayOfMonth(m), 1);
		month = Limit(m, 12, 1);
		year = y;
	}
	Date(Date& a) {
		this->day = a.day;
		this->month = a.month;
		this->year = a.year;
	}
	friend ostream& operator<<(ostream& o, const Date& a) {
		return o << a.day << '/' << a.month << '/' << a.year;
	}
	friend istream& operator>>(istream& i, Date& a) {
		return i >> a.day >> a.month >> a.year;
	}
};

