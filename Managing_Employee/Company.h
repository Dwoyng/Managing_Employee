#pragma once
#include<iostream>
#include<string>
#include "Department.h"
#include<istream>
#include<ostream>
#include<fstream>

using namespace std;
class Company {
	string NameOfCom;
	vector<Department> CacPhongBan;
	double TongNganSachCongTy;
public:
	
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
		ofstream file;
		file.open("CacPhongBan.txt", ios::app);
		if (file.is_open()) {
			file << a.GetMaPhong() << ',' << a.GetTenPhong() << ',' << endl;
			file.close();
			cout << "Them thanh cong!";
		}
		else cout << "Them that bai!";
	}

	void DeleteDepartment(const Department& departmentToDelete) {
		std::ifstream file("CacPhongBan.txt");
		std::vector<std::string> remainingDepartments;
		std::string line;

		// Đọc từng dòng từ file và kiểm tra nếu trùng với Department cần xóa
		while (getline(file, line)) {
			std::stringstream ss(line);
			std::string name, code;

			// Giả sử định dạng mỗi dòng là: Tên Phòng, Mã Phòng
			getline(ss, name, ',');
			getline(ss, code, ',');

			// Nếu thông tin department không trùng khớp thì giữ lại dòng này
			if (code != departmentToDelete.GetMaPhong()) {
				remainingDepartments.push_back(line);
			}
		}
		file.close();
	
		// Ghi lại các phòng ban còn lại vào file
		std::ofstream outFile("CacPhongBan.txt", std::ios::trunc);  // Mở file ở chế độ ghi đè (truncate)
		for (const auto& department : remainingDepartments) {
			outFile << department << std::endl;
		}
		outFile.close();
	}

	//Hàm truy vẫn vào danh sách nhân viên từ class Company
	void PrinfEmployeeFromCompany() {

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
