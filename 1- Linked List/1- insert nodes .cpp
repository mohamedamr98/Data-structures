#include <iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
 
class node
{
public:
	int value;
	node *next;
};
 
void printLinkedList(node *head)
{
	cout << "Printing Linked List:" << endl;
	node *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->value;
		if (tmp->next != NULL)
		{
			cout << "->";
		}
 
		tmp = tmp->next;
	}
	cout << endl;
}
 
 
void insertNodeAtHead(node *&head,int data,node *&tail)
{
	node *newNode = new node();
	newNode->value = data;
 
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}
 
 
void insertNodeAtEnd(node *&head, int data, node *&tail) // pass by reference
{
	node *newNode = new node();
	newNode->value = data;
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}
 
 
void insertNodeatPos(node *&head, int position, int data, node *&tail) // 1-based
{
	if (position == 1)
	{
		insertNodeAtHead(head, data, tail);
	}
	else
	{
		// traverse till position -1
		node *tmp = head;
		int cnt = 0;
		while (tmp != NULL)
		{
			cnt++;
			if (cnt == position-1)
			{
				break;
			}
			tmp = tmp->next;
		}
 
		if (tmp->next == NULL) // I am at tail Node
		{
			insertNodeAtEnd(head, data, tail);
		}
		else
		{
			node *newNode = new node();
			newNode->value = data;
 
			newNode->next = tmp->next;
			tmp->next = newNode;
		}
	}
}
int main() 
{
	node *head = NULL, *tail = NULL;
 
 
	bool choice = 1;
	int data;
	while (choice)
	{
		cout << "Do you want to insert a new node?(1/0)" << endl;
		cin >> choice;
		if (!choice)break;
		cout << "Enter the value of the node: ";
		cin >> data;
		insertNodeAtEnd(head, data, tail);
	}
 
	printLinkedList(head);
 
 
 
	cout << "Insert node at the beginning, enter the value: ";
	cin >> data;
	insertNodeAtHead(head, data, tail);
 
	printLinkedList(head);
 
 
	cout << "Insert node at the beginning, enter the value: ";
	cin >> data;
	insertNodeAtHead(head, data, tail);
 
	printLinkedList(head);
 
 
	cout << "Insert node at a position, enter the position: ";
	int position;
	cin >> position;
	cout << "Enter the value: ";
	cin >> data;
	insertNodeatPos(head, position, data, tail);
	printLinkedList(head);
 
 
 
	cout << "Insert node at a position, enter the position: ";
	cin >> position;
	cout << "Enter the value: ";
	cin >> data;
 
	insertNodeatPos(head, position, data, tail);
	printLinkedList(head);
 
	return 0;
}