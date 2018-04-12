#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map_temp[8][8];
int dir[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };//동서남북
int N, M, Answer = 0;
vector<pair<int, int>> wall;
vector<int> combination;
int main()
{
	scanf("%d %d", &N, &M);
	wall.clear();
	vector<pair<int, int>> temp;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			scanf("%d", &map_temp[n][m]);
			if (map_temp[n][m] == 0)wall.push_back(make_pair(n, m));
		}
	}
	for (int i = 0; i < wall.size(); i++)
	{
		if (i < wall.size() - 3)combination.push_back(0);
		else combination.push_back(1);
	}
	do {
		queue<pair<int, int>> virus;
		bool visit[8][8];
		int map[8][8];
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				map[n][m] = map_temp[n][m];
				visit[n][m] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < wall.size(); i++)
		{
			if (combination[i] == 1)
			{
				map[wall[i].first][wall[i].second] = 1;
			}
		}//벽을 세우고
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (map[n][m] == 2 && !visit[n][m])
				{
					virus.push(make_pair(n, m));
					visit[n][m] = true;
					while (!virus.empty())
					{
						int v_x = virus.front().first;
						int v_y = virus.front().second;
						virus.pop();
						for (int i = 0; i < 4; i++)
						{
							int Vx = v_x + dir[i][0], Vy = v_y + dir[i][1];
							if (Vx < 0 || Vy < 0 || Vx >= N || Vy >= M || map[Vx][Vy] == 1 || visit[Vx][Vy])continue;//벗어나면 나가기
							map[Vx][Vy] = 2;
							visit[Vx][Vy] = true;
							virus.push(make_pair(Vx, Vy));
						}
					}
				}
			}
		}
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (map[n][m] == 0)cnt++;
			}
		}
		if (Answer < cnt)Answer = cnt;
	} while (next_permutation(combination.begin(), combination.end()));
	printf("%d\n", Answer);
	return 0;
}