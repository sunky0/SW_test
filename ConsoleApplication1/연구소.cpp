#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
int map[8][8];
int N, M;
int main()
{
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			scanf("%d", &map[n][m]);
		}
	}
	return 0;
}