#include "stdafx.h"
/////순열 조합// 12 13 14 21 23 24 31 32 34 41 42 43
#include <iostream>
using namespace std;
int N, M;
bool visit[8];
int arr[8];
void dfs(int pos)
{
	if (pos == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[pos] = i + 1;
			dfs(pos + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	dfs(0);
	return 0;
}
////조합//// 12 13 14 23 24 34
#include <iostream>
using namespace std;
int N, M;
int arr[8];
void dfs(int pos, int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = pos + 1; i < N; i++) {
		arr[cnt] = i + 1;
		dfs(i, cnt + 1);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	dfs(-1, 0);
	return 0;
}
///중복순열조합/// 11 12 13 14 21 22 23 24 31 32 33 34
#include <iostream>
using namespace std;
int N, M;
bool visit[8];
int arr[8];
void dfs(int pos)
{
	if (pos == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		arr[pos] = i + 1;
		dfs(pos + 1);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	dfs(0);
	return 0;
}
////중복조합//// 11 12 13 14 22 23 24 33 34 44
void dfs(int pos, int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = pos; i < N; i++) {
		arr[cnt] = i + 1;
		dfs(i, cnt + 1);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	dfs(0, 0);
	return 0;
}