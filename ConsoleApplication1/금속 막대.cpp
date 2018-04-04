#include"stdafx.h"
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<pair<int, int>> vec;
vector<bool> visit;
deque<int> dq;
int N;
void req(int n, int dir)
{
	printf("%d --", n);
	if (dq.size() >= N)return;
	else {
		for (int i = 0; i<N; i++)
		{
			if (!visit[i] && n != i)
			{
				if (dir == -1 && vec[n].first == vec[i].second)
				{
					printf(" left %d left ", i);
					dq.push_front(i);
					visit[i] = true;
					req(i, -1);
					visit[i] = false;
					//dq.pop_front();
				}
				else if (dir == 1 && vec[n].second == vec[i].first)
				{
					printf(" right %d right ", i);
					dq.push_back(i);
					visit[i] = true;
					req(i, 1);
					visit[i] = false;
					//  dq.pop_back();
				}
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t<T; t++)
	{
		scanf("%d", &N);
		vec.clear();
		for (int n = 0; n<N; n++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			vec.push_back(make_pair(a, b));
			visit.push_back(false);
		}
		dq.clear();
		dq.push_back(0);
		visit[0] = true;
		req(0, 1);
		req(0, -1);
		printf("#%d ", t + 1);
		for (int i = 0; i<dq.size(); i++)printf("%d %d ", vec[dq[i]].first, vec[dq[i]].second);
		printf("\n");
	}
}
//#include <cstdio>
//int T, N, n[41];
//bool ex[2][41];
//int main()
//{
//	scanf("%d", &T);
//	for (int TC = 1; TC <= T; TC++)
//	{
//		scanf("%d", &N);
//		for (int i = 0; i < 2; i++) for (int j = 0; j < 41; j++) ex[i][j] = n[j] = 0;
//		for (int i = 0; i < N; i++)
//		{
//			int x, y;
//			scanf("%d %d", &x, &y);
//			n[x] = y;
//			ex[0][x] = ex[0][y] = true;
//			ex[1][x] = !ex[1][x];// toggle
//			ex[1][y] = !ex[1][y];
//		}
//		int s;
//		for (int i = 0; i < 41; i++)
//			if (ex[0][i] && ex[1][i] && n[i])
//				s = i;
//		printf("#%d", TC);
//		while (n[s])
//		{
//			printf(" %d %d", s, n[s]);
//			s = n[s];
//		}
//		printf("\n");
//	}
//	return 0;
//}