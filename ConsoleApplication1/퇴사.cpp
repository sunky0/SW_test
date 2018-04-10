#include "stdafx.h"
#include <iostream>
using namespace std;
int map[15][2];
int Answer = 0, N;
void DFS(int start, int val)
{
	if (start + map[start][0] > N)
	{
		if (val > Answer)Answer = val;
		return;
	}
	else if (start + map[start][0] == N)
	{
		if (val + map[start][1] > Answer)Answer = val + map[start][1];
		return;
	}
	for (int i = start + map[start][0]; i < N; i++)
	{
		DFS(i, val + map[start][1]);
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &map[i][0], &map[i][1]);
	}
	for (int i = 0; i < N; i++)
	{
		DFS(i, 0);
	}
	printf("%d\n", Answer);
	return 0;
}