#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int num, N;
int w[10];
void Req(int prevL, int prevR, int n) {
	if (n != N) {
		Req(prevL + w[n], prevR, n + 1);
		if (prevL >= prevR + w[n]) {
			Req(prevL, prevR + w[n], n + 1);
		}
	}
	else num++;//끝까지 오면 추가
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int W;
		num = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> W;
			w[i] = W;
		}
		sort(w, w + N);
		do {
			Req(w[0], 0, 1);
		} while (next_permutation(w, w + N));
		cout << "#" << tc << " " << num << endl;
	}
	return 0;
}




