#include<iostream>
using namespace std; 
//class  stack{
//private:
//	string  action[6];
//	string time[6];
//	string officer[6];
//
//	int  topindex;
//	int  undoCount;
//	bool locked;
//public:
//
//	stack() {
//		topindex = 0;
//		undoCount = 0;
//		locked = 0;
//	}
//
//	void push(string a, string t, string o) {
//		if (locked) {
//			cout << "System Locked!\n";
//			return;
//		}
//
//		if (topindex == 5) {
//			cout << "Stack Full\n";
//			return;
//		}
//
//		topindex++;
//		action[topindex] = a;
//		time[topindex] = t;
//		officer[topindex] = o;
//
//		undoCount = 0;
//	 }
//
//// pop   from the  stack 
//	void pop (){
//		if (locked) {
//			cout << "System Locked!" << endl;
//			return;
//		}
//
//		if (topindex == -1) {
//			cout << "Empty" << endl;
//			return;
//		}
//		cout << "Undo: " << action[topindex] << endl;
//		topindex--;
//		undoCount++;
//
//		if (undoCount >= 3) {
//			locked = true;
//			cout << "? Locked after 3 undos" << endl;
//		}
//	}
//
//	void  top() {
//		if (topindex==-1) {
//			cout << "empty" << endl; 
//
//		}
//		cout << "latest " <<
//			action[topindex] << "| " << time[topindex] << " | " << officer[topindex] << endl; 
//	}
//	// display
//	void display() {
//		if (topindex == -1) {
//			cout << "Empty\n";
//			return;
//		}
//
//		cout << "\nLogs (Latest to Oldest):\n";
//		for (int i = topindex; i >= 0; i--) {
//			cout << action[i] << " | "
//				<< time[i] << " | "
//				<< officer[i] << endl;
//		}
//	}
//
//
//	void  reset(string key ) {
//		if (key == "admin123") {
//			locked = false;
//			undoCount = 0;
//			cout << "System Reset\n";
//		}
//		else {
//			cout << "Wrong Password\n";
//		}	
//	}
//};
//
//
class listStack {
private:
    class node {
    public:
        string action;
        string time;
        string officer;
        node* next;
    };

    node* topnode;
    int undoCount;
    bool locked;

public:
    listStack() {
        topnode = NULL;
        undoCount = 0;
        locked = false;
    }

    // push
    void push(string a, string t, string o) {
        if (locked) {
            cout << "System Locked!\n";
            return;
        }

        node* newNode = new node;
        newNode->action = a;
        newNode->time = t;
        newNode->officer = o;

        newNode->next = topnode;
        topnode = newNode;

        undoCount = 0;
    }

    // pop
    void pop() {
        if (locked) {
            cout << "System Locked!\n";
            return;
        }

        if (topnode == NULL) {
            cout << "Empty\n";
            return;
        }

        node* temp = topnode;
        cout << "Undo: " << temp->action << endl;

        topnode = topnode->next;
        delete temp;

        undoCount++;

        if (undoCount >= 3) {
            locked = true;
            cout << "? Locked after 3 undos\n";
        }
    }

    // display
    void display() {
        if (topnode == NULL) {
            cout << "Empty\n";
            return;
        }

        cout << "\nLogs:\n";
        node* temp = topnode;

        while (temp != NULL) {
            cout << temp->action << " | "
                << temp->time << " | "
                << temp->officer << endl;
            temp = temp->next;
        }
    }

    // top
    void top() {
        if (topnode == NULL) {
            cout << "Empty\n";
            return;
        }

        cout << "Latest: "
            << topnode->action << " | "
            << topnode->time << " | "
            << topnode->officer << endl;
    }

    // reset
    void reset(string pass) {
        if (pass == "admin123") {
            locked = false;
            undoCount = 0;
            cout << "System Reset\n";
        }
    }
};




int main() {

    listStack s;

	s.push("Fire Alert", "10:00", "O1");
	s.push("Evacuation", "10:05", "O2");
	s.push("Rescue", "10:10", "O3");

	s.display();

	s.pop();
	s.pop();
	s.pop(); // lock

	s.push("Test", "11:00", "O4"); // blocked

	s.reset("admin123");

	s.push("New Event", "11:30", "O5");

	s.display();

	return 0;
}