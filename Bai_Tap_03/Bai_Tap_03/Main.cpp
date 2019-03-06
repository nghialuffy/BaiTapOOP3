#include<iostream>
#include"Person.h"
#include"SinhVien.h"
#include"Lecturer.h"
#include"LopSinhHoat.h"
#include<string>
using namespace std;
int choose = 0;


ostream &operator<<(ostream &o, LopSinhHoat &lsh) {
	o << "=== Ten Lop ===" << endl;
	o << lsh.NameClass << endl;
	o << "=== Si So ===" << endl;
	o << lsh.Siso << endl;
	o << endl;
	o << "=== Giao Vien Chu Nhiem ===" << endl;
	lsh.GVCN->Show();
	o << endl;
	o << "=== Danh Sach Sinh Vien ===" << endl;
	lsh.ListSV.Show();
	o << endl;
	return o;
}
istream &operator>>(istream &i, LopSinhHoat &lsh) {
	cout << "Nhap Ten Lop \t: ";
	i >> lsh.NameClass;
	cout << "Nhap GVCN \t: " << endl;
	lsh.GVCN->Input();
	return i;
}
ostream &operator<<(ostream &o, SinhVien &sv) {
	cout << endl << "MSSV \t\t: " << sv.MSSV << endl
		<< "Lop \t\t: " << sv.lop << endl
		<< "Diem \t\t: " << sv.diem << endl
		<< "Ten \t\t: " << sv.name << endl
		<< "Tuoi\t\t: " << sv.age << endl
		<< "Dia Chi \t: " << sv.address << endl
		<< "Gioi Tinh \t: " << sv.sex << endl;
	return o;
}
istream &operator>>(istream &i, SinhVien &sv) {
	cout << endl << "MSSV \t\t: ";
	cin >> sv.MSSV;
	cout << "Lop \t\t: ";
	cin >> sv.lop;
	cout << "Diem \t\t: ";
	cin >> sv.diem;
	cout << "Ten \t\t: ";
	cin.ignore();
	getline(cin, sv.name);
	cout<< "Tuoi\t\t: ";
	cin >> sv.age;
	cout<< "Dia Chi \t: ";
	cin.ignore();
	getline(cin, sv.address);
	cout << "Gioi Tinh \t: ";
	cin	>> sv.sex;
	return i;
}

void Menu() {
	cout << "===========\t\tMENU\t\t===========" << endl;
	cout << "||\t0.\t Thoat\t\t\t\t||" << endl;
	cout << "||\t1.\t Hien thi danh sach lop\t\t||" << endl;
	cout << "||\t2.\t Sua Lop\t\t\t||"<< endl;
	cout << "||\t3.\t Them Sinh Vien\t\t\t||" << endl;
	cout << "||\t4.\t Xoa Sinh Vien\t\t\t||" << endl;
	cout << "||\t5.\t Cap nhat Sinh Vien\t\t||" << endl;
	cout << "||\t6.\t Them Giang Vien\t\t||" << endl;
	cout << "||\t7.\t Hien thi sinh vien\t\t||" << endl;
	cout << "||\t8.\t Tim Kiem Sinh Vien (theo MSSV)\t||" << endl;
	cout << "||\t9.\t Sap Xep Sinh Vien (theo MSSV)\t||" << endl;
	cout << "||\t\t\t*****\t\t\t||"<< endl;
}
int main() {
	int solop;
	cout << "Nhap So Lop : ";
	cin >> solop;
	cout << "Nhap Ten Lop" << endl;
	LopSinhHoat *mainLSH = new LopSinhHoat[solop];
	string lop;
	for (int i = 0; i < solop; i++) {
		cin >> lop;
		mainLSH[i].SetLop(lop);
	}
	int sosv;
	cout << "Nhap so Sinh Vien" << endl;
	cin >> sosv;
	SinhVien tempsv;
	for (int i = 0; i < sosv; i++) {
		cin >> tempsv;
		for (int j = 0; j < solop; j++) {
			if (tempsv.getLop() == mainLSH[j].GetLop()) {
				mainLSH[j].InsertHead(tempsv);
			}
		}
	}
	SinhVien a;
	ListNode l1, l2;
	l2.InsertHead(a);
	l1 = l2;
	do {
		Menu();
		cout << "cin >> ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			for (int i = 0; i < solop; i++) {
				cout << mainLSH[i];
			}
			break;
		}
		case 2:
		{
			int temp2;
			cout << "Ban muon sua lop nao (0 <= ... < "<<solop<<") : ";
			cin >> temp2;
			cin >> mainLSH[temp2];
			break;
		}
		case 3:
		{
			int temp2;
			cout << "Ban muon them sinh vien lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			SinhVien temp30;
			cout << "Sinh vien ban muon them : ";
			cin >> temp30;
			cout << "Ban muon them vao vi tri nao ([b: Dau] [e: Cuoi] [Hoac Bat ky]) : ";
			char temp31;
			cin >> temp31;
			if (temp31 == 'b')
				mainLSH[temp2].InsertHead(temp30);
			else if(temp31 == 'e')
				mainLSH[temp2].InsertTail(temp30);
			else
				mainLSH[temp2].InsertK(temp30,temp31);
			break;
		}
		case 4:
		{
			int temp2;
			cout << "Ban muon xoa sinh vien lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			cout << "Ban muon xoa vao vi tri nao ([b: Dau] [e: Cuoi] [Hoac Bat ky]) : ";
			char temp40;
			cin >> temp40;
			if (temp40 == 'b')
				mainLSH[temp2].DeleteHead();
			else if (temp40 == 'e')
				mainLSH[temp2].DeleteTail();
			else
				mainLSH[temp2].DeleteK(temp40);
			break;
		}
		case 5:
		{
			int temp2;
			cout << "Ban muon cap nhat sinh vien lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			cout << "Cung cap MSSV cua sinh vien do : ";
			string temp50;
			cin >> temp50;
			SinhVien temp51;
			cout << "Cap nhat lai Sinh Vien : ";
			cin >> temp51;
			mainLSH[temp2].Update(temp51, temp50);
			break;
		}
		case 6:
		{
			int temp2;
			cout << "Ban muon them giang vien vao lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			Lecturer *temp60 = new Lecturer;
			cout << "Giang Vien ban muon them : " << endl;
			temp60->Input();
			mainLSH->SetGiaoVien(temp60);
			break;
		}
		case 7:
		{
			int temp2;
			cout << "Ban muon hien thi sinh vien cua lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			int temp70;
			cout << "So thu tu sinh vien ban muon hien thi (0 <= ... < " << mainLSH[temp2].GetSiso() << ") : ";
			cin >> temp70;
			cout << mainLSH[temp2][temp70];
			break;
		}
		case 8:
		{
			int temp2;
			cout << "Ban muon tim kiem sinh vien cua lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			cout << "Cung cap MSSV cua sinh vien do : ";
			string temp80;
			cin >> temp80;
			mainLSH[temp2].Search(temp80);
			break;
		}
		case 9:
		{
			int temp2;
			cout << "Ban muon sap xep sinh vien cua lop nao (0 <= ... < " << solop << ") : ";
			cin >> temp2;
			char temp90;
			do {
				cout << "Ban muon sap xep tang dan hay giam dan ([t: tang] [g: giam]) : ";
				;
				cin >> temp90;
			} while (temp90 != 't'&&temp90 != 'g');
			if (temp90 == 't')
				mainLSH[temp2].Sort(1);
			else
				mainLSH[temp2].Sort(0);
			break;
		}
		default:
			choose = 0;
		}
	} while (choose);
	system("pause");
	return 0;
}