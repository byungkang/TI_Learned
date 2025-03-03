#include <iostream>

using namespace std;

int salary[16][2] = {0,};
bool position[16] = { 0, };
int arr[16] = { 0 };
int N;

void employee(int result, int nowposition, int& money)
{
	if (result == N+1)
	{
		int max = 0;		
		for (int i = 1; i <= nowposition-1; i++)
		{
			max += arr[i];
		}
		if (salary[result - 1][0] == 1)
		{
			max += salary[result][1];
		}
		if (money < max)
		{
			money=max;
		}
		return;
	}
	else if (result > N+1)
	{
		int max = 0;
		for (int i = 1; i < nowposition-1; i++)
		{
			max += arr[i];
		}
		if (money < max)
		{
			money = max;
		}
		return;
	}

	

	for (int i = result; i <= N; i++)
	{
		if (!position[i])
		{
			position[i] = true;
			arr[nowposition] = salary[i][1];
			employee(i + salary[i][0], nowposition + 1, money);
			position[i] = false;
		}
	}

}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		// 0번 Index는 Time, 1번 Index는 금액
		cin >> salary[i][0];
		cin >> salary[i][1];
	}

	int finalresult = 0;
	employee(1, 1, finalresult);
	cout << finalresult;
}