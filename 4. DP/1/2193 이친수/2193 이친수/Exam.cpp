#include <iostream>
 
using namespace std;

#define Max 91
long long arr[Max][3] = { 0 };

int main()
{
	int N;
	cin >> N;

	arr[1][1] = 1;
	arr[1][2] = arr[1][0] + arr[1][1];

	arr[2][0] = 1;
	arr[2][2] = arr[2][0] + arr[2][1];
	
	for (int i = 3; i <= 90; i++)
	{
		arr[i][1] = arr[i-1][0];
		arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
		arr[i][2] = arr[i][1] + arr[i][0];
	}

	cout << arr[N][2];
}