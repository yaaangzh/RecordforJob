#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, c;
	cin >> c;
	cin >> n;
	vector<int> w(n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	vector<vector<int>> m(n + 1, vector<int>(c + 1, 0));
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j >= w[i-1])
				m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i-1]] + v[i-1]);
			else
				m[i][j] = m[i - 1][j];
		}
	}
	cout << m[n][c] <<endl;
	
	//system("pause");
	return 0;
}