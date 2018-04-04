#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include<vector>
using namespace std;
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))

int main(int argc, char** argv)
{
	int T,A,B,C,ans=0;
	vector<int> arr1,arr2;

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> A;
		arr1.push_back(A);
	}
	cin >> B >> C;
	for (int i = 0; i < T; i++) {
		arr1[i] = arr1[i] - B;
		if (arr1[i] > 0) {
			ans += arr1[i] / C + 1;
		}
		ans += 1;
	}
	cout << ans << endl;
	return 0;
}