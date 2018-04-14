#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[16][16], visit[16][16];
int dir[4][2] = {{-1,0} ,{0,-1} ,{1,0} ,{0,1} };
int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int N;
		scanf("%d", &N);
		vector<pair<int, int>> vortex;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < N; m++)
			{
				scanf("%d", &map[n][m]);
				if (map[n][m] == 2)
				{
					vortex.push_back(make_pair(n, m));
				}
				visit[n][m] = 0;
			}
		}
		int A, B, C, D;
		scanf("%d %d", &A, &B);
		scanf("%d %d", &C, &D);
		queue<pair<int, int>> road;
		road.push(make_pair(A, B));
		visit[A][B] = 1;
		int cnt = 0;//초임
		bool success = false;
		while (!road.empty())
		{
			//map 변형
			if (cnt % 3 == 2)
			{
				for (int i = 0; i < vortex.size(); i++)
				{
					map[vortex[i].first][vortex[i].second] = 0;
				}
			}
			else
			{
				for (int i = 0; i < vortex.size(); i++)
				{
					map[vortex[i].first][vortex[i].second] = 2;
				}
			}
			int num = road.size();
			while (num--)
			{
				bool wait = false;
				int x = road.front().first;
				int y = road.front().second;
				road.pop();
				for (int i = 0; i < 4; i++)
				{
					int next_x = x + dir[i][0];
					int next_y = y + dir[i][1];
					if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || map[next_x][next_y] == 1||visit[next_x][next_y] == 1)continue;
					if (map[next_x][next_y] == 2 && cnt % 3 != 2)
					{
						wait = true;
						continue;
					}
					if (next_x == C && next_y == D)
					{
						success = true;
						break;
					}
					visit[next_x][next_y] = 1;
					road.push(make_pair(next_x, next_y));
				}
				if(wait)road.push(make_pair(x, y));
				if (success)break;
			}
			cnt++;
			if (success)break;
		}
		if (!success)cnt = -1;
		printf("#%d %d\n", testcase, cnt);
	}
	return 0;
}