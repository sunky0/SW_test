#include"stdafx.h"
#include <stdio.h>
#include <queue>
using namespace std;
int honey[10][10];
int M, C;
#define maxs(a,b) ((a)>(b)? (a):(b))
int get(int gain, int total, int y, int x, int index) 
{//합이 C보다 작은? 최대값 함수
	if (index >= M) return gain;
	if (total + honey[y][x + index] <= C)
		return maxs(get(gain, total, y, x, index + 1), get(gain + honey[y][x + index] * honey[y][x + index], total + honey[y][x + index], y, x, index + 1));
	else return get(gain, total, y, x, index + 1);
}
int main() {
	int T, Answer, N, i, j;
	int Maxgain, Max_i, Max_j;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d %d %d", &N, &M, &C);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++) 
			{
				scanf("%d", &honey[i][j]);
			}
		}
		priority_queue<pair<int, pair<int, int> > >Maxhoney;
		Maxgain = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N - M + 1; j++)
			{
				Maxhoney.push(make_pair(get(0, 0, i, j, 0), make_pair(i, j)));
			}
		}

		Answer = Maxhoney.top().first;
		Max_i= Maxhoney.top().second.first;
		Max_j= Maxhoney.top().second.second;
		Maxhoney.pop();
		for (;;)
		{
			if (Maxhoney.top().second.first != Max_i)
			{
				Answer += Maxhoney.top().first;
				break;
			}
			else
			{
				if (Maxhoney.top().second.second - Max_j >= C || Maxhoney.top().second.second - Max_j <= (-1)*C)
				{
					Answer += Maxhoney.top().first;
					break;
				}
				else
				{
					Maxhoney.pop();
				}continue;
			}
			
		}
		printf("#%d %d\n", testcase, Answer);
	}
}