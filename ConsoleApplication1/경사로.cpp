#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
vector<int> test;
vector<int> visit;
int main() {
	int T, N, X;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		map.clear();
		scanf("%d %d", &N, &X);
		map.resize(N);
		int Answer = 2 * N;
		for (int i = 0; i < N; i++)
		{
			map[i].resize(N);
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < N; i++)
		{
			test.clear();
			visit.clear();
			visit.resize(N);
			test.resize(N);
			int temp = map[i][0];
			for (int j = 1; j < N; j++)
			{
				test[j] = map[i][j] - temp;
				temp = map[i][j];
			}
			for (int j = 1; j < N; j++)
			{
				if (test[j] == 1)
				{
					int k;
					for (k = 0; k < X; k++)
					{
						if (j - k - 1 < 0)break;
						if (visit[j - k - 1] == 0 && (test[j - k - 1] == 0 || test[j - k - 1] == 1))visit[j - k - 1] = 1;
						else break;
					}
					if (k != X)
					{
						Answer--;
						break;
					}
				}
				else if (test[j] == -1)
				{
					int k;
					visit[j] = 1;
					for (k = 1; k < X; k++)
					{
						if (j + k > N - 1)break;
						if (visit[j + k] == 0 && test[j + k] == 0)visit[j + k] = 1;
						else break;
					}
					if (k != X)
					{
						Answer--;
						break;
					}
				}
				else if (test[j] != 0)
				{
					Answer--;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			test.clear();
			visit.clear();
			visit.resize(N);
			test.resize(N);
			int temp = map[0][i];
			for (int j = 1; j < N; j++)
			{
				test[j] = map[j][i] - temp;
				temp = map[j][i];
			}
			for (int j = 1; j < N; j++)
			{
				if (test[j] == 1)
				{
					int k;
					for (k = 0; k < X; k++)
					{
						if (j - k - 1 < 0)break;
						if (visit[j - k - 1] == 0 && (test[j - k - 1] == 0|| test[j - k - 1] == 1))visit[j - k - 1] = 1;
						else break;
					}
					if (k != X)
					{
						Answer--;
						break;
					}
				}
				else if (test[j] == -1)
				{
					int k;
					visit[j] = 1;
					for (k = 1; k < X; k++)
					{
						if (j + k > N - 1)break;
						if (visit[j + k] == 0 && test[j + k] == 0)visit[j + k] = 1;
						else break;
					}
					if (k != X)
					{
						Answer--;
						break;
					}
				}
				else if (test[j] != 0)
				{
					Answer--;
					break;
				}
			}
		}
		printf("#%d %d\n", testcase, Answer);
	}
	return 0;
}