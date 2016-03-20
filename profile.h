#ifndef PROFILE_H
#define PROFILE_H
using namespace std;

class Profile{

	public:
		Profile();
		Profile(string new_name, string new_filter, string new_remark);
		string get_name(){
			return name;
		}
		string get_filter(){
			return filter;
		}
		string get_remark(){
			return remark;
		}
		void output(ostream& outs);
		void input(istream& ins);

	private:
		string name;
		string filter;
		string remark;
};

ostream& operator <<(ostream& outs, Profile& tmp);
istream& operator >>(istream& ins, Profile& tmp);

#endif
