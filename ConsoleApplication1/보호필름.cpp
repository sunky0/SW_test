#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
const int DSIZE = 13;
const int WSIZE = 20;
int D, W, K;
int film[DSIZE][WSIZE];
int minchemicalCnt;
int chemical[DSIZE];//어느 행에 약품투입했는지 0은 A, 1은 B, 2는 처리안함
void solve(int curD, int chemicalCnt, int prevContinum[WSIZE], int prevMaxContinum[WSIZE]) {
	if (chemicalCnt >= minchemicalCnt)return;//K개 연속이면 최대 K번 넣으면 되니깐 K번보다 크면 멈춘다
	if (curD == D) {//재귀가 D까지 다 내려왔으면
		bool isSatisfied = true;
		for (int i = 0; i < W; i++) {
			if (prevMaxContinum[i] < K){//열에 한 열이라도 K개를 만족 못하면 중단
				isSatisfied = false;
				break;
			}
		}
		if (isSatisfied && chemicalCnt < minchemicalCnt) minchemicalCnt = chemicalCnt;//K개 연속을 만족하면 
		//chemicalcnt는 약품 넣은 횟수
		return;
	}
	int continum[WSIZE], maxContinum[WSIZE];
	int prev, cur;
	for (int i = 2; i >= 0; i--) {//약품 처리안할때, A일때, B일때로 나눔
		chemical[curD] = i;
		for (int j = 0; j < W; j++) {
			cur = chemical[curD] == 2 ? film[curD][j] : chemical[curD];
			prev = chemical[curD - 1] == 2 ? film[curD - 1][j] : chemical[curD - 1];
			continum[j] = cur == prev ? prevContinum[j] + 1 : 1;//열별로 연속되는 수 저장
			if (continum[j] > prevMaxContinum[j])maxContinum[j] = continum[j];//연속되는 최대 수 저장
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
			continum[i] = maxContinum[i] = 1;//연속된 수를 1개로 초기화
		chemical[0] = 2;//처리안함
		solve(1, 0, continum, maxContinum);
		chemical[0] = 0;//A약품
		solve(1, 1, continum, maxContinum);
		chemical[0] = 1;//B약품
		solve(1, 1, continum, maxContinum);

		cout << "#" << test_case << " " << minchemicalCnt << endl;
	}
	return 0;
}
