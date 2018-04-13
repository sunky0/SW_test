#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int M, N, Answer = 0;
int main()
{
	scanf("%d %d", &M, &N);
	vector<vector<int>> map(M);
	for (int m = 0; m < M; m++)
	{
		map[m].resize(N);
		for (int n = 0; n < N; n++)
		{
			map[m][n] = 0;
		}
	}
	map[0][0] = 1;
	int x = 0, y = 0, d = 0, cnt = 0;
	for (int cnt = 0; cnt < N*M; cnt++)
	{
		d %= 4;
		x += dir[d][0];
		y += dir[d][1];
		if (x < 0 || y < 0 || x >= M || y >= N || map[x][y] == 1)
		{
			x -= dir[d][0];
			y -= dir[d][1];
			if (cnt != N * M - 1)cnt--;
			d++;
			Answer++;
		}
		else map[x][y] = 1;
	}
	printf("%d\n", Answer - 1);
	return 0;
}