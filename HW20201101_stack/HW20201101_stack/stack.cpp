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
	stacksize = _msize(comlinecnt) / 4;/*int���� byte���� 4byte�̱� ������
									   �迭�� ������ �˾ƺ� ������ 4�� �������ش�.
									   _msize�Լ��� �����޸��� 
									   �������� �޸� ����� �����ϴ� �Լ���.*/
}

stack::~stack() {
	if (comlinecnt) {//���� comlinecnt�� ���� �Ҵ�� �迭�� ������
		delete[]comlinecnt;//���� �Ҵ� �޸� �Ҹ�
		cout << "���� �Ҹ�" << endl;
	}
}

int stack::select() {
	string select;
	char ex;
	int temp;
	int sum = 0;
	do {
	cout << "��ɾ �Է��ϼ��� : ";
	getline(cin, select);
		switch (select[0]) {//���ڿ��� ù��° ���ڸ��� ������,push�� pop�� �����ϰ� ��ɾ� ������ ������
		case 'p':
			if (select[1] == 'u') {//�ι�° ���ڰ� push�� u�̸� push
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
				return 0;//push�� ���� 0���� ���Ͽ� ��ȯ
				//���ڿ� ���ڸ� �и��Ͽ� ���� ���� �����Ͽ�����
			}
			else {//push�� �ƴϸ� pop, p�� �Է��Ͽ��� ������ pop
				return 1;//pop�� ���� 1�� ���Ͽ� ��ȯ
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
		default://����ó��
			cout << "Ʋ�� ��ɾ��Դϴ�. �ٽ��Է��ϼ���. " << endl;
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

int howmanycnt() {//�Լ����� �� ����
	int input;
	do {
		cout << "��ɾ��� �� N�� �Է��ϼ��� : ";
		cin >> input;
		if (input < 1 || input>10000) {
			cout << "��ɾ��� �� N�� 1�̻� 10000������ ���� �Է��ϼ���." << endl;
		}
	} while (input < 1 || input>10000);
	cin.ignore();//�Է¹��۸� �����ֱ� ���� �Լ�
	return input;
}

int main() {//�����Լ� ����
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