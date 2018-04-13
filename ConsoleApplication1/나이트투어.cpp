#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int dir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
int map[6][6];
int main()
{
	string str;
	int i, s_x, s_y, prev_x, prev_y;
	bool success = false;
	for (i = 0; i < 36; i++)
	{
		bool suc = false;
		cin >> str;
		int x = str[0] - 'A';
		int y = str[1] - '1';
		if (i == 0)
		{
			s_x = x;
			s_y = y;
			prev_x = x;
			prev_y = y;
			map[x][y] = 1;
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				if (prev_x + dir[i][0] == x && prev_y + dir[i][1] == y)suc = true;
			}
			if (suc)
			{
				if (map[x][y] == 1)success = true;
				else map[x][y] = 1;
			}
			else success = true;
			prev_x = x;
			prev_y = y;
		}
	}
	bool first = false;
	for (int i = 0; i < 8; i++)
	{
		if (prev_x + dir[i][0] == s_x && prev_y + dir[i][1]==s_y)first = true;
	}
	for (int n = 0; n < 6; n++)
	{
		for (int m = 0; m < 6; m++)
		{
			if (map[n][m] == 0)success = true;
		}
	}
	if (!success && first)cout << "Valid" << endl;
	else cout << "Invalid" << endl;
	return 0;
}