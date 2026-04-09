#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a;
vector<int> A;

int find_first(int i, int r) {
	while (i<A.size() && A[i] < r) { i++; }
	if (i > A.size() - 1) return -1;
	return i;
}

int main() {
	cin >> N >> M;
	for (; N > 0; N--) {
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	int min = A.back() - A[0];

	int l = A[0], r;
	for (int i = 0; i < A.size() - 1; l = A[++i]) {
		r = l + M;
		int f = find_first(i, r);
		if (f == -1) break;
		if (A[f] - l < min) min = A[f] - l;
	}
	int i = A.size() - 1;
	while (A[i] > l) { i--; }
	if (A.back() - A[i]>=M && A.back()-A[i] < min) min = A.back() - A[i];

	cout << min;

	return 0;
}