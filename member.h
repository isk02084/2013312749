#include <iostream>
#include <string>
#include <map>
using namespace std;

class member {
private:
	string name;
	int capacitor;
public:
	member();
	void set_name(string input);
	string get_name();
	void set_capacitor(int cap);
	int get_capacitor();
};

class undergraduate : public member{
private :
	map<string, int> list;
	bool ban;
	string date_ban;
	int book_borrow;
public : 
	undergraduate();
	undergraduate(string m_name);
	void set_list(string name,int date);
	void erase_list(string name);
	int get_date(string name);
	void set_ban(bool ban2);
	bool get_ban();
	void set_date_ban(string date_ban2);
	string get_date_ban();
	bool get_book_name(string name);
	void set_borrow(int borrow);
	int get_borrow();
	int get_min_date();
};

class graduate : public member{
private :
	map<string, int> list;
	bool ban;
	string date_ban;
	int book_borrow;
public : 
	graduate();
	graduate(string m_name);
	void set_list(string name,int date);
	void erase_list(string name);
	int get_date(string name);
	void set_ban(bool ban2);
	bool get_ban();
	void set_date_ban(string date_ban2);
	string get_date_ban();
	bool get_book_name(string name);
	void set_borrow(int borrow);
	int get_borrow();
	int get_min_date();
};

class faculty : public member{
private :
	map<string, int> list;
	bool ban;
	string date_ban;
	int book_borrow;
public : 
	faculty();
	faculty(string m_name);
	void set_list(string name,int date);
	void erase_list(string name);
	int get_date(string name);
	void set_ban(bool ban2);
	bool get_ban();
	void set_date_ban(string date_ban2);
	string get_date_ban();
	bool get_book_name(string name);
	void set_borrow(int borrow);
	int get_borrow();
	int get_min_date();
};
