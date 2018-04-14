#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int result[51] = { -1, };
int grade[51];
bool visit[51];
int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < 51; i++)result[i] = -1;
		for (int i = 0; i < 51; i++)visit[i] = false;
		vector<deque<int>>man(N);
		vector<vector<int>>team(N);
		for (int i = 0; i < N; i++)
		{
			man[i].resize(N);
			for (int j = 0; j < N; j++)	scanf("%d", &man[i][j]);
		}
		for (int i = 0; i < N; i++)
		{
			team[i].resize(N);
			for (int j = 0; j < N; j++)
			{
				int tem;
				scanf("%d", &tem);
				team[i][tem - 1] = j;//¼ø¼­
			}
		}
		for (int i = 0; i < N; i++)
		{
			int mm = 52, g_mm=0;
			for (int j = 0; j < N; j++)
			{
				if (!man[j].empty() && result[j] == -1 && mm > team[man[j][0] - 1][j])
				{
					mm = team[man[j][0] - 1][j];
					g_mm = j;
				}
			}
			if(!man[g_mm].empty())
			{
				result[g_mm] = man[g_mm][0];
				visit[man[g_mm][0]] = true;
			}
			for (int j = 0; j < N; j++)
			{
				while (!man[j].empty() && visit[man[j][0]])man[j].pop_front();
			}
		}
		printf("#%d\n", testcase);
		for (int i = 0; i < N; i++)printf("%d\n", result[i]);
	}
	return 0;
}