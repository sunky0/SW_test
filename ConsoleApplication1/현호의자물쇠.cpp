#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {

	int T, N, K;
	scanf("%d", &T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		scanf("%d", &N);
		string *arr = new string[N];
		int *remain = new int[N];
		for (int n = 0; n < N; n++)
		{
			string num;
			cin >> num;
			arr[n] = num;
		}
		int R = 0;
		scanf("%d", &K);
		int *dupli = new int[K];
		for (int n = 0; n < N; n++)
		{
			unsigned long long int b = 0;
			for (int m = 0; m < arr[n].size(); m++)
			{
				unsigned long long int a = ((int)(arr[n][m] - 48)) % K;
				for (int i = 0; i < arr[n].size() - m - 1; i++)
				{
					a *= 10 % K;
				}
				b += a;
			}
			printf("%lld ", b%K);
			remain[n] = b%K;
		}
		unsigned long long int ans = 0;
		sort(remain, remain + N);
		do {
			unsigned long long int val = remain[N - 1], temp;
			for (int n = N - 2; n >= 0; n--)
			{
				temp = remain[n];
				int dem = val % 10;
				for (int i = 0; i < dem+1; i++)
				{
					temp *= 10;
				}
				val += temp;
			}
			if (val%K == 0) {
				ans++;
				
			}
		} while (next_permutation(remain, remain + N));
		delete[] arr;
		delete[] remain;
		delete[] dupli;
		printf("#%d %lld\n",testCase, ans);
	}
	return 0;
}