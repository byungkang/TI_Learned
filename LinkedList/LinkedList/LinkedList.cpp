#include <iostream>

using namespace std;

// node 구조체 구현 (data와 nextNode의 주소 값)
struct node
{
	int data;
	node * nextNode;
};

// LinkedList 클래스 생성
class LinkedList
{
public:
	LinkedList()
	{
		// haed와 tail의 포인터를 초기화
		head = NULL;
		tail = NULL;
	}

	// 첫번째의 node 추가
	void addFrontNode(int n);
	
	// 마지막의 node 추가
	void addNode(int n);

	// node 삽입
	void insertNode(node* prevNode, int n);

	// node 삭제 
	void deleteNode(node* prevNode);
	
	// 첫번째 노드 가져오기
	node* getHead()
	{
		return head;
	}

	// LinkedList 출력
	void display(node* head);
private:
	node* head;
	node* tail;
};

// 첫 번째의 node 추가
void LinkedList::addFrontNode(int n)
{
	node* temp = new node;
	//	temp의 데이터는 n
	temp->data = n;
	
	//	LinkedList가 비어있으면 
	if (head == NULL)
	{
		//첫 node는 temp
		head = temp;
		// 마지막 node는 temp
		tail = temp;
	}
	//	LinkeList에 데이터가 있으면
	else
	{
		//temp의 NextNode는 head
		temp->nextNode = head;
		//head는 temp
		head = temp;
	}
}

//마지막의 node 추가
void LinkedList::addNode(int n)
{
	node* temp = new node;

	// Node temp의 data는 n
	temp->data = n;
	// Node의 NextNode 주소는 NULL
	temp->nextNode = NULL;

	// LinkedList가 비어있으면 
	if (head == NULL)
	{
		// 첫 Node는 temp
		head = temp;
		// 마지막 Node는 temp
		tail = temp;
	}
	// LinkedList에 데이터가 있으면
	else
	{
		// 기존 마지막 Node의 nextNode는 temp
		tail->nextNode = temp;
		// 마지막 Node는 temp
		tail = temp;
	}
}

// node 삽입
void LinkedList::insertNode(node* prevNode, int n)
{
	node* temp = new node;
	
	temp->data = n;

	temp->nextNode = prevNode->nextNode;

	prevNode->nextNode = temp;
}

// node 삭제
void LinkedList::deleteNode(node* prevNode)
{
	node* temp = prevNode->nextNode;

	prevNode->nextNode = temp->nextNode;

	delete temp;
}

// LinkedList 출력
void LinkedList::display(node* head)
{
	if (head == NULL)
	{
		cout << "\n";
	}
	else
	{
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << "\n";
}

int main()
{
	LinkedList a;

	a.addNode(1);
	a.addNode(2);
	a.addNode(3);

	cout << "1,2,3을 LinkeList에 추가\n";
	a.display(a.getHead());

	a.addFrontNode(0);

	a.insertNode(a.getHead()->nextNode->nextNode, 1);
	cout << "0을 첫번째에 추가, 1을 네번쨰에 추가";
	a.display(a.getHead());

	a.deleteNode(a.getHead()->nextNode);

	cout << "세번째 노드를 삭제\n";
	a.display(a.getHead());
}