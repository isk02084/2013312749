#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
using namespace std;

library :: library() {
	bookshelf();
	input();
}

void library :: bookshelf() {
	ifstream input_resource;
	input_resource.open("resource.dat");
	string line;
	input_resource >> line;
	input_resource >> line;

	while(input_resource >> line) {
		input_resource >> line;
		book A(line);
		books.push_back(A);
	}
/*
	for(auto s : books) {
		cout << s.get_name() << endl;
	}
*/
	input_resource.close();
}

void library :: input() {
	ifstream input_file;
	ofstream output_file;
	input_file.open("input.dat");
	output_file.open("output.dat");
	string line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file >> line;

	int count = 1;
	string date, resource_type, resource_name, operation, member_type, member_name;
	output_file << "Op_#\tReturn_code\tDescription" << endl;
	while(input_file >> date) {
		input_file >> resource_type;
		input_file >> resource_name;
		input_file >> operation;
		input_file >> member_type;
		input_file >> member_name;
		database(count, date, resource_type, resource_name, operation, member_type, member_name);
		count ++;
		//cout << date << "\t" << resource_type << "\t" << resource_name << "\t" << operation << "\t" << member_type << "\t" << member_name << "\t" << endl;
	}

	input_file.close();
	output_file.close();

	
}

void library :: database(int count, string d, string r_t, string r_n, string op, string m_t, string m_n) {
	//code 1
	int flag = 0;
	for( auto s : books) {
		if(s.get_name() == r_n) flag = 1;
	}
	if(flag == 0) {
		output(count, 1, "Non exist resource.");
		return;
	}

	//code 2
	string error;
	flag = 0;
	if(op == "B") {
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(s.get_borrow() > 0) {
					error = "Exceeds your possible number of borrow. Possible # of borrows: 1";
					output(count, 2, error);
					return;
				} 
			}
		}	
	}

	//code 3
	flag = 0;
	if(op == "R") {
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				flag = 1;
				if(s.get_book_name() != r_n) {
					output(count, 3, "You did not borrow this book.");
					return;
				}
			}
		}
		if(flag = 0) {
			output(count, 3, "You did not borrow this book.");
			return;
		}
	}

	//code 4
	if(op == "B") {
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(s.get_book_name() == r_n) {
					error = "You already borrow this book at " + s.get_date();
					output(count, 4, error);
					return;
				}
			}
		}
	}

	//code 5
	if(op == "B") {
		for (auto s : books) {
			if(s.get_name() == r_n) {
				if(s.get_member_borrow() != m_n && s.get_member_borrow() != "") {
					error = "Other member already borrowed this book. This book will be returned at " + s.get_date_return();
					output(count, 5, error);
					return;
				}
			} 
		}
	}

	//code 6
	if(op == "B") {
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(s.get_ban() == true && dateToint(s.get_date_ban()) >= dateToint(d)) {
					error = "Restricted member until " + s.get_date_ban();
					output(count, 6, error);
					return;
				}
			}
		}
	}

	//code 7
	if(op == "R") {
		int i = 0;
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(dateToint(s.get_date())+13 < dateToint(d)) {
					error = "Delayed return. You'll be restricted until " + intTodate(2*dateToint(d) - dateToint(s.get_date())-13);
					s.set_date_ban(intTodate(2*dateToint(d) - dateToint(s.get_date())-13));
					s.set_date("");
					s.set_ban(true);
					s.set_book_name("");
					s.set_borrow(s.get_borrow()-1);
					undergraduates.push_back(s);
					undergraduates.erase(undergraduates.begin() + i);
					i = 0;
					for (auto s : books) {
						if(s.get_name() == r_n) {
							s.set_member_borrow("");
							s.set_date_borrow("");
							s.set_date_return("");
							books.push_back(s);
							books.erase(books.begin() + i);
						}
						i ++;
					}
					output(count, 7, error);
					return;
				}
			}
			i++;
		}
	}

	//code 0
	flag = 0;
	if(op == "B") {
		int i = 0;
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				s.set_date(d);
				s.set_ban(false);
				s.set_date_ban("");
				s.set_book_name(r_n);
				s.set_borrow(s.get_borrow()+1);
				undergraduates.push_back(s);
				undergraduates.erase(undergraduates.begin() + i);
				flag = 1;
			}
			i ++;
		}
		if(flag == 0) {
			undergraduate A(m_n);
			A.set_date(d);
			A.set_ban(false);
			A.set_date_ban("");
			A.set_book_name(r_n);
			A.set_borrow(A.get_borrow()+1);
			undergraduates.push_back(A);
		}
		i = 0;
		for (auto s : books) {
			if(s.get_name() == r_n) {
				s.set_member_borrow(m_n);
				s.set_date_borrow(d);
				s.set_date_return(intTodate(dateToint(d)+13));
				books.push_back(s);
				books.erase(books.begin() + i);
			}
			i ++;
		}
		output(count, 0, "Success.");
	}

	else if(op == "R") {
		int i = 0;
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				s.set_date("");
				s.set_ban(false);
				s.set_date_ban("");
				s.set_book_name("");
				s.set_borrow(s.get_borrow()-1);
				undergraduates.push_back(s);
				undergraduates.erase(undergraduates.begin() + i);
			}
			i++;
		}
		i = 0;
		for (auto s : books) {
			if(s.get_name() == r_n) {
				s.set_member_borrow("");
				s.set_date_borrow("");
				s.set_date_return("");
				books.push_back(s);
				books.erase(books.begin() + i);
			} 
			i++;
		}
		output(count, 0, "Success.");
	}

}

void library :: output(int op_num, int return_code, string description) {
	ofstream file;
	file.open("output.dat", ios::app);
	file << op_num << "\t" << return_code << "\t" << description << endl;
	file.close();
}

int library :: dateToint(string date) {

	string year, month, day;

	/*cout << date[0] << date[1] <<endl;
	cout << date[3] << date[4] <<endl;
	cout << date[6] << date[7] <<endl;*/

	year = date[0];
	year += date[1];
	month = date[3];
	month +=date[4];
	day = date[6];
	day += date[7];



	//cout << year << month << day << endl;
	int result = stoi(year) * 360 + stoi(month)*30 + stoi(day);
	//cout << result << endl;
	return result;
}

string library :: intTodate(int date) {
	string year, month, day;
	year = to_string(date/360);
	if(year.length()==1) year = "0" + year;
	month = to_string((date%360)/30);
	if(month.length()==1) month = "0" + month;
	day = to_string((date%360)%30);
	if(day.length()==1) day = "0" + day;

	//cout << year + "/" + month + "/" + day << endl;
	return year + "/" + month + "/" + day;
}