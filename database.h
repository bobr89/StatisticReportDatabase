#ifndef DATABASE_H
#define DATABASE_H
#include "profile.h"
using namespace std;

class Database{

	public:
		Database();
		~Database();
		Database(Database& other);
		void operator =(Database& other);
		void search(string name);
		void add(Profile& emp);
		void display_all();
		void remove(string name);
		void save(ostream& outs);
		void load(istream& ins);
		void sort_name();

	private:
		void make_bigger();
		int capacity;
		int used;
		Profile *data;
};

#endif