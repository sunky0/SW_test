#include"stdafx.h"
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define SIZE 101
int map[SIZE][SIZE];
int inputmap[SIZE][SIZE];
bool visit[SIZE][SIZE];
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int N ,dis = 1000, landNumber = 1;
queue<pair<int, int>> que;

void bfs(int i, int j, int landNumber) {
	int y, x, nexty, nextx;
	que.push(make_pair(i, j));

	while (!que.empty()) {
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			nexty = y + dy[i];
			nextx = x + dx[i];

			if (0 <= nextx && nextx < N && 0 <= nexty && nexty < N) {
				if (inputmap[nexty][nextx] & !map[nexty][nextx]) {//그 주변이 1이고 map은0이면 같은 구역
					map[nexty][nextx] = landNumber;
					que.push(make_pair(nexty, nextx));
				}
			}
		}
	}
}
void dfs(int x, int y, int land, int cnt)
{
	visit[x][y] = true;//시간 줄이는 마법의 방문여부 
	if (cnt >= dis) return;
	int nextx, nexty;
	for (int k = 0; k < 4; ++k) 
	{
		nexty = y + dy[k];
		nextx = x + dx[k];

		if (0 <= nextx && nextx < N && 0 <= nexty && nexty < N && map[nextx][nexty] != land && !visit[nextx][nexty])
		{
			if (map[nextx][nexty] == 0) dfs(nextx, nexty, land, cnt + 1);
			else
			{	
				if (dis > cnt) dis = cnt;
			}
		}
		else continue;
	}
}
void resett()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &inputmap[i][j]);
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (inputmap[i][j] & !map[i][j]) {//1이고 map이 0이라면
				map[i][j] = landNumber;
				bfs(i, j, landNumber++);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] != 0)
			{
				dfs(i, j, map[i][j], 0);
				resett();
			}
		}
	}
	cout << dis << endl;
	return 0;
}