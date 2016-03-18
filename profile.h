#ifdef PROFILE_H
#define PROFILE_H
using namespace std;

class Profile{

	public:
		Profile();
		Profile(string name, string filter, string remark);
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