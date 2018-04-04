#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int>pq;
int N;
int main() {
	
	int T;
	long long int x, y;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		int arr[20] = { 0, };
		vector<pair<int, int>> position;
		for (int n = 0; n < N; n++) {
			if(n<N/2)arr[n] = -1;
			else arr[n] = 1;
			cin >> x >> y;
			position.push_back(make_pair(x, y));
		}
		long long int Vsum = INT64_MAX;
		long long int mins = INT64_MAX;
		do {
			x = y = 0;
			for (int n = 0; n < N; n += 2) {
				x += arr[n]*position[n].first + arr[n + 1] * position[n + 1].first;
				y += arr[n]*position[n].second + arr[n + 1] * position[n + 1].second;
			}
			Vsum = x*x + y*y;
			if (mins > Vsum) {
				mins = Vsum;
			}
		} while (next_permutation(arr, arr + N));
		cout << "#" << tc << " " << mins << endl;
	}
	return 0;
}