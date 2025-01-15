//트리는 자료구조의 한 종류이며, 트리의 각 요소를 노드라고 부른다.
//각 노드는 데이터를 저장하며 다음 노드를 연결한다.
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
	// 트리의 맨 위에 있는 노드를 루트 노드라고 부른다.
	// 트리에서 노드와 노드 사이는 엣지로 연결되어 있다.
	//자신보다 하위 노드를 가지고 있는 노드의 경우 parent 라고 한다.
	Node* root = new Node("Tree");
	{
		Node* node = new Node("Branch1");
		root->children.push_back(node);
		{
			Node* leaf = new Node("사과");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("파인애플");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("딸기");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("Branch2");
		root->children.push_back(node);
		{
			Node* leaf = new Node("수학");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("국어");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("영어");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("Branch3");
		root->children.push_back(node);
		{
			Node* leaf = new Node("서울");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("대구");
			node->children.push_back(leaf);
		}
	}
	return 0;
}