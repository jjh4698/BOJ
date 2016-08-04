#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt[81];
int ans;
int temp;

int main()
{
	//freopen("input.txt", "r", stdin);
	int s1, s2, s3;
	scanf("%d%d%d", &s1, &s2, &s3);
	for (int i = 1; i <= s1; i++){
		for (int j = 1; j <= s2; j++){
			for (int k = 1; k <= s3; k++){
				cnt[i + j + k]++;
			}
		}
	}
	for (int i = 1; i <= s1 + s2 + s3; i++)
	{
		if (cnt[i] > temp){
			temp = cnt[i];
			ans = i;
		}
	}
	printf("%d", ans);
}
