#include <iostream>
#include <string>
#include "member.h"
using namespace std;

/*member :: member() {

}*/

void member :: set_name(string input) {
	name = input;
}

string member :: get_name() {
	return name;
}

undergraduate :: undergraduate() {
	date = "";
	ban = false;
	date_ban = "";
	book_name = "";
	book_borrow = 0;
}

undergraduate :: undergraduate(string m_name) {
	date = "";
	ban = false;
	date_ban = "";
	book_name = "";
	book_borrow = 0;
	set_name(m_name);
}

void undergraduate :: set_date(string date2) {
	date = date2;
}

string undergraduate :: get_date() {
	return date;
}

void undergraduate :: set_ban(bool ban2) {
	ban = ban2;
}

bool undergraduate :: get_ban() {
	return ban;
}

void undergraduate :: set_date_ban(string date_ban2) {
	date_ban = date_ban2;
}

string undergraduate :: get_date_ban() {
	return date_ban;
}

void undergraduate :: set_book_name(string name) {
	book_name = name;
}

string undergraduate :: get_book_name() {
	return book_name;
}

void undergraduate :: set_borrow(int borrow) {
	book_borrow = borrow;
}

int undergraduate :: get_borrow() {
	return book_borrow;
}

