#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

char str[1000001];

int zari(int number)
{
	int ret = 1;
	while (number >= 10)
	{
		number /= 10;
		ret++;
	}
	return ret;
}

void func(int cnt, char* input)
{
	int len = strlen(input);
	int ret = 0;
	if (len == 1)
	{ 
		if ((input[0] - 48) % 3 == 0)
			printf("%d\nYES",cnt);
		else
			printf("%d\nNO", cnt);
		return;
	}
	for (int i = 0; i < len; i++)
		ret += input[i] - 48;
	int Z = zari(ret);
	int i = 0;
	while (ret>=10)
	{
		input[i++]=ret / pow(10, Z - 1) + 48;
		ret%=(int)pow(10, Z - 1);
		Z--;
	}
	input[i++] = ret + 48;
	input[i] = '\0';
	func(cnt+1, input);
}

int main()
{
	scanf("%s", str);
	func(0, str);
}