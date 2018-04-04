#include "stdafx.h"
#include <stdio.h>
int road[20][20];
int dir[4][2] = { { -1, 1 } ,{ 1, 1 },{ 1, -1 },{ -1, -1 } };
int N, maxs = -1, x_in, y_in, ans = -1, up, down;
bool visit[101];
void clr()
{
	for (int i = 0; i < 101; i++)visit[i] = false;
}
void clr2()
{
	for (int i = 0; i<20; i++)
		for (int j = 0; j<20; j++)
			road[i][j] = 0;
}
int req(int x, int y, int upp, int downn, int d, int cnt)
{
	if (cnt == 0 || x_in==6)printf("%d %d-- %d %d\t", x_in, y_in, upp, downn);
	if (cnt != 0 && x_in == x && y_in == y)
	{
		if (cnt > maxs)maxs = cnt;
		return maxs;
	}
	if (visit[road[x][y]]) {/*if(x_in==6)printf("%d visit\n", road[x][y]);*/ return -1;  }
	visit[road[x][y]] = true;

	//if(x_in==6)printf("%d %d--%d %d: %d --%d %d : %d %d\n", x_in, y_in, x, y, road[x][y],maxs, cnt, upp, downn);
	int xx = x + dir[d][0];
	int yy = y + dir[d][1];
	int dd = d;
	if (cnt == upp || cnt == upp + downn || cnt == upp * 2 + downn)
	{
		dd = (d + 1) % 4;
		xx = x + dir[dd][0];
		yy = y + dir[dd][1];
	}
	if (req(xx, yy, upp, downn, dd, cnt + 1) == -1)
	{
		clr();
		//if(x_in==6)printf("$$\n");
		if ((upp + downn) * 2 >ans)
		{
			if (upp - 1 != 0)req(x_in, y_in, upp - 1, downn, 0, 0);
			if (downn - 1 != 0)req(x_in, y_in, upp, downn - 1, 0, 0);
		}
	}
	return maxs;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		clr2();
		maxs = -1, ans = -1;
		scanf("%d", &N);
		int v;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < N; m++)
			{
				scanf("%d", &v);
				road[n][m] = v;
			}
		}
		for (int n = 1; n < N - 1; n++)
		{
			for (int m = 0; m < N - 2; m++)
			{
				clr();
				up = 1; down = 1;
				if (m >= N - n - 1)
				{
					up = N - m - 2;
					down = 1;
				}
				else
				{
					up = n;
					down = N - n - 1 - m;
				}
				int temp = -1;
				if ((up + down) * 2 >ans)
				{
					x_in = n;
					y_in = m;
					temp = req(n, m, up, down, 0, 0);
				}
				if (ans < temp)ans = temp;
				if(n==6)printf("%d \n", temp);
			}
		}
		printf("#%d %d\n", testCase + 1, ans);
	}
	return 0;
}

//#include<cstdio>
//
//int M[20][20] = { 0 };
//int N;
//int drow[4] = { 1, 1, -1, -1 };
//int dcol[4] = { -1, 1, 1, -1 };
//
//using namespace std;
//
//int search() {
//	int ans = -1;
//	for (int L = N - 1; L > 1; L--) {
//		for (int start_row = 0; start_row < N - L; start_row++) {
//			for (int start_col = 0; start_col < N - L; start_col++) {
//
//				for (int search_col = start_col + 1; search_col < start_col + L; search_col++) {
//					int dir = 0;
//					int row = start_row, col = search_col;
//					bool V[101] = { 0 };
//					while (1) {
//						if (dir == 3 && row == start_row && col == search_col) {
//							return (L) * 2;
//						}
//						else if (row + drow[dir] >= start_row && row + drow[dir] < start_row + L + 1 && col + dcol[dir] >= start_col && col + dcol[dir] < start_col + L + 1) {
//							row += drow[dir];
//							col += dcol[dir];
//							if (!V[M[row][col]]) {
//								V[M[row][col]] = true;
//							}
//							else {
//								break;
//							}
//						}
//						else {
//							dir++;
//						}
//					}
//				}
//			}
//		}
//	}
//	return ans;
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	for (int test_case = 1; test_case <= T; test_case++) {
//		scanf("%d", &N);
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				scanf("%d", &M[i][j]);
//			}
//		}
//
//		printf("#%d %d\n", test_case, search());
//	}
//
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int N, max;
//int dx[4] = { 1, 1, -1, -1 };
//int dy[4] = { 1, -1, -1, 1 };
//int len[4];
//int chk[101];
//int map[22][22];
//
//void clear(void){
//	int i;
//	for (i = 0; i < 101; i++)chk[i] = 0;
//}
//void travel(int x, int y, int l1, int l2){
//	int i, j;
//	len[0] = l1;len[1] = l2;
//	len[2] = l1;len[3] = l2;
//	for (i = 0; i < 4; i++){
//		for (j = 0; j < len[i]; j++){
//			x += dx[i];
//			y += dy[i];
//			if (chk[map[x][y]]) return;
//			chk[map[x][y]] = 1;
//		}
//	}
//	max = l1 + l2;
//}
//
//int main(void){
//	int t, T, i, j, l1, l2;
//	scanf("%d", &T);
//	for (t = 1; t <= T; t++){
//		scanf("%d", &N);
//		for (i = 1; i <= N; i++){
//			for (j = 1; j <= N; j++){
//				scanf("%d", &map[i][j]);
//			}
//			map[i][N + 1] = 0;
//		}
//		for (i = 1; i <= N; i++)
//			map[N + 1][i] = 0;
//		max = 0;
//		for (i = 1; i < N; i++){
//			for (j = 2; j < N; j++){
//				for (l1 = 1; l1 <= N - j; l1++){
//					for (l2 = 1; l2 <= j - 1 && l2 <= N - i - l1; l2++){
//						if (l1 + l2 <= max) continue;
//						clear();
//						travel(i, j, l1, l2);
//					}
//				}
//			}
//		}
//		max *= 2;
//		if (!max) max--;
//		printf("#%d %d\n", t, max);
//	}
//	return 0;
//}