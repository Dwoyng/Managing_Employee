#pragma once
#include<iostream>
#include<string>
#include <iomanip>  // For setw and setfill
#include <sstream>  // For ostringstream
#include <cstdio>   // For sscanf


using namespace std;
class Date {
	int day, month, year;
public:
	// Cac ham lay thong tin
	int GetDay()const { return day; }
	int GetMonth()const { return month; }
	int GetYear()const { return year; }

	// Cac ham set thong tin cho Date
	void SetDate(int d) { day = d; }
	void SetMonth(int m) { month = m; }
	void SetYear(int y) { year = y; }

	// ham gioi han 1 tham so nao day trong khoang nhat dinh
	int Limit(int v, int max, int min) {
		if (v < min) return min;
		return v < max ? max : v;
	}

	// ham lay ra so ngay trong thang
	int DayOfMonth(int a)const {
		switch (a) {
		case 2: return year & 3 ? 28 : 29;
		case 4: case 9: case 11: case 6: return 30;
		default: return 31;
		}
	}
	// Constructor
	Date() { day = month = year = 0; }
	Date(int d, int m, int y) {
		day = Limit(d, DayOfMonth(m), 1);
		month = Limit(m, 12, 1);
		year = y;
	}
	Date(Date& a):day(a.day), month(a.month), year(a.year) { }


	friend ostream& operator<<(ostream& o, const Date& a) {
		return o << a.day << '/' << a.month << '/' << a.year;
	}
	friend istream& operator>>(istream& i, Date& a) {
		return i >> a.day >> a.month >> a.year;
	}
	
	// Toán tử so sánh
	bool operator==(const Date& another) {
		if (day == another.day && month == another.month && year == another.year) return true;
		return false;
	}
};

