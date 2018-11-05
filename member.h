#include <iostream>
#include <string>
using namespace std;

class member {
private:
	string name;
public:
	void set_name(string input);
	string get_name();
};

class undergraduate : public member{
private :
	string date;
	bool ban;
	string date_ban;
	string book_name;
	int book_borrow;
public : 
	undergraduate();
	undergraduate(string m_name);
	void set_date(string date2);
	string get_date();
	void set_ban(bool ban2);
	bool get_ban();
	void set_date_ban(string date_ban2);
	string get_date_ban();
	void set_book_name(string name);
	string get_book_name();
	void set_borrow(int borrow);
	int get_borrow();
};
