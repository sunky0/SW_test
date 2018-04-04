#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n, k;
int ans;
string a;
bool check[1000000];
void solve(int cnt, int x) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp += pow(10, n - i - 1)*(a[i] - 48);
	}
	if (cnt == k) {
		ans = max(temp, ans);
		return;
	}
	if (check[temp]) {
		return;
	}
	check[temp] = true;
	for (int i = x; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j) continue;
			swap(a[i], a[j]);
			solve(cnt + 1, i);
			swap(a[j], a[i]);
		}
	}
	return;
}
int main() {
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {
		ans = 0;
		cin >> a >> k;
		n = a.size();
		solve(0, 0);
		cout << '#' << test << ' ' << ans << endl;
	}
	return 0;
}