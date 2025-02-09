#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;					// int�� Ű�� string ������ ������ �� ����

	m.insert(make_pair(2, "a"));		// make_pair�� Ȱ���Ͽ� �ڷ� �߰�
	m.insert(make_pair(1, "b"));
	m.insert(make_pair(3, "c"));
	m.insert(make_pair(5, "d"));
	m.insert(make_pair(9, "f"));
	m.insert(make_pair(11, "v"));

	m.begin();							// map�� ���� �� �κ� value��
	m.end();							// map�� ���� �� �κ� value��

	// Hash Map�� key-value ���� �����͸� ����
	// unorderedmap�� map 2������ �ִ� (key�� �������� ������������ ���� ����)
	// unorderedmap ���� ��� �ð����⵵�� O(1)�� �ӵ��� �����ٴ� ����
}