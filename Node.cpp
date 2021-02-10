//Course: SENG1120
//Coded by: Timothy Kemmis

#include <cmath>
#include <iostream>
#include <string>
#include "Node.h"


Node::Node(){
	previous = NULL;
	next = NULL;
}

Node::Node(value_type data){
	previous = NULL;
	next = NULL;
	sData = data;
}


Node::~Node(){
	//destructor code
	previous = NULL;
	next = NULL;
}

void Node::setPrevious(Node* prev){
	previous = prev;
}

Node* Node::getPrevious(){
	return previous;
}

void Node::setNext(Node* nxt){
	next = nxt;
}

Node* Node::getNext(){
	return next;
}

void Node::setData(value_type s){
	sData = s;
}

Node::value_type Node::getData(){
	return sData;
}
