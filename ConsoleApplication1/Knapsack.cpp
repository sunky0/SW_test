#include "stdafx.h"
#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T, K;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, V, C;
		int Bag[1001] = { 0, };
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> V >> C;
			for (int j = K; j >= V; j--) {
				if (Bag[j] < Bag[j - V] + C)Bag[j] = Bag[j - V] + C;
			}
			for (int i = 0; i < 100; i++)printf("%d ", Bag[i]);
		}
		cout << "#" << test_case << " " << Bag[K] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}