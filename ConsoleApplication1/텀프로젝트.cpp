#include"stdafx.h"
#include<stdio.h>
#include<malloc.h>
int *student;
int *visit;
int *first;

int dfs(int start, int current, int cnt) {//시작번호, 현재학생번호, 지나간 학생 수

	if (visit[current]) {
		if (first[current] != start)
			return 0;
		return cnt - visit[current];//그룹을 만든 학생 수
	}
	first[current] = start;
	visit[current] = cnt;
	return dfs(start, student[current], cnt + 1);
}

int main() {

	int T;
	scanf("%d", &T);

	int N;
	for (int testCase = 0; testCase < T; testCase++)
	{
		scanf("%d", &N);

		student = (int*)malloc(sizeof(int)*(N + 1));
		visit = (int*)malloc(sizeof(int)*(N + 1));
		first = (int*)malloc(sizeof(int)*(N + 1));

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &student[i]);
			visit[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				ans += dfs(i, i, 1);
			}
		}
		printf("%d\n", N - ans);
	}
	return 0;
}