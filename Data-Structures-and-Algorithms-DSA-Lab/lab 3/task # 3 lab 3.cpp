#include<iostream>
using namespace std; 


template <class t >
class  mycarstack {
private:  
    int   size;
	t* arr;
	int topindex;
public :
	   //  constructor prametrize 
	mycarstack(int s ){
		size = s; 
		arr = new t [size];
		topindex = -1;
	}
	   // distructor
	~mycarstack() {
		delete[] arr;
	}

	bool isEmpty() {
		return (topindex == -1);
	}

	bool isFull() {
		return (topindex == size - 1);
	}

	void  push(t car ){

		if (isFull()){
			cout << " the stack is over flow " << endl;
			return;
		}
		arr[++topindex] = car;
		cout << "Car parked: " << car << endl;
	}
	
	t pop() {
		if (isEmpty()) {
			cout << "  parking  Empty " << endl;
			return t();
		}
		return  arr[topindex--];
	}
	
	t top() {
		if (isEmpty()) {
			return t();
		}
		return arr[topindex];
	}

	void display() {
		if (isEmpty()) {
			cout << "No cars parked\n";
			return ;
		}
		cout << "Cars in Parking (Top to Bottom):\n";
		for (int i = topindex; i >= 0; i--) {
			cout << arr[i] << endl;
		}

	}

	int count() {
		return topindex + 1;
	}
	
	bool search(t car){
		for (int i = 0; i <= topindex; i++){
			if (arr[i] == car)
				return true;
		}
		return false;
	}

	void removeCar(t car){

		if (isEmpty()){
			cout << "Parking Empty!\n";
			return;
		}

		mycarstack  <t> temp(size);

		bool found = false;

		// Move cars until target found
		while (!isEmpty()){
			if (top() == car){
				pop();
				found = true;
				cout << "Car removed: " << car << endl;
				break;
			}
			temp.push(pop());
		}
		// Restore cars
		while (!temp.isEmpty()){ 
		   push(temp.pop());
		}

		if (!found) {
			cout << "Car not found!\n";
		}
	}
};





int main() {

	mycarstack <string> parking(8);

	int choice;
	string car;

	do {
		cout << "\n===== PARKING MENU =====\n";
		cout << "1. Park Car\n";
		cout << "2. Remove Car\n";
		cout << "3. Show Top Car\n";
		cout << "4. Display All Cars\n";
		cout << "5. Total Cars\n";
		cout << "6. Search Car\n";
		cout << "7. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			cout << "Enter car number: ";
			cin >> car;
			parking.push(car);
			break;

		case 2:
			cout << "Enter car number to remove: ";
			cin >> car;
			parking.removeCar(car);
			break;

		case 3:
			cout << "Top car: " << parking.top() << endl;
			break;

		case 4:
			parking.display();
			break;

		case 5:
			cout << "Total cars: " << parking.count() << endl;
			break;

		case 6:
			cout << "Enter car number: ";
			cin >> car;
			if (parking.search(car))
				cout << "Car Found\n";
			else
				cout << "Car NOT Found\n";
			break;

		case 7:
			cout << "Exiting...\n";
			break;

		default:
			cout << "Invalid choice\n";
		}

	} while (choice != 7);

	return 0;
}