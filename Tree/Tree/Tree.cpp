//Ʈ���� �ڷᱸ���� �� �����̸�, Ʈ���� �� ��Ҹ� ����� �θ���.
//�� ���� �����͸� �����ϸ� ���� ��带 �����Ѵ�.
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
	Node(const char* data)
	{
		value = data;
	}
	const char* value;
	vector<Node*> children;
};

void PrintTree1(Node* root)
{
	cout << root->value << endl;

	int size = root->children.size();
	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		PrintTree1(node);
	}
}
void PrintTree2(Node* root, int depth = 0)
{
	for (int i = 0; i < depth; i++)
		cout << "-";

	cout << root->value << endl;

	int size = root->children.size();
	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		PrintTree2(node, depth + 1);
	}
}
int GetHeight(Node* root)
{
	int ret = 1;

	int size = root->children.size();
	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		int h = GetHeight(node) + 1;

		if (ret < h)
			ret = h;
	}

	return ret;
}

int main()
{
	// Ʈ���� �� ���� �ִ� ��带 ��Ʈ ����� �θ���.
	// Ʈ������ ���� ��� ���̴� ������ ����Ǿ� �ִ�.
	//�ڽź��� ���� ��带 ������ �ִ� ����� ��� parent ��� �Ѵ�.
	Node* root = new Node("Tree");
	{
		Node* node = new Node("Branch1");
		root->children.push_back(node);
		{
			Node* leaf = new Node("���");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("���ξ���");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("Branch2");
		root->children.push_back(node);
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("Branch3");
		root->children.push_back(node);
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("�뱸");
			node->children.push_back(leaf);
		}
	}
	return 0;
}