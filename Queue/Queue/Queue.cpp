#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// ���Լ��ⱸ���� �ڷ� �������� �߰�/������ ������ �ڷᱸ��
	//push(), pop(), front(), back(), empty(), size() ���� �Լ� ���
	queue<int> que;

	for (int i = 0; i < 5; i++)
	{
		que.push(i);	//queue�� i �� �Է�
	}

	que.size();			// queue�� ũ�� ���
	que.pop();			// queue ����(���� �տ� �ִ� �� ����)
	que.front();		// ���� ���� �Էµ� ��
	que.back();			// ���� �ֽ��� �Էµ� �� 

	
	// �ڷθ� �߰� / ������ ������ queue, vector�� �޸�, �� / �ڷ� �߰� / ������ ������ �ڷᱸ��.
	// push_back(), push_front(), pop_back(), pop_front(), front(), back(), empty(), size(), clear() ���� �Լ� ���
	deque<int> dque;

	for (int i = 0; i < 5; i++)
	{
		dque.push_back(i);
	}

	dque.pop_back();			// ���� ���� �Էµ� �� ����
	dque.pop_front();			// ���� �ֽſ� �Էµ� �� ����

	
	// ��� ���� �߿��� ���� ū ���� Top�� �����ϴ� Queue
	priority_queue<int> pq;
	// ��� ���� �߿��� ���� ���� ���� Top�� �����ϴ� Queue
	priority_queue<int, vector<int>, greater<int>> pq1;

	pq.push(4);
	pq.push(7);
	pq.push(3);
	pq.push(10);
	pq.push(5);
	pq.push(8);

	pq1.push(4);
	pq1.push(7);
	pq1.push(3);
	pq1.push(10);
	pq1.push(5);
	pq1.push(8);

	cout << "�켱���� ť ������ : " << pq.size() << "\n";
	while (!pq.empty())
	{
		cout << pq.top() << '\n';			//	10	8	7	5	4	3	
		pq.pop();
	}
	cout << "�켱(��������)���� ť ������ : " << pq1.size() << "\n";
	while (!pq1.empty())
	{
		cout << pq1.top() << '\n';			//	3	4	5	7	8	10	
		pq1.pop();
	}

}