#include"stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
bool visit[10001];
int answer[10001];
bool map[10001][10001];
bool confirm[10001];
int cnt, N;
void dfs(int start, int cn)
{
	if (!confirm[start] || visit[start]) return;
	else 
	{
		answer[start]++;
		visit[start] = true;
		for (int i = 0; i < N + 1; i++)
		{
			if (map[i][start])
			{
				cnt++;
				dfs(i, cnt);
			}
		}
		answer[start] = cnt - cn;
	}
}
int main() {

	int M;
	scanf("%d %d", &N, &M);
	for (int testCase = 0; testCase < M; testCase++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		map[A][B] = true;
		confirm[B] = true;
	}
	int n = 0;
	n = !n;
	printf("%d ", n);
	/*
	int max = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cnt = 0;
		dfs(i, 0);
		if (max < cnt)max = cnt;
	}
	for (int i = 1; i < N + 1; i++)
	{
		//if (answer[i] == max)printf("%d ", i);
		printf("%d ", answer[i]);
	}
	*/
	return 0;
}