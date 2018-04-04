#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 1000
#define max_s(a,b) ((a)>(b)? (a):(b))
int main() {
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		char X[SIZE], Y[SIZE];
		int m, n;
		int **map = new int*[SIZE + 1];
		for (int i = 0; i <= SIZE; i++) {
			map[i] = new int[SIZE + 1];
		}
		cin >> X >> Y;
		m = strlen(X);
		n = strlen(Y);
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 || j == 0) { map[i][j] = 0; }
				else if (X[i - 1] == Y[j - 1]) { map[i][j] = 1 + map[i - 1][j - 1]; }
				else { map[i][j] = max_s(map[i - 1][j], map[i][j - 1]); }
			}
		}
		cout << "#" << tc << " " << map[m][n] << endl;
	}
	return 0;
}