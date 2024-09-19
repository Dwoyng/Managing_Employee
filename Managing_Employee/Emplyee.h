#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include "Date.h"

using namespace std;

class Employee {
	string TenNhanVien;
	string MaNhanVien;
	string ChucVu;
	string DiaChi;
	string SoDienThoai;
	Date Birth;
	vector<Date> SoNgayDiLam;
	double HeSoLuong;
	int MucLuongCoBan;
public:

	//Constuctor
	Employee() { }
	Employee(string Name, string Address, string Phone, Date birth, vector<Date>so_ngay, double he_so, int LuongCoBan, string Chuc, string ma) : TenNhanVien(Name), DiaChi(Address), SoDienThoai(Phone), Birth(birth), SoNgayDiLam(so_ngay), HeSoLuong(he_so), MucLuongCoBan(LuongCoBan), ChucVu(Chuc), MaNhanVien(ma) { }
	
	// Hàm tính lương
	double TinhLuong()const {
		return MucLuongCoBan * HeSoLuong;
	}

	// Toán tử nhập xuất dữ liệu
	friend ostream& operator<<(ostream& o, const Employee& a) {
		return o << "Ho va Ten: " << a.TenNhanVien << endl
			<< "Ma Nhan Vien: " << a.MaNhanVien << endl
			<< "Chuc Vu: " << a.ChucVu << endl
			<< "Dia Chi: " << a.DiaChi << endl
			<< "So Dien Thoai: " << a.SoDienThoai << endl
			<< "Ngay Sinh: " << a.Birth << endl
			<< "So Ngay Di Lam: " << a.SoNgayDiLam.size() << endl
			<< "He So Luong: " << a.HeSoLuong << endl
			<< "Muc Luong Co Ban: " << a.MucLuongCoBan << endl;
	}
	friend istream& operator>>(istream& in, Employee& a) {
		in >> a.TenNhanVien >> a.Birth >> a.ChucVu >> a.DiaChi >> a.HeSoLuong >> a.MaNhanVien >> a.MucLuongCoBan >> a.SoDienThoai;
		int so_ngay;
		in >> so_ngay;
		a.SoNgayDiLam.resize(so_ngay);
		for (int i = 0; i < so_ngay; i++) {
			in >> a.SoNgayDiLam[i];
		}
		return in;
	}

	//Toán tử gán
	Employee& operator=(const Employee& a) {

		TenNhanVien = a.TenNhanVien;
		DiaChi = a.DiaChi;
		SoDienThoai = a.SoDienThoai;
		SoNgayDiLam = a.SoNgayDiLam;
		MaNhanVien = a.MaNhanVien;
		ChucVu = a.ChucVu;
		Birth = a.Birth;
		MucLuongCoBan = a.MucLuongCoBan;
		HeSoLuong = a.HeSoLuong;

		return *this;
	}


	// Toán tử so sánh bằng mã nhân viên
	bool operator==(const Employee& other) const {
		return MaNhanVien == other.MaNhanVien;  
	}


	//Các hàm lấy thông tin nhân viên
	string GetName()const { return TenNhanVien; }
	string GetDiaChi()const { return DiaChi; }
	string GetSDT()const { return SoDienThoai; }
	Date GetBirth() { return Birth; }
	int GetSoNgayDiLam()const { return SoNgayDiLam.size(); }
	double GetHeSoLuong()const { return HeSoLuong; }
	int GetLuongCoBan()const { return MucLuongCoBan; }
	string GetChucVu()const { return ChucVu; }
	string GetMaNhanVien()const { return MaNhanVien; }


	// Cac ham set thong tin Nhan Vien
	void SetName() { getline(cin, TenNhanVien); }
	void SetDiaChi() { getline(cin, DiaChi); }
	void SetSDT() { getline(cin, SoDienThoai); }
	void SetBirth() { cin >> Birth; }
	void SetNgayDiLam(int n) {
		SoNgayDiLam.resize(n);
		for (int i = 0; i < n; i++) {
			 cin >> SoNgayDiLam[i];
		}
	}
	void SetHeSoLuong() { cin >> HeSoLuong; }
	void SetLuongCoBan() { cin >> MucLuongCoBan; }
	void SetChuc() { getline(cin, ChucVu); }
	void SetMaNhanVien() { getline(cin, MaNhanVien); }
};
