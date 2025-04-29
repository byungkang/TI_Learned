#include <iostream>
#include <string>
using namespace std;

void add(char c);
void sub(char c);

int S, P;
char A[1000000];
int conditions[4];
int check[4] = { 0 };
int chk = 0;

int main() {


	cin >> S >> P;
	cin >> A;                      // string ���� �ѹ��� �Է¹ޱ�
	int count = 0;

	// �� ������ �����
	for (int i = 0; i < 4; i++) 
	{  
		cin >> conditions[i];
		// ���ʿ� ���� 0�̸� ���� �����ϴ°Ŵϱ� ���� �÷��ش�.
		if (conditions[i] == 0) 
		{  
			chk++;
		}
	}

	// �Էºκ� �� 

	// �ϴ� ó���� ù ������ ����
	for (int i = 0; i < P; i++) {
		add(A[i]); // ������ ��쿡 ���� add ����
	}

	if (chk == 4) {
		count++;
	}

	int start = 0;
	int end = P;

	while (end < S) 
	{
		sub(A[start]);
		add(A[end]);
		if (chk == 4) 
		{
			count++;
		}
		start++;
		end++;
	}

	cout << count << endl;
}


void add(char c) {
	switch (c) {
	case 'A':                          // �̷��� �����찡 �ٲ𶧸��� ���� üũ�迭�� ����� 
		check[0]++;                    // O(n^2)�� �ȴ�
		if (check[0] == conditions[0])
			chk++;
		break;
	case 'C':
		check[1]++;
		if (check[1] == conditions[1])
			chk++;
		break;
	case 'G':
		check[2]++;
		if (check[2] == conditions[2])
			chk++;
		break;
	case 'T':
		check[3]++;
		if (check[3] == conditions[3])
			chk++;
		break;
	}
}

void sub(char c) {
	switch (c) {
	case 'A':
		if (check[0] == conditions[0])
			chk--;
		check[0]--;
		break;
	case 'C':
		if (check[1] == conditions[1])
			chk--;
		check[1]--;
		break;
	case 'G':
		if (check[2] == conditions[2])
			chk--;
		check[2]--;
		break;
	case 'T':
		if (check[3] == conditions[3])
			chk--;
		check[3]--;
		break;
	}
}