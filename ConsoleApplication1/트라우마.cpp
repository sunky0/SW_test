#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int check[27] = { 1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,2,0,1,0,0,0,0,0 };
int min_ans, N;
struct letter
{
	int length;
	char name[11];
	int point;
};
vector<letter>str;
void DFS(int pos, int cnt, int point_s, int chk[27]) //선택할 면접관번호, 카운트
{
	if (cnt > N)return;
	bool success = true;
	int temp_chk[27];
	for (int i = 0; i < 27; i++)
	{
		if (chk[i] > 0)
		{
			success = false;
			break;
		}
	}
	if (success)
	{
		if (point_s < min_ans)min_ans = point_s;
		return;
	}
	else
	{
		for (int i = pos + 1; i < N; i++)
		{
			for (int j = 0; j < 27; j++)temp_chk[j] = chk[j];
			for (int j = 0; j < str[i].length; j++)
			{
				temp_chk[str[i].name[j] - 'A']--;
			}
			DFS(i, cnt + 1, point_s + str[i].point, temp_chk);
		}
	}
	return;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		min_ans = 0x7FFFFFFF;
		scanf("%d", &N);
		str.resize(N);
		for (int n = 0; n < N; n++)
		{
			scanf("%d", &str[n].length);
			for (int l = 0; l < str[n].length; l++)
				scanf("%s", &str[n].name[l]);
			scanf("%d", &str[n].point);
		}
		DFS(-1, 0, 0, check);
		if (min_ans == 0x7FFFFFFF) min_ans = -1;
		printf("#%d %d\n", test_case, min_ans);
	}
	return 0;
}