#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int T;
	queue<int> arr1, ar2;
	arr1 = ar2;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string A, B;
		cin >> A >> B;
		int ans = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				if (A[i + j] != B[j]) break;
				if (j == B.size() - 1) {
					i += B.size() - 1;
				}
			}
			ans++;
		}
		cout << "#" << tc << " "<< ans << endl;
	}
	return 0;
}




