#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int T, Answer, N, M, K, A, B, temp;
	int a[10], b[10], t[1001];
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d %d %d", &N, &M, &K, &A, &B);//A창구와 B창구를 모두들린 손님번호의 합
		for (int n = 1; n <= N; n++)scanf("%d", &a[n]);
		for (int n = 1; n <= M; n++)scanf("%d", &b[n]);
		for (int n = 1; n <= K; n++)scanf("%d", &t[n]);

		for (int clock = 0; ; clock++) 
		{
			
		}


		printf("#%d %d\n", testcase, Answer);
	}
}