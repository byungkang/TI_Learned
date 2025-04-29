#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int N;
int M;
int move_count;

int maps[21][21];
int d_direction[6];
//d_direction[0] = 앞
//d_direction[1] = 위
//d_direction[2] = 뒤
//d_direction[3] = 아
//d_direction[4] = 좌
//d_direction[5] = 우



pair<int, int> now_position;

int movedirection = 1;
int under_value;

// 주사위를 회전하여 아랫면 찾기
void rotate_dice(int direction)
{
	//d_direction[1] = 위
	//d_direction[3] = 아
	//d_direction[4] = 좌
	//d_direction[5] = 우
	int temp_direction[6];
	if (direction == 1)
	{		
		temp_direction[1] = d_direction[4];
		temp_direction[3] = d_direction[5];
		temp_direction[4] = d_direction[3];
		temp_direction[5] = d_direction[1];
		temp_direction[2] = d_direction[2];
		temp_direction[0] = d_direction[0];
		for (int i = 0; i < 6; i++)
		{
			d_direction[i] = temp_direction[i];
		}
		under_value = d_direction[3];
	}
	else if (direction == 2)
	{
		temp_direction[1] = d_direction[5];
		temp_direction[3] = d_direction[4];
		temp_direction[4] = d_direction[1];
		temp_direction[5] = d_direction[3];
		temp_direction[2] = d_direction[2];
		temp_direction[0] = d_direction[0];		
		for (int i = 0; i < 6; i++)
		{
			d_direction[i] = temp_direction[i];
		}
		under_value = d_direction[3];
	}
	//d_direction[0] = 앞
	//d_direction[1] = 위
	//d_direction[2] = 뒤
	//d_direction[3] = 아

	else if (direction == 3)
	{
		temp_direction[0] = d_direction[1];
		temp_direction[1] = d_direction[2];
		temp_direction[2] = d_direction[3];
		temp_direction[3] = d_direction[0];
		temp_direction[4] = d_direction[4];
		temp_direction[5] = d_direction[5];
		for (int i = 0; i < 6; i++)
		{
			d_direction[i] = temp_direction[i];
		}
		under_value = d_direction[3];
	}
	else if (direction == 4)
	{
		temp_direction[0] = d_direction[3];
		temp_direction[1] = d_direction[0];
		temp_direction[2] = d_direction[1];
		temp_direction[3] = d_direction[2];
		temp_direction[4] = d_direction[4];
		temp_direction[5] = d_direction[5];
		for (int i = 0; i < 6; i++)
		{
			d_direction[i] = temp_direction[i];
		}
		under_value = d_direction[3];
	}
}

// 주사위의 현재 위치 찾기
void move_position(int direction)
{
	if (direction == 1)
	{
		now_position.second = now_position.second + 1;
	}
	else if (direction == 2)
	{
		now_position.second = now_position.second - 1;
	}
	else if (direction == 3)
	{
		now_position.first = now_position.first - 1;
	}
	else if (direction == 4)
	{
		now_position.first = now_position.first + 1;
	}
}

// 칸(x,y)에 대한 값 찾기
void find_mapvalue(int nowvalue, stack<int> &t_row, stack<int>& t_col, int &count, bool check_position[][21])
{
	if (!t_row.empty() && !t_col.empty())
	{
		int x = t_row.top();
		int y = t_col.top();
		check_position[x][y] = true;

		// 왼쪽 오른쪽
		for (int i = -1; i <= 1; i += 2)
		{
			if (maps[x][y + i] == nowvalue && 1 <= (y + i) <= M &&  check_position[x][y+i] != 1)
			{				
				count++;
				t_row.push(x);
				t_col.push(y + i);
				find_mapvalue(nowvalue, t_row, t_col, count, check_position);
			}
			else
			{
				continue;
			}
		}
		// 위 아래 
		for (int i = -1; i <= 1; i += 2)
		{
			if (maps[x+i][y] == nowvalue && 1 <= (x + i) <= N && check_position[x+i][y] != 1)
			{
				count++;
				t_row.push(x+i);
				t_col.push(y);
				find_mapvalue(nowvalue, t_row, t_col, count, check_position);
			}
			else
			{
				continue;
			}
		}
		if (!t_row.empty() && !t_col.empty())
		{
			t_row.pop();
			t_col.pop();
		}
		else
		{
			return;
		}
		
	}	
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	d_direction[0] = 2;
	d_direction[1] = 1;
	d_direction[2] = 5;
	d_direction[3] = 6;
	d_direction[4] = 4;
	d_direction[5] = 3;

	under_value = d_direction[3];

	// 1 : east,	2 : west	3 : north	4 : south 
	cin >> N >> M >> move_count;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> maps[i][j];
		}
	}

	// first는 행의 위치 second는 열의 위치
	now_position.first = 1;
	now_position.second = 1;
	
	int final_resultvalue = 0;

	for (int i = 0; i < move_count; i++)
	{
		// 방향 이동
		move_position(movedirection);
		if (now_position.first < 1 || now_position.first > N || now_position.second < 1 || now_position.second > M)
		{
			if (movedirection == 1)
			{
				movedirection = 2;
				move_position(movedirection);
				move_position(movedirection);
			}
			else if (movedirection == 2)
			{
				movedirection = 1;
				move_position(movedirection);
				move_position(movedirection);
			}
			else if (movedirection == 3)
			{
				movedirection = 4;
				move_position(movedirection);
				move_position(movedirection);
			}
			else if (movedirection == 4)
			{
				movedirection = 3;
				move_position(movedirection);
				move_position(movedirection);
			}
		}

		// 방향 이동에 맞춰 주사위 회전
		rotate_dice(movedirection);

		
		stack<int> t_row;
		stack<int> t_col;
		int now_value = 1;
		t_row.push(now_position.first);
		t_col.push(now_position.second);
		bool checkpo[21][21] = { 0, };
		find_mapvalue(maps[now_position.first][now_position.second], t_row, t_col, now_value, checkpo);

		final_resultvalue += maps[now_position.first][now_position.second] * now_value;


		// 다음 주사위 이동 방향 설정 
		if (under_value > maps[now_position.first][now_position.second])
		{
			if (movedirection == 1)
			{
				movedirection = 4;
			}
			else if (movedirection == 2)
			{
				movedirection = 3;
			}
			else if (movedirection == 3)
			{
				movedirection = 1;
			}
			else if (movedirection == 4)
			{
				movedirection = 2;
			}
		}
		else if (under_value < maps[now_position.first][now_position.second])
		{
			if (movedirection == 1)
			{
				movedirection = 3;
			}
			else if (movedirection == 2)
			{
				movedirection = 4;
			}
			else if (movedirection == 3)
			{
				movedirection = 2;
			}
			else if (movedirection == 4)
			{
				movedirection = 1;
			}
		}
	}

	cout << final_resultvalue << "\n";
}

