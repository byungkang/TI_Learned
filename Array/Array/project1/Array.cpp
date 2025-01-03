#include <iostream>

using namespace std;
const int input_number = 10;
#define X 3
#define Y 2

void printsort(int* arr, int size)
{
	arr[3] = 777;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void printsort2(int (*arr)[3], int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int* PrintSort(int* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		arr[i] = 7 * (i + 1);
	}
	return arr;
}

typedef int(*Array2D)[X];
Array2D PrintSort2(int(*arr)[X], int x, int y)
{
	int count = 1;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			arr[i][j] = count++;
		}
	}
	return arr;
}

int main()
{
	// 1���� �迭
	int arr1[30];
	int arr2[5] = { 1,2,3 };
	int arr3[] = { 1,2,3 };

	// 2���� �迭
	int arr4[5][5];
	int arr5[5][5] =
	{
	{ 1,2,3,4,5 },
	{ 6,7,8,9,10 }
	};

	// 3���� �迭
	int arr6[2][2][2] =
	{
		{
			{ 1, 2 },{ 3, 4 }
		},
		{
			{ 1, 2 },{ 3, 4 }
		},
	};

	// 1���� �����Ҵ�
	int* arr7 = new int[input_number]; // ����
	delete[] arr7;					   // ����

	// 2���� �����Ҵ�

	// ���� 
	int** arr8 = new int* [input_number];

	for (int i = 0; i < input_number; i++)
	{
		arr8[i] = new int[input_number];
	}

	// ����
	for (int i = 0; i < input_number; i++)
	{
		delete[] arr8[i];
	}

	int alpha, beta;
	while (1)
	{
		cout << "�����Ҵ� // ���� ������ �Է½ÿ� :_";
		cin >> alpha;
		cout << "�����Ҵ� // ���� ������ �Է½ÿ� :_";
		cin >> beta;
		cout << "\n";

		int** ar1 = new int* [alpha];
		for (int i = 0; i < alpha; i++)
		{
			ar1[i] = new int[beta];
		}

		int count = 10;
		for (int i = 0; i < alpha; i++)
		{
			for (int j = 0; j < beta; j++)
			{
				ar1[i][j] = count++;
			}
		}

		for (int i = 0; i < alpha; i++)
		{
			for (int j = 0; j < beta; j++)
			{
				cout << ar1[i][j] << " , "; //2���� �迭 ���� ���
			}
			cout << "\n";
		}

		for (int i = 0; i < alpha; i++)
		{
			delete[] ar1[i];		// �� ���� �迭 ���� 
		}
		delete[] ar1;
	}

	// �Լ� ȣ��
	int input[6] = { 1,2,3,4,5,6 };
	int input2[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "1���� �迭 ���" << "\n";
	printsort(input, 6);
	cout << "\n";

	cout << "2���� �迭 ���" << "\n";
	printsort2(input2, X, Y);
	cout << "\n";



	// 1���� �迭
	cout << "[1���� �迭 ���]" << endl;
	int arr[10] = { 1, 2, 3, 4, 5 };
	int* arrPtr = PrintSort(arr, 10);

	for (int i = 0; i < 6; ++i) {
		cout << arrPtr[i] << " ";
	}
	cout << "\n\n";



	// 2���� �迭
	cout << "[2���� �迭 ���]" << endl;
	int arr_2[Y][X];

	int (*arrPtr2)[X] = PrintSort2(arr_2, X, Y);

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cout << arrPtr2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}