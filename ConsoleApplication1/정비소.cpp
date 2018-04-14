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
					use_A[i] = j;//�մԹ�ȣ�� �̿�����â�� ��ȣ �ֱ�
					reception[j] = make_pair(a[j], i);//����â���� �մԵ� �ð��� �մ� ��ȣ �ֱ�
					i++;
				}
				if (reception[j].first > 0) {//����â���� ���� �� ó���ð��� �ִٸ�
					reception[j].first--;
					if (reception[j].first == 0) {//�� ó���ߴٸ�
						E++;//�׳� repair_wait�� ���������� �ֱ� ���� �ε���
						repair_wait[E] = make_pair(time + 1, reception[j].second);//����â���� ���ʺ��� ��ٸ�����, �մԹ�ȣ �ֱ�
					}	//����â�� ��ȣ�� ���������� ���ϱ� repair_wait�� ������ â����ȣ ���� ������ ����â���� ���� ����
				}
			}
		}
		int fin = 0, Answer = 0;
		for (int i = 1, time = repair_wait[1].first; fin < K; time++) {
			for (int j = 1; j <= M; j++) {
				if (i <= K && repair_wait[i].first <= time && repair[j].first == 0) {
					use_B[repair_wait[i].second] = j;//�մԹ�ȣ�� �̿��� ����â�� �ֱ�
					repair[j] = make_pair(b[j], repair_wait[i].second);//����â���� �� �ð��� �մԹ�ȣ �ֱ�
					if (use_A[repair_wait[i].second] == A && use_B[repair_wait[i].second] == B) Answer += repair_wait[i].second;
					//A����â���� B����â�� �̿��ߴٸ� �մԹ�ȣ�� Answer�� ���ϱ�
					i++;//�� ���� �Ո�~
				}
				if (repair[j].first > 0) {
					repair[j].first--;
					if (repair[j].first == 0) fin++;//�Ո� �����̾~
				}
			}
		}
		printf("#%d %d\n", testcase, Answer == 0 ? -1 : Answer);
	}
}