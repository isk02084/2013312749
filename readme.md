# Project1

## resoure.h

기본적으로 set함수는 private에 선언된 변수에 input을 저장해주는 함수이다.
get함수는 변수에 저장된 값을 읽는 함수이다.

resource class에는 name 변수가 있고 책의 이름을 저장한다.

resource class를 상속받는 book class가 있으며 변수는 3개가 있다.
	string member_borrow; //이 책을 빌린 사람의 이름을 저장한다.
	string date_borrow; // 책이 빌려진 시점을 저장한다.
	string date_return; // 책을 반납해야되는 시점을 저장한다.

## member.h

마찬가지로 변수에 대하여 set함수와 get함수가 있다.

member class에는 name 변수가 있고 사람의 이름을 저장한다.

member class를 상속받는 undergraduate class가 있으며 변수는 5개가 있다.
	string date;	// 책을 빌린 시점을 저장한다.
	bool ban;	// 책을 빌릴수 있는 사람인지를 저장한다. (1이면 제한된 사람)
	string date_ban; // 제한된 날짜를 저장한다.
	string book_name; // 빌린 책 이름을 저장한다.
	int book_borrow; // 빌릴 수 있는 책의 권수를 저장한다.

## library.h

변수로는 vector type의 books와 undergraduates가 있다. input으로 들어간 자료가 저장된다.
함수로는 7가지 기능을 하는 함수가 존재한다.
	library(); // bookshelf()함수와 input()함수를 실행시키는 함수이다.
	void bookshelf(); // input 파일인 resource.dat를 open하여 input을 resuorce class 변수에 저장하고 book vector에 push해준다.
	void input(); // input 파일인 input.dat를 open하여 input을 class 변수에 저장하고 vector에 push해준다. 그리고 database함수를 실행시켜 나온 결과를 output.dat write한다.
	void database(int count, string d, string r_t, string r_n, string op, string m_t, string m_n); // input받은 정보로 opeartion을 하는 함수이다. op 1번부터 B/R에 따라 검사를 하고 return을 string으로 선언하여 output함수로 넘겨준다.
	void output(int op_num, int return_code, string description); //database()함수를 거쳐 나온 return string를 받아서 output.dat에 write해주는 함수이다.
	int dateToint(string date); // 날짜 계산을 위해 만들어준 함수이다. string을 input으로 받아 /를 제거하고 년에는 360, 달에는 30을 곱하여 일 단위로 return한다.
	string intTodate(int date); // output.dat에 에러코드를 write할 때 날짜를 써주기 위해 만든 함수이다. 일 단위로 계산된 date를 input으로 받아 year/month/day 형태로 return된다.


# Project2

project1에서 도서 관리 시스템을 만들었다면 project2는 space 관리 시스템을 만든다.
기존 도서 관리 시스템과 동시에 동작되어야 하기 때문에 library.h에 space 관리 시스템을 추가하였다.

## space.h
space class에는 4가지 변수가 존재한다.
	string name;	// 빌린 사람의 이름을 저장한다.
	int time;	// 빌린 날짜의 시간을 저장한다.
	int status;	// 좌석의 상태를 나타낸다. 0 : not use  1: using   2:use but no people(empty)
	int use_time; 	// 좌석을 사용할 시간을 저장한다.

또한 space class를 상속받는 studyroom class와 seat class가 있다.
studyroom class에는 studyroom의 번호를 나타내는 studyroom_number 변수가 있다.
seat class에는 seat의 층수를 저장하는 seat_floor 변수와 E operation을 위한 wantempty 변수가 존재한다.

## library.h
변경된 함수는 다음과 같다.
	library(); // space인 studyroom 10개와 seat 3층 50개를 vector로 만들어준다. 
	input();// input 파일을 추가로 space.dat를 열어 class 변수에 저장한다. 여기서 도서 관리 시스템과 동시에 동작이 되고, 날짜 순서로 시스템이 동작 되기 때문에 date 비교하여 관리 시스템을 동작하도록 하였다.
	space_database(int count, string date2, string space_type, string space_number, string operation2, string member_type2, string member_name2, int number_of_member, int in_time);// input에서 받은 정보로 space 관리의 opearation을 결정하는 함수이다. op 8번 부터 B/R/E/C에 따라 검사를 하고, error 메세지를 return 한다. 
	emptyorclear(string date2); // 이 project에 추가한 함수인데, 문제에서 밤 12시가 지나면 모든 studyroom과 seat가 비워저야 한다는 조건이 있다. 이 조건을 실행해 주기 위하여 만들어 준 함수이다. input으로 date를 받으면 database2가 동작하기 전에 날짜를 검사하여 바로 전 input의 date 변수와 비교하여 날짜가 변했으면 database 함수가 실행되기 직전에 모든 space vector를 초기화 해준다. 또한 좌석을 비운 사람이 1시간 안에 돌아오지 않으면 space를 초기화 시켜줘야 하기 때문에 이 동작도 하는 함수이다.


