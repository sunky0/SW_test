#include "stdafx.h"
#include <iostream>
#include <queue>
#include <cstring>
#define MAX_ 200000
using namespace std;
bool check[MAX_];
int dist[MAX_];
int main()
{
	int N, K;
	ios::ios_base::sync_with_stdio(false);
	cin >> N >> K;
	queue<int> q;
	memset(check, false, sizeof(check));
	memset(dist, 0, sizeof(dist));
	check[N] = true;
	dist[N] = 0;
	q.push(N);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		int next = 0;
		if (now - 1 >= 0 && !check[now - 1])
		{
			next = now - 1;
			check[next] = true;
			q.push(next);
			dist[next] = dist[now] + 1;
		}
		if (now + 1 < MAX_ && !check[now + 1])
		{
			next = now + 1;
			check[next] = true;
			q.push(next);
			dist[next] = dist[now] + 1;
		}
		if (2 * now < MAX_ && !check[2 * now])
		{
			next = 2*now;
			check[next] = true;
			q.push(next);
			dist[next] = dist[now] + 1;
		}
	}
	cout << dist[K] << endl;
	return 0;
}