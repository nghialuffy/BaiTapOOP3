#pragma once
#include<string>
#include<iostream>
using namespace std;
class Person
{
protected:
	string name;
	int age;
	string address;
	bool sex;
public:
	void Show();
	Person();
	Person(string, int, string, bool);
	~Person();
};

