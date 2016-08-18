#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int get_len(int number)
{
	int ret = 1;
	while (number >= 10)
	{
		number /= 10;
		ret++;
	}
	return ret;
}

int make_ten(int zari)
{
	return pow(10, zari - 1);
}

int main()
{
	int N, ans = 0, in;

	scanf("%d", &in);
	N = in;
	while (N >= 10)
	{
		int zari = get_len(N);
		ans += (N - make_ten(zari) + 1)*zari;
		N = make_ten(zari) - 1;
	}
	if (in >= 9)
		ans += 9;
	else
		ans += in;
	printf("%d", ans);
}
