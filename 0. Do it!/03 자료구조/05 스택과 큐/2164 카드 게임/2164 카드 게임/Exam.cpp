#include<iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	deque<int> alpha;

	for (int i = N; i >= 1; i--)
	{
		alpha.push_back(i);
	}

	while (alpha.size() >= 2)
	{
		alpha.pop_back();
		int temp = alpha.back();
		alpha.pop_back();
		alpha.push_front(temp);
	}

	cout << alpha.front();
}