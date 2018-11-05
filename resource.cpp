#include <iostream>
#include "resource.h"
using namespace std;

/*resource :: resource() {

}*/

void resource :: set_name(string input) {
	name = input;
}

string resource :: get_name() {
	return name;
}

/*book :: book() {

}*/

book :: book(string b_name) {
	set_name(b_name);
}

void book :: set_member_borrow(string m_borrow) {
	member_borrow = m_borrow;
}

string book :: get_member_borrow() {
	return member_borrow;
}

void book :: set_date_borrow(string d_borrow) {
	date_borrow = d_borrow;
}

string book :: get_date_borrow() {
	return date_borrow;
}

void book :: set_date_return(string d_return) {
	date_return = d_return;
}

string book :: get_date_return() {
	return date_return;
}