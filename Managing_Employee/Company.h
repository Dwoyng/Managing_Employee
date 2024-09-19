#pragma once
#include<iostream>
#include<string>
#include "Department.h"

using namespace std;
class Company {
	string NameOfCom;
	vector<Department> CacPhongBan;
	double TongNganSachCongTy;
public:
	// Ngan sach can de tra luong cho nha vien

	// Ngan sach con lai sau khi tra luong cho nhan vien

	// Constructor
	Company() { }
	Company(string Name, vector<Department> PhongBan, double NganSach): NameOfCom(Name), CacPhongBan(PhongBan), TongNganSachCongTy(NganSach) { }

	// Các hàm lấy ra thông tin của công ty
	string GetNameCongTy()const { return NameOfCom; }
	vector<Department> GetCacPhong()const { return CacPhongBan; }
	double GetNganSach()const { return TongNganSachCongTy; }
	void ThongTinCacPhongBan() {
		for (auto x : CacPhongBan) {
			cout << x;
		}
	}

	// Các hàm set thông tin của công ty
	void SetNameCongTy() { getline(cin, NameOfCom); }
	void SetCacPhongBan(int n) {
		CacPhongBan.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> CacPhongBan[i];
		}
	}
	void SetTongNganSach() { cin >> TongNganSachCongTy; }

	// Các hàm thêm hoặc xóa phòng ban
	void AddDeparment(const Department& a) {
		CacPhongBan.push_back(a);
	}
	void RemoveDepartment(const Department& a) {
		auto it = find(CacPhongBan.begin(), CacPhongBan.end(), a);
		if (it != CacPhongBan.end()) CacPhongBan.erase(it);
	}
	// Tính tổng tất cả các nhân viên trong công ty
	int SumEmployeeOfCompany() {
		int sum = 0;
		for (int i = 0; i < CacPhongBan.size(); i++) {
			sum += CacPhongBan[i].SumEmployeeOfDepartment();
		}
		return sum;
	}

	// Số tiền cần để trả lương cho nhân viên toàn công ty

	// Số tiền còn lại sau khi trả lương xong
};
