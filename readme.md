##resoure.h

기본적으로 set함수는 private에 선언된 변수에 input을 저장해주는 함수이다.
get함수는 변수에 저장된 값을 읽는 함수이다.

resource class에는 name 변수가 있고 책의 이름을 저장한다.

resource class를 상속받는 book class가 있으며 변수는 3개가 있다.
	string member_borrow; //이 책을 빌린 사람의 이름을 저장한다.
	string date_borrow; // 책이 빌려진 시점을 저장한다.
	string date_return; // 책을 반납해야되는 시점을 저장한다.

##member.h

마찬가지로 변수에 대하여 set함수와 get함수가 있다.

member class에는 name 변수가 있고 사람의 이름을 저장한다.

member class를 상속받는 undergraduate class가 있으며 변수는 5개가 있다.
	string date;	// 책을 빌린 시점을 저장한다.
	bool ban;	// 책을 빌릴수 있는 사람인지를 저장한다. (1이면 제한된 사람)
	string date_ban; // 제한된 날짜를 저장한다.
	string book_name; // 빌린 책 이름을 저장한다.
	int book_borrow; // 빌릴 수 있는 책의 권수를 저장한다.

##library.h

변수로는 vector type의 books와 undergraduates가 있다. input으로 들어간 자료가 저장된다.
함수로는 7가지 기능을 하는 함수가 존재한다.
	library(); // bookshelf()함수와 input()함수를 실행시키는 함수이다.
	void bookshelf(); // input 파일인 resource.dat를 open하여 input을 resuorce class 변수에 저장하고 book vector에 push해준다.
	void input(); // input 파일인 input.dat를 open하여 input을 class 변수에 저장하고 vector에 push해준다. 그리고 database함수를 실행시켜 나온 결과를 output.dat write한다.
	void database(int count, string d, string r_t, string r_n, string op, string m_t, string m_n); // input받은 정보로 opeartion을 하는 함수이다. op 1번부터 B/R에 따라 검사를 하고 return을 string으로 선언하여 output함수로 넘겨준다.
	void output(int op_num, int return_code, string description); //database()함수를 거쳐 나온 return string를 받아서 output.dat에 write해주는 함수이다.
	int dateToint(string date); // 날짜 계산을 위해 만들어준 함수이다. string을 input으로 받아 /를 제거하고 년에는 360, 달에는 30을 곱하여 일 단위로 return한다.
	string intTodate(int date); // output.dat에 에러코드를 write할 때 날짜를 써주기 위해 만든 함수이다. 일 단위로 계산된 date를 input으로 받아 year/month/day 형태로 return된다.
