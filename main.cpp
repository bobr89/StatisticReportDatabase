#include <iostream>
#include <fstream>
#include <string>
#include "profile.h"
#include "database.h"

using namespace std;

int menu();
int main(){

	Database database;
	Profile emp;
	string filename;
	cout << "Enter name of file (No file extension): ";

	getline(cin, filename);
	filename + ".txt";
	ifstream fin(filename.c_str());
	if(!fin.fail()){

		database.load(fin);
		fin.close();
		int choice;
		while(choice!=5){

			choice = menu();
			switch(choice){

				case 1:{
					cin >> emp;
					database.add(emp);
					break;
				}

				case 2:{
					string name;
					cout << "Enter name of profile to find: ";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					database.search(name);
					break;
				}

				case 3:{
					cout << "All profiles in the database." << endl;
					database.display_all();
					break;
				}

				case 4:{
					database.sort_name();
					cout << "Profile sorted by name." << endl;
					database.display_all();
					break;
				}

				case 5:{
					break;
				}

				default:{
					cout << "Not a valid input." << endl;
					break;
				}
			}
		}
		ofstream fout(filename.c_str());

		if(!fout.fail()){

			database.save(fout);
		}
		else{
			cout << "File could not open." << endl;
		}
		fout.close();
		cout << "Thank you for using database system." << endl;
	}
	else{
		cout << "File does not exist, creating new file." << endl;
		ofstream new_file(filename.c_str());
		new_file.close();
		main();
	}
	return 0;
}

int menu(){

	int choice;
	cout << "1. Add new profile" << endl;
	cout << "2. Search for profile by name" << endl;
	cout << "3. Display all profiles" << endl;
	cout << "4. Sort profile by name" << endl;
	cout << "5. Quit" << endl;
	cin >> choice;
	return choice;
}
