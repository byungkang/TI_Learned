#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;					// int형 키와 string 벨류를 가지는 맵 생성

	m.insert(make_pair(2, "a"));		// make_pair을 활용하여 자료 추가
	m.insert(make_pair(1, "b"));
	m.insert(make_pair(3, "c"));
	m.insert(make_pair(5, "d"));
	m.insert(make_pair(9, "f"));
	m.insert(make_pair(11, "v"));

	m.begin();							// map의 가장 앞 부분 value값
	m.end();							// map의 가장 뒷 부분 value값

	// Hash Map은 key-value 쌍의 데이터를 저장
	// unorderedmap과 map 2가지가 있다 (key를 기준으로 오름차순으로 정렬 유무)
	// unorderedmap 같은 경우 시간복잡도가 O(1)로 속도가 빠르다는 장점
}