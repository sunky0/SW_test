#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int L, R, C, minn = 1 << 30, end_x, end_y, end_z;
int map[900][30];
bool visit[900][30];
int dir[6][3] = { {0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0} };
void req(int x, int y, int z, int cnt)//
{
	visit[x*R + y][z] = true;
	if (x == end_x && y == end_y && z == end_z)
	{
		if (minn > cnt)minn = cnt;
	}
	for (int i = 0; i < 6; i++)
	{
		int xx = x + dir[i][0];//L
		int yy = y + dir[i][1];//R
		int zz = z + dir[i][2];//C

		if (xx < 0 || xx >= L || yy < 0 || yy >= R || zz < 0 || zz >= C || map[xx*R + yy][zz] == 9 || visit[xx*R + yy][zz])continue;
		req(xx, yy, zz, cnt + 1);
		//visit[xx*R + yy][zz] = false;
	}
}
int main()
{
	for(;;)
	{
		for (int i = 0; i < 900; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				map[i][j] = 0;
				visit[i][j] = false;
			}

		}
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0)break;
		string str;
		minn = 1 << 30;
		int start_x, start_y, start_z;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				cin >> str;
				for (int k = 0; k < str.size(); k++)
				{
					if (str[k] == '.')map[i*R + j][k] = 1;
					else if (str[k] == '#')
					{
						map[i*R + j][k] = 9;
						visit[i*R + j][k] = true;
					}
					else if (str[k] == 'S')
					{
						map[i*R + j][k] = 1;
						start_x = i;
						start_y = j;
						start_z = k;
					}
					else if (str[k] == 'E')
					{
						map[i*R + j][k] = 1;
						end_x = i;
						end_y = j;
						end_z = k;
					}
				}
			}
		}
		req(start_x, start_y, start_z, 0);
		if (minn == 1 << 30)printf("Trapped!\n");
		else printf("Escaped in %d minute(s).", minn);
	}
	return 0;
}