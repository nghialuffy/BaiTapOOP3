#pragma once
#include"Node.h"
class ListNode
{
private:
	Node *head;
	Node *tail;
	int size;
public:

	Node *CreatNode(SinhVien);

	ListNode *InsertHead(SinhVien);
	ListNode *InsertTail(SinhVien);
	ListNode *InsertK(SinhVien, int);

	ListNode *DeleteHead();
	ListNode *DeleteTail();
	ListNode *DeleteK(int);

	Node *Search(string);

	SinhVien &Index(int);

	ListNode *Update(SinhVien, string);
	static bool Dec(string, string);
	static bool Inc(string, string);
	ListNode *Sort(bool(*pp)(string left, string right));
	int getSize();
	void Show();
	ListNode();
	~ListNode();
	ListNode& operator=(const ListNode& l1);

};

