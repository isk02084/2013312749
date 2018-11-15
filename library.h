#include <iostream>
#include <vector>
#include <string>
#include "member.h"
#include "resource.h"
#include "space.h"

using namespace std;

class library {
private:
	vector<book> books;
	vector<undergraduate> undergraduates;
	vector<studyroom> studyrooms;
	vector<seat> seats;

public:
	library();
	void bookshelf();
	void input();
	void database(int count, string d, string r_t, string r_n, string op, string m_t, string m_n);
	void output(int op_num, int return_code, string description);
	int dateToint(string date);
	string intTodate(int date);
	int dateToint2(string date2);
	int dateTohour(string date2);
};
