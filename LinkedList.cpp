//Course: SENG1120
//Coded by: Timothy Kemmis

#include "Student.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <cmath>

		LinkedList::LinkedList(){
			head = NULL;
			tail = NULL;
			current = NULL;
			size = 0;
		}

		LinkedList::~LinkedList(){
			//empty destructor
		}

		Node* LinkedList::getHead(){
			return head;
		}

		Node* LinkedList::getTail(){
			return tail;
		}

		void LinkedList::setHead(Node* h){
			head = h;
		}

		void LinkedList::setTail(Node* t){
			tail = t;
		}

		void LinkedList::addToHead(value_type value){
			//add new node at head
			Node* node = new Node(value);
			node->setNext(head);
			if(size == 0){
				tail = node;
				current = node;
			} else {
				current = node;
				getHead()->setPrevious(node);
			}
			head = node;
			size++;
		}

		void LinkedList::addToTail(LinkedList::value_type value){
			//add new node at tail
			Node* node = new Node(value);
			node->setPrevious(tail);
			if(size == 0){
				head = node;
				current = node;
			} else {
				current = node;
				getTail()->setNext(node);
			}
			tail = node;
			size++;
		}

		void LinkedList::addToTail(Node* node){
			//update another node at tail
			node->setPrevious(tail);
			if(size == 0){
				head = node;
				current = node;
			} else {
				current = node;
				getTail()->setNext(node);
			}
			tail = node;
			size++;
		}

		void LinkedList::setCurrentToHead(){
			current = head;
		}

		void LinkedList::setCurrentToNext(){
			current = current->getNext();
		}

		void LinkedList::setCurrentToPrevious(){
			current = current->getPrevious();
		}

		Node* LinkedList::getCurrent(){
			return current;
		}

		int LinkedList::getSize(){
			return size;
		}
		void LinkedList::remove(std::string name){
			setCurrentToHead();
			bool condition = true;
			while(condition){
				//cout << 99 << endl;
				if(current->getData().get_name() == name){
									//cout << 55 << endl;

					if(current == tail){
						cout << 1 << endl;
						removeNode(current);
						cout << "removed" << endl;
						condition = false;
					} else{
						setCurrentToNext();
						removeNode(current->getPrevious());
						cout << "removed" << endl;
					}

				} else if(current != tail) {
					setCurrentToNext();
				} else {
					condition = false;
				}
			}
		}

		void LinkedList::removeNode(Node* n){


			if(n == head){
				//set head to next
				//set the next nodes previous to NULL
				head = n->getNext();
				n->getNext()->setPrevious(NULL);
			} else if(n == tail){
				//set tail to previous
				//set the node before current to have next = NULL
										cout << 2 << endl;

				tail = n->getPrevious();
				n->getPrevious()->setNext(NULL);
			} else{
			//set the node after current to have its previous be current node previous
			//set the node before current node to have its next be current node next
				n->getPrevious()->setNext(n->getNext());
				n->getNext()->setPrevious(n->getPrevious());
			}
			cout << 3 << endl;
			delete n;
			cout << 4 << endl;
		}

		/*
		*/


		string LinkedList::print(){
			//LinkedList* l1;
			setCurrentToHead();

			string output = "";
			//int counter = 1;


			stringstream ss;
			//l1->setCurrentToHead();

			bool condition = true;
			while(condition){
				stringstream temp;
				temp << "(" + current->getData().get_name() << "," << current->getData().get_score() << ")  ";
				output += temp.str();
		    	if(current != tail){
		    		setCurrentToNext();
		    	} else {
		    		condition = false;
		    	}
		    }



			return output;
		}


		ostream& operator <<(ostream& out, LinkedList& l1){
			out << l1.print();
		    return out;
		}

		void operator+=(LinkedList& l1, LinkedList& l2){
			l1.addToTail(l2.getHead());



			l1.setTail(l2.getTail());
		}

		void operator-=(LinkedList& l1, LinkedList& l2){
			int list1Size = l1.getSize();
			int list2Size = l2.getSize();

			l1.setCurrentToHead();
			for(int i = 0; i<list1Size; i++){

				l2.setCurrentToHead();
				for(int j = 0; i<list2Size; j++){
					if(l1.getCurrent()->getData() == l2.getCurrent()->getData()){
						l1.remove(l1.getCurrent()->getData().get_name());
					}
					l2.setCurrentToNext();
				}
				l1.setCurrentToNext();
			}
		}
