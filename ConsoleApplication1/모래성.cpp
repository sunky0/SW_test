#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T, H, W;
	char v;
	ios::ios_base::sync_with_stdio(false);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> H >> W;
		bool **del = new bool*[H];
		int **aroundmap = new int*[H];
		int **map = new int*[H];
		for (int i = 0; i < H; i++) {
			map[i] = new int[W];
			aroundmap[i] = new int[W];
			del[i] = new bool[W];
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> v;
				if (v == '.') {
					map[i][j] = -1;
					del[i][j] = true;
				}
				else {
					map[i][j] = (int)(v - 48);
					if (map[i][j] == 9)del[i][j] = true;
					else del[i][j] = false;
				}
			}
		}
		int cnt, wave = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (del[i][j] == false) {
					cnt = 0;
					if (map[i - 1][j - 1] == -1) { cnt++; }
					if (map[i - 1][j] == -1) { cnt++; }
					if (map[i - 1][j + 1] == -1) { cnt++; }
					if (map[i][j - 1] == -1) { cnt++; }
					if (map[i][j + 1] == -1) { cnt++; }
					if (map[i + 1][j - 1] == -1) { cnt++; }
					if (map[i + 1][j] == -1) { cnt++; }
					if (map[i + 1][j + 1] == -1) { cnt++; }
					aroundmap[i][j] = cnt;
				}
				else {
					aroundmap[i][j] = 0;
				}
			}
		}
		queue<pair<int, int>>pos;
		for (int i = 1; i < H - 1; i++) {
			for (int j = 1; j < W - 1; j++) {
				if (aroundmap[i][j] >= map[i][j] && del[i][j] == false) {
					pos.push(make_pair(i, j));
					del[i][j] = true;
				}
			}
		}
		while (!pos.empty()) {
			int num = pos.size();
			for (int i = 0; i < num; i++) {
				int x = pos.front().first;
				int y = pos.front().second;
				pos.pop();
				map[x][y] = -1;
				aroundmap[x][y] = 0;
				for (int j = x - 1; j < x + 2; j++) {
					for (int k = y - 1; k < y + 2; k++) {
						if (j == x &&k == y)continue;
						if (del[j][k] == false) {
							aroundmap[j][k] ++;
							if (aroundmap[j][k] >= map[j][k]) {
								pos.push(make_pair(j, k));
								del[j][k] = true;
							}
						}
					}
				}
			}
			wave++;
		}
		cout << "#" << tc << " " << wave << endl;
	}
	return 0;
}