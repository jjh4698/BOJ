#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#define INF 987654321

using namespace std;

int cnt;

vector<int> slice(int number)
{
	vector<int> ret;
	while (number > 0)
	{
		ret.push_back(number % 10);
		number = number / 10;
	}
	return ret;
}

bool check(int number,vector<int> v)
{
	if (v.size() <= 2)
		return true;
	else{
		int temp = v[1]-v[0];
		for (int i = 1; i <= v.size() - 1; i++)
		{
			if (temp != v[i] - v[i - 1])
				return false;
		}
		return true;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int input;
	vector<int> v;
	scanf("%d", &input);
	for (int i = 1; i <= input; i++)
	{
		v = slice(i);
		if (check(i, v))
			cnt++;
	}
	printf("%d", cnt);
}