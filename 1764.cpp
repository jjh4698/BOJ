#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define INF 987654321
using namespace std;

map<string, bool> m;
vector<string> ans;
char str[21];
int main()
{
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		m[str] = true;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%s", str);
		if (m.find(str) != m.end())
			ans.push_back(str);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}