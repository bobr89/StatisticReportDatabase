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

	if(outs == cout){
		outs << "Name: " << name << endl;
		outs << "Filter: " << filter << endl;
		outs << "Remark: " << remark << endl;
	}
	else{
		outs << name << endl;
		outs << filter << endl;
		outs << remark << endl;
	}
}

void Profile::input(istream& ins){

	if(ins == cin){

		if(ins.peek() == '\n')ins.ignore();
		cout << "Name: ";
		getline(ins, name);
		
		cout << "Filter: ";
		getline(ins, filter);

		cout << "Remark: ";
		getline(ins, remark);
	}
	else{

		if(ins.peek() == '\n')ins.ignore();
	    getline(ins,name);
	    if(ins.peek() == '\n')ins.ignore();
	    ins >> (ins,filter);
	    if(ins.peek() == '\n')ins.ignore();
	    getline(ins,remark);
	}
}

ostream& operator <<(ostream& outs, Profile& tmp){

	tmp.output(outs);
	return outs;
}

istream& operator >>(istream& ins, Profile& tmp){

	tmp.input(ins);
	return ins;
}
