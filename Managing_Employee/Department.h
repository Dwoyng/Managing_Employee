#pragma once
#include<string>
#include<iostream>
#include "Emplyee.h"
#include<fstream>
#include<istream>
#include<ostream>

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
	// kiểm tra nhân viên có thuốc văn phòng này không
	bool IsEmployeeInDepartment(const Employee& e) {
		for (const auto& emp : DanhSachNhanVien) {
			if (emp.GetMaNhanVien() == e.GetMaNhanVien()) {
				return true;
			}
		}
		return false;
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


	// Hàm nhập thông tin danh sách nhân viên vào file
	void InsertListEmployee(const Employee& a) {
		string nm = GetTenPhong();
		string outline = nm + ".txt";
		ofstream file;
		file.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\"+ nm +"\\" + outline, ios::app);
		if (file.is_open()) {
			file << a.GetMaNhanVien() << ',' << a.GetName() << ',' << a.GetSDT() << endl;
			file.close();
			cout << "Them thanh cong!" << endl;
		}
		else cout << "Khong mo duoc file!" << endl;
	}

	// hàm đọc- xuất thông tin từ file
	void ExportInfListEmployee(Employee& a)const {
		string nm = GetTenPhong();
		string outline = nm + ".txt";
		ifstream file("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\" + nm + "\\" + outline);
		if (file.is_open()) {
			string name, ma_nhan_vien, sdt;
			getline(file, name, ',');
			getline(file, ma_nhan_vien, ',');
			getline(file, sdt);

			a.SetName(name);
			a.SetSDT(sdt);
			a.SetMaNhanVien(ma_nhan_vien);
			cout << a;
			file.close();
		}
		else cout << "Khong mo duoc file!";
	}


	// Số ngày đi làm của từng nhân viên
	// 1.hàm thêm ngày đi làm cho nhân viên
	void InsertWorkingDay( Employee &a) {
		string nm = GetTenPhong();
		string s = a.GetName();
		string outline = s + " wd.txt";
		ofstream file;
		file.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\" + nm + "\\" + s + "\\" + outline, ios::app);
		if (file.is_open()) {
			file << a.GetSoNgayDiLam() << ',';
			for (int i = 0; i < a.GetSoNgayDiLam(); i++) {
				file << a.NhungNgayLam()[i].GetDay() << '/' << a.NhungNgayLam()[i].GetMonth() << '/' << a.NhungNgayLam()[i].GetYear();
				file << ',';
			}
			file.close();
			cout << "Them thanh cong!";
		}
	}
	// 2.Hàm thêm 1 ngày làm vào cho nhân viên
	void AddOneDay(Employee& a, int d, int m, int y) {
		a.NhungNgayLam().push_back(Date(d, m, y));
		string nm = GetTenPhong();
		string s = a.GetName();
		string outline = s + " wd.txt";
		ofstream file;
		file.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\" + nm + "\\" + s + "\\" + outline, ios::app);
		if (file.is_open()) {
			auto it = a.NhungNgayLam().rbegin();
			file << *it;
			file.close();
		cout << "Them thanh cong!" << endl;
		}
		else cout << "Mo file that bai!";
	}
	
	// Hàm lấy ra số ngày đi làm của nhân viên từ file
	void CheckDayWorking( Employee& a)const  {
		string nm = GetTenPhong();
		string s = a.GetName();
		string outline = s + " wd.txt";
		ifstream file("C:\\Users\\ADMIN\\OneDrive\\Documents\\Visual Studio\\Managing_Employee\\Managing_Employee\\Company\\" + nm + "\\" + s + "\\" + outline);
		if (file.is_open()) {
			int day;
			file >> day;

			a.SetNgayDiLam(day);
			cout << a.GetSoNgayDiLam();
			file.close();
			cout << "Da xuat thanh cong!";
		}
		else cout << "Mo file that bai!";
	}
	// Kiểm tra xem ngày hôm ấy nhân viên có đi làm hay không
	bool CheckVar(Employee& a, int d, int m, int y) {
		for (auto x : a.NhungNgayLam()) {
			if (x == Date(d, m, y)) return true;
			else return false;
		}
	}

};

