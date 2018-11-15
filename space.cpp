#include <iostream>
#include <string>
#include "space.h"
using namespace std;

space :: space() {
	name = "";
	time = 0;
	status = 0;
}

void space :: set_name(string input) {
	name = input;
}

string space :: get_name() {
	return name;
}

void space :: set_time(int input_time) {
	time = input_time;
}

int space :: get_time() {
	return time;
}

/*studyroom :: studyroom() {

}*/

void studyroom :: set_studyroom_number(int input_number) {
	studyroom_number = input_number;
}

int studyroom :: get_studyroom_number() {
	return studyroom_number;
}

/*seat :: seat() {

}*/

void seat :: set_seat_floor(int input_floor) {
	seat_floor = input_floor;
}

int seat :: get_seat_floor() {
	return seat_floor;
}