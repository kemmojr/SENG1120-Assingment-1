//Course: SENG1120
//Coded by: Timothy Kemmis

#ifndef TIM_NODE
#define TIM_NODE


#include "Student.h"
#include <cmath>
#include <iostream>

class Node{

	public:
		typedef Student value_type;
		//Constructors
		Node();
		Node(value_type data);


		//destructor
		~Node();
		//Setters
		//sets the previous pointer of a node
		void setPrevious(Node* n);
		//sets the next pointer of a node
		void setNext(Node* n);
		//sets the data of the node
		void setData(value_type s);

		//Getters
		Node* getPrevious();
		//gets the next pointer of a node
		Node* getNext();
		//gets the data of the node
		value_type getData();



	private:
		Node* previous;
		Node* next;
		value_type sData;



};

//overloads the << operator for outputting Node's
Node operator <<(ostream& out, const Node& value);

#endif
