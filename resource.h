#include <iostream>
#include <string>
using namespace std;

class resource {
private:
	string name;
public:
	void set_name(string input);
	string get_name();
};

class book : public resource {
private :
	string member_borrow;
	string date_borrow;
	string date_return;

public : 
	book(string b_name);
	void set_member_borrow(string m_borrow);
	string get_member_borrow();
	void set_date_borrow(string d_borrow);
	string get_date_borrow();
	void set_date_return(string d_return);
	string get_date_return();
};

class magazine : public resource {
private :
	string member_borrow;
	string date_borrow;
	string date_return;

public : 
	magazine(string b_name);
	void set_member_borrow(string m_borrow);
	string get_member_borrow();
	void set_date_borrow(string d_borrow);
	string get_date_borrow();
	void set_date_return(string d_return);
	string get_date_return();
};

class e_book : public resource {
private :
	string member_borrow;
	string date_borrow;
	string date_return;
	int size;

public : 
	e_book(string b_name);
	void set_member_borrow(string m_borrow);
	string get_member_borrow();
	void set_date_borrow(string d_borrow);
	string get_date_borrow();
	void set_date_return(string d_return);
	string get_date_return();
	void set_size(int i_size);
	int get_size();
};