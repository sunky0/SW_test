#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[4][8];
int check[3] = { 0,0,0 };
bool visit[4];
void req(int num, int dir)
{
	if (visit[num - 1] == 1)return;
	visit[num - 1] = 1;
	if (dir == 1)//시계
	{
		int tem = arr[num - 1][7];
		for (int m = 7; m > 0; m--)arr[num - 1][m] = arr[num - 1][m - 1];
		arr[num - 1][0] = tem;
		if (num - 1 < 3)//오른쪽
		{
			if (check[num - 1] == 1)req(num + 1, -1);
		}
		if (num - 2 >= 0)//왼쪽
		{
			if (check[num - 2] == 1)req(num - 1, -1);
		}
	}
	else 
	{
		int tem = arr[num - 1][0];
		for (int m = 0; m < 7; m++)arr[num - 1][m] = arr[num - 1][m + 1];
		arr[num - 1][7] = tem;
		if (num - 1 < 3)//오른쪽
		{
			if (check[num - 1] == 1)req(num + 1, 1);
		}
		if (num - 2 >= 0)//왼쪽
		{
			if (check[num - 2] == 1)req(num - 1, 1);
		}
	}
}
int main() {
	int T, K;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d",&K);
		int Answer = 0;
		for (int n = 0; n < 4; n++)
		{
			for (int m = 0; m < 8; m++)
			{
				scanf("%d", &arr[n][m]);
			}
		}
		for (int n = 0; n < K; n++)
		{
			int num, dir;
			if (arr[0][2] != arr[1][6])check[0] = 1;
			else check[0] = 0;
			if (arr[1][2] != arr[2][6])check[1] = 1;
			else check[1] = 0;
			if (arr[2][2] != arr[3][6])check[2] = 1;
			else check[2] = 0;
			scanf("%d %d", &num, &dir);
			for (int m = 0; m < 4; m++)visit[m] = 0;
			req(num, dir);
		}
		if (arr[0][0] == 1)Answer += 1;
		if (arr[1][0] == 1)Answer += 2;
		if (arr[2][0] == 1)Answer += 4;
		if (arr[3][0] == 1)Answer += 8;
		printf("#%d %d\n", testcase, Answer);
	}
	return 0;
}