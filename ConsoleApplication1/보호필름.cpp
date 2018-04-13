#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int D, W, K, Answer;
int Film[13][20];
bool visit[14];
int temp[20], max_val[20];
void DFS(int pos,int cnt, int save[13][20])//변경할 행, 카운트, 변경전 행 정보
{
	if (cnt >= Answer)return;
	bool success = false;
	int tem[13][20];
	for (int d = 0; d < D; d++)
	{
		for (int w = 0; w < W; w++)
		{
			tem[d][w] = save[d][w];
		}
	}
	for (int w = 0; w < W; w++)
	{
		int val = save[0][w], val_cnt = 1, val_final = 0;
		for (int d = 1; d < D; d++)
		{
			if (val != save[d][w])
			{
				if (val_final < val_cnt)val_final = val_cnt;
				val = save[d][w];
				val_cnt = 1;
			}
			else ++val_cnt;
		}
		if (val_final < val_cnt)val_final = val_cnt;
		max_val[w] = val_final;
	}
	for (int w = 0; w < W; w++)
	{
		if (max_val[w] < K)break;
		if (w == W - 1)success = true;
	}
	if (success)
	{
		if (Answer > cnt)Answer = cnt;
		return;
	}
	else//성공하지 못했다면
	{
		for (int d = 0; d < D; d++)
		{
			if (!visit[d])
			{
				for (int w = 0; w < W; w++)tem[d][w] = 0;
				visit[d] = true;
				DFS(d, cnt + 1, tem);
				for (int w = 0; w < W; w++)tem[d][w] = 1;
				DFS(d, cnt + 1, tem);
				visit[d] = false;
				for (int w = 0; w < W; w++)tem[d][w] = save[d][w];
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d %d %d", &D, &W, &K);
		for (int d = 0; d < D; d++)
		{
			for (int w = 0; w < W; w++)
			{
				scanf("%d ", &Film[d][w]);
			}//0-A, 1-B
		}
		for (int i = 0; i < 13; i++)visit[i] = false;
		Answer = K;
		DFS(13, 0, Film);
		printf("#%d %d\n", testcase, Answer);
	}
	return 0;
}