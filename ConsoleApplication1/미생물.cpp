#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, K, x, y, n, p, q, t = 0;;
		cin >> N >> M >> K;
		int *arr = new int[N*N];
		int **mat = new int*[K];
		multimap<int, int>mm;
		multimap<int, int> mm1;
		multimap<int, int>::iterator iter;
		multimap<int, int>::iterator iter1;
		for (int i = 0; i < K; i++) {
			mat[i] = new int[3];
		}
		for (int i = 0; i < K; i++) {
			cin >> x>>y>>n>>p;
			mat[i][0] = x*N + y;//현재 위치
			mat[i][1] = n;
			mat[i][2] = p;
		}
		while (t != M) {
			for (int i = 0; i < K; i++) {
				x = mat[i][0];
				n = mat[i][1];
				if (mat[i][2] == 1) q = -N;
				else if (mat[i][2] == 2) q = N;
				else if (mat[i][2] == 3)q = -1;
				else if (mat[i][2] == 4)q = 1;
				else q = 0;
				mat[i][0] = x + q;//다음위치
			}
			for (int i = 0; i < K; i++) {
				mm.insert(make_pair(mat[i][0], i));//정렬
				if (mat[i][0] % N == 0 || mat[i][0]<N || mat[i][0] % N == N - 1 || mat[i][0]>N*N - N) {
					mat[i][1] = mat[i][1] / 2;
					if (mat[i][2] == 1)mat[i][2]=2;
					else if (mat[i][2] == 2) mat[i][2]=1;
					else if (mat[i][2] == 3)mat[i][2]=4;
					else if (mat[i][2] == 4)mat[i][2]=3;
				}
			}
			int i1 = 0, n1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
			for (iter=mm.begin(); iter != mm.end();++iter) {
				if (i1 == iter->first) {
					if(i4==0) mm1.insert(make_pair(mat[i3][1], i3));
					mm1.insert(make_pair(mat[iter->second][1], iter->second));
					i4 = 1;
				}
				else {
					i4 = 0;
					if (mm1.size() != 0) {
						n1 = 0;
						for (iter1=mm1.begin(); iter1 != mm1.end(); ++iter1){
							n1 = n1 + iter1->first;
							mat[iter1->second][1] = 0;
							i2 = iter1->second;
						}
						mat[i2][1] = n1;
					}
					mm1.clear();
				}
				i1 = iter->first;
				i3 = iter->second;
			}
			mm1.clear();
			mm.clear();
			t++;
		}
		int max = 0;
		for (int i = 0; i < K; i++) {
			max = max + mat[i][1];
		}
		for (int i = 0; i < K; i++) {
			delete[]mat[i];
		}
		delete[]mat;
		cout << "#" << test_case + 1 << " "<<max << endl;
	}
	return 0;
}