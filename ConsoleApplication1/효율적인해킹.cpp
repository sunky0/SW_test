#include"stdafx.h"
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
//얼마나 깊게 들어가는지 보기 위함이니 BFS
int main(void) {

	int N, M;
	vector<int> a[10001];
	queue<int> que;
	int save[10001];
	int size = 0;
	int max = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int start, end;
		scanf("%d %d", &end, &start);
		a[start].push_back(end);
	}

	for (int i = 1; i <= N; i++) {
		int count = 0;
		int visit[10001] = {};

		que.push(i);
		visit[i] = 1;
		count++;

		while (!que.empty()) {
			int now = que.front();
			que.pop();

			for (int j = 0; j < a[now].size(); j++) {
				int temp = a[now][j];

				if (visit[temp] == 0) {
					visit[temp] = 1;
					que.push(temp);
					count++;
				}

			}
		}
		if (max < count)
		{
			size = 0;
			max = count;
			save[size++] = i;
		}
		else if (max == count)
		{
			save[size++] = i;
		}

	}
	for (int i = 0; i < size; i++)
		printf("%d ", save[i]);

	return 0;
}
