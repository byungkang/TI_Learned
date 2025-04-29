#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[1000001] = { 0, };
bool position[1000001] = {0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;

	cin >> M >> N;
	int temp = sqrt(N);
	position[1] = 1;


	for (int i = 2; i <= temp; i++)
	{
		if (position[i] == true)
		{
			continue;
		}
		for (int j = i + i; j <= N; j = j + i)
		{
			position[j] = true;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (position[i] == false)
		{
			cout << i << "\n";
		}
	}
}