#include"stdafx.h"
#include<stdio.h>
#include<malloc.h>
int N;
double ans;
int **work;
bool *visit;
double req(int maxx, int x, int cnt)
{
	double tem=0, temp=0;
	printf("%d %d:\n ", cnt, maxx);
	visit[x] = true;
	int a, b, c = 0;
	if (cnt<N-1)
	{
		for (int n = 0; n<N; n++)
		{
			if (!visit[n] && tem<work[n][cnt+1]) {
				tem = req(work[n][cnt + 1], n, cnt + 1);
				visit[n] = false;
				if (tem == 0)return 1;
				printf("==%lf==\n", tem);
				if (tem > temp)temp = tem;
			}
		}
		return (double)(maxx*temp) / 100;
	}
	else return maxx;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		work = (int**)malloc(sizeof(int*)*N);
		for (int n = 0; n<N; n++) work[n] = (int*)malloc(sizeof(int)*N);
		visit = (bool*)malloc(sizeof(bool)*N);
		int maxx = 0, x = 0, y = 0;
		ans = 0;
		double tem=0;
		for (int n = 0; n<N; n++)
		{
			visit[n] = false;
			for (int m = 0; m < N; m++)scanf("%d", &work[n][m]);
		}
		for (int n = 0; n < N; n++)
		{
			if (tem < work[n][0])
			{
				printf("** %lf\n", tem);
				tem = req(work[n][0], n, 0);
				if (ans < tem)ans = tem;
			}
		}
		printf("#%d %lf\n", t, ans);
	}
}