#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, Answer;
int main() {
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		Answer = 0;
		scanf("%d %d", &N, &M);
		vector<vector<int>> map(N);
		for (int i = 0; i < N; i++)
		{
			map[i].resize(N);
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (int k = 1; k<N * 2; k++)
		{
			int cost = k*k + (k - 1)*(k - 1);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					int cnt = 0;
					for (int a = 0; a < N; a++)
					{
						for (int b = 0; b < N; b++)
							if (map[a][b] && abs(i - a) + abs(j - b) < k) cnt++;
					}
					if (cnt*M >= cost) Answer = max(Answer, cnt);
				}
			}
		}

		printf("#%d %d\n", testcase, Answer);
	}
}