#include "LopSinhHoat.h"
#include <iostream>
#include<string>
using namespace std;

LopSinhHoat::LopSinhHoat()
{
	this->NameClass = "17T1";
	this->Siso = 0;
	this->ListSV;
	this->GVCN = new Lecturer;
}
LopSinhHoat::LopSinhHoat(string nameclass, Lecturer *lecturer)
{
	this->NameClass = nameclass;
	this->Siso = 0;
	this->ListSV;
	this->GVCN = lecturer;
}
LopSinhHoat::~LopSinhHoat()
{
	this->ListSV.~ListNode();
}

void LopSinhHoat::SetGiaoVien(Lecturer *gv)
{
	this->GVCN = gv;
}

void LopSinhHoat::SetLop(string lop)
{
	this->NameClass = lop;
}

string LopSinhHoat::GetLop()
{

	return this->NameClass;
}

void LopSinhHoat::Show()
{
	cout << "=== Ten Lop ===" << endl;
	cout << this->NameClass << endl;
	cout << endl;
	cout << "=== Giao Vien Chu Nhiem ===" << endl;
	GVCN->Show();
	cout << endl;
	cout << "=== Danh Sach Sinh Vien ===" << endl;
	this->ListSV.Show();
	cout << endl;
}

void LopSinhHoat::InsertHead(SinhVien sv)
{
	sv.setLop(this->NameClass);
	this->ListSV.InsertHead(sv);
	this->Siso = this->ListSV.getSize();
}

void LopSinhHoat::InsertTail(SinhVien sv)
{
	sv.setLop(this->NameClass);
	this->ListSV.InsertTail(sv);
	this->Siso = this->ListSV.getSize();
	cout << this->ListSV.getSize();
}

void LopSinhHoat::InsertK(SinhVien sv, int k)
{
	sv.setLop(this->NameClass);
	this->ListSV.InsertK(sv, k);
	this->Siso = this->ListSV.getSize();
}

void LopSinhHoat::DeleteHead()
{
	this->ListSV.DeleteHead();
	this->Siso = this->ListSV.getSize();
}

void LopSinhHoat::DeleteTail()
{
	this->ListSV.DeleteTail();
	this->Siso = this->ListSV.getSize();
}

void LopSinhHoat::DeleteK(int k)
{
	this->ListSV.DeleteK(k);
	this->Siso = this->ListSV.getSize();
}

void LopSinhHoat::Search(string mssv)
{
	Node *temp = this->ListSV.Search(mssv);
	if (temp != NULL) {
		temp->getData().Show();
	}
	else
		cout << "Does Not Exist" << endl;
}

void LopSinhHoat::Update(SinhVien sv, string mssv)
{
	sv.setLop(this->NameClass);
	this->ListSV.Update(sv, mssv);
}

void LopSinhHoat::Sort(int i)
{
	if (i == 1) {
		this->ListSV.Sort(ListNode::Inc);
	}
	else {
		this->ListSV.Sort(ListNode::Dec);
	}
}

int LopSinhHoat::GetSiso()
{
	return this->ListSV.getSize();
}

SinhVien &LopSinhHoat::operator[](const int i)
{
	static SinhVien *temp = new SinhVien;
	if (i >= 0 && i < this->Siso) {
		return this->ListSV.Index(i);
	}
	return *temp;
}

LopSinhHoat & LopSinhHoat::operator=(LopSinhHoat &p)
{
	this->NameClass = p.NameClass;
	this->GVCN = p.GVCN;
	this->Siso = p.Siso;
	for (int i = 0; i < this->Siso; i++) {
		this->ListSV.InsertTail(p.ListSV.Index(i));
	}
	return *this;
}
