#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int N, M, visit[50][50][1 << 7];
int dir[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
char map[51][51];
int main() {
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d %d", &N, &M);
		queue<pair<pair<int, int>, int>> root;
		for (int n = 0; n < N; n++)
		{
			string str;
			cin >> str;
			for (int m = 0; m < M; m++)
			{
				map[n][m] = str[m];
				if (map[n][m] == '0')
				{
					root.push(make_pair(make_pair(n, m), 0));
					visit[n][m][0] = 1;
				}
			}
		}
		bool success = false;
		int Answer = 0;
		while (!root.empty())
		{
			int num = root.size();
			if (success)break;
			while (num--)
			{
				int x = root.front().first.first;
				int y = root.front().first.second;
				int key = root.front().second;
				root.pop();
				if (map[x][y] == '1')
				{
					success = true;
					break;
				}
				for (int i = 0; i < 4; i++)
				{
					int next_x = x + dir[i][0];
					int next_y = y + dir[i][1];
					if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M || map[next_x][next_y] == '#')continue;
					if ('a' <= map[next_x][next_y] && map[next_x][next_y] <= 'f')
					{
						int next_key = key | (1 << (map[next_x][next_y] - 'a'));
						if (visit[next_x][next_y][next_key])continue;
						visit[next_x][next_y][next_key] = 1;
						root.push(make_pair(make_pair(next_x, next_y), next_key));
					}
					else if ('A' <= map[next_x][next_y] && map[next_x][next_y] <= 'F' && !visit[next_x][next_y][key]) {
						if (key&(1 << map[next_x][next_y] - 'A'))
						{
							visit[next_x][next_y][key] = 1;
							root.push(make_pair(make_pair(next_x, next_y), key));
						}
					}
					else if (!visit[next_x][next_y][key]) {
						visit[next_x][next_y][key] = 1;
						root.push(make_pair(make_pair(next_x, next_y), key));
					}
				}
			}
			Answer++;
		}
		if (!success)Answer = 0;
		printf("#%d %d\n", testcase, Answer - 1);
	}
	return 0;
}