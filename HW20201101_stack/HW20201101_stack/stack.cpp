#include <iostream>
#include <string>
using namespace std;

class stack {
	int *comlinecnt;
	int stackpointer=-1;
	int move;
public:
	int stacksize;
	stack(int cnt);
	~stack();
	int select();
	void push();//0
	void pop();//1
	void size();//2
	void empty();//3
	void top();//4
};

stack::stack(int cnt) {
	comlinecnt = new int[cnt];
	stacksize = _msize(comlinecnt) / 4;/*int형의 byte수는 4byte이기 때문에
									   배열을 개수를 알아볼 때에는 4로 나누어준다.
									   _msize함수는 동적메모리인 
									   힙영역의 메모리 사이즈를 리턴하는 함수다.*/
}

stack::~stack() {
	if (comlinecnt) {//만일 comlinecnt에 동적 할당된 배열이 있으면
		delete[]comlinecnt;//동적 할당 메모리 소멸
		cout << "스택 소멸" << endl;
	}
}

int stack::select() {
	string select;
	char ex;
	int temp;
	int sum = 0;
	do {
	cout << "명령어를 입력하세요 : ";
	getline(cin, select);
		switch (select[0]) {//문자열의 첫번째 글자만을 가지고도,push와 pop을 제외하고 명령어 구분이 가능함
		case 'p':
			if (select[1] == 'u') {//두번째 글자가 push의 u이면 push
				switch (select.size()) {
				case 6:	ex = select[5];
						sum = ex - '0';
						this->move = sum;
						break;
				case 7: ex = select[5];
						temp = ex - '0';
						temp *= 10;
						sum += temp;
						ex = select[6];
						temp = ex - '0';
						sum += temp;
						this->move = sum;
						break;
				case 8: ex = select[5];
					temp = ex - '0';
					temp *= 100;
					sum += temp;
					ex = select[6];
					temp = ex - '0';
					temp *= 10;
					sum += temp;
					ex = select[7];
					temp = ex - '0';
					sum += temp;
					this->move = sum;
					break;
				case 9: ex = select[5];
					temp = ex - '0';
					temp *= 1000;
					sum += temp;
					ex = select[6];
					temp = ex - '0';
					temp *= 100;
					sum += temp;
					ex = select[7];
					temp = ex - '0';
					temp *= 10;
					sum += temp;
					ex = select[8];
					temp = ex - '0';
					temp *= 1;
					sum += temp;
					this->move = sum;
					break;
				case 10: ex = select[5];
					temp = ex - '0';
					temp *= 10000;
					sum += temp;
					ex = select[6];
					temp = ex - '0';
					temp *= 1000;
					sum += temp;
					ex = select[7];
					temp = ex - '0';
					temp *= 100;
					sum += temp;
					ex = select[8];
					temp = ex - '0';
					temp *= 10;
					sum += temp;
					ex = select[9];
					temp = ex - '0';
					temp *= 1;
					sum += temp;
					this->move = sum;
					break;
				case 11: ex = select[5];
					temp = ex - '0';
					temp *= 100000;
					sum += temp;
					ex = select[6];
					temp = ex - '0';
					temp *= 10000;
					sum += temp;
					ex = select[7];
					temp = ex - '0';
					temp *= 1000;
					sum += temp;
					ex = select[8];
					temp = ex - '0';
					temp *= 100;
					sum += temp;
					ex = select[9];
					temp = ex - '0';
					temp *= 10;
					sum += temp;
					ex = select[10];
					temp = ex - '0';
					temp *= 1;
					sum += temp;
					this->move = sum;
					break;
				case 12: ex = select[5];
					temp = ex - '0';
					temp *= 1000000;
					sum += temp;
					ex = select[6];
					temp = ex - '0';
					temp *= 100000;
					sum += temp;
					ex = select[7];
					temp = ex - '0';
					temp *= 10000;
					sum += temp;
					ex = select[8];
					temp = ex - '0';
					temp *= 1000;
					sum += temp;
					ex = select[9];
					temp = ex - '0';
					temp *= 100;
					sum += temp;
					ex = select[10];
					temp = ex - '0';
					temp *= 10;
					sum += temp;
					ex = select[11];
					temp = ex - '0';
					temp *= 1;
					sum += temp;
					this->move = sum;
					break;
				}
				return 0;//push의 값을 0으로 정하여 반환
				//문자와 숫자를 분리하여 따로 값을 저장하여야함
			}
			else {//push가 아니면 pop, p만 입력하였을 때에는 pop
				return 1;//pop의 값을 1로 정하여 반환
			}
			break;
		case 's':
			return 2;
			break;
		case 'e':
			return 3;
			break;
		case 't':
			return 4;
			break;
		default://예외처리
			cout << "틀린 명령어입니다. 다시입력하세요. " << endl;
		}
	} while (true);
}

void stack::push() {
	//cout << "push" << endl;;
	cout << move << endl;
	stackpointer++;
	comlinecnt[stackpointer] = move;
}

void stack::pop() {
	//cout << "pop" << endl;;
	if (stackpointer == -1) {
		cout << stackpointer << endl;
	}
	else {
		cout << comlinecnt[stackpointer] << endl;
		comlinecnt[stackpointer] = 0;
		stackpointer--;
	}
}

void stack::size() {
	//cout << "size" << endl;;
	cout << stackpointer + 1 << endl;
}

void stack::empty() {
	//cout << "empty" << endl;;
	if (stackpointer == -1) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

void stack::top() {
	//cout << "top" << endl;
	if (stackpointer == -1) {
		cout << stackpointer << endl;
	}
	else {
		cout << comlinecnt[stackpointer] << endl;
	}
}

int howmanycnt() {//함수선언 및 정의
	int input;
	do {
		cout << "명령어의 수 N을 입력하세요 : ";
		cin >> input;
		if (input < 1 || input>10000) {
			cout << "명령어의 수 N은 1이상 10000이하의 값만 입력하세요." << endl;
		}
	} while (input < 1 || input>10000);
	cin.ignore();//입력버퍼를 지워주기 위한 함수
	return input;
}

int main() {//메인함수 선언
	stack s1(howmanycnt());
	for (int i = 0; i < s1.stacksize; i++) {
		switch (s1.select()) {
		case 0:
			s1.push();
			break;
		case 1:
			s1.pop();
			break;
		case 2:
			s1.size();
			break;
		case 3:
			s1.empty();
			break;
		case 4:
			s1.top();
			break;		
		}
	}
	return 0;
}