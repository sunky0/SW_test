#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, visit[11][11][11][11], bx, by, rx, ry;
char map[11][11];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> ball;
	ball.push(make_pair(make_pair(rx, ry), make_pair(bx, by)));
	visit[rx][ry][bx][by] = 1;
	int cnt = 0;
	while (!ball.empty()) {
		int num = ball.size();
		for (int i = num; i > 0; i--)
		{
			int r_x = ball.front().first.first;
			int r_y = ball.front().first.second;
			int b_x = ball.front().second.first;
			int b_y = ball.front().second.second;
			ball.pop();
			if (map[r_x][r_y] == 'O'&&map[r_x][r_y] != map[b_x][b_y])//빨간공만 빠졌을 때
				return cnt;
			for (int i = 0; i < 4; i++) {
				int Rx = r_x, Ry = r_y, Bx = b_x, By = b_y;
				while (map[Rx + dir[i][0]][Ry + dir[i][1]] != '#'&&map[Rx][Ry] != 'O') {
					Rx += dir[i][0];
					Ry += dir[i][1];
				}//빨강공 움직움직
				while (map[Bx + dir[i][0]][By + dir[i][1]] != '#'&&map[Bx][By] != 'O') {
					Bx += dir[i][0];
					By += dir[i][1];
				}//파란공 움직움직
				if (Rx == Bx && Ry == By) {//같은 위치라면
					if (map[Rx][Ry] == 'O')continue;//동시에 구멍에 빠지면 실패
					if (abs(Rx - r_x) + abs(Ry - r_y) < abs(Bx - b_x) + abs(By - b_y)) {//Blue가 뒤에이쑴
						Bx -= dir[i][0];
						By -= dir[i][1];
					}//빼줘야 함
					else {
						Rx -= dir[i][0];
						Ry -= dir[i][1];
					}
				}
				if (visit[Rx][Ry][Bx][By])continue;//방문을 했다면 넘어가고
				ball.push(make_pair(make_pair(Rx, Ry), make_pair(Bx, By)));//안했다면 넣어줌
				visit[Rx][Ry][Bx][By] = 1;//방문표시도 해줌
			}
		}
		if (cnt == 10)
			return -1;
		cnt++;
	}
	return -1;
}
int Answer = 11;
void DFS(int r_x, int r_y, int b_x, int b_y, int cnt)
{
	if (map[r_x][r_y] == 'O'&&map[r_x][r_y] != map[b_x][b_y])//빨간공만 빠졌을 때
	{
		if (Answer > cnt)Answer = cnt;
		return;
	}
	if (cnt > 10)return;
	else
	{
		for (int i = 0; i < 4; i++) {
			int Rx = r_x, Ry = r_y, Bx = b_x, By = b_y;
			while (map[Rx + dir[i][0]][Ry + dir[i][1]] != '#'&&map[Rx][Ry] != 'O') {
				Rx += dir[i][0];
				Ry += dir[i][1];
			}
			while (map[Bx + dir[i][0]][By + dir[i][1]] != '#'&&map[Bx][By] != 'O') {
				Bx += dir[i][0];
				By += dir[i][1];
			}
			if (Rx == Bx && Ry == By) {//같은 위치라면
				if (map[Rx][Ry] == 'O')continue;//동시에 구멍에 빠지면 실패
				if (abs(Rx - r_x) + abs(Ry - r_y) < abs(Bx - b_x) + abs(By - b_y)) {//Blue가 뒤에이쑴
					Bx -= dir[i][0];
					By -= dir[i][1];
				}//빼줘야 함
				else {
					Rx -= dir[i][0];
					Ry -= dir[i][1];
				}
			}
			if (visit[Rx][Ry][Bx][By])continue;//방문을 했다면 넘어가고
			visit[Rx][Ry][Bx][By] = 1;//방문표시도 해줌
			DFS(Rx, Ry, Bx, By, cnt + 1);
			visit[Rx][Ry][Bx][By] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	//DFS(rx, ry, bx, by, 0);
	//if (Answer == 11)Answer = -1;
	//printf("%d\n", Answer);
	printf("%d\n",bfs());
	return 0;
}