#include <iostream>
using namespace std;

class multi {
	int fnum;
	char snum[4];
	int result[4];
	char ex;
public:
	multi();
	void input();

	int fout();
	int sout();
	int tout();
	int final_cal();
};

multi::multi() {
	//cout << "클래스 생성 완료" << endl;
}

void multi::input() {
	cin >> fnum;
	cin >> snum;
}

int multi::fout() {
	ex = snum[2];
	result[0] = fnum * (ex - '0');
	return result[0];
}

int multi::sout() {
	ex = snum[1];
	result[1] = 10 * (fnum * (ex - '0'));
	return result[1] / 10;
}

int multi::tout() {
	ex = snum[0];
	result[2] = 100 * (fnum * (ex - '0'));
	return result[2] / 100;
}

int multi::final_cal() {
	result[3] = result[0] + result[1] + result[2];
	return result[3];
}


int main() {
	multi x;
	x.input();
	cout << x.fout() << endl;
	cout << x.sout() << endl;
	cout << x.tout() << endl;
	cout << x.final_cal() << endl;
}