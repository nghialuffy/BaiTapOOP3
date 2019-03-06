#pragma once
#include<string>
#include<iostream>
#include "Person.h"
using namespace std;

class SinhVien : public Person
{
private:
	string MSSV;
	string lop;
	double diem;
public:
	void Show();
	string getMSSV();
	string getLop();
	SinhVien setLop(string);
	bool operator==(const SinhVien);
	bool operator!=(const SinhVien);
	SinhVien();
	SinhVien(string, double, string, int, string, bool);
	~SinhVien();
	friend ostream &operator<<(ostream &, SinhVien &);
	friend istream &operator>>(istream &, SinhVien &);
};

