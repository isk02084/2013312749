#include <iostream>
#include <vector>
#include <string>
#include "member.h"
#include "resource.h"

using namespace std;

class library {
private:
	vector<book> books;
	vector<magazine> magazines;
	vector<e_book> e_books;
	vector<undergraduate> undergraduates;
	vector<graduate> graduates;
	vector<faculty> facultys;

public:
	library();
	void bookshelf();
	void input();
	void database(int count, string d, string r_t, string r_n, string op, string m_t, string m_n);
	void output(int op_num, int return_code, string description);
	int dateToint(string date);
	string intTodate(int date);
};
