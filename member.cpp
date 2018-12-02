#include <iostream>
#include <string>
#include <map>
#include "member.h"
using namespace std;

member :: member() {
	capacitor = 0;
}

void member :: set_name(string input) {
	name = input;
}

string member :: get_name() {
	return name;
}

void member :: set_capacitor(int cap){
	capacitor += cap;
}

int member :: get_capacitor(){
	return capacitor;
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

graduate :: graduate() {
	ban = false;
	date_ban = "";
	book_borrow = 0;
}

graduate :: graduate(string m_name) {
	ban = false;
	date_ban = "";
	book_borrow = 0;
	set_name(m_name);
}

void graduate :: set_list(string name, int date) {
	list.insert(make_pair(name,date));
}

void graduate :: erase_list(string name) {
	list.erase(name);
}

int graduate :: get_date(string name) {
	return list.find(name)->second;
}

void graduate :: set_ban(bool ban2) {
	ban = ban2;
}

bool graduate :: get_ban() {
	return ban;
}

void graduate :: set_date_ban(string date_ban2) {
	date_ban = date_ban2;
}

string graduate :: get_date_ban() {
	return date_ban;
}

bool graduate :: get_book_name(string name) {
	if(list.find(name) == list.end()) {
		return false;
	} return true;
}

void graduate :: set_borrow(int borrow) {
	book_borrow = borrow;
}

int graduate :: get_borrow() {
	return book_borrow;
}

int graduate :: get_min_date() {
	int min = 10000000;
	for(auto s : list) {
		if(s.second < min) min = s.second;
	}
	return min;
}

faculty :: faculty() {
	ban = false;
	date_ban = "";
	book_borrow = 0;
}

faculty :: faculty(string m_name) {
	ban = false;
	date_ban = "";
	book_borrow = 0;
	set_name(m_name);
}


void faculty :: set_list(string name, int date) {
	list.insert(make_pair(name,date));
}

void faculty :: erase_list(string name) {
	list.erase(name);
}

int faculty :: get_date(string name) {
	return list.find(name)->second;
}

void faculty :: set_ban(bool ban2) {
	ban = ban2;
}

bool faculty :: get_ban() {
	return ban;
}

void faculty :: set_date_ban(string date_ban2) {
	date_ban = date_ban2;
}

string faculty :: get_date_ban() {
	return date_ban;
}

bool faculty :: get_book_name(string name) {
	if(list.find(name) == list.end()) {
		return false;
	} return true;
}

void faculty :: set_borrow(int borrow) {
	book_borrow = borrow;
}

int faculty :: get_borrow() {
	return book_borrow;
}

int faculty :: get_min_date() {
	int min = 10000000;
	for(auto s : list) {
		if(s.second < min) min = s.second;
	}
	return min;
}