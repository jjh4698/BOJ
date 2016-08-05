#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
char maps[101][101];
bool check[101][101];
int cnt;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int a, int b, char clr)
{
	for (int i = 0; i < 4; i++)
	{
		int x = a + dx[i];
		int y = b + dy[i];
		if (maps[x][y]==clr && check[x][y] == false &&x >= 0 && x <= M - 1 && y >= 0 && y <= N - 1)
		{
			cnt++;
			check[x][y] = true;
			dfs(x, y,clr);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int ans[2] = { 0, 0 };
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%s", maps[i]);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (check[i][j] == false)
			{
				cnt = 1;
				check[i][j] = true;
				dfs(i, j, maps[i][j]);
				if (maps[i][j] == 'W')
					ans[0] += cnt*cnt;
				else
					ans[1] += cnt*cnt;
			}
		}
	}
	printf("%d %d", ans[0], ans[1]);

}
