#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
#define max_s(a,b) ((a)>(b)? (a):(b))
bool **del;
int **aroundmap;
void BFS(int x,int y) {
	del[x][y] = true;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0)continue;
			else {
				if (aroundmap[x + i][y + j] == 0 && del[x+i][y+j]==false)BFS(x + i, y + j);
			}
			del[x + i][y + j] = true;
		}
	}
}
int main() {
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		int **map = new int*[N + 2];
		aroundmap = new int*[N + 2];
		del = new bool*[N + 2];
		for (int i = 0; i < N + 2; i++) {
			map[i] = new int[N + 2];
			aroundmap[i] = new int[N + 2];
			del[i] = new bool[N + 2];
		}
		char v;
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				aroundmap[i][j] = -1;
				if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
					map[i][j] = -1;
					del[i][j] = true;
				}
				else {
					cin >> v;
					if (v == '.') { 
						map[i][j] = -1;
						del[i][j] = false;
					}
					else { 
						map[i][j] = -2;
						del[i][j] = true;
					}
				}
			}
		}
		int cnt = 0;
		queue<pair<int, int>>pos;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (map[i][j] == -2) { aroundmap[i][j] = 9; }
				else {
					cnt = 0;
					if (map[i - 1][j - 1] == -2) { cnt++; }
					if (map[i - 1][j] == -2) { cnt++; }
					if (map[i - 1][j + 1] == -2) { cnt++; }
					if (map[i][j - 1] == -2) { cnt++; }
					if (map[i][j + 1] == -2) { cnt++; }
					if (map[i + 1][j - 1] == -2) { cnt++; }
					if (map[i + 1][j] == -2) { cnt++; }
					if (map[i + 1][j + 1] == -2) { cnt++; }
					aroundmap[i][j] = cnt;
					if(cnt==0)pos.push(make_pair(i, j));
				}
			}
		}
		int x = 0, y = 0, num = 0;
		while (!pos.empty()) {
			x = pos.front().first;
			y = pos.front().second;
			if (del[x][y] == false)num++;
			pos.pop();
			//0ÁÖº¯
			BFS(x,y);
		}
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (del[i][j] == false)num++;
			}
		}
		cout << "#" << tc << " " <<num<< endl;
	}
	return 0;
}