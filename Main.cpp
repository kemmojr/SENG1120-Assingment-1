#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList list1;
	LinkedList list2;
	
	Student c("Alex", 15);
    list1.addToTail(c);
    c.set_name("Peter"); c.set_score(10);
    list1.addToTail(c);
	c.set_name("John"); c.set_score(32);
    list1.addToTail(c);
    c.set_name("Mary"); c.set_score(50);
    list1.addToTail(c);
	c.set_name("Carol"); c.set_score(31);
    list1.addToTail(c);
	
	//firstList.remove("Alex");
	
	
	cout << "List 1: " << list1 <<  endl;
	
	/*bool condition = true;
	
	
	list1.setCurrentToHead();
	while(condition){
		cout << list1.getCurrent()->getData() << endl;
		if(list1.getCurrent() != list1.getTail()){
			list1.setCurrentToNext();
		} else {
			condition = false;
		}
	}*/
	
	return 0;
}