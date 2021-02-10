//Course: SENG1120
//Coded by: Timothy Kemmis

#ifndef LINKED_LIST
#define LINKED_LIST

#include "Node.h"
#include <iostream>
#include <cmath>

class LinkedList {



	public:
		typedef Node::value_type value_type;
		//constructor
		LinkedList();

		//destructor
		~LinkedList();

		//return the head pointer
		Node* getHead();
		//return the tail pointer
		Node* getTail();
		//sets the head pointer
		void setHead(Node* h);
		//sets the tail pointer
		void setTail(Node* t);
		//adds a new node before the head which becomes the head
		void addToHead(value_type value);
		//adds a new node after the tail which becomes the tail

		void addToTail(value_type value);
		void addToTail(Node* node);
		//sets the current pointer to head
		void setCurrentToHead();
		//moves the current pointer to the next node
		void setCurrentToNext();
		//moves the current pointer to the previous node
		void setCurrentToPrevious();
		//get current
		string getHeadString();

		Node* getCurrent();

		int getSize();

		//removes a named student node
		void remove(std::string name);

		void removeNode(Node* current);
		/*
		//counts how many instances there are of a named node
		void count(std::string name);
		//orders the nodes alphabetically
		void order();
		*/
		string print();






	private:
		//
		//ostream& operator <<(ostream& out, LinkedList& l1) ;
		//private getHead function to preserve encapsulation
		//Node* getHead();
		//a pointer to the head node
		Node* head;
		//a pointer to the tail node
		Node* tail;
		//a pointer to the current node
		Node* current;

		int size;




};

//overloads the << operator for outputting LinkedList's
ostream& operator <<(ostream& out, LinkedList& l1);
//overloads the + operator to deal with LinkedList's
//void operator+(LinkedList& l1, LinkedList& l2);
//overloads the += operator to deal with LinkedList's
void operator+=(LinkedList& l1, LinkedList& l2);
/*
//overloads the - operator to deal with LinkedList's
LinkedList& operator-(const LinkedList* l2);
*/
//overloads the -= operator to deal with LinkedList's
void operator-=(LinkedList& l1, LinkedList& l2);
#endif
