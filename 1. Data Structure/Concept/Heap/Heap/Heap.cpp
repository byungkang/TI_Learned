#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Heap은 Min / Max 2개로 구현이 가능하다.
// Min : 부모 노드가 자식 노드보다 항상 작다
// Max : 부모 노드가 자식 노드보다 항상 크다
// Heap 자료구조를 응용한 대표적인 사례 우선순위 큐(Priority queue)

// Vector에 있는 make_heap 알고리즘을 사용하여 구현 
void print(vector<int>& vs)
{
	for (auto v:vs)
	{
		cout << v << ' ';
	}
	cout << "\n";
}
void q_make_heap()
{
	vector<int> v(vector<int>{1, 6, 5, 2, 3, 8, 4, 9, 7});
	cout << "Before make_heap V \n";
	print(v);
	cout << "\n";

	cout << "After make_heap V \n";
	make_heap(v.begin(), v.end());
	print(v);
}

// priority Queue로 구현
void q_priorityqueue()
{
	// 우선순위 큐 내림차순
	priority_queue<int> q;

	q.push(1);
	q.push(5);
	q.push(3);
	int q_size = q.size();
	for (int i = 0; i < q_size; i++)
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << "\n";

	// 우선순위 큐 오름차순
	priority_queue<int, vector<int>, greater<int>> q_greater;

	q_greater.push(1);
	q_greater.push(5);
	q_greater.push(3);
	int q_greater_size = q_greater.size();
	for (int i = 0; i < q_greater_size; i++)
	{
		cout << q_greater.top() << " ";
		q_greater.pop();
	}
	cout << "\n";
}

// make_pair로 구현 
void q_make_pair()
{
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(10, 100));
	pq.push(make_pair(1, 50));
	pq.push(make_pair(1, 200));
	pq.push(make_pair(50, 50));
	pq.push(make_pair(-10, 200));

	int pq_size = pq.size();
	for (int i = 0; i < pq_size; i++)
	{
		cout << pq.top().first << " " << pq.top().second << "\n";
	}

}
int main()
{

}