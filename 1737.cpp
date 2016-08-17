#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

map<double, long long> m;

long long func(double number)
{
	if (m.find(number)!= m.end())
		return m[number];
	if (number >= 0 && number <= M_PI)
		return 1;
	return m[number] = (func(number - 1) % 1000000000000000000 + func(number - M_PI) % 1000000000000000000) % 1000000000000000000;
}

int main()
{
	//freopen("input.txt", "r", stdin);
		
	int num;
	scanf("%d",&num);
	printf("%lld", func(num));
	printf("1");
}