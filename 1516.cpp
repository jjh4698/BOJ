#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

int dp[501];
int N;
int ti[501];
vector<vector<int> > input;

int dfs(int building)
{
	if (dp[building] != 0)
		return dp[building];

	for (int i = 0; i < input[building].size(); i++)
	{
		dp[building] = max(dp[building], dfs(input[building][i]));
	}
	return dp[building]+=ti[building];
}

int main()
{
	int temp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	input.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		scanf("%d", &ti[i]);
		while (true)
		{
			scanf("%d", &temp);
			if (temp == -1)
				break;
			cnt++;
			input[i].push_back(temp);
		}
		if (cnt == 0)
			dp[i] = ti[i];
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", dfs(i));
}