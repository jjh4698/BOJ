#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int A, B, C,S,E;
vector<vector<pair<int, int > > > v;
queue<pair<int, int> > q;
int dp[10001];
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	v.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
		dp[i] = 0;
	
	for (int i = 0; i < M; i++){
		scanf("%d%d%d", &A, &B, &C);
		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
	}
	scanf("%d%d", &S, &E);
	q.push(make_pair(S, INF));
	while (!q.empty())
	{
		int p = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < v[p].size(); i++)
		{
			if (dp[v[p][i].first] < min(v[p][i].second, cnt))
			{
				dp[v[p][i].first] =	 min(v[p][i].second, cnt);
				q.push(make_pair(v[p][i].first, min(v[p][i].second, cnt)));
			}
		}
	}
	printf("%d", dp[E]);
}