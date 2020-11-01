#include <iostream>
#include <string>
using namespace std;

class stack {
	int *comlinecnt;
	int stackpointer=0;
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
	do {
	cout << "��ɾ �Է��ϼ��� : ";
	getline(cin, select);
		switch (select[0]) {//���ڿ��� ù��° ���ڸ��� ������,push�� pop�� �����ϰ� ��ɾ� ������ ������
		case 'p':
			if (select[1] == 'u') {//�ι�° ���ڰ� push�� u�̸� push
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
	cout << "push" << endl;;
}

void stack::pop() {
	cout << "pop" << endl;;
}

void stack::size() {
	cout << "size" << endl;;
}

void stack::empty() {
	cout << "empty" << endl;;
}

void stack::top() {
	cout << "top" << endl;;
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