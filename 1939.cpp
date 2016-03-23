#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000001
using namespace std;

int N, M;
bool check[10001];
int dp[10001];
int f1, f2;
vector<vector<pair<int,int> > > v;

queue<pair<int,int > > q;

int has(int x,int y)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		if (v[x][i].first == y)
			return i;
	}
	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	int x, y,z,ret=0;
	int temp;
	scanf("%d %d", &N, &M);
	v.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		if ((temp=has(x, y))!=-1){
			v[x][temp].second = max(v[x][temp].second, z);
			temp = has(y, x);
			v[y][temp].second = max(v[y][temp].second, z);
		}
		else{
		v[x].push_back(make_pair(y,z));
		v[y].push_back(make_pair(x, z));
		}
	}
	scanf("%d %d", &f1, &f2);
	q.push(make_pair(f1,INF));
	check[f1] = true;

	while (!q.empty())
	{
		int x =q.front().first;
		int w =q.front().second;
		check[x] = true;
		q.pop();
		if (x == f2)
		{
			if (ret < w)
				ret = w;
			check[f2] = false; 
			w = INF;
		}

		for (int i = 0; i < v[x].size(); i++)
		{
			if (check[v[x][i].first] == false)
			{
				q.push(make_pair(v[x][i].first, min(w,v[x][i].second)));
			}
		}
	}
	printf("%d", ret);

}
