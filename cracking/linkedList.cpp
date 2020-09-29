#include "linkedList.h"



#include <iostream>

using namespace std;

linkedList sumLists(linkedList l1, linkedList l2);
bool intersect(linkedList l1, linkedList l2);


int main(int argc, char * argv[]) {

	cout << "yo\n";
	linkedList l1;
	cout << "test1\n";
	for (int i = 0; i < 10; i++) {
		l1.addToBack(i);
	}
	cout << "test2\n";
	l1.print();
    cout << endl;

    l1.addToBack(6);
    l1.addToBack(3);
	l1.deleteMiddle();
    l1.print();
    
    cout << endl;
    
    l1.removeDups();

	l1.print();

    cout << l1.kThToLast(4) << endl;
    cout << l1.kThToLast(2) << endl;
    
    
    cout << endl << "NEW TESTS" << endl << endl;
    
    
    linkedList one;
    one.addToBack(4);
    one.addToBack(2);
    linkedList two;
    two.addToBack(3);
    two.addToBack(5);
    
    linkedList newList;
    
    newList = sumLists(one, two);
    
    newList.print();
    
    linkedList n1;
    n1.addToBack(2);
    n1.addToBack(3);
    n1.addToBack(2);
    n1.print();
    cout << endl;
    if (n1.isPalindrome()) {
        cout << "This list is a palindrome\n";
    }
    
    if (intersect(one, two)) {
        cout << "They intersect" << endl;
    } else {
        cout << "They don't intersect" << endl;
    }
    
	return 0;


}

// reverseSum
linkedList sumLists(linkedList l1, linkedList l2) {
    int x = 0;
    int y = 0;
    linkedList::Node * xTemp = l1.getHead();
    linkedList::Node * yTemp = l2.getHead();
    int pow = 1;
    
    while (xTemp != NULL) {
        x += (pow * xTemp->val);
        pow *= 10;
        xTemp = xTemp->next;
    }
    pow = 1;
    while (yTemp != NULL) {
        y += (pow * yTemp->val);
        pow *= 10;
        yTemp = yTemp->next;
    }
    
    int newSum = x+y;
    
    linkedList newList;
    
    int digit;
    
    while (newSum > 0) {
        digit = newSum % 10;
        newSum = newSum / 10;
        newList.addToFront(digit);
    }
    return newList;
}

bool intersect(linkedList l1, linkedList l2) {
    
    linkedList::Node * tempA = l1.getHead();
    linkedList::Node * tempB = l2.getHead();
    
    while (tempA != nullptr) {
        tempB = l2.getHead();
        while (tempB != nullptr) {
            if (tempA == tempB) {
                return true;
            }
            tempB = tempB->next;
        }
        tempA = tempA->next;
    }
    return false;
}
