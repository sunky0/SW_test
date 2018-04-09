#include "stdafx.h"
#include <iostream>
using namespace std;
int map[52][52];
bool visit[52][52];
int N, M, Answer;//d 0��->��, 1��->��, 2��->��, 3��->�� r--,c++,r++,c--
void req(int r, int c, int d)
{
	if (!visit[r][c])Answer++;
	visit[r][c] = true;
	if (visit[r - 1][c] && visit[r + 1][c] && visit[r][c - 1] && visit[r][c + 1])
	{
		if (d == 0)//��
		{
			if (map[r + 1][c] == 1)return;
			else req(r + 1, c, 0);
		}
		else if (d == 1)//��
		{
			if (map[r][c - 1] == 1)return;
			else req(r, c - 1, 1);
		}
		else if (d == 2)//��
		{
			if (map[r - 1][c] == 1)return;
			else req(r - 1, c, 2);
		}
		else if (d == 3)//��
		{
			if (map[r][c + 1] == 1)return;
			else req(r, c + 1, 3);
		}
	}
	else
	{
		if (d == 0)//d 0��->3��, 
		{
			if (!visit[r][c - 1])req(r, c - 1, 3);
			else req(r, c, 3);
		}
		else if (d == 1)//1��->0��, 
		{
			if (!visit[r - 1][c])req(r - 1, c, 0);
			else req(r, c, 0);
		}
		else if (d == 2)//2��->1��, 
		{
			if (!visit[r][c + 1])req(r, c + 1, 1);
			else req(r, c, 1);
		}
		else if(d == 3)//3��->2�� r--,c++,r++,c--
		{
			if (!visit[r + 1][c])req(r + 1, c, 2);
			else req(r, c, 2);
		}
	}
	return;
}
int main()
{
	ios::ios_base::sync_with_stdio(false);
	int r, c, d;
	Answer = 0;
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			map[i][j] = 1;
			visit[i][j] = true;
		}
	}
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int n = 1; n < N + 1; n++)
	{
		for (int m = 1; m < M + 1; m++)
		{
			cin >> map[n][m];
			if (map[n][m] == 0)visit[n][m] = false;
		}
	}
	req(r + 1, c + 1, d);
	cout << Answer << endl;
	return 0;
}