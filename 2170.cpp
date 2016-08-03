#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct line
{
	int s, e;
}L[1000001];

bool cmp(struct line a, struct line b)
{
	if (a.s != b.s)
		return a.s < b.s;
	return a.e < b.e;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int x, y;
	int N;
	int cnt = 0;
	int temp_start, temp_end;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d%d", &x, &y);
		L[i].s = min(x, y);
		L[i].e = max(x, y);
	}sort(L, L + N, cmp);

	int k = 0;
	temp_start = L[k].s;
	temp_end = L[k].e;


	for (int i = k + 1; i < N; i++)
	{

		if (temp_start <= L[i].s && L[i].s <= temp_end)
		{
			if (L[i].e>temp_end)
				temp_end = L[i].e;
		}
		else
		{
			cnt += temp_end - temp_start;
			temp_start = L[i].s;
			temp_end = L[i].e;
		}
	}
	printf("%d", cnt +(temp_end - temp_start));
}
