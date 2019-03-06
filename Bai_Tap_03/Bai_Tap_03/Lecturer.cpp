#include "Lecturer.h"

Lecturer::Lecturer() 
{
	this->MaLecturer = "102dhphuong";
	this->Capbac = "full professor";
	this->name = "Dang Hoai Phuong";
	this->age = 30;
	this->sex = true;
	this->address = "Da Nang";
}
Lecturer::Lecturer(string maleturer, string capbac, string name, int age, string address, bool sex):Person(name, age, address, sex)
{
	this->MaLecturer = maleturer;
	this->Capbac = capbac;
}
Lecturer::~Lecturer()
{
}
void Lecturer::Input()
{
	cout << "Ma Giang Vien \t: ";
	cin >> this->MaLecturer;
	cout << "Cap Bac \t: ";
	cin.ignore();
	getline(cin, this->Capbac);
	cout << "Ten \t\t: ";
	cin.ignore();
	getline(cin, this->name);
	cout << "Tuoi \t\t: "; 
	cin >> this->age;
	cout << "Dia Chi \t: "; 
	cin.ignore();
	getline(cin, this->address);
	cout << "Gioi Tinh \t: ";
	cin >> this->sex;
}
void Lecturer::Show()
{
	cout << "Ma Giang Vien \t: " << this->MaLecturer << endl
		<<"Cap Bac \t: "<< this->Capbac << endl
		<< "Ten \t\t: "<<this->name << endl
		<< "Tuoi \t\t: "<<this->age << endl
		<< "Dia Chi \t: "<<this->address << endl
		<< "Gioi Tinh \t: " << this->sex << endl;
}

