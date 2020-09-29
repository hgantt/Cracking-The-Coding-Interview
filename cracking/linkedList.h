#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stack>
#include <map>


using namespace std;



class linkedList {


//	struct Node
//	{
//		int val;
//		Node * next;
//	};

public:
    
    struct Node
    {
        int val;
        Node * next;
    };
    
    
	linkedList() {
		head = NULL;
		size = 0;
	}

	int sizeOfList() {
		return size;
	}

	void print() {
		Node * temp = head;
		while (temp != NULL) {
			cout << temp->val << " " << endl;
			temp = temp->next;
		}
	}

	Node * newNode(int val) {
		Node * newNode = new Node;
		newNode->val = val;
		newNode->next = NULL;
		return newNode;
	}

	void addToBack(int val) {
		Node * newNode = new Node;
		newNode->val = val;
		newNode->next = NULL;

		if (size == 0) {
			head = newNode;
			size++;
			return;
		}

		Node * temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		size++;
	}

	void deleteMiddle() {
		Node * fast = head;
		Node * slow = head;
		Node * slowPrev = head;

		if (not (size > 2)) {
			return;
		}
		// cout << "Test1\n";
		while (fast->next != NULL and fast->next->next != NULL) {
			slowPrev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		// cout << "TESTIES\n";
		slowPrev->next = slow->next;
		slow->next = NULL;
		delete slow;
		slow = NULL;
		size--;
	}
    
    // could do with hash table?
    void removeDups() {
        Node * temp1 = head;
        Node * temp2 = head;
        Node * temp2prev = head;
        
        while (temp1->next != NULL) {
            temp2 = temp1->next;
            while (temp2 != NULL) {
                if (temp1->val == temp2->val) {
                    deleteNode(temp2, temp2prev);
                }
                temp2prev = temp2;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    void deleteNode(Node * del, Node * delPrev) {
        // beginning of list -- don't care about this case right now
        // middle of list
        if (del->next != nullptr) {
            delPrev->next = del->next;
            del->next = nullptr;
            delete del;
            del = NULL;
        } else {
            delPrev->next = NULL;
            delete del;
            delPrev = NULL;
        }
        size--;
    }
    
    int kThToLast(int k) {
        int count = 0;
        Node * temp = head;
        while (count != (size - k)) {
            temp = temp->next;
            count++;
        }
        return temp->val;
    }
    
    Node * getHead () {
        return head;
    }
    
    void addToFront(int val) {
        Node * temp = head;
        head = newNode(val);
        head->next = temp;
    }
    
    // using stack
    bool isPalindrome() {
    
        stack<int> s;
        Node * temp = head;
        while (temp != NULL) {
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        
        while (not s.empty()) {
            if (s.top() != temp->val) {
                return false;
            }
            s.pop();
            temp = temp->next;
        }
        return true;
    }
    
    bool hasLoop() {
        
        Node * temp = head;
        map <Node*, int> m;
        
        while (true) {
            if (temp == NULL) {
                return false;
            }
            if (m.find(temp) != m.end()) {
                return true;
            } else {
                m.insert(pair<Node*, int> (temp, 0));
            }
            temp = temp->next;
        }
        return true;
    }
    
private:
	Node * head;
	int size;
	
};

#endif
