#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int D, W, K;
int film[13][20];
int Answer;
int visit[13];//��� �࿡ ��ǰ�����ߴ��� 0�� A, 1�� B, 2�� ó������
void solve(int curD, int cnt, int prevContinum[20], int prevMaxContinum[20]) {
	if (cnt >= Answer)return;//K�� �����̸� �ִ� K�� ������ �Ǵϱ� K������ ũ�� �����
	if (curD == D) {//��Ͱ� D���� �� ����������
		bool success = true;
		for (int i = 0; i < W; i++) {
			if (prevMaxContinum[i] < K) {//���� �� ���̶� K���� ���� ���ϸ� �ߴ�
				success = false;
				break;
			}
		}
		if (success && cnt < Answer) Answer = cnt;//K�� ������ �����ϸ� 
																					  //cnt�� ��ǰ ���� Ƚ��
		return;
	}
	int continum[20], maxContinum[20];
	int prev, cur;
	for (int i = 2; i >= 0; i--) {//��ǰ ó�����Ҷ�, A�϶�, B�϶��� ����
		visit[curD] = i;
		for (int j = 0; j < W; j++) {
			cur = visit[curD] == 2 ? film[curD][j] : visit[curD];
			prev = visit[curD - 1] == 2 ? film[curD - 1][j] : visit[curD - 1];
			continum[j] = cur == prev ? prevContinum[j] + 1 : 1;//������ ���ӵǴ� �� ����
			if (continum[j] > prevMaxContinum[j])maxContinum[j] = continum[j];//���ӵǴ� �ִ� �� ����
			else maxContinum[j] = prevMaxContinum[j];
		}
		solve(curD + 1, cnt + (i == 2 ? 0 : 1), continum, maxContinum);
	}
}
int main(int argc, char** argv)
{
	int T;

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++)
				cin >> film[i][j];
		}
		Answer = K;
		int continum[20], maxContinum[20];
		for (int i = 0; i < W; i++)
			continum[i] = maxContinum[i] = 1;//���ӵ� ���� 1���� �ʱ�ȭ
		visit[0] = 2;//ó������
		solve(1, 0, continum, maxContinum);
		visit[0] = 0;//A��ǰ
		solve(1, 1, continum, maxContinum);
		visit[0] = 1;//B��ǰ
		solve(1, 1, continum, maxContinum);

		cout << "#" << test_case << " " << Answer << endl;
	}
	return 0;
}
