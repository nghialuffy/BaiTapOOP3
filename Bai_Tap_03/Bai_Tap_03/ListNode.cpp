#include "ListNode.h"
#include<iostream>
#include<string>
using namespace std;

Node *ListNode::CreatNode(SinhVien sv)
{
	Node *p = new Node(sv, NULL, NULL);
	this->size = 0;
	return p;
}

ListNode * ListNode::InsertHead(SinhVien sv)
{
	Node *temp = new Node(sv, NULL, NULL);
	if (this->size == 0) {
		this->head = this->tail = temp;
	}
	else {
		temp->next = this->head;
		this->head->pre = temp;
		this->head = temp;
	}
	this->head->pre = this->tail;
	this->tail->next = this->head;

	this->size++;
	return this;
}

ListNode * ListNode::InsertTail(SinhVien sv)
{
	Node *temp = new Node(sv, NULL, NULL);
	if (this->size == 0) {
		this->head = this->tail = temp;
	}
	else {
		this->tail->next = temp;
		temp->pre = this->tail;
		this->tail = temp;
	}
	this->head->pre = this->tail;
	this->tail->next = this->head;
	this->size++;
	return this;
}

ListNode * ListNode::InsertK(SinhVien sv, int k)
{
	if (k <= 0)
		this->InsertHead(sv);
	else if (k > this->size - 1) {
		this->InsertTail(sv);
	}
	else {
		Node *temp = new Node(sv, NULL, NULL);
		Node *temph = this->head, *tempt, *tempr = new Node(sv, NULL, NULL);
		int i = 1;
		do {
			i++;
			temph = temph->next;
		} while (temph != this->head && i != k);
		tempt = temph->next;
		tempr->next = tempt;
		tempr->pre = temph;
		temph->next = tempr;
		tempt->pre = tempr;
		this->size++;
	}
	return this;
}

ListNode * ListNode::DeleteHead()
{
	this->head->data.setLop("None");
	if (this->size != 0) {
		this->head = this->head->next;
		this->head->pre = this->tail;
		this->tail->next = this->head;
		this->size--;
	}
	return this;
}

ListNode * ListNode::DeleteTail()
{
	this->tail->data.setLop("None");
	if (this->size != 0) {
		this->tail = this->tail->pre;
		this->head->pre = this->tail;
		this->tail->next = this->head;
		this->size--;
	}
	return this;
}

ListNode * ListNode::DeleteK(int k)
{
	Node *temph = this->head, *tempt;
	int i = 1;
	if (k <= 0) {
		this->DeleteHead();
	}
	else if (k >= this->size - 1) {
		this->DeleteTail();
	}
	else {
		while (temph != NULL && i != k) {
			i++;
			temph = temph->next;
		}
		temph->data.setLop("None");
		tempt = temph->next->next;
		temph->next = tempt;
		tempt->pre = temph;
		this->size--;
	}
	return this;
}

Node * ListNode::Search(string mssv)
{
	Node *temph = this->head;
	do {
		if (temph->data.getMSSV() == mssv)
			return temph;
		temph = temph->next;
	} while (temph != this->head);
	return NULL;
}

SinhVien & ListNode::Index(int i)
{
	SinhVien *temp = new SinhVien;
	Node *temph = this->head;
	if (i < 0 || i >= this->size) {
		cout << "Index Error" << endl;
		return *temp;
	}
	int j = 0;
	while (j < i) {
		j++;
		temph = temph->next;
	}
	return temph->data;
}

ListNode * ListNode::Update(SinhVien sv, string mssv)
{
	Node *temph = this->head;
	int i = 0;
	do {
		if (temph->data.getMSSV() == mssv) {
			break;
		}
		i++;
		temph = temph->next;
	} while (temph != this->head);
	if (i >= this->size) {
		cout << "Can't Update" << endl;
		return this;
	}
	this->DeleteK(i);
	this->InsertK(sv, i);
	return this;
}

bool ListNode::Dec(string left, string right)
{
	if (left < right) {
		return true;
	}
	else
		return false;
}

bool ListNode::Inc(string left, string right)
{
	if (left > right) {
		return true;
	}
	else
		return false;
}

bool(*pp)(string left, string right);

ListNode * ListNode::Sort(bool(*pp)(string left, string right))
{
	Node *temp;
	SinhVien data;
	bool check = false;
	while (!check) {
		check = true;
		temp = this->head;
		do {
			if (pp(temp->data.getMSSV(), temp->next->data.getMSSV())) {
				data = temp->getData();
				temp->SetData(temp->next->getData());
				temp->next->SetData(data);
				check = false;
			}
			temp = temp->next;
		} while (temp->next != this->head);

	}
	return this;
}

int ListNode::getSize()
{
	return this->size;
}

void ListNode::Show()
{
	if (this->head) {
		Node *temph = this->head;
		do {
			temph->data.Show();
			temph = temph->next;
		} while (temph != this->head);
	}
	else {
		cout << "List Empty" << endl;
	}

}

ListNode::ListNode()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

ListNode::~ListNode()
{
}

ListNode& ListNode::operator=(const ListNode & l1)
{
	Node *temp = l1.head;
	if (l1.size != 0) {
		do {
			this->DeleteHead();
		} while (this->size != 0);
		do {
			this->InsertTail(temp->data);
			temp->next;
		} while (temp->next != l1.head);
	}
	return *this;
}
