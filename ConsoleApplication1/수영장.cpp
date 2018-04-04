#include "stdafx.h"
#include<stdio.h>
int cost[4];
int plan[12];
int minn = 1 << 30;
void req(int cnt, int val)
{
	if (cnt >= 12)
	{
		if (minn > val)minn = val;
		return;
	}
	req(cnt + 1, val + plan[cnt] * cost[0]);
	req(cnt + 1, val + cost[1]);
	req(cnt + 3, val + cost[2]);
	req(cnt + 12, val + cost[3]);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		minn = 1 << 30;
		for (int i = 0; i < 4; i++)scanf("%d", &cost[i]);
		for (int i = 0; i < 12; i++)scanf("%d", &plan[i]);
		req(0, 0);
		printf("#%d %d\n", testCase + 1, minn);
	}
	return 0;
}