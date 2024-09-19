#pragma once
#include<string>
#include<iostream>
#include "Emplyee.h"
using namespace std;
class Department {
	string TenPhong;
	string MaPhong;
	vector<Employee> DanhSachNhanVien;
	Employee TruongPhong;
	double TongNganSachPhong;
public:

	// Chọn ra trưởng phòng
	Employee SelectCaptian(const Employee& a) {
		return TruongPhong = a;
	}

	//Constructor
	Department() { }
	Department(string Name, string Ma, vector<Employee> NhanSu, double Tien, Employee Captian): TenPhong(Name), MaPhong(Ma), DanhSachNhanVien(NhanSu), TongNganSachPhong(Tien),TruongPhong(Captian) { }
	
	// Các hàm lấy thông tin
	string GetTenPhong()const { return TenPhong; }
	string GetMaPhong()const { return MaPhong; }
	int GetDanhSachNhanVien()const { return DanhSachNhanVien.size(); }


	//Lấy thông tin của 1 nhân viên trong danh sách
	void GetThongTin(vector<Employee> &a, string ma)const {
		for (int i = 0; i < a.size(); i++) {
			if (ma == a[i].GetMaNhanVien()) cout << a[i];
			else  cout << "Khong tim thay nhan vien nay !";
		}
		
	}
	double GetNganSachPhong()const { return TongNganSachPhong; }
	Employee GetTruongPhong() { return TruongPhong; }


	// Các toán tử nhập xuất dữ liệu
	friend ostream& operator<<(ostream& o, const Department& a) {
		return o << "Phong: " << a.TenPhong << endl
			<< "Ma: " << a.MaPhong << endl
			<< "Truong Phong: " << a.TruongPhong << endl
			<< "Tong Ngan Sach: " << a.TongNganSachPhong << endl;
	}
	friend istream& operator>>(istream& in, Department& a) {
		in >> a.TenPhong >> a.MaPhong >> a.TruongPhong >> a.TongNganSachPhong;
		int n;
		in >> n;
		a.DanhSachNhanVien.resize(n);
		for (int i = 0; i < n; i++) {
			in >> a.DanhSachNhanVien[i];
		}
		return in;
	}

	// Các hàm set thông tin cho attribute
	void SetTenPhong() { getline(cin, TenPhong); }
	void SetMaPhong() { getline(cin, MaPhong); }
	void SetDanhSachNhanVien(int n) {
		DanhSachNhanVien.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> DanhSachNhanVien[i];
		}
	}
	void SetSoLuongNhanVien(int n) { DanhSachNhanVien.resize(n); }
	void SetNganSachPhong() { cin >> TongNganSachPhong; }
	void SetTruongPhong() { cin >> TruongPhong; }

	// thêm 1 nhân viên
	void AddEmployee(const Employee &a) {
		DanhSachNhanVien.push_back(a);
	}

	// In thông tin của tất các nhân viên trong phòng + Trưởng Phòng
	void PrintAll() {
		cin >> TruongPhong;
		for (auto A : DanhSachNhanVien) {
			cout << A;
		}
	 }
	
	// Xóa 1 nhân viên
	void RemoveEmployee(const Employee &a) {
		auto it = find(DanhSachNhanVien.begin(), DanhSachNhanVien.end(), a);
		if (it != DanhSachNhanVien.end()) DanhSachNhanVien.erase(it);
	}
	// Hàm tính tổng sô nhân viên trong phòng ban
	int SumEmployeeOfDepartment() {
		return DanhSachNhanVien.size() + 1;
	}

	// Tính tổng tiền cần trả cho nhân viên + Trưởng phòng

	// Ngân sách còn lại sau khi trả lương
};