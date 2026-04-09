#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a;
vector<int> A;

int find_first(int i, int right) {
	while (i<A.size() && A[i] < right) { i++; }
	return i;
}

int main() {
	// input and sort
	cin >> N >> M;
	for (; N > 0; N--) {
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());

	// find minimum
	int min = A.back() - A[0];	// maximum diff

	int left = A[0], right;
	for (int i = 0; i < A.size() - 1; left = A[++i]) {
		right = left + M;
		int f = find_first(i, right);
		if (f == A.size()) break;
		if (A[f] - left < min) min = A[f] - left;
	}
	int i = A.size() - 1;
	while (A[i] > left) { i--; }
	if (A.back() - A[i]>=M && A.back()-A[i] < min) min = A.back() - A[i];

	cout << min;

	return 0;
}