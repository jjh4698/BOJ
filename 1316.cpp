#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char str[101];
bool check[26];

int main()
{
	freopen("input.txt", "r", stdin);
	int N,k;
	int len,cnt=0;
	bool test;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", str);
		memset(check, false, sizeof(check));
		test = true;
		len = strlen(str);
		k = 0;
		while (k < len){
			if (check[str[k] - 97] == false){
				check[str[k] - 97] = true;
				char temp = str[k];
				for (int j = k; j < len; j++){
					if (temp != str[j]){
//						k++;
						break;
					}
					k++;
				}
			}
			else
			{
				test = false;
				break;
			}
		}
		if (test) cnt++;
	}
	printf("%d", cnt);
}
