#include"stdafx.h"
#include<stdio.h>
#include<malloc.h>
int N;
bool *visit;
double *X;
double *Y;
double ans;
void BFS(int cnt, int num, double ma)
{
	if (cnt == N - 1) {
		ans = ma;
		return;
	}
	double Min = 1 << 30;
	int min_num=num;

	for (int n = 0; n < N; n++)
	{
		if (!visit[n])
		{
			double temp= (X[num] - X[n])*(X[num] - X[n]) + (Y[num] - Y[n])*(Y[num] - Y[n]);
			if (Min > temp) {
				Min = temp;
				min_num = n;
			}
		}
	}
	visit[min_num] = true;
	//printf("%d %lf %lf\n", cnt, ma, Min);
	BFS(cnt + 1, min_num, ma + Min);
}
int main()
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		X = (double*)malloc(sizeof(double)*N);
		Y = (double*)malloc(sizeof(double)*N);
		visit = (bool*)malloc(sizeof(bool)*N);
		double E, temp= 1<<30;
		ans = 1<<30;
		for (int n = 0; n < N; n++)
		{
			visit[n] = false;
			scanf("%lf", &X[n]);
		}
		for (int n = 0; n < N; n++)scanf("%lf", &Y[n]);
		scanf("%lf", &E);
		int xx=0;
		for (int n = 0; n < N; n++) {
			for (int i = 0; i < N; i++)visit[i] = false;
			visit[n] = true;
			BFS(0, n, 0.0);
			if (temp > ans) {
				temp = ans;
				xx = n;
			}
		}
		printf("%d: \n", xx);
		printf("#%d %.0lf\n", t, temp*E);
		free(X);
		free(Y);
		free(visit);
	}
}