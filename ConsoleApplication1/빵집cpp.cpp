#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> bread;
int R, C;
int dir[2] = {0,1};
int DFS(int x, int y)
{
	bread[x][y] = '-';
	if (y == C - 1)return 1;
	else
	{
		for (int i = 0; i < 2; i++) {
				int r = x + dir[i];

				if (r < 0 || y < -1 || r > R - 1 || y > C - 2 || bread[r][y + 1] == 'x' || bread[r][y + 1] == '-')
					continue;

				if (DFS(r, y + 1) == 1)return 1;
			}
	}
	return 0;
}
int main()
{
	scanf("%d %d", &R, &C);
	bread.clear();
	for (int r = 0; r < R; r++)
	{
		string str;
		cin >> str;
		bread.push_back(str);
	}
	int ans = 0;
	for (int r = 0; r < R; r++)
	{
		ans += DFS(r, 0);// 첫번째 열에서 출봘
	}
	printf("%d\n", ans);
	return 0;
}