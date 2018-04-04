#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdlib>
using namespace std;
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
struct position {
	int x1;
	int y1;
};
struct distan {
	int x1;
	int y1;
};
struct stair {
	int x1;
	int y1;
	int len;
};
int main(int argc, char** argv)
{
	int T, test_case, w, max, mini;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;
		int **mat = new int*[N];
		position p1[10];
		distan p3[10];
		stair p2[2];//계단 무조건 두개
		deque<int> s1, s2;
		for (int i = 0; i < N; i++) {
			mat[i] = new int[N];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> w;
				mat[i][j] = w;
			}
		}
		int a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mat[i][j] == 1) {
					p1[a].x1 = i;
					p1[a].y1 = j;
					a++;
				}
				else if (mat[i][j] > 1) {
					p2[b].x1 = i;
					p2[b].y1 = j;
					p2[b].len = mat[i][j];
					b++;
				}
			}
		}
		b = 1;
		for (int i = 0; i < a; i++) {//각각 계단에 대한 거리 저장
			p3[i].x1 = abs(p1[i].x1 - p2[0].x1) + abs(p1[i].y1 - p2[0].y1);
			p3[i].y1 = abs(p1[i].x1 - p2[1].x1) + abs(p1[i].y1 - p2[1].y1);
			b = b * 2;//모든 경우의 수
		}
		for (int i = 0; i < b; i++) {
			string s = "\0";
			//char str[100];
			//itoa(i, str, 2);
			//s = str;
			int in = i;
			while (in > 0) {//0, 1, 0, 11, 00
				if (in % 2 == 0)s = '0' + s;
				else s = '1' + s;
				in /= 2;
			}
			if (i == 0)s = '0';
			while (s.length() != a) {
				s = '0' + s;
			}
			for (int j = 0; j<s.length(); j++) {
				if (s[j] == '0')s1.push_back(p3[j].x1);
				else s2.push_back(p3[j].y1);//각 계단에 도착할 때 시간
			}
			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());
			int v1[3] = { 0,0,0 };
			int v2[3] = { 0,0,0 };

			while (s1.size() != 0) {
				sort(v1, v1 + 3);
				if (v1[0] <s1.front()) {
					v1[0] = s1.front() + p2[0].len;
					s1.pop_front();
				}
				else {
					v1[0] = v1[0] + 1 + p2[0].len;
					s1.pop_front();
				}
			}
			while (s2.size() != 0) {
				sort(v2, v2 + 3);
				if (v2[0] <s2.front()) {
					v2[0] = s2.front() + p2[1].len;
					s2.pop_front();
				}
				else {
					v2[0] = v2[0] + p2[1].len;
					s2.pop_front();
				}
			}
			if (v1[0] < 0)v1[0] = 0;
			if (v2[0] < 0) v2[0] = 0;
			max = max(v1[0], v2[0]);//모든 이동이 완료하는데 걸린시간
			if (i == 0) {
				mini = max;
			}
			else {
				mini = min(mini, max);
			}
		}
		for (int i = 0; i < N; i++) {
			delete[]mat[i];
		}
		delete[]mat;

		cout << "#" << test_case + 1 << " " << mini + 1 << endl;
	}
	return 0;
}