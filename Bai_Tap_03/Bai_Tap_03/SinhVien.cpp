#include "SinhVien.h"


SinhVien::SinhVien() {
	this->MSSV = "102170038";
	this->lop = "None";
	this->diem = 4;
}
SinhVien::SinhVien(string MSSV, double diem, string name, int age, string address, bool sex):Person(name, age, address, sex)
{
	this->MSSV = MSSV;
	this->diem = diem;
}
void SinhVien::Show() {
	cout << endl << "MSSV \t\t: " << this->MSSV << endl
		<<"Lop \t\t: "<< this->lop<< endl
		<<"Diem \t\t: "<< this->diem << endl 
		<<"Ten \t\t: "<< this->name << endl 
		<< "Tuoi\t\t: " << this->age << endl
		<< "Dia Chi \t: " <<this->address << endl 
		<< "Gioi Tinh \t: " << this->sex << endl;
}
string SinhVien::getMSSV()
{
	return this->MSSV;
}
string SinhVien::getLop()
{
	return this->lop;
}
SinhVien SinhVien::setLop(string lop)
{
	this->lop = lop;
	return *this;
}
bool SinhVien::operator==(const SinhVien sv)
{
	if (this->MSSV != sv.MSSV) {
		return false;
	}
	return true;
}
bool SinhVien::operator!=(const SinhVien sv)
{
	return !(*this == sv);
}
SinhVien::~SinhVien()
{
}
