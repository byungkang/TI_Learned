#include <iostream>

using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int start_index = 1;
	int end_index = 1;
	int count = 1;
	int sum = 1;

	while (end_index != N)
	{
		if (sum == N)
		{
			count++;
			end_index++;
			sum = sum + end_index;
		}
		else if (sum > N)
		{
			sum = sum - start_index;
			start_index++;
		}
		else if (sum < N)
		{
			end_index++;
			sum = sum + end_index;
		}
	}
	cout << count << "\n";

}