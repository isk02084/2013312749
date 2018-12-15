#include <iostream>
#include <fstream>
#include <string>
#include "library.h"

using namespace std;

library :: library() {
	day_check = 0;
	int i;
	for(i=0;i<10;i++){                  //make studyroom
		studyroom S;
		S.set_studyroom_number(i+1);
		studyrooms.push_back(S);
	}
	int j;
	for(i=0;i<3;i++){				//make seat
		for(j=0;j<50;j++){
			seat T;
			T.set_seat_floor(i+1);
			seats.push_back(T);
		}
	}

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
		if(line == "Book"){
			input_resource >> line;
			book A(line);
			books.push_back(A);
		}
		else if(line == "Magazine"){
			input_resource >> line;
			magazine A(line);
			magazines.push_back(A);
		}
		else if(line == "E-book"){
			input_resource >> line;
			string save_name(line, 0, line.find('['));
			string save_capacitor(line, line.find('[')+1, line.find(']')-line.find('[')-1);
			e_book A(save_name);
			A.set_size(stoi(save_capacitor));
			e_books.push_back(A);
		}
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
	ifstream input_file2;
	ofstream output_file;
	input_file.open("input.dat");
	input_file2.open("space.dat");
	output_file.open("output.dat");
	string line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file >> line;
	input_file2 >> line;
	input_file2 >> line;
	input_file2 >> line;
	input_file2 >> line;
	input_file2 >> line;
	input_file2 >> line;
	input_file2 >> line;
	input_file2 >> line;

	int count = 1;
	string date, resource_type, resource_name, operation, member_type, member_name;
	string date2, space_type, space_number, operation2, member_type2, member_name2, number_of_member, in_time;
	output_file << "Op_#\tReturn_code\tDescription" << endl;
	int flag=0;
	int flag_book_file=0;
	int flag_space_file=0;
	while(1) {
		
		if((flag == 0 || flag == 1) && flag_book_file == 0) {
			if(!(input_file >> date)) {
				flag_book_file = 1;
				date = "99/12/30";
			}
		}

		if((flag == 0 || flag == 2) && flag_space_file == 0) {
			if(!(input_file2 >> date2)){
				flag_space_file = 1;
				date2 = "9999/12/30/10";
			}
			if(day_check ==0 ) {
				day_check = dateToint2(date2);
			}
		}

		if(flag_book_file ==1 && flag_space_file ==1){
			break;
		}
		int int_date = dateToint(date);
		int int_date2 = dateToint2(date2);

		if(int_date <= int_date2){
			input_file >> resource_type;
			input_file >> resource_name;
			input_file >> operation;
			input_file >> member_type;
			input_file >> member_name;
			flag = 1;

			database(count, date, resource_type, resource_name, operation, member_type, member_name);
		}
		else{
			input_file2 >> space_type;
			input_file2 >> space_number;
			input_file2 >> operation2;
			input_file2 >> member_type2;
			input_file2 >> member_name2;
			if(operation2 == "B") {
				input_file2 >> number_of_member;
				input_file2 >> in_time;
			} else {
				number_of_member="0";
				in_time="0";
			}
			flag = 2;
			
			int check = 0;
			try{
				if(dateToint2(date2) <= dateToint("09/12/30")){
					check = 1;
					throw check;
				}
				else if(space_type != "StudyRoom" && space_type != "Seat"){
					check = 2;
					throw check;
				}
				else if(operation2 != "B" && operation2 != "R" && operation2 != "E" && operation2 != "C"){
					check = 3;
					throw check;
				}
				else if(member_type2 != "Undergraduate" && member_type2 != "Graduate" && member_type2 != "Faculty"){
					check = 4;
					throw check;
				}

				int ii;
				int flag2 = 0;
				string jj;
				for(ii = 0 ; ii<10; ii++){
					jj = to_string(ii);
					if(member_name2.find(jj) != -1){
						flag2 = 1;
					}
				}
				

				if(flag2 == 1){
					check = 5;
					throw check;
				}
				else if(operation2 == "B" && stoi(in_time) <= 0){
					check = 6;
					throw check;
				}
				else{
					emptyorclear(date2);
					space_database(count, date2, space_type, space_number, operation2, member_type2, member_name2, stoi(number_of_member), stoi(in_time));
				}
				
			} catch(int expn){
				char x;
				while(1){
					input_file2.get(x);
					if(x=='\n') break;
				}
				if(expn == 1){
					output(count, -1, "Date out of range");
				}
				else if(expn == 2){
					output(count, -1, "Non-exist space type");
				}
				else if(expn == 3){
					output(count, -1, "Non-exist operation");
				}
				else if(expn == 4){
					output(count, -1, "Non-exist member type");
				}
				else if(expn == 5){
					output(count, -1, "Member name with numbers");
				}
				else if(expn == 6){
					output(count, -1, "Negative time");
				}
			}
			

		}

		
		count ++;
		//cout << date << "\t" << resource_type << "\t" << resource_name << "\t" << operation << "\t" << member_type << "\t" << member_name << "\t" << endl;
	}

	input_file.close();
	input_file2.close();

	output_file.close();

	
}

void library :: database(int count, string d, string r_t, string r_n, string op, string m_t, string m_n) {
	int mag_y;
	int mag_m;
	string mag_n;
	int y = dateToint(d)/360;
	int m = (dateToint(d)%360)/30+1;
	//code 1
	int flag = 0;
	if(r_t == "Magazine"){
		string a(r_n, 0, r_n.find('['));
		mag_n = a;
		string b(r_n, r_n.find('[')+1,2);
		mag_y = stoi(b);
		string c(r_n,r_n.find('/')+1,2);
		mag_m = stoi(c);
	}
	for( auto s : books) {
		if(s.get_name() == r_n) flag = 1;
	}
	for( auto s : magazines) {
		if(s.get_name() == mag_n && (y*12+m) - (mag_y*12+mag_m) < 12 && (y*12+m) - (mag_y*12+mag_m) >= 0) flag = 1;
		else if(s.get_name() == mag_n && (y*12+m) - (mag_y*12+mag_m) >= 12 && op=="R") flag =1;
	}
	for( auto s : e_books) {
		if(s.get_name() == r_n) flag = 1;
	}
	if(flag == 0) {
		output(count, 1, "Non exist resource.");
		return;
	}

	//code 2
	string error;
	flag = 0;
	if(op == "B" && r_t != "E-book") {
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(s.get_borrow() > 0) {
					error = "Exceeds your possible number of borrow. Possible # of borrows: 1";
					output(count, 2, error);
					return;
				} 
			}
		}
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				if(s.get_borrow() > 4) {
					error = "Exceeds your possible number of borrow. Possible # of borrows: 5";
					output(count, 2, error);
					return;
				} 
			}
		}
		for (auto s : facultys) {
			if(s.get_name() == m_n) {
				if(s.get_borrow() > 9) {
					error = "Exceeds your possible number of borrow. Possible # of borrows: 10";
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
				if(s.get_book_name(r_n) == false) {
					output(count, 3, "You did not borrow this book.");
					return;
				}
			}
		}
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				flag = 1;
				if(s.get_book_name(r_n) == false) {
					output(count, 3, "You did not borrow this book.");
					return;
				}
			}
		}
		for (auto s : facultys) {
			if(s.get_name() == m_n) {
				flag = 1;
				if(s.get_book_name(r_n) == false) {
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
		int i =0;
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(s.get_book_name(r_n) == true) {
					if(r_t == "E-book" && s.get_date(r_n)+13 < dateToint(d)) {
						s.erase_list(r_n);
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(-k.get_size());
						}
						undergraduates.push_back(s);
						undergraduates.erase(undergraduates.begin() + i);
						break;
					} else {
						error = "You already borrow this book at " + intTodate(s.get_date(r_n));
						output(count, 4, error);
						return;
					}
				}
			}
			i++;
		}
		i = 0;
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				if(s.get_book_name(r_n) == true) {
					if(r_t == "E-book" && s.get_date(r_n)+29 < dateToint(d)) {
						s.erase_list(r_n);
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(-k.get_size());
						}
						graduates.push_back(s);
						graduates.erase(graduates.begin() + i);
						break;
					} else {
						error = "You already borrow this book at " + intTodate(s.get_date(r_n));
						output(count, 4, error);
						return;
					}
				}
			}
			i++;
		}
		i = 0;
		for (auto s : facultys) {
			if(s.get_name() == m_n) {
				if(s.get_book_name(r_n) == true) {
					if(r_t == "E-book" && s.get_date(r_n)+29 < dateToint(d)) {
						s.erase_list(r_n);
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(-k.get_size());
						}
						facultys.push_back(s);
						facultys.erase(facultys.begin() + i);
						break;
					} else {
						error = "You already borrow this book at " + intTodate(s.get_date(r_n));
						output(count, 4, error);
						return;
					}
				}
			}
			i++;
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
		for (auto s : magazines) {
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
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				if(s.get_ban() == true && dateToint(s.get_date_ban()) >= dateToint(d)) {
					error = "Restricted member until " + s.get_date_ban();
					output(count, 6, error);
					return;
				}
			}
		}
		for (auto s : facultys) {
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
				if(s.get_date(r_n)+13 < dateToint(d)) {
					error = "Delayed return. You'll be restricted until " + intTodate(2*dateToint(d) - s.get_date(r_n)-13);
					s.set_date_ban(intTodate(2*dateToint(d) - s.get_date(r_n)-13));
					s.set_ban(true);
					s.set_borrow(s.get_borrow()-1);
					s.erase_list(r_n);
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
					for (auto s : magazines) {
						if(s.get_name() == r_n) {
							s.set_member_borrow("");
							s.set_date_borrow("");
							s.set_date_return("");
							magazines.push_back(s);
							magazines.erase(magazines.begin() + i);
						}
						i ++;
					}
					output(count, 7, error);
					return;
				}
			}
			i++;
		}
		i = 0;
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				if(s.get_date(r_n)+29 < dateToint(d)) {
					error = "Delayed return. You'll be restricted until " + intTodate(2*dateToint(d) - s.get_date(r_n)-29);
					s.set_date_ban(intTodate(2*dateToint(d) - s.get_date(r_n)-29));
					s.erase_list(r_n);
					s.set_ban(true);
					s.set_borrow(s.get_borrow()-1);
					graduates.push_back(s);
					graduates.erase(graduates.begin() + i);
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
					for (auto s : magazines) {
						if(s.get_name() == r_n) {
							s.set_member_borrow("");
							s.set_date_borrow("");
							s.set_date_return("");
							magazines.push_back(s);
							magazines.erase(magazines.begin() + i);
						}
						i ++;
					}
					output(count, 7, error);
					return;
				}
			}
			i++;
		}
		i = 0;
		for (auto s : facultys) {
			if(s.get_name() == m_n) {
				if(s.get_date(r_n)+29 < dateToint(d)) {
					error = "Delayed return. You'll be restricted until " + intTodate(2*dateToint(d) - s.get_date(r_n)-29);
					s.set_date_ban(intTodate(2*dateToint(d) - s.get_date(r_n)-29));
					s.erase_list(r_n);
					s.set_ban(true);
					s.set_borrow(s.get_borrow()-1);
					facultys.push_back(s);
					facultys.erase(facultys.begin() + i);
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
					for (auto s : magazines) {
						if(s.get_name() == r_n) {
							s.set_member_borrow("");
							s.set_date_borrow("");
							s.set_date_return("");
							magazines.push_back(s);
							magazines.erase(magazines.begin() + i);
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

	//code 15
	if(op == "B" && r_t == "E-book") {
		int size_in = 0;
		for(auto s : e_books) {
			if(s.get_name() == r_n){
				size_in = s.get_size();
			}
		}
		for (auto s : undergraduates) {
			if(s.get_name() == m_n) {
				if(s.get_capacitor()+size_in > 100) {
					output(count, 15, "Exceeds your storage capacity");
					return;
				}
			}
		}
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				if(s.get_capacitor()+size_in > 500) {
					output(count, 15, "Exceeds your storage capacity");
					return;
				}
			}
		}
		for (auto s : facultys) {
			if(s.get_name() == m_n) {
				if(s.get_capacitor()+size_in > 1000) {
					output(count, 15, "Exceeds your storage capacity");
					return;
				}
			}
		}
	}

	//code 16
	if(op == "B") {
		for (auto s : graduates) {
			if(s.get_name() == m_n) {
				if(s.get_min_date()+29 < dateToint(d)) {
					output(count, 16, "Previously borrowed books are overdue, so borrow is limited.");
					return;
				}
			}
		}
		for (auto s : facultys) {
			if(s.get_name() == m_n) {
				if(s.get_min_date()+29 < dateToint(d)) {
					output(count, 16, "Previously borrowed books are overdue, so borrow is limited.");
					return;
				}
			}
		}
	}

	//code 0
	flag = 0;
	if(op == "B") {
		if(m_t == "Undergraduate") {
			int i = 0;
			for (auto s : undergraduates) {
				if(s.get_name() == m_n) {
					s.set_ban(false);
					s.set_date_ban("");
					s.set_list(r_n,dateToint(d));
					s.set_borrow(s.get_borrow()+1);
					if(r_t == "E-book") {
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(k.get_size());
						}
						s.set_borrow(s.get_borrow()-1);
					}
					undergraduates.push_back(s);
					undergraduates.erase(undergraduates.begin() + i);
					flag = 1;
				}
				i ++;
			}
			if(flag == 0) {
				undergraduate A(m_n);
				A.set_ban(false);
				A.set_date_ban("");
				A.set_list(r_n, dateToint(d));
				A.set_borrow(A.get_borrow()+1);
				if(r_t == "E-book") {
					for(auto k : e_books) {
						if(k.get_name() == r_n) A.set_capacitor(k.get_size());
					}
					A.set_borrow(A.get_borrow()-1);
				}
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
			if(r_t == "Magazine") {
				magazine s(r_n);
				s.set_member_borrow(m_n);
				s.set_date_borrow(d);
				s.set_date_return(intTodate(dateToint(d)+13));
				magazines.push_back(s);
			}
			output(count, 0, "Success.");
		}
		else if(m_t == "Graduate"){
			int i = 0;
			for (auto s : graduates) {
				if(s.get_name() == m_n) {
					s.set_list(r_n, dateToint(d));
					s.set_ban(false);
					s.set_date_ban("");
					s.set_borrow(s.get_borrow()+1);
					if(r_t == "E-book") {
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(k.get_size());
						}
						s.set_borrow(s.get_borrow()-1);
					}
					graduates.push_back(s);
					graduates.erase(graduates.begin() + i);
					flag = 1;
				}
				i ++;
			}
			if(flag == 0) {
				graduate A(m_n);
				A.set_list(r_n, dateToint(d));
				A.set_ban(false);
				A.set_date_ban("");
				A.set_borrow(A.get_borrow()+1);
				if(r_t == "E-book") {
					for(auto k : e_books) {
						if(k.get_name() == r_n) A.set_capacitor(k.get_size());
					}
					A.set_borrow(A.get_borrow()-1);
				}
				graduates.push_back(A);
			}
			i = 0;
			for (auto s : books) {
				if(s.get_name() == r_n) {
					s.set_member_borrow(m_n);
					s.set_date_borrow(d);
					s.set_date_return(intTodate(dateToint(d)+29));
					books.push_back(s);
					books.erase(books.begin() + i);
				}
				i ++;
			}
			if(r_t == "Magazine") {
				magazine s(r_n);
				s.set_member_borrow(m_n);
				s.set_date_borrow(d);
				s.set_date_return(intTodate(dateToint(d)+29));
				magazines.push_back(s);
			}
			output(count, 0, "Success.");
		}
		else if(m_t == "Faculty"){
			int i = 0;
			for (auto s : facultys) {
				if(s.get_name() == m_n) {
					s.set_list(r_n, dateToint(d));
					s.set_ban(false);
					s.set_date_ban("");
					s.set_borrow(s.get_borrow()+1);
					if(r_t == "E-book") {
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(k.get_size());
						}
						s.set_borrow(s.get_borrow()-1);
					}
					facultys.push_back(s);
					facultys.erase(facultys.begin() + i);
					flag = 1;
				}
				i ++;
			}
			if(flag == 0) {
				faculty A(m_n);
				A.set_list(r_n, dateToint(d));
				A.set_ban(false);
				A.set_date_ban("");
				A.set_borrow(A.get_borrow()+1);
				if(r_t == "E-book") {
					for(auto k : e_books) {
						if(k.get_name() == r_n) A.set_capacitor(k.get_size());
					}
					A.set_borrow(A.get_borrow()-1);
				}
				facultys.push_back(A);
			}
			i = 0;
			for (auto s : books) {
				if(s.get_name() == r_n) {
					s.set_member_borrow(m_n);
					s.set_date_borrow(d);
					s.set_date_return(intTodate(dateToint(d)+29));
					books.push_back(s);
					books.erase(books.begin() + i);
				}
				i ++;
			}
			if(r_t == "Magazine") {
				magazine s(r_n);
				s.set_member_borrow(m_n);
				s.set_date_borrow(d);
				s.set_date_return(intTodate(dateToint(d)+29));
				magazines.push_back(s);
			}
			output(count, 0, "Success.");
		}
	}

	else if(op == "R") {
		if(m_t == "Undergraduate"){
			int i = 0;
			for (auto s : undergraduates) {
				if(s.get_name() == m_n) {
					s.set_ban(false);
					s.set_date_ban("");
					s.erase_list(r_n);
					s.set_borrow(s.get_borrow()-1);
					if(r_t == "E-book") {
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(-k.get_size());
						}
						s.set_borrow(s.get_borrow()+1);
					}
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
			i=0;
			for (auto s : magazines) {
				if(s.get_name() == r_n) {
					magazines.erase(magazines.begin() + i);
				}
				i++;
			}
			output(count, 0, "Success.");
		}
		else if(m_t == "Graduate") {
			int i = 0;
			for (auto s : graduates) {
				if(s.get_name() == m_n) {
					s.erase_list(r_n);
					s.set_ban(false);
					s.set_date_ban("");
					s.set_borrow(s.get_borrow()-1);
					if(r_t == "E-book") {
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(-k.get_size());
						}
						s.set_borrow(s.get_borrow()+1);
					}
					graduates.push_back(s);
					graduates.erase(graduates.begin() + i);
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
			i=0;
			for (auto s : magazines) {
				if(s.get_name() == r_n) {
					magazines.erase(magazines.begin() + i);
				}
				i++;
			}
			output(count, 0, "Success.");
		}
		else if(m_t == "Faculty") {
			int i = 0;
			for (auto s : facultys) {
				if(s.get_name() == m_n) {
					s.erase_list(r_n);
					s.set_ban(false);
					s.set_date_ban("");
					s.set_borrow(s.get_borrow()-1);
					if(r_t == "E-book") {
						for(auto k : e_books) {
							if(k.get_name() == r_n) s.set_capacitor(-k.get_size());
						}
						s.set_borrow(s.get_borrow()+1);
					}
					facultys.push_back(s);
					facultys.erase(facultys.begin() + i);
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
			i=0;
			for (auto s : magazines) {
				if(s.get_name() == r_n) {
					magazines.erase(magazines.begin() + i);
				}
				i++;
			}
			output(count, 0, "Success.");
		}
	}

}

void library :: space_database(int count, string date2, string space_type, string space_number, string operation2, string member_type2, string member_name2, int number_of_member, int in_time) {
	// code = 8
	if(space_type == "StudyRoom"){
		if(stoi(space_number) > 10 || stoi(space_number) ==0 ){
			output(count, 8, "Invalid space id.");
			return;
		}
	}
	if(space_type == "Seat"){
		if(stoi(space_number) > 3 || stoi(space_number) == 0){
			output(count, 8, "Invalid space id.");
			return;
		}
	}


	//code 9
	int hour = dateTohour(date2);

	if(space_type == "StudyRoom"){
		if(hour >= 18 || hour < 9){
			output(count, 9, "This space is not available now. Available from 09 to 18.");
			return;
		}
	}
	else if(stoi(space_number) == 2){
		if(hour >= 21 || hour < 9){
			output(count, 9, "This space is not available now. Available from 09 to 21.");
			return;
		}
	}
	else if(stoi(space_number) == 3){
		if(hour >= 18 || hour < 9){
			output(count, 9, "This space is not available now. Available from 09 to 18.");
			return;
		}
	}



	//code 10
	if(operation2 != "B"){
		if(space_type == "StudyRoom"){
			for(auto s : studyrooms){
				if(s.get_studyroom_number()==stoi(space_number)){
					if(s.get_name() != member_name2){
						output(count, 10, "You did not borrow this space.");
						return;
					}
				}
			}
		}
		else{
			for(auto s : seats){
				if(s.get_seat_floor()==stoi(space_number)){
					if(s.get_name() != member_name2){
						output(count, 10, "You did not borrow this space.");
						return;
					}
				}
			}
		}

	}
	
	//code 11
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			for(auto s : studyrooms){
				if(s.get_name() == member_name2){
					output(count, 11, "You already borrowed this kind of space.");
					return;
				}
			}
		}
		else{
			for(auto s : seats){
				if(s.get_name() == member_name2){
					output(count, 11, "You already borrowed this kind of space.");
					return;
				}
			}
		}
	}

	//code 12
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			if(number_of_member > 6){
				output(count, 12, "Exceed available number.");
				return;
			}
		}
		else{
			if(number_of_member > 1){
				output(count, 12, "Exceed available number.");
				return;
			}
		}
	}

	//code 13
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			if(in_time > 3){
				output(count, 13, "Exceed available time.");
				return;
			}
		}
		else{
			if(in_time > 3){
				output(count, 13, "Exceed available time.");
				return;
			}
		}
	}

	//code 14
	string error;
	int limit;
	string s_limit;
	int seat_limit=24;
	int flag_limit=0;
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					if(s.get_status() != 0){
						limit = s.get_time()+3;
						if(limit >= 18) limit = 18;
						s_limit = to_string(limit);
						if(limit>=0 && limit <=9){
							s_limit = "0" + s_limit;
						}
						error = "There is no remain space. This space is available after " + s_limit + ".";
						output(count, 14, error);
						return;
					}
					
				}
			}
		}
		else{
			if(stoi(space_number) == 3){           // 3 floor
				for(auto s : seats){
					if(s.get_seat_floor() == 3){
						if(s.get_status() != 0){
							if(seat_limit >= s.get_time() + 3){
								seat_limit = s.get_time() + 3;
								if(seat_limit > 18) seat_limit = 18;
							}
							
						}
						else{
							flag_limit = 1;
						}
					}
				}
				if(flag_limit == 0){
					s_limit = to_string(seat_limit);
					if(seat_limit>=0 && seat_limit <=9){
						s_limit = "0" + s_limit;
					}
					error = "There is no remain space. This space is available after " + s_limit + ".";
					output(count, 14, error);
					return;
				}
			}
			else if(stoi(space_number) == 2){           // 2 floor
				for(auto s : seats){
					if(s.get_seat_floor() == 2){
						if(s.get_status() != 0){
							if(seat_limit >= s.get_time() + 3){
								seat_limit = s.get_time() + 3;
								if(seat_limit > 21) seat_limit = 21;
							}
							
						}
						else{
							flag_limit = 1;
						}
					}
				}
				if(flag_limit == 0){
					s_limit = to_string(seat_limit);
					if(seat_limit>=0 && seat_limit <=9){
						s_limit = "0" + s_limit;
					}
					error = "There is no remain space. This space is available after " + s_limit + ".";
					output(count, 14, error);
					return;
				}
			}
			else if(stoi(space_number) == 1){           // 1 floor
				for(auto s : seats){
					if(s.get_seat_floor() == 1){
						if(s.get_status() != 0){
							if(seat_limit >= s.get_time() + 3){
								seat_limit = s.get_time() + 3;
								if(seat_limit > 24) seat_limit = 24;
							}
							
						}
						else{
							flag_limit = 1;
						}
					}
				}
				if(flag_limit == 0){
					s_limit = to_string(seat_limit);
					if(seat_limit>=0 && seat_limit <=9){
						s_limit = "0" + s_limit;
					}
					if(seat_limit == 24) s_limit = "00";
					error = "There is no remain space. This space is available after " + s_limit + ".";
					output(count, 14, error);
					return;
				}
			}
		}
	}

	//code =0 success
	int i;
	if(operation2 == "B"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_name(member_name2);
					s.set_time(dateTohour(date2));
					s.set_status(1);
					s.set_use_time(in_time);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_status() == 0){
					s.set_name(member_name2);
					s.set_time(dateTohour(date2));
					s.set_status(1);
					s.set_use_time(in_time);
					seats.push_back(s);
					seats.erase(seats.begin() + i);
					break;
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
	else if(operation2 == "R"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_name("");
					s.set_time(24);
					s.set_status(0);
					s.set_use_time(0);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}			
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_name()==member_name2){
					s.set_name("");
					s.set_time(24);
					s.set_status(0);
					s.set_use_time(0);
					s.set_wantempty(0);
					seats.push_back(s);
					seats.erase(seats.begin() + i);
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
	else if(operation2 == "E"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_status(2);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}			
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_name() == member_name2){
					s.set_status(2);
					s.set_wantempty(dateTohour(date2));
					seats.push_back(s);
					seats.erase(seats.begin() + i);
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
	}
	else if(operation2 == "C"){
		if(space_type == "StudyRoom"){
			i = 0;
			for(auto s : studyrooms){
				if(s.get_studyroom_number() == stoi(space_number)){
					s.set_status(1);
					studyrooms.push_back(s);
					studyrooms.erase(studyrooms.begin() + i);
				}
				i++;
			}			
		}
		else{
			i = 0;
			for(auto s : seats){
				if(s.get_seat_floor() == stoi(space_number) && s.get_name() == member_name2){
					s.set_status(1);
					s.set_wantempty(0);
					seats.push_back(s);
					seats.erase(seats.begin() + i);
				}
				i++;
			}
		}
		output(count, 0, "Success.");
		return;
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
	int result = stoi(year) * 360 + (stoi(month)-1)*30 + (stoi(day)-1);
	//cout << result << endl;
	return result;
}

string library :: intTodate(int date) {
	string year, month, day;
	year = to_string(date/360);
	if(year.length()==1) year = "0" + year;
	month = to_string(1+(date%360)/30);
	if(month.length()==1) month = "0" + month;
	day = to_string((date%360)%30+1);
	if(day.length()==1) day = "0" + day;

	//cout << year + "/" + month + "/" + day << endl;
	return year + "/" + month + "/" + day;
}

int library :: dateToint2(string date2) {

	string year, month, day, hour;

	/*cout << date[0] << date[1] <<endl;
	cout << date[3] << date[4] <<endl;
	cout << date[6] << date[7] <<endl;*/

	year = date2[2];
	year += date2[3];
	month = date2[5];
	month +=date2[6];
	day = date2[8];
	day += date2[9];

	//cout << year << month << day << endl;
	int result = stoi(year) * 360 + (stoi(month)-1)*30 + (stoi(day)-1);
	//cout << result << endl;
	return result;
}

int library :: dateTohour(string date2) {
	string hour;
	hour = date2[11];
	hour += date2[12];
	int result = stoi(hour);
	return result;
}


void library :: emptyorclear(string date2) {
	int i;
	if(day_check < dateToint2(date2)){                     //change date
		studyrooms.clear();
		seats.clear();
		for(i=0;i<10;i++){                  //make studyroom
			studyroom S;
			S.set_studyroom_number(i+1);
			studyrooms.push_back(S);
		}
		int j;
		for(i=0;i<3;i++){				//make seat
			for(j=0;j<50;j++){
				seat T;
				T.set_seat_floor(i+1);
				seats.push_back(T);
			}
		}
		day_check = dateToint2(date2);
	}
	else {
		i = 0;
		for(auto s : studyrooms){
			if(s.get_status() != 0 && dateTohour(date2) >= (s.get_use_time() + s.get_time())){
				s.set_name("");
				s.set_time(24);
				s.set_status(0);
				studyrooms.push_back(s);
				studyrooms.erase(studyrooms.begin() + i);
				i--;
			}
			i++;
		}			

		i = 0;
		for(auto s : seats){
			if(s.get_status() == 1 && dateTohour(date2) >= (s.get_use_time() + s.get_time())){
				s.set_name("");
				s.set_time(24);
				s.set_status(0);
				s.set_wantempty(0);
				seats.push_back(s);
				seats.erase(seats.begin() + i);
				i--;
			}
			else if(s.get_status() == 2 && dateTohour(date2) >= (1 + s.get_wantempty())){
				s.set_name("");
				s.set_time(24);
				s.set_status(0);
				s.set_wantempty(0);
				seats.push_back(s);
				seats.erase(seats.begin() + i);
				i--;
			}
			i++;
		}

	}
}