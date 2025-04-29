#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> alpha;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K;
	cin >> N >> K;

	int start = 1;
	int end = K;
	int mid;
	
	while (start <= end)
	{
		mid = (start + end) / 2;
		int count = 0;

		for (int i = 1; i <= N; i++)
		{
			count += min(N, mid / i);
		}

		if (count < K)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << start;
}