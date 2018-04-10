#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int N, K, L, x, y, X, x_t, y_t, t = 0, dir = 3;//dir 0:북, 1:서 2:남 3:동
	char C;
	scanf("%d", &N);
	int map[102][102];
	queue<pair<int, int>>snack;
	for (int i = 0; i < N + 2; i++)
	{
		map[i][0] = 1;
		map[i][N + 1] = 1;
		for (int j = 1; j < N + 1; j++)
		{
			if (i == 0 || i == N + 1)map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	map[1][1] = 1;
	scanf("%d", &K);
	for (int k = 0; k < K; k++)
	{
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}
	scanf("%d", &L);
	x = 1; y = 1;//초기머리
	snack.push(make_pair(1, 1));
	for (int i = 0; i < L; i++)
	{
		scanf("%d %c", &X, &C);
		while (t <= X)
		{
			x_t = snack.front().first;
			y_t = snack.front().second;
			if (t == X)
			{
				if (dir == 0)
				{
					if (C == 'L')dir = 1;
					else dir = 3;
				}
				else if (dir == 1)
				{
					if (C == 'L')dir = 2;
					else dir = 0;
				}
				else if (dir == 2)
				{
					if (C == 'L')dir = 3;
					else dir = 1;
				}
				else if (dir == 3)
				{
					if (C == 'L')dir = 0;
					else dir = 2;
				}
				if (i == L - 1)X = 0x7FFFFFFF;
			}
			if (dir == 0)
			{
				if (map[x - 1][y] == 2)
				{
					map[x - 1][y] = 1;
					snack.push(make_pair(x - 1, y));
					x -= 1;
				}
				else if (map[x - 1][y] == 1)break;
				else
				{
					map[x - 1][y] = 1;
					snack.push(make_pair(x - 1, y));
					map[x_t][y_t] = 0;
					snack.pop();
					x -= 1;
				}
			}
			else if (dir == 1)
			{
				if (map[x][y - 1] == 2)
				{
					map[x][y - 1] = 1;
					snack.push(make_pair(x, y - 1));
					y -= 1;
				}
				else if (map[x][y - 1] == 1)break;
				else
				{
					map[x][y - 1] = 1;
					snack.push(make_pair(x, y - 1));
					map[x_t][y_t] = 0;
					snack.pop();
					y -= 1;
				}
			}
			else if (dir == 2)
			{
				if (map[x + 1][y] == 2)
				{
					map[x + 1][y] = 1;
					snack.push(make_pair(x + 1, y));
					x += 1;
				}
				else if (map[x + 1][y] == 1)break;
				else
				{
					map[x + 1][y] = 1;
					snack.push(make_pair(x + 1, y));
					map[x_t][y_t] = 0;
					snack.pop();
					x += 1;
				}
			}
			else if (dir == 3)
			{
				if (map[x][y + 1] == 2)
				{
					map[x][y + 1] = 1;
					snack.push(make_pair(x, y + 1));
					y += 1;
				}
				else if (map[x][y + 1] == 1)break;
				else
				{
					map[x][y + 1] = 1;
					snack.push(make_pair(x, y + 1));
					map[x_t][y_t] = 0;
					snack.pop();
					y += 1;
				}
			}
			t++;
		}
		if (t != X + 1)break;
	}
	printf("%d\n", t + 1);
	return 0;
}