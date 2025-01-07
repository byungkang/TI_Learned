#include <iostream>

using namespace std;

// node ����ü ���� (data�� nextNode�� �ּ� ��)
struct node
{
	int data;
	node * nextNode;
};

// LinkedList Ŭ���� ����
class LinkedList
{
public:
	LinkedList()
	{
		// haed�� tail�� �����͸� �ʱ�ȭ
		head = NULL;
		tail = NULL;
	}

	// ù��°�� node �߰�
	void addFrontNode(int n);
	
	// �������� node �߰�
	void addNode(int n);

	// node ����
	void insertNode(node* prevNode, int n);

	// node ���� 
	void deleteNode(node* prevNode);
	
	// ù��° ��� ��������
	node* getHead()
	{
		return head;
	}

	// LinkedList ���
	void display(node* head);
private:
	node* head;
	node* tail;
};

// ù ��°�� node �߰�
void LinkedList::addFrontNode(int n)
{
	node* temp = new node;
	//	temp�� �����ʹ� n
	temp->data = n;
	
	//	LinkedList�� ��������� 
	if (head == NULL)
	{
		//ù node�� temp
		head = temp;
		// ������ node�� temp
		tail = temp;
	}
	//	LinkeList�� �����Ͱ� ������
	else
	{
		//temp�� NextNode�� head
		temp->nextNode = head;
		//head�� temp
		head = temp;
	}
}

//�������� node �߰�
void LinkedList::addNode(int n)
{
	node* temp = new node;

	// Node temp�� data�� n
	temp->data = n;
	// Node�� NextNode �ּҴ� NULL
	temp->nextNode = NULL;

	// LinkedList�� ��������� 
	if (head == NULL)
	{
		// ù Node�� temp
		head = temp;
		// ������ Node�� temp
		tail = temp;
	}
	// LinkedList�� �����Ͱ� ������
	else
	{
		// ���� ������ Node�� nextNode�� temp
		tail->nextNode = temp;
		// ������ Node�� temp
		tail = temp;
	}
}

// node ����
void LinkedList::insertNode(node* prevNode, int n)
{
	node* temp = new node;
	
	temp->data = n;

	temp->nextNode = prevNode->nextNode;

	prevNode->nextNode = temp;
}

// node ����
void LinkedList::deleteNode(node* prevNode)
{
	node* temp = prevNode->nextNode;

	prevNode->nextNode = temp->nextNode;

	delete temp;
}

// LinkedList ���
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

	cout << "1,2,3�� LinkeList�� �߰�\n";
	a.display(a.getHead());

	a.addFrontNode(0);

	a.insertNode(a.getHead()->nextNode->nextNode, 1);
	cout << "0�� ù��°�� �߰�, 1�� �׹����� �߰�";
	a.display(a.getHead());

	a.deleteNode(a.getHead()->nextNode);

	cout << "����° ��带 ����\n";
	a.display(a.getHead());
}