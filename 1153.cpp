#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

vector<int> sosu;
vector<int> ans;
bool check[1000001];

int dfs(int number)
{
	int ret = 0;

	for (int i = 0; i < sosu.size(); i++)
	{
		if (sosu[i]>number)
			break;
		if (ans.size() < 2)
		{
			ans.push_back(sosu[i]);
			ret = dfs(number - sosu[i]);
			ans.pop_back();
		}
		else if (ans.size() == 2 && check[sosu[i]]==false && check[number-sosu[i]]==false)
		{
			for (int i = 0; i < 2; i++)
				printf("%d ", ans[i]);
			printf("%d %d", sosu[i], number - sosu[i]);
			ret = 1;
		}
		
		if (ret == 1)
			return 1;
	}
	return -1;
}

int main()
{
	int temp;
	int N,ret;
	check[0] = check[1] = true;
	//freopen("input.txt", "r", stdin);
	for (long long i = 2; i <= 1000000; i++)
	{
		if (check[i] == false)
		{
			sosu.push_back(i);
			for (long long j = i*i; j <= 1000000; j+=i)
				check[j] = true;
		}
	}
	scanf("%d", &N);
	ret=dfs(N);
	if (ret == -1)
		printf("-1");
}