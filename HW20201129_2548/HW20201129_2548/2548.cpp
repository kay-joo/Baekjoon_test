#include <iostream>
using namespace std;

class Rep {
	int input;
	int array[20000];
	int result;
	int min = 0;
public:
	void cnt_rep();
	void Ncnt_rep();
	void cal();
	void sorting();
	void showme() {
		for (int i = 0; i < input; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

void Rep::sorting() {
	int temp;
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void Rep::cnt_rep() {
	cin >> input;
}

void Rep::Ncnt_rep() {
	for (int i = 0; i < input; i++) {
		cin >> array[i];
	}
}

void Rep::cal() {
	int temp = 0;
	int temp_result[20000];
	
	int cnt = 0;
	for (int i = 0; i < input; i++) {
		temp_result[i] = 0;
		for (int j = 0; j < input; j++) {
			if (array[i] - array[j] >= 0) {
				temp = array[i] - array[j];
			}
			else {
				temp = (array[i] - array[j]) * -1;
			}
			temp_result[i] += temp;
		}
		//cout << temp_result[i] << endl;
	}
	//cout << endl;
	min = temp_result[0];
	for (int i = 0; i < input; i++) {
		if (temp_result[i] < min) {
			min = temp_result[i];
			cnt = i;
		}
		//cout << min << endl;
	}
	//cout << endl;
	cout << array[cnt] << endl;
}


int main(void) {
	Rep x;
	x.cnt_rep();
	x.Ncnt_rep();
	//x.showme();
	x.sorting();
	//x.showme();
	x.cal();
}