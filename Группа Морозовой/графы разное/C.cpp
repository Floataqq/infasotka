#include <iostream>
using namespace std;
int main()
{
	int n, counter = 0; cin >> n;
	int a[100][100];
	int b[100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] == 1 and b[i] != b[j]) counter++;
		}
	}
	cout << counter;
	return 0;
}
