#include"stdafx.h"
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//순열조합문제이다
vector<char> arr;
char result[16];
int l, c;
void solve(char* result, int len, int index, int jacnt, int mocnt) {
	if (len == l) {
		result[len] = '\0';
		if (mocnt >= 1 && jacnt >= 2) printf("%s\n", result);
		return;
	}

	for (int i = index; i <c; i++) {
		result[len] = arr[i];
		if (result[len] == 'a' || result[len] == 'e' || result[len] == 'i' || result[len] == 'o' || result[len] == 'u')
			solve(result, len + 1, i + 1, jacnt, mocnt + 1);
		else solve(result, len + 1, i + 1, jacnt + 1, mocnt);
	}
}

int main() {
	cin >> l >> c;
	arr.resize(c);
	for (int i = 0; i < c; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	solve(result, 0, 0, 0, 0);

}