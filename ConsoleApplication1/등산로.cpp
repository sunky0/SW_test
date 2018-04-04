#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define Size 10

int N, K;
int map[Size][Size];
int visit[Size][Size];//�湮�� ���
int heighest;//���� ���� ���� ����
int ans;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�¿���� ����
typedef struct info {
	int h, w;
	int height;
	int usedK;//���������� �ִ���
	int len;//������� ������ ����
};
void sol(info cur) {
	ans = ans > cur.len ? ans : cur.len;//���� ���̰� �ִ밡 �ǵ���
	for (int d = 0; d < 4; d++) {
		info nxt = cur;//������ �ٲܶ����� ���� ���ǵǾ� ���̴� 
		nxt.h += dir[d][0];
		nxt.w += dir[d][1];//�����¿�� �̵��غ���
		nxt.height = map[nxt.h][nxt.w];

		if (nxt.h < 0 || nxt.h >= N || nxt.w < 0 || nxt.w >= N)continue;//���� ����� �ǳʶٱ�
		if (visit[nxt.h][nxt.w])continue;//�湮�߾ �ǳʶٱ�

		if (nxt.height < cur.height) {//������ ���̰� �������� �۴ٸ�
			visit[nxt.h][nxt.w] = 1;
			nxt.len++;
			sol(nxt);
			visit[nxt.h][nxt.w] = 0;//����湮��..�ʱ�ȭ���ִ� ������ �ٸ��������� Ž���ϱ� ����
		}
		else {
			if (!cur.usedK &&nxt.height - K < cur.height) {//���������� ���� �����Ҷ� ���̰� �������� �۾����ٸ�
				visit[nxt.h][nxt.w] = 1;
				nxt.len++;
				nxt.usedK = 1;//�����ߵ�
				nxt.height = cur.height - 1;//K��ŭ �� �����ʿ� ���� ���纸�� 1�� ������ �Ǵϱ�
				sol(nxt);
				visit[nxt.h][nxt.w] = 0;//??
			}
		}
	}
	return;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		heighest = ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				heighest = heighest > map[i][j] ? heighest : map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (heighest == map[i][j]) {
					visit[i][j] = 1;
					info cur = { i,j,map[i][j],0,1 };
					sol(cur);
					visit[i][j] = 0;
				}
			}
		}
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}
