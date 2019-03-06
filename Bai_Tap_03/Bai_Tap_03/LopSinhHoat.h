#pragma once
#include<string>
#include<iostream>
#include"ListNode.h"
#include"SinhVien.h"
#include"Lecturer.h"
using namespace std;

class LopSinhHoat
{
private:
	string NameClass;
	ListNode ListSV;
	Lecturer *GVCN;
	int Siso;
public:
	LopSinhHoat();
	LopSinhHoat(string, Lecturer*);
	~LopSinhHoat();
	void SetGiaoVien(Lecturer*);
	void SetLop(string);
	string GetLop();
	void Show();
	void InsertHead(SinhVien);
	void InsertTail(SinhVien);
	void InsertK(SinhVien, int);
	void DeleteHead();
	void DeleteTail();
	void DeleteK(int);
	void Search(string);
	void Update(SinhVien, string);
	void Sort(int i);
	int GetSiso();
	friend ostream &operator<<(ostream &, LopSinhHoat &);
	friend istream &operator>>(istream &, LopSinhHoat &);
	SinhVien &operator[](const int);
	LopSinhHoat &operator=(LopSinhHoat &);
};

