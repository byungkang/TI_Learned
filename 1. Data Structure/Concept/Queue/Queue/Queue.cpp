#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// 후입선출구조로 뒤로 데이터의 추가/삭제가 가능한 자료구조
	//push(), pop(), front(), back(), empty(), size() 등의 함수 사용
	queue<int> que;

	for (int i = 0; i < 5; i++)
	{
		que.push(i);	//queue에 i 값 입력
	}

	que.size();			// queue의 크기 출력
	que.pop();			// queue 삭제(가장 앞에 있는 값 삭제)
	que.front();		// 가장 먼저 입력된 값
	que.back();			// 가장 최신의 입력된 값 

	
	// 뒤로만 추가 / 삭제가 가능한 queue, vector와 달리, 앞 / 뒤로 추가 / 삭제가 가능한 자료구조.
	// push_back(), push_front(), pop_back(), pop_front(), front(), back(), empty(), size(), clear() 등의 함수 사용
	deque<int> dque;

	for (int i = 0; i < 5; i++)
	{
		dque.push_back(i);
	}

	dque.pop_back();			// 가장 먼저 입력된 값 삭제
	dque.pop_front();			// 가장 최신에 입력된 값 삭제

	
	// 모든 원소 중에서 가장 큰 값이 Top을 유지하는 Queue
	priority_queue<int> pq;
	// 모든 원소 중에서 가장 작은 값이 Top을 유지하는 Queue
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

	cout << "우선순위 큐 사이즈 : " << pq.size() << "\n";
	while (!pq.empty())
	{
		cout << pq.top() << '\n';			//	10	8	7	5	4	3	
		pq.pop();
	}
	cout << "우선(오름차순)순위 큐 사이즈 : " << pq1.size() << "\n";
	while (!pq1.empty())
	{
		cout << pq1.top() << '\n';			//	3	4	5	7	8	10	
		pq1.pop();
	}

}