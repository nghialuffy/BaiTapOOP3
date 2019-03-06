#include "Person.h"
#include<string>
#include<iostream>

using namespace std;

Person::Person() {
	this->name = "Le Van Nghia";
	this->age = 19;
	this->address = "Hue";
	this->sex = 1;
}

Person::Person(string name, int age, string address, bool sex)
{
	this->name = name;
	this->age = age;
	this->address = address;
	this->sex = sex;
}

void Person::Show() {
	cout << this->name << endl 
		<< this->age << endl 
		<< this->address << endl 
		<< this->sex << endl;
}
Person::~Person()
{
}
