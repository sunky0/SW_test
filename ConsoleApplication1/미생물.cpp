#include "stdafx.h"
#include <stdio.h>
typedef struct micro {
	int y, x, max, move, sum;
};
int visited[101][101];
micro group[1001];
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };
int N, M, K;
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++) 
	{
		scanf("%d %d %d", &N, &M, &K);
		for (int k = 1; k <= K; k++)
		{
			scanf("%d %d %d %d", &group[k].y, &group[k].x, &group[k].max, &group[k].move);
			group[k].sum = group[k].max;
		}
		while (M--) {
			for (int i = 1; i <= K; i++) {
				group[i].y += dir[group[i].move][0];
				group[i].x += dir[group[i].move][1];
				if (group[i].y == 0 || group[i].y == N - 1 || group[i].x == 0 || group[i].x == N - 1) {
					group[i].max /= 2;
					group[i].sum /= 2;
					group[i].move += (group[i].move & 1) ? 1 : -1;//짝수일때 홀수일때
				}
				if (visited[group[i].y][group[i].x]) {////중요
					int tmp = visited[group[i].y][group[i].x];
					group[tmp].sum += group[i].max;
					if (group[i].max > group[tmp].max) {
						group[tmp].max = group[i].max;
						group[tmp].move = group[i].move;
					}
					if (i != K)
						group[i--] = group[K];
					else
						group[i] = { 0, 0, 0, 0, 0 };
					K--;//앞으로 밀어낸다
				}
				else
					visited[group[i].y][group[i].x] = i;
			}
			for (int i = 1; i <= K; i++) {
				visited[group[i].y][group[i].x] = 0;
				group[i].max = group[i].sum;
			}
		}
		int result = 0;
		for (int i = 1; i <= K; i++)
			result += group[i].sum;

		printf("#%d %d\n", testcase, result);
	}
	return 0;
}