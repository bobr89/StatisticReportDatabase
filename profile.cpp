#include <iostream>
#include "profile.h"
using namespace std;

Profile::Profile(){}

Profile::Profile(string new_name, string new_filter, string new_remark){

	name = new_name;
	filter = new_filter;
	remark = new_remark;
}

void Profile::output(ostream& outs){

	outs << "Name: " << name;
	outs << "Filter: " << filter;
	outs << "Remark: " << remark;
}

void Profile::input(istream& ins){

	cout << "Name: ";
	getline(ins, name);
	cout << "Filter: ";
	getline(ins, filter);
	cout << "Remark: ";
	getline(ins, remark);
}

ostream& operator <<(ostream& outs, Profile& tmp){

	tmp.output(outs);
	return outs;
}

istream& operator >>(istream& ins, Profile& tmp){

	tmp.input(ins);
	return ins;
}
