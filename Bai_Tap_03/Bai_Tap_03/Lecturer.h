#pragma once
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;

class Lecturer :public Person
{
private:
	string MaLecturer;
	string Capbac;
public:
	Lecturer();
	Lecturer(string, string, string name, int age, string address, bool sex);
	~Lecturer();
	void Input();
	void Show();
};

