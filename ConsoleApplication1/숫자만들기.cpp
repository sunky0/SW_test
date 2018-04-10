#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cal;
vector<int> num;
int main() {
	int T, N, plus, minus, multi, divi, Answer;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d", &N);
		cal.clear();
		num.clear();
		num.resize(N);
		scanf("%d %d %d %d", &plus, &minus, &multi, &divi);
		for (int p = 0; p < plus; p++)cal.push_back(0);//+
		for (int p = 0; p < minus; p++)cal.push_back(1);//-
		for (int p = 0; p < multi; p++)cal.push_back(2);//*
		for (int p = 0; p < divi; p++)cal.push_back(3);// /
		//연산자 갯수
		for (int n = 0; n < N; n++) 
		{
			scanf("%d", &num[n]);
		}//숫자
		int small = 0x7FFFFFFF, big = -0x7FFFFFFF
		do {
			int res = num[0];
			for (int n = 0; n < N - 1; n++)
			{
				if (cal[n] == 0)res += num[n + 1];
				else if (cal[n] == 1)res -= num[n + 1];
				else if (cal[n] == 2)res *= num[n + 1];
				else res /= num[n + 1];
			}
			if (small > res)small = res;
			if (big < res)big = res;
		} while (next_permutation(cal.begin(), cal.end()));
		printf("#%d %d\n", testcase, big-small);
	}
	return 0;
}