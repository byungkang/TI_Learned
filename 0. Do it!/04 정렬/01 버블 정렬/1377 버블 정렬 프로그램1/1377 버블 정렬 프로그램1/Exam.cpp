#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001] = { 0, };

// 10 1 5 2 3

// Bubble Sort Algorithm
	//bool changed = false;
	//for (int i = 1; i <= N + 1; i++) {
	//	changed = false;
	//	for (int j = 1; j <= N - i; j++) {
	//		if (A[j] > A[j + 1]) {
	//			changed = true;
	//			swap(A[j], A[j + 1]);
	//		}
	//	}
	//	if (changed == false) {
	//		cout << i << '\n';
	//		break;
	//	}
	//}

	// 풀이 Bubble Sort알고리즘에서 큰수가 오른쪽으로 가는것은 한번의 i for문에서 몇번이든 이뤄진다.
	// But, 작은수가 왼쪽으로 가는것은 한번의 i for문에서 단 한번만 이루어진다.
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	int ans = -1;

	for (int i = 0; i < N; i++)
	{
		if (ans < v[i].second - i)
		{
			ans = v[i].second - i;
		}
	}

	cout << ans + 1;
}