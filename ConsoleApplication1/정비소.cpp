#include "stdafx.h"
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int T, N, M, K, A, B, E;
	int a[11], b[11], t[1002], use_A[1001], use_B[1001];
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		vector<pair<int, int>> reception(N + 1);
		vector<pair<int, int>> repair(M + 1);
		vector<pair<int, int>> repair_wait(K + 1);
		for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= M; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= K; i++) scanf("%d", &t[i]);
		E = 0;
		for (int i = 1, time = t[1]; E < K; time++) {
			for (int j = 1; j <= N; j++) {
				if (i <= K && time >= t[i] && reception[j].first == 0) {
					use_A[i] = j;//손님번호에 이용접수창구 번호 넣기
					reception[j] = make_pair(a[j], i);//접수창구에 손님들어간 시간과 손님 번호 넣기
					i++;
				}
				if (reception[j].first > 0) {//접수창구에 누가 들어가 처리시간이 있다면
					reception[j].first--;
					if (reception[j].first == 0) {//다 처리했다면
						E++;//그냥 repair_wait에 순차적으로 넣기 위한 인덱스
						repair_wait[E] = make_pair(time + 1, reception[j].second);//정비창구를 몇초부터 기다리는지, 손님번호 넣기
					}	//접수창구 번호가 작을때부터 들어가니깐 repair_wait에 들어감으로 창구번호 낮은 순으로 정비창구에 들어갈수 있음
				}
			}
		}
		int fin = 0, Answer = 0;
		for (int i = 1, time = repair_wait[1].first; fin < K; time++) {
			for (int j = 1; j <= M; j++) {
				if (i <= K && repair_wait[i].first <= time && repair[j].first == 0) {
					use_B[repair_wait[i].second] = j;//손님번호에 이용한 정비창구 넣기
					repair[j] = make_pair(b[j], repair_wait[i].second);//정비창구에 들어간 시간과 손님번호 넣기
					if (use_A[repair_wait[i].second] == A && use_B[repair_wait[i].second] == B) Answer += repair_wait[i].second;
					//A접수창구와 B정비창구 이용했다면 손님번호를 Answer에 합하기
					i++;//그 다음 손늼~
				}
				if (repair[j].first > 0) {
					repair[j].first--;
					if (repair[j].first == 0) fin++;//손늼 끝나셨어여~
				}
			}
		}
		printf("#%d %d\n", testcase, Answer == 0 ? -1 : Answer);
	}
}