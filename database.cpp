#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "database.h"
using namespace std;

Database::Database(){

	used = 0;
	capacity = 3;
	data = new Profile[capacity];
}

Database::~Database(){

	delete[]data;
}

Database::Database(Database& other){

	used = other.used;
	capacity = other.capacity;
	data = new Profile[capacity];
	copy(other.data, other.data + used, data);
}

void Database:: operator =(Database& other){

	delete[] data;
	capacity = other.capacity;
	used = other.used;
	data = new Profile[capacity];
	copy(other.data, other.data + used, data);
}

void Database::search(string name){

	int num_found = 0;
	for (int i=0; i<used; i++){

		if(data[i].get_name() == name){
			cout << "Found Profile" << endl;
			data[i].output(cout);
			num_found = num_found + 1;
		}
	}

	if(num_found == 0){
		cout << "No profile found" << endl;
	}
}

void Database::add(Profile& emp){

	if(used >= capacity){
		make_bigger();
	}
	data[used] = emp;
	used++;
}

void Database::display_all(){

	for(int i=0; i<used; i++){
		data[i].output(cout);
	}
}

void Database::save(ostream& outs){

	sort_name();
	for(int i=0; i<used; i++){

		outs << data[i];
	}
}

void Database::load(istream& ins){

	Profile tmp;
	while(ins >> tmp){

		if(used >= capacity){
			make_bigger();
		}
		data[used] = tmp;
		used++;
	}
}

void Database::sort_name(){

	bool done = false;
	Profile tmp;
	while(!done){

		done = true;
		for(int i=0; i<used-1; i++){

			if(data[i].get_name() > data[i+1].get_name()){

				done = false;
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}
		}
	}
}

void Database::make_bigger(){

	Profile *tmp;
	tmp = new Profile[capacity + 3];
	copy(data, data+used, tmp);
	delete[] data;
	data = tmp;
	capacity = capacity + 3;
}

