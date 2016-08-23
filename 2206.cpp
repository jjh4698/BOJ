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

char maps[1001][1001];
int dp[1001][1001][2];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
struct Point
{
	Point(){};
	Point(int a, int b,int c) : x(a), y(b), stone(c){};
	int x, y,stone;
};

queue<pair<Point, int>> q;
int main()
{
	freopen("input.txt", "r", stdin);
	int N, M;
	struct Point temp;
	int cnt;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = INF;
		}
	}
	for (int i = 0; i < N; i++)
		scanf("%s", maps[i]);
	q.push(make_pair(Point(0, 0,0), 1));
	dp[0][0][0] = 1;
	while (!q.empty())
	{
		temp = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (temp.stone == 1){
			for (int i = 0; i < 4; i++)
			{
				int x = temp.x + dx[i];
				int y = temp.y + dy[i];
				if (maps[x][y] == '0' && dp[x][y][1]>cnt + 1){
					dp[x][y][1] = cnt + 1;
					q.push(make_pair(Point(x, y, 1), cnt + 1));
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int x = temp.x + dx[i];
				int y = temp.y + dy[i];
				if (maps[x][y] == '0' && dp[x][y][0]>cnt + 1){
					dp[x][y][0] = cnt + 1;
					q.push(make_pair(Point(x, y, 0), cnt + 1));
				}
				else if (maps[x][y] == '1' && dp[x][y][1] > cnt + 1)
				{
					dp[x][y][1] = cnt + 1;
					q.push(make_pair(Point(x, y, 1), cnt + 1));

				}
			}
		}
	}
	if (dp[N - 1][M - 1][0] == INF && dp[N - 1][M - 1][1] == INF)
		printf("-1");
	else
		printf("%d", min(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]));
}