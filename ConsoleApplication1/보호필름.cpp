#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
const int DSIZE = 13;
const int WSIZE = 20;
int D, W, K;
int film[DSIZE][WSIZE];
int minchemicalCnt;
int chemical[DSIZE];//��� �࿡ ��ǰ�����ߴ��� 0�� A, 1�� B, 2�� ó������
void solve(int curD, int chemicalCnt, int prevContinum[WSIZE], int prevMaxContinum[WSIZE]) {
	if (chemicalCnt >= minchemicalCnt)return;//K�� �����̸� �ִ� K�� ������ �Ǵϱ� K������ ũ�� �����
	if (curD == D) {//��Ͱ� D���� �� ����������
		bool isSatisfied = true;
		for (int i = 0; i < W; i++) {
			if (prevMaxContinum[i] < K){//���� �� ���̶� K���� ���� ���ϸ� �ߴ�
				isSatisfied = false;
				break;
			}
		}
		if (isSatisfied && chemicalCnt < minchemicalCnt) minchemicalCnt = chemicalCnt;//K�� ������ �����ϸ� 
		//chemicalcnt�� ��ǰ ���� Ƚ��
		return;
	}
	int continum[WSIZE], maxContinum[WSIZE];
	int prev, cur;
	for (int i = 2; i >= 0; i--) {//��ǰ ó�����Ҷ�, A�϶�, B�϶��� ����
		chemical[curD] = i;
		for (int j = 0; j < W; j++) {
			cur = chemical[curD] == 2 ? film[curD][j] : chemical[curD];
			prev = chemical[curD - 1] == 2 ? film[curD - 1][j] : chemical[curD - 1];
			continum[j] = cur == prev ? prevContinum[j] + 1 : 1;//������ ���ӵǴ� �� ����
			if (continum[j] > prevMaxContinum[j])maxContinum[j] = continum[j];//���ӵǴ� �ִ� �� ����
			else maxContinum[j] = prevMaxContinum[j];
		}
		solve(curD + 1, chemicalCnt + (i == 2 ? 0 : 1), continum, maxContinum);
	}
}
int main(int argc, char** argv)
{
	int T;
	
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++){
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++)
				cin >> film[i][j];
		}
		minchemicalCnt = K;
		int continum[WSIZE], maxContinum[WSIZE];
		for (int i = 0; i < W; i++)
			continum[i] = maxContinum[i] = 1;//���ӵ� ���� 1���� �ʱ�ȭ
		chemical[0] = 2;//ó������
		solve(1, 0, continum, maxContinum);
		chemical[0] = 0;//A��ǰ
		solve(1, 1, continum, maxContinum);
		chemical[0] = 1;//B��ǰ
		solve(1, 1, continum, maxContinum);

		cout << "#" << test_case << " " << minchemicalCnt << endl;
	}
	return 0;
}
