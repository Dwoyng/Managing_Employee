#pragma once
#include<string>
#include<iostream>
#include "Emplyee.h"
using namespace std;
class Department {
	string TenPhong;
	string MaPhong;
	vector<Employee> DanhSachNhanVien;
public:
	//Constructor
	Department() { }
	Department(string Name, string Ma, vector<Employee> NhanSu): TenPhong(Name), MaPhong(Ma), DanhSachNhanVien(NhanSu) { }
	
	// GET THONG TIN CUA PHONG BAN
	string GetTenPhong() { return TenPhong; }
	string GetMaPhong() { return MaPhong; }
	int GetDanhSachNhanVien() { return DanhSachNhanVien.size(); }
	Employee GetThongTin(vector<Employee> &a, string ma)const {
		for (int i = 0; i < a.size(); i++) {
			if (ma == a[i].GetMaNhanVien()) return a[i];
		}
	}
	// SET THONG TIN CHO PHONG BAN
	void SetTenPhong() { getline(cin, TenPhong); }
	void SetMaPhong() { getline(cin, MaPhong); }
	void SetDanhSachNhanVien(int n, vector<Employee> &a) {
		DanhSachNhanVien.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
	}
	void SetSoLuongNhanVien(int n) { DanhSachNhanVien.resize(n); }
};