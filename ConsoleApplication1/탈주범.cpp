#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int N, M, R, C, L, Answer;
int Tunnel[8][4] = { { 0,0,0,0 },{ 1,1,1,1 },{ 1,0,1,0 },{ 0,1,0,1 },{ 1,0,0,1 },{ 0,0,1,1 },{ 0,1,1,0 },{ 1,1,0,0 } };//»óÁÂÇÏ¿ì
int dir[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
vector<vector<int>> map;
//vector<vector<int>> visit;
int visit[51][51];
vector<vector<int>> check;
int BFS()
{
	queue<pair<int, int>>man;
	man.push(make_pair(R, C));
	visit[R][C] = 1;
	int cnt = 0;
	int ans = 1;
	for (int i = 0; i < L - 1; i++)
	{
		int num = man.size();
		while (num--)
		{
			int x = man.front().first;
			int y = man.front().second;
			man.pop();
			int pos = map[x][y];
			for (int i = 0; i < 4; i++)//»óÁÂÇÏ¿ì
			{
				int next_x = x + dir[i][0];
				int next_y = y + dir[i][1];
				if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M || visit[next_x][next_y] == 1)continue;
				int next_pos = map[next_x][next_y];
				if (Tunnel[pos][i] && Tunnel[next_pos][(i + 2) % 4])
				{
					visit[next_x][next_y] = 1;
					man.push(make_pair(next_x, next_y));
					ans++;
				}
			}
		}
	}
	return ans;
}
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
	if (Tunnel[pos][0] && x - 1 >= 0 && Tunnel[map[x - 1][y]][2] && !visit[x - 1][y])DFS(x - 1, y, cnt + 1);
	if (Tunnel[pos][1] && y - 1 >= 0 && Tunnel[map[x][y - 1]][3] && !visit[x][y - 1])DFS(x, y - 1, cnt + 1);
	if (Tunnel[pos][2] && x + 1 < N && Tunnel[map[x + 1][y]][0] && !visit[x + 1][y])DFS(x + 1, y, cnt + 1);
	if (Tunnel[pos][3] && y + 1 < M && Tunnel[map[x][y + 1]][1] && !visit[x][y + 1])DFS(x, y + 1, cnt + 1);
	visit[x][y] = 0;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		map.clear();
		check.clear();
		//visit.clear();
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
				visit[i][j] = 0;
			}
			map.push_back(temp);
			//visit.push_back(temp1);
			check.push_back(temp1);
		}
		//DFS(R, C, 1);
		Answer = BFS();
		printf("#%d %d\n", testcase, Answer);
	}
}