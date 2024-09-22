#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include "Date.h"
#include<fstream>
#include<ostream>
#include<istream>
#include "Department.h"
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
	vector<Date>& NhungNgayLam() { return SoNgayDiLam; }
	double GetHeSoLuong()const { return HeSoLuong; }
	int GetLuongCoBan()const { return MucLuongCoBan; }
	string GetChucVu()const { return ChucVu; }
	string GetMaNhanVien()const { return MaNhanVien; }


	// Cac ham set thong tin Nhan Vien
	void SetName(string Name) { TenNhanVien = Name; }
	void SetDiaChi(string dia_chi) { DiaChi = dia_chi; }
	void SetSDT(string sdt) { SoDienThoai = sdt; }
	void SetBirth(int d, int m, int y) {
		Birth.SetDate(d);
		Birth.SetMonth(m);
		Birth.SetYear(y);
	}
	void SetNhungNgayLam(int n) {
		SoNgayDiLam.resize(n);
		for (int i = 0; i < n; i++) {
			 cin >> SoNgayDiLam[i];
		}
	}
	void SetNgayDiLam(int n) { SoNgayDiLam.resize(n); }
	void SetHeSoLuong(double he_so) { HeSoLuong = he_so; }
	void SetLuongCoBan(int luong) { MucLuongCoBan = luong; }
	void SetChuc(string chuc) { ChucVu = chuc; }
	void SetMaNhanVien(string ma) { MaNhanVien = ma; }

	// Ghi thông tin của nhân viên vào file text
	void WriteInfToFileInf(const Employee& a) {
		int fir = a.Birth.GetDay();
		int sec = a.Birth.GetMonth();
		int thir = a.Birth.GetYear();
		char ma = a.MaNhanVien[0];   
		string u;
		if (ma == 'A') u = "Department A";
		if (ma == 'B') u = "Department B";
		if (ma == 'C') u = "Department C";
		ofstream file;
		string s = a.GetName();
		string outline = s + " inf.txt";
		file.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\"+ u +"\\" + s +"\\" + outline ,ios::app);
	
		if (file.is_open()) {  
			
			file << a.GetMaNhanVien() << endl 
				<< a.GetName() << endl
				<< a.GetChucVu() << endl
				<< fir << '/' << sec << '/' << thir << endl
				<< a.GetDiaChi() << endl
				<< a.GetHeSoLuong() << endl
				<< a.GetLuongCoBan() << endl
				<< a.GetSDT() << endl;
			file.close();
			cout << "Da ghi thong tin thanh cong !" << endl;
		}
		else
		{
			cout << "Khong the mo file !" << endl;
		}
	}
	// Đoc-xuất thông tin từ file text inf ra
	void ExportInfFromFileInf(Employee& a) {
		string u;
		char ma = a.MaNhanVien[0];
		if (ma == 'A') u = "Department A";
		if (ma == 'B') u = "Department B";
		if (ma == 'C') u = "Department C";
		string s = a.GetName();
		string outline = s + " inf.txt";
		ifstream file("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\" + u + "\\" + s + "\\" + outline);
		if (file.is_open()) {
			string name, ma_nhan_vien, chuc_vu, dia_chi, sdt;
			double he_so_luong;
			int luong_co_ban, fir, sec, thir;
			getline(file, name);     
			getline(file, ma_nhan_vien);
			getline(file, chuc_vu);
			file >> fir; file.seekg(1, 1);
			file >> sec; file.seekg(1, 1);
			file >> thir;
			file.ignore();
			getline(file, dia_chi);
			file >> he_so_luong;
			file >> luong_co_ban;
			getline(file, sdt);

			// thiet lap cac gia tri
			a.SetName(name);
			a.SetBirth(fir, sec, thir);
			a.SetDiaChi(dia_chi);
			a.SetChuc(chuc_vu);
			a.SetHeSoLuong(he_so_luong);
			a.SetLuongCoBan(luong_co_ban);
			a.SetMaNhanVien(ma_nhan_vien);
			a.SetSDT(sdt);
			cout << a;
			file.close();
		}
		else
		{
			cout << "Khong the mo file!" << endl;
		}
	}

};
