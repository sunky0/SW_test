#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int map[10][10];
int N, M, Answer = 11, RX, RY, BX, BY, x_h, y_h;
void DFS(int cnt, int dir, int Rx, int Ry, int Bx, int By)//0북 1서 2남 3동
{
	int x_r = Rx, y_r = Ry, x_b = Bx, y_b = By;
	bool flag = false;//false면 r가 뒤 true면 r이 앞
	if (cnt > Answer)return;
	else
	{
		if (dir == 0)
		{
			if (x_r > x_b)flag = false;
			else flag = true;
			if (flag)
			{
				for (int i = x_b; i >= 0; i--)
				{
					if (map[i][y_b] == 1)
					{
						x_b = i + 1;
						break;
					}
					if (i == x_h && y_b == y_h)return;//실패
				}
				for (int i = x_r; i >= 0; i--)
				{
					if (map[i][y_r] == 1)
					{
						x_r = i + 1;
						break;
					}
					if (i == x_h && y_r == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
			}
			else
			{
				for (int i = x_r; i >= 0; i--)
				{
					if (map[i][y_r] == 1)
					{
						x_r = i + 1;
						break;
					}
					if (i == x_h && y_r == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
				for (int i = x_b; i >= 0; i--)
				{
					if (map[i][y_b] == 1)
					{
						x_b = i + 1;
						break;
					}
					if (i == x_h && y_b == y_h)return;//실패
				}
			}
			if (x_b == x_r && y_b == y_r)
			{
				if (flag)x_b += 1;
				else x_r += 1;
			}
			DFS(cnt + 1, 1, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 2, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 3, x_r, y_r, x_b, y_b);
		}
		else if (dir == 1)//서
		{
			if (y_r > y_b)flag = false;//r이 뒤 true면 r이 앞
			else flag = true;
			if (flag)
			{
				for (int i = y_b; i >= 0; i--)
				{
					if (map[x_b][i] == 1)
					{
						y_b = i + 1;
						break;
					}
					if (i == y_h && x_b == x_h)return;//실패
				}
				for (int i = y_r; i >= 0; i--)
				{
					if (map[x_r][i] == 1)
					{
						y_r = i + 1;
						break;
					}
					if (x_r == x_h && i == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
			}
			else
			{
				for (int i = y_r; i >= 0; i--)
				{
					if (map[x_r][i] == 1)
					{
						y_r = i + 1;
						break;
					}
					if (x_r == x_h && i == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
				for (int i = y_b; i >= 0; i--)
				{
					if (map[x_b][i] == 1)
					{
						y_b = i + 1;
						break;
					}
					if (i == y_h && x_b == x_h)return;//실패
				}
			}
			if (x_b == x_r && y_b == y_r)
			{
				if (flag)y_b += 1;
				else y_r += 1;
			}
			DFS(cnt + 1, 0, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 2, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 3, x_r, y_r, x_b, y_b);
		}
		else if (dir == 2)//남
		{
			if (x_r > x_b)flag = false;//r이 앞
			else flag = true;
			if (flag)
			{
				for (int i = x_r; i < N; i++)
				{
					if (map[i][y_r] == 1)
					{
						x_r = i - 1;
						break;
					}
					if (i == x_h && y_r == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
				for (int i = x_b; i < N; i++)
				{
					if (map[i][y_b] == 1)
					{
						x_b = i - 1;
						break;
					}
					if (i == x_h && y_b == y_h)return;//실패
				}
			}
			else
			{
				for (int i = x_b; i < N; i++)
				{
					if (map[i][y_b] == 1)
					{
						x_b = i - 1;
						break;
					}
					if (i == x_h && y_b == y_h)return;//실패
				}
				for (int i = x_r; i < N; i++)
				{
					if (map[i][y_r] == 1)
					{
						x_r = i - 1;
						break;
					}
					if (i == x_h && y_r == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
			}
			if (x_b == x_r && y_b == y_r)
			{
				if (flag)x_r -= 1;
				else x_b -= 1;
			}
			DFS(cnt + 1, 0, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 1, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 3, x_r, y_r, x_b, y_b);
		}
		else
		{
			if (y_r > y_b)flag = false;//r이 앞 true면 r이 뒤
			else flag = true;
			if (flag)
			{
				for (int i = y_r; i < M; i++)
				{
					if (map[x_r][i] == 1)
					{
						y_r = i - 1;
						break;
					}
					if (x_r == x_h && i == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
				for (int i = y_b; i < M; i++)
				{
					if (map[x_b][i] == 1)
					{
						y_b = i - 1;
						break;
					}
					if (i == y_h && x_b == x_h)return;//실패
				}
			}
			else
			{
				for (int i = y_b; i < M; i++)
				{
					if (map[x_b][i] == 1)
					{
						y_b = i - 1;
						break;
					}
					if (i == y_h && x_b == x_h)return;//실패
				}
				for (int i = y_r; i < M; i++)
				{
					if (map[x_r][i] == 1)
					{
						y_r = i - 1;
						break;
					}
					if (x_r == x_h && i == y_h)
					{
						if (cnt < Answer)Answer = cnt;
						return;
					}
				}
			}
			if (x_b == x_r && y_b == y_r)
			{
				if (flag)y_r -= 1;
				else y_b -= 1;
			}
			DFS(cnt + 1, 0, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 1, x_r, y_r, x_b, y_b);
			DFS(cnt + 1, 2, x_r, y_r, x_b, y_b);
		}
	}
}
int main()
{
	cin >> N >> M;
	string str;
	for (int n = 0; n < N; n++)
	{
		cin >> str;
		for (int m = 0; m < M; m++)//#=1, .=0, R=2, B=3, O=9;
		{
			if (str[m] == '#')map[n][m] = 1;
			else if (str[m] == '.')
			{
				x_h = n;
				y_h = m;
				map[n][m] = 0;
			}
			else if (str[m] == 'R')
			{
				RX = n;
				RY = m;
				map[n][m] = 0;
			}
			else if (str[m] == 'B')
			{
				map[n][m] = 0;
				BX = n;
				BY = m;
			}
			else map[n][m] = 0;
		}
	}
	DFS(1, 0, RX, RY, BX, BY);
	DFS(1, 1, RX, RY, BX, BY);
	DFS(1, 2, RX, RY, BX, BY);
	DFS(1, 3, RX, RY, BX, BY);
	if (Answer == 11)Answer = -1;
	printf("%d\n", Answer);
	return 0;
}