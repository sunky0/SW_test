#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define maxs(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
long long int A, B,x,y;

int main() {
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> A >> B;//Ax+By=1
		long long int r1, r2, q, r, t, t1, t2;
		r1 = A;
		r2 = B;
		t1 = 0; t2 = 1;
		while (r1 != 1) {
			q = r2 / r1;
			r = r2 - r1*q;
			t = t1 - t2*q;
			r2 = r1;
			r1 = r;
			t1 = t2;
			t2 = t;
		}
		x = t2;
		y = (1 - A*x) / B;
		if ((1-A*x)%B!=0) {
			cout << "#" << tc << " -1" << endl;
		}
		else {
			cout << "#" << tc << " " << x << " " << y << endl;
		}
	}
	return 0;
}