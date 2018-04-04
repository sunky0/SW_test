#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define Size 10

int N, K;
int map[Size][Size];
int visit[Size][Size];//방문한 기록
int heighest;//가장 높은 산의 높이
int ans;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//좌우상하 방향
typedef struct info {
	int h, w;
	int height;
	int usedK;//공사한적이 있는지
	int len;//현재까지 등산로의 길이
};
void sol(info cur) {
	ans = ans > cur.len ? ans : cur.len;//등산로 길이가 최대가 되도록
	for (int d = 0; d < 4; d++) {
		info nxt = cur;//방향을 바꿀때마다 새로 정의되어 길이는 
		nxt.h += dir[d][0];
		nxt.w += dir[d][1];//상하좌우로 이동해보기
		nxt.height = map[nxt.h][nxt.w];

		if (nxt.h < 0 || nxt.h >= N || nxt.w < 0 || nxt.w >= N)continue;//맵을 벗어나면 건너뛰기
		if (visit[nxt.h][nxt.w])continue;//방문했어도 건너뛰기

		if (nxt.height < cur.height) {//움직인 높이가 원래보다 작다면
			visit[nxt.h][nxt.w] = 1;
			nxt.len++;
			sol(nxt);
			visit[nxt.h][nxt.w] = 0;//여기방문을..초기화해주는 이유는 다른방향으로 탐색하기 위해
		}
		else {
			if (!cur.usedK &&nxt.height - K < cur.height) {//공사한적이 없고 공사할때 높이가 원래보다 작아진다면
				visit[nxt.h][nxt.w] = 1;
				nxt.len++;
				nxt.usedK = 1;//공사했둠
				nxt.height = cur.height - 1;//K만큼 다 깍을필요 없이 현재보다 1만 작으면 되니깐
				sol(nxt);
				visit[nxt.h][nxt.w] = 0;//??
			}
		}
	}
	return;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		heighest = ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				heighest = heighest > map[i][j] ? heighest : map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (heighest == map[i][j]) {
					visit[i][j] = 1;
					info cur = { i,j,map[i][j],0,1 };
					sol(cur);
					visit[i][j] = 0;
				}
			}
		}
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}
