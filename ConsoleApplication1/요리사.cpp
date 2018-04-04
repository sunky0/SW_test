#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
int main() {
	int T, N;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		map.clear();
		scanf("%d", &N);
		int Answer = 1 << 30;
		for (int i = 0; i < N; i++)
		{
			vector<int> temp;
			int val;
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &val);
				temp.push_back(val);
			}
			map.push_back(temp);
		}
		vector<int> position;
		for (int n = 0; n < N; n++) {
			if (n < N / 2)position.push_back(-1);
			else position.push_back(1);
		}
		do {
			int Sum1 = 0, Sum2 = 0;
			for (int n = 0; n < N; n++) 
			{
				if (position[n] == 1) 
				{
					for (int m = n + 1; m < N; m++)
					{
						if (position[m] == 1)Sum1 += (map[n][m] + map[m][n]);
					}
				}
				else
				{
					for (int m = n + 1; m < N; m++)
					{
						if (position[m] == -1)Sum2 += (map[n][m] + map[m][n]);
					}
				}
			}
			int ab = abs(Sum1 - Sum2);
			if (Answer > ab)Answer = ab;
		} while (next_permutation(position.begin(), position.end()));
		printf("#%d %d\n", testcase, Answer);
	}
	return 0;
}