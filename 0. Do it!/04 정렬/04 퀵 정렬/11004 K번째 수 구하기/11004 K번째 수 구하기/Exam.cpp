#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> alpha(N);
	for (int i = 0; i < N; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	cout << alpha[K-1];
}