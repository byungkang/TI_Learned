#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	// Vector ���� �� �ʱ�ȭ
	vector<int> vec;		// int�� Vector ����
	vector<int> vec(4);		// int�� Vector ���� �� ũ�⸦ 4�� �Ҵ�
	vector<int> vec = { 1,2,3 };		//int�� Vector ���� �� 1, 2, 3���� �ʱ�ȭ
	vector<int> vec[] = { {1,2}, {3,4} };		
	// int�� Vector �迭 ���� (���� ���������� ���� ����)
	// �Ʒ� Vector ���� �� ����ϴ� ���� ���ƺ��� 
	vector<vector<int>> vec;		// 2���� Vector ����(��� �� ��� ����) 
	
	vec.assign(5, 10);		// Vector ������ 5�� �����ϰ� ���� 10���� �ʱ�ȭ

	
	// Vector�� Iterators
	vector<int> vec = { 1,2,3,4,5 };
	vec.begin();							// vector�� ������ �ּҰ� ��ȯ
	vec.end();								// vector�� (���κ�+1)�� �ּҰ� ��ȯ
	vec.rbegin();							// vector�� �� ������ ���������� ��ȯ
	vec.rend();								// vector(����+1) ������ �� �κ����� ��ȯ

	vec.at(3);								// vector�� 3��° ��� ���� vec.at(i)
	vec[2];									// vecotr�� 2��° ��� ����
	vec.front();							// vecotr�� ù��° ��� ����
	vec.back();								// vector�� ������ ��� ����

	vec.push_back(6);						// vecotr�� ������ �κп� ���ο� ��� �߰�
	vec.pop_back();							// vecotr�� ������ �κ� ����
	
	vec.insert(vec.begin() + 1, 100);		// vec.insert(��ġ, ��) ���ο� ��� �߰�
	
	vec.emplace_back(7);					// vecotr�� ������ �κп� ���ο� ��� �߰�
	vec.emplace(vec.begin() + 1, 50);		// vec.emplace(��ġ, ��) �ּ��� ���� ����
	
	vec.erase(vec.begin() + 1);				// vec.erase(�ּ�) �ּ��� ���� ����
	
	vec.resize(10);							// vecotr�� ����� ����(���� �ʰ��� 0���� �ʱ�ȭ)
	vec.clear();							// vecotr�� ��� ��Ҹ� �����. ==> vec.empty()
}