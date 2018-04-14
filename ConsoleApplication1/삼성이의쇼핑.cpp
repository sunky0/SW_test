#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> info;
int N, M, Answer, Answer_key;
void DFS(int pos, int cnt, int num, int price, int key)
{
	if (Answer < price)
	{
		Answer_key = key;
	}
	if (num > N)return;
	if (Answer < price)Answer = price;
	for (int i = pos + 1; i < M; i++)
	{
		DFS(i, cnt + 1, num + info[i].first, price + info[i].second, (key|(1<<i)));
	}
	return;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		Answer = 0;
		Answer_key = 0;
		scanf("%d %d", &N, &M);
		info.clear();
		for (int m = 0; m < M; m++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			info.push_back(make_pair(a, b));
		}
		DFS(-1, 0, 0, 0, 0);
		printf("#%d ", testcase);
		for (int m = 0; m < M; m++)
		{
			if (Answer_key&(1 << m)) printf("%d ", m);
		}
		printf("%d\n", Answer);
	}
	return 0;
}