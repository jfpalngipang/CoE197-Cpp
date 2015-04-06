#include <iostream>
#include <map>
#include "List"

using namespace std;
int choice;
int manage_trains();
int ticket_service();
void add_train();
void delete_train();
void print_trains();
void searchAvailbleTrains(string, string);
int computeCost(char, int, int);


map<string, int> stations_map;


class Train {
	protected:
		int train_id;
		int capacity;
		int occupied;
		char type;
		int cost;

		

	public:
		Train();
		~Train();
		virtual void showTrainInfo() = 0;
		virtual int getCost(int, int) = 0;
		int getTrainId();
		int getCapacity();
		int getOccupied();
		void setTrainId(int);
		void setCapacity(int);
		void setOccupied(int);
		char getType();
		int printCost();
		//void setType(char);
		//void setStations();
};

Train::Train() {

}
Train::~Train() {
	
}
int Train::printCost() {
	return cost;
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
char Train::getType() {
	return type;
}
/*
void setType(char t) {
	type = t;
}
*/

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
	Train* searchList(char);
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

Train* List::searchList(char type) {
	curr = head;

	while (curr != NULL) {
		//return curr->train->getType();
		
		if(curr->train->getType() == type) {
				return curr->train;
			
		}
		curr = curr->next;
	}
	return 0;
}

List trains_list;


class N: public Train {
	public:
		void showTrainInfo();
		int getCost(int, int);
		void setType(char);
	
};

int N::getCost(int orig_int, int dest_int){
	int cost;
	cost = (dest_int - orig_int) * 3;

	return cost;
}

void N::showTrainInfo() {
		getTrainId();
		getType();
			
}
void N::setType(char t){
	type = t;
}

class A: public Train {

	public:
		void showTrainInfo();
		int getCost(int, int);
		void setType(char);

};
int A::getCost(int orig_int, int dest_int){
	int cost;
	cost = ((((dest_int - orig_int)/2)*3) + ((dest_int - orig_int)/2));

	return cost;
}
void A::showTrainInfo() {
		getTrainId();
		getType();
			
}
void A::setType(char t){
	type = t;
}
class B: public Train {
		public:
		void showTrainInfo();
		int getCost(int, int);
		void setType(char);
};
int B::getCost(int orig_int, int dest_int){
	int cost;
	cost = ((((dest_int - orig_int)/2)*3) + ((dest_int - orig_int)/2));

	return cost;
}

void B::showTrainInfo() {
		getTrainId();
		getType();
			
}
void B::setType(char t){
	type = t;
}
class S: public Train {
		public:
		void showTrainInfo();
		int getCost(int, int);
		void setType(char);

};
int S::getCost(int orig_int, int dest_int){
	int cost;
	cost = (((dest_int-orig_int-6)*3) + 6);

	return cost;
}
void S::showTrainInfo() {
		getTrainId();
		getType();
			
}
void S::setType(char t){
	type = t;
}

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
/*************************
Ticket Buying
*************************/
void buy_tickets() {
	Ticket t;
	string orig, dest;

	cout << "Origin: " << endl;
	cin >> orig;
	cout << "Destination: " << endl;
	cin >> dest;

	searchAvailbleTrains(orig, dest);

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
		n1->setType('N');
		trains_list.addNode(n1);
	} else if (new_type == 'A' || new_type == 'a') {
		A* a1;
		a1 = new A();
		a1->setTrainId(new_train_id);
		a1->setCapacity(new_capacity);
		a1->setOccupied(0);
		a1->setType('A');
		trains_list.addNode(a1);
	} else if (new_type == 'B' || new_type == 'b') {
		B* b1;
		b1 = new B();
		b1->setTrainId(new_train_id);
		b1->setCapacity(new_capacity);
		b1->setOccupied(0);
		b1->setType('B');
		trains_list.addNode(b1);
	} else if (new_type == 'S' || new_type == 's') {
		S* s1;
		s1 = new S();
		s1->setTrainId(new_train_id);
		s1->setCapacity(new_capacity);
		s1->setOccupied(0);
		s1->setType('S');
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

                if (choice == 1) {
                        buy_tickets();
                } else
                        break;
        }      
    return 0;
}

void searchAvailbleTrains(string orig, string dest) {
	int orig_int, dest_int, dist_int;
	char type;
	int chosen_train_id;
	Train *chosen_train;

	stations_map["1A"] = 1;
	stations_map["1B"] = 2;
	stations_map["2A"] = 3;
	stations_map["2B"] = 4;
	stations_map["3A"] = 5;
	stations_map["3B"] = 6;
	stations_map["4A"] = 7;
	stations_map["4B"] = 8;
	stations_map["5A"] = 9;
	stations_map["5B"] = 10;

	orig_int = stations_map[orig];
	dest_int = stations_map[dest];


	dist_int = dest_int - orig_int;
	if(((dist_int % 2) == 0) && (dist_int < 7)) {
		if((orig_int % 2) == 0 ){
			type = 'B';
			chosen_train = trains_list.searchList(type);
			chosen_train->getCost(orig_int, dest_int);
			if(chosen_train->getTrainId() == 0){
				type = 'N';
				chosen_train = trains_list.searchList(type);
				chosen_train->getCost(orig_int, dest_int);
				if(chosen_train->getTrainId() == 0){
					cout << "no train" << endl;
				} else {
					cout << "N" << endl;
					cout << "Train ID: " << chosen_train->getTrainId() << endl;
					cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
				}
			}else {

				cout << "B" << endl;
				cout << "Train ID: " << chosen_train->getTrainId() << endl;
				cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
			}
		} else {
			type = 'A';
			chosen_train = trains_list.searchList(type);
			chosen_train->getCost(orig_int, dest_int);

			if(chosen_train->getTrainId() == 0){
				type = 'N';
				chosen_train = trains_list.searchList(type);
				chosen_train->getCost(orig_int, dest_int);
				if(chosen_train->getTrainId() == 0){
					cout << "no train" << endl;
				} else {
					cout << "N" << endl;
					cout << "Train ID: " << chosen_train->getTrainId() << endl;
					cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
				}
			}else {
				cout << "A" << endl;
				cout << "Train ID: " << chosen_train->getTrainId() << endl;
				cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
			}
		}

	}else if(((dist_int % 2) != 0) && (dist_int <= 7)){
		type = 'N';
		chosen_train = trains_list.searchList(type);
		chosen_train->getCost(orig_int, dest_int);
		if(chosen_train->getTrainId() == 0){
			cout << "no train" << endl;
		} else {
			cout << "N" << endl;
			cout << "Train ID: " << chosen_train->getTrainId() << endl;
			cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
		}

	} else {
		type = 'S';
		chosen_train = trains_list.searchList(type);
		chosen_train->getCost(orig_int, dest_int);
		if(chosen_train->getTrainId() == 0) {
			if((orig_int % 2 ==0) && (dest_int % 2 ==0)) {
				type = 'B';
				chosen_train = trains_list.searchList(type);
				chosen_train->getCost(orig_int, dest_int);
				if(chosen_train->getTrainId() == 0){
					type = 'N';
					chosen_train = trains_list.searchList(type);
					chosen_train->getCost(orig_int, dest_int);
					if(chosen_train->getTrainId() == 0){
						cout << "no train" << endl;
					}else {
						cout << "N" << endl;
						cout << "Train ID: " << chosen_train->getTrainId() << endl;
						cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
					}
				}else{
					cout << "B" << endl;
					cout << "Train ID: " << chosen_train->getTrainId() << endl;
					cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
				}
			} else if ((orig_int % 2 !=0) && (dest_int % 2 !=0)){
				type = 'A';
				chosen_train = trains_list.searchList(type);
				chosen_train->getCost(orig_int, dest_int);
				if(chosen_train->getTrainId() == 0){
					type = 'N';
					chosen_train = trains_list.searchList(type);
					chosen_train->getCost(orig_int, dest_int);
					if(chosen_train->getTrainId() == 0){
						cout << "no train" << endl;
					}else {
						cout << "N" << endl;
						cout << "Train ID: " << chosen_train->getTrainId() << endl;
						cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
					}
				}else{
					cout << "A" << endl;
					cout << "Train ID: " << chosen_train->getTrainId() << endl;
					cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
				}
			} else {
				type = 'N';
				chosen_train = trains_list.searchList(type);
				chosen_train->getCost(orig_int, dest_int);
				if(chosen_train->getTrainId() == 0){
					cout << "no train" << endl;
				}else{
					cout << "N" << endl;
					cout << "Train ID: " << chosen_train->getTrainId() << endl;
					cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
				}
			}
		} else {
			cout << "S" << endl;
			cout << "Train ID: " << chosen_train->getTrainId() << endl;
			cout << "Cost: " << chosen_train->getCost(orig_int, dest_int) << endl;
		}
		
	}


	//cout << trains_list.searchList(type) << endl;

}
/*
int computeCost(char type, int orig_int, int dest_int) {
	int cost;


	if(type == 'N') {
		cost = (dest_int - orig_int) * 3;
	} else if((type == 'A') || (type == 'B')) {
		cost = ((((dest_int - orig_int)/2)*3) + ((dest_int - orig_int)/2));
	} else {
		cost = (((dest_int-orig_int-6)*3) + 6);
	}
	return cost;

}
*/



