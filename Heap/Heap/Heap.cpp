#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Heap�� Min / Max 2���� ������ �����ϴ�.
// Min : �θ� ��尡 �ڽ� ��庸�� �׻� �۴�
// Max : �θ� ��尡 �ڽ� ��庸�� �׻� ũ��
// Heap �ڷᱸ���� ������ ��ǥ���� ��� �켱���� ť(Priority queue)

// Vector�� �ִ� make_heap �˰����� ����Ͽ� ���� 
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

// priority Queue�� ����
void q_priorityqueue()
{
	// �켱���� ť ��������
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

	// �켱���� ť ��������
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

// make_pair�� ���� 
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