#include <iostream>
#include "List"

using namespace std;
int choice;
int manage_trains();
int ticket_service();
void add_train();
void delete_train();
void print_trains();




class Train {
	protected:
		int train_id;
		int capacity;
		int occupied;
		const string stations[10];
		

	public:
		Train();
		~Train();
		virtual void showTrainInfo() = 0;
		virtual int getCost(string, string) = 0;
		int getTrainId();
		int getCapacity();
		int getOccupied();
		void setTrainId(int);
		void setCapacity(int);
		void setOccupied(int);
		//void setStations();
};

Train::Train() {

}
Train::~Train() {
	
}


int Train::getTrainId(){
	return train_id;

}
int Train::getCapacity(){
	return capacity;
}
int Train::getOccupied(){
	return occupied;
}
void Train::setTrainId(int id){
	train_id = id;

}
void Train::setCapacity(int cap){
	capacity = cap;

}
void Train::setOccupied(int occ){
	occupied = occ;

}

class List {
private:
	typedef struct node {
		Train* train;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
public:
	List();
	~List();
	void addNode(Train*);
	void deleteNode(int);
	void printList();
};
List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;

}
List::~List() {

}
void List::addNode(Train* new_train){
	nodePtr n = new node;
	n->next = NULL;
	n->train = new_train;

	if (head != NULL) {
		curr = head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	} else {
		head = n;
	}
}
void List::deleteNode(int del_train_id) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->train->getTrainId() != del_train_id) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "Invalid ID: " << del_train_id << endl; 
		delete delPtr;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "delete succeeded" << endl;
	}
}
void List::printList() {
	curr = head;
	while (curr != NULL) {
		cout << curr->train->getTrainId() << endl;
		curr = curr->next;
	}
}

List trains_list;


class N: public Train {

	public:
		void showTrainInfo() {
			getTrainId();
			getCapacity();
			getOccupied();
		}
		int getCost(string orig, string dest) {
			return 1;
		}
		void setStations() {
			
		}
};

class A: public Train {

	public:
		void showTrainInfo() {
			getTrainId();
			getCapacity();
			getOccupied();
		}
		int getCost(string orig, string dest) {
			return 1;
		}

};
class B: public Train {
		public:
		void showTrainInfo() {
			getTrainId();
			getCapacity();
			getOccupied();
		}
		int getCost(string orig, string dest) {
			return 1;
		}
};
class S: public Train {
		public:
		void showTrainInfo() {
			getTrainId();
			getCapacity();
			getOccupied();
		}
		int getCost(string orig, string dest) {
			return 1;
		}
};

class Ticket {
	string origin;
	string destination;


	public:
		Ticket();
		~Ticket();
};
Ticket::Ticket() {

}
Ticket::~Ticket() {

}

void add_train() {	
	int new_train_id, new_capacity;
	char new_type;
	cout << "Train ID: "  << endl;
	cin >> new_train_id;
	cout << "Capacity: "  << endl;
	cin >> new_capacity;
	cout << "Train Type: "  << endl;
	cin >> new_type;

	Train* train;

	if (new_type == 'N' || new_type == 'n') {
		N* n1;
		n1 = new N();
		n1->setTrainId(new_train_id);
		n1->setCapacity(new_capacity);
		n1->setOccupied(0);
		trains_list.addNode(n1);
	} else if (new_type == 'A' || new_type == 'a') {
		A* a1;
		a1 = new A();
		a1->setTrainId(new_train_id);
		a1->setCapacity(new_capacity);
		a1->setOccupied(0);
		trains_list.addNode(a1);
	} else if (new_type == 'B' || new_type == 'b') {
		B* b1;
		b1 = new B();
		b1->setTrainId(new_train_id);
		b1->setCapacity(new_capacity);
		b1->setOccupied(0);
		trains_list.addNode(b1);
	} else if (new_type == 'S' || new_type == 's') {
		S* s1;
		s1 = new S();
		s1->setTrainId(new_train_id);
		s1->setCapacity(new_capacity);
		s1->setOccupied(0);
		trains_list.addNode(s1);
	} else {
		cout << "not a train" << endl;
	}

	
	return;	
}
void delete_train() {
	int del_train_id;
	cout << "Train ID: " << endl;
	cin >> del_train_id;

	trains_list.deleteNode(del_train_id);
	
}

void print_trains() {
	trains_list.printList();

}
Ticket buy_tickets() {
	Ticket t;
	string orig, dest;

	cout << "Origin: " << endl;
	cin >> orig;
	cout << "Destination: " << endl;
	cin >> dest;

	return t;
}
int get_input_and_check (int choices) {
	int err;
	//cin >> choice;
	//if return value is 1, error is detected
	if(!(cin>>choice)) {
		cin.clear();
		cin.ignore(999, '\n');
		err = 1;
	}else {
		if (choice < 1)
			err = 1;
		else if (choice > choices)
			err = 1;
		else
			err = 0;
	}
	//cout << err << endl; 
	return err;
}
int main () {
//	int err;
	

	while(1) {	
		do {
			cout << "1. Manage Trains" << endl;
			cout << "2. Ticket Service" << endl;
			cout << "3. Exit" << endl;
		//	err = get_input_and_check(3);
		} while(get_input_and_check(3));
	
		if(choice == 1)
			manage_trains();
		else if (choice == 2)
			ticket_service();
		else
			break;
	
	}
	cout << "reached end of program" << endl;

}

int manage_trains() {

	while(1) {	
		choice = 0;
		do {
			cout << "1. Add Train" << endl;
			cout << "2. Delete Train" << endl;
			cout << "3. Print Trains" << endl;
			cout << "4. Back" << endl;
		//      err = get_input_and_check(4);
		}while(get_input_and_check(4));
		cout << "reached end of program 2" << endl;
		
		if (choice == 1) {
			cout << "1" << endl;
			add_train();
		}
		else if (choice == 2) {
			cout << "2" << endl;
			delete_train();
		}
		else if (choice == 3) {
			cout << "3" << endl;
			print_trains();
		}
		else
			break;
	}	
	return 0;
}

int ticket_service() {
	while(1) {
                choice = 0;
                do {
                        cout << "1. Buy Tickets" << endl;
                        cout << "2. Back" << endl;
                }while(get_input_and_check(2));
                cout << "reached end of program 3" << endl;

                if (choice == 1) {
                        cout << "1" << endl;
                        buy_tickets();
                } else
                        break;
        }      
        return 0;
}

