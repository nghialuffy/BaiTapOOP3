#pragma once
#include"SinhVien.h"
class Node
{
private:
	SinhVien data;
	Node *next;
	Node *pre;
public:
	friend class ListNode;
	SinhVien getData();
	Node *GetNode(SinhVien);
	SinhVien GetData();
	Node *SetData(SinhVien);
	Node();
	Node(SinhVien, Node *, Node *);
	~Node();
};

