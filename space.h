#include <iostream>
#include <string>
using namespace std;

class space {
private:
	string name;
	int time;
	int status;			// 0 : not use  1: using   2:use but no people(empty)
public:
	space();
	void set_name(string input);
	string get_name();
	void set_time(int input_time);
	int get_time();

};

class studyroom : public space{
private :
	int studyroom_number;
public : 

	void set_studyroom_number(int input_number);
	int get_studyroom_number();
	
};

class seat : public space{
private :
	int seat_floor;
public : 

	void set_seat_floor(int input_floor);
	int get_seat_floor();
};