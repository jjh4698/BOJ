#include <stdio.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct FenwickTree
{
	vector<long long> tree;
	FenwickTree(long long n) : tree(n+1){}

	long long sum(int pos)
	{
		long long ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, long long value)
	{
		while (pos < tree.size()){
			tree[pos] += value;
			pos += (pos &-pos);
		}
	}
};

long long arr[100001];

int main()
{
	freopen("input.txt", "r", stdin);
	long long N;
	long long Q,x,y,a,b;
	scanf("%lld%lld", &N, &Q);
	FenwickTree fen(N);
	for (int i = 1; i <=N; i++){
		scanf("%lld", &arr[i]);
		fen.add(i, arr[i]);
	}
	for (int i = 0; i < Q; i++)
	{
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if (x > y){
			long long k = y;
			y = x;
			x = k;
		}
		printf("%lld\n",fen.sum(y) - fen.sum(x-1));
		fen.add(a, b - arr[a]);
		arr[a] = b;
	}
}
