#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	// Vector 생성 및 초기화
	vector<int> vec;		// int형 Vector 생성
	vector<int> vec(4);		// int형 Vector 생성 후 크기를 4로 할당
	vector<int> vec = { 1,2,3 };		//int형 Vector 생성 후 1, 2, 3으로 초기화
	vector<int> vec[] = { {1,2}, {3,4} };		
	// int형 Vector 배열 생성 (행은 가변이지만 열은 고정)
	// 아래 Vector 선언 후 사용하는 것이 나아보임 
	vector<vector<int>> vec;		// 2차원 Vector 생성(행과 열 모두 가변) 
	
	vec.assign(5, 10);		// Vector 범위를 5로 지정하고 정수 10으로 초기화

	
	// Vector의 Iterators
	vector<int> vec = { 1,2,3,4,5 };
	vec.begin();							// vector의 시작점 주소값 반환
	vec.end();								// vector의 (끝부분+1)의 주소값 반환
	vec.rbegin();							// vector의 끝 지점을 시작점으로 반환
	vec.rend();								// vector(시작+1) 지점을 끝 부분으로 반환

	vec.at(3);								// vector의 3번째 요소 접근 vec.at(i)
	vec[2];									// vecotr의 2번째 요소 접근
	vec.front();							// vecotr의 첫번째 요소 접근
	vec.back();								// vector의 마지막 요소 접근

	vec.push_back(6);						// vecotr의 마지막 부분에 새로운 요소 추가
	vec.pop_back();							// vecotr의 마지막 부분 제거
	
	vec.insert(vec.begin() + 1, 100);		// vec.insert(위치, 값) 새로운 요소 추가
	
	vec.emplace_back(7);					// vecotr의 마지막 부분에 새로운 요소 추가
	vec.emplace(vec.begin() + 1, 50);		// vec.emplace(위치, 값) 주소의 값을 변경
	
	vec.erase(vec.begin() + 1);				// vec.erase(주소) 주소의 값을 삭제
	
	vec.resize(10);							// vecotr의 사이즈를 조정(범위 초과시 0으로 초기화)
	vec.clear();							// vecotr의 모든 요소를 지운다. ==> vec.empty()
}