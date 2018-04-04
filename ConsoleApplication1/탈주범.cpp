#include "stdafx.h"
#include <stdio.h>
#include <vector>
using namespace std;
int N, M, R, C, L, Answer;
int Tunnel[8][4] = { {0,0,0,0}, {1,1,1,1}, {1,1,0,0}, {0,0,1,1}, {1,0,0,1}, {0,1,0,1}, {0,1,1,0}, {1,0,1,0} };//»óÇÏÁÂ¿ì
vector<vector<int>> map;
vector<vector<int>> visit;
vector<vector<int>> check;
void DFS(int x, int y, int cnt)
{
	if (check[x][y] == 0)
	{
		check[x][y] = 1;
		Answer++;
	}
	visit[x][y] = 1;
	if (cnt >= L)
	{
		visit[x][y] = 0;
		return;
	}
	int pos = map[x][y];
	if (Tunnel[pos][0] && x - 1 >= 0 && Tunnel[map[x - 1][y]][1] && !visit[x - 1][y])DFS(x - 1, y, cnt + 1);
	if (Tunnel[pos][1] && x + 1 < N && Tunnel[map[x + 1][y]][0] && !visit[x + 1][y])DFS(x + 1, y, cnt + 1);
	if (Tunnel[pos][2] && y - 1 >= 0 && Tunnel[map[x][y - 1]][3] && !visit[x][y - 1])DFS(x, y - 1, cnt + 1);
	if (Tunnel[pos][3] && y + 1 < M && Tunnel[map[x][y + 1]][2] && !visit[x][y + 1])DFS(x, y + 1, cnt + 1);
	visit[x][y] = 0;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		map.clear();
		check.clear();
		visit.clear();
		Answer = 0;
		int val;
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++)
		{
			vector<int> temp;
			vector<int> temp1;
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &val);
				temp.push_back(val);
				temp1.push_back(0);
			}
			map.push_back(temp);
			visit.push_back(temp1);
			check.push_back(temp1);
		}
		DFS(R, C, 1);
		printf("#%d %d\n", testcase, Answer);
	}
}