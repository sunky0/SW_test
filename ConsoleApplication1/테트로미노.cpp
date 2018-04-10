#include "stdafx.h"
#include <iostream>
using namespace std;
int map[500][500];
int N, M, Answer = -0x7FFFFFFF;
void DFS(int x, int y, int cnt, int val, int dir)//0ºÏ 1¼­ ³²2 µ¿3
{
	if (cnt >= 3)
	{
		if (val > Answer)Answer = val;
		return;
	}
	if (cnt == 1)
	{
		if (dir == 0 && x - 1 >= 0)
		{
			if (y - 1 >= 0)DFS(x - 1, y, cnt + 2, val + map[x - 1][y] + map[x][y - 1], 0);
			if (y + 1 < M)DFS(x - 1, y, cnt + 2, val + map[x - 1][y] + map[x][y + 1], 0);
		}
		if (dir == 1 && y - 1 >= 0)
		{
			if (x + 1 < N)DFS(x, y - 1, cnt + 2, val + map[x][y - 1] + map[x + 1][y], 1);
			if (x - 1 >= 0)DFS(x, y - 1, cnt + 2, val + map[x][y - 1] + map[x - 1][y], 1);
		}
		if (dir == 2 && x + 1 < N)
		{
			if (y - 1 >= 0)DFS(x - 1, y, cnt + 2, val + map[x + 1][y] + map[x][y - 1], 2);
			if (y + 1 < M)DFS(x - 1, y, cnt + 2, val + map[x + 1][y] + map[x][y + 1], 2);
		}
		if (dir == 3 && y + 1 < M)
		{
			if (x + 1 < N)DFS(x, y - 1, cnt + 2, val + map[x][y + 1] + map[x + 1][y], 3);
			if (x - 1 >= 0)DFS(x, y - 1, cnt + 2, val + map[x][y + 1] + map[x - 1][y], 3);
		}
	}
	if (dir != 2 && x - 1 >= 0)DFS(x - 1, y, cnt + 1, val + map[x - 1][y], 0);
	if (dir != 3 && y - 1 >= 0)DFS(x, y - 1, cnt + 1, val + map[x][y - 1], 1);
	if (dir != 0 && x + 1 < N)DFS(x + 1, y, cnt + 1, val + map[x + 1][y], 2);
	if (dir != 1 && y + 1 < M)DFS(x, y + 1, cnt + 1, val + map[x][y + 1], 3);
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			DFS(i, j, 0, map[i][j], -1);
		}
	}
	printf("%d\n", Answer);
	return 0;
}