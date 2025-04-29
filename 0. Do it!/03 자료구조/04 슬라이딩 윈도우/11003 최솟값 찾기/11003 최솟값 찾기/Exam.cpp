#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int arr[5000000] = { 0, };
int temp[5000000] = { 0, };

struct A {
	int data;
	int pos;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	deque <A> alpha;

	for (int i = 0; i < N; i++)
	{
		if (!alpha.empty() && i == alpha.front().pos + L)
		{
			alpha.pop_front();
		}

		while (!alpha.empty() && alpha.back().data > arr[i])
		{
			alpha.pop_back();
		}
		alpha.push_back({ arr[i],i });
		cout << alpha.front().data << " ";
	}


}