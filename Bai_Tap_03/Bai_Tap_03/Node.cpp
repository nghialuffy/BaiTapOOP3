#include "Node.h"



SinhVien Node::getData()
{
	return this->data;
}

Node * Node::GetNode(SinhVien sv)
{
	Node *temp = new Node;
	temp->data = sv;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

SinhVien Node::GetData()
{
	return this->data;
}

Node * Node::SetData(SinhVien sv)
{
	this->data = sv;
	return this;
}

Node::Node()
{
	this->next = NULL;
	this->pre = NULL;
}
Node::Node(SinhVien sv, Node *next, Node *pre)
{
	this->data = sv;
	this->next= next;
	this->pre = pre;
}

Node::~Node()
{
}
