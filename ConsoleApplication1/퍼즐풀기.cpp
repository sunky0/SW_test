#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
#define max_s(a,b) ((a)>(b)? (a):(b))
int main() {
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, a, b;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a;
		}
		for (int i = 0; i < N; i++) {
			cin >> b;
		}
		cout << "#" << tc << " " << num << endl;
	}
	return 0;
}