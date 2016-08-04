#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int alpha[27];
char input[51];
int main()
{
	//freopen("input.txt", "r", stdin);
	int len;
	scanf("%s", input);

	len = strlen(input);
	for (int i = 0; i < len; i++)
		alpha[input[i] - 65]++;
	if (len % 2 == 0)
	{
		for (int k = 0; k <= 26; k++){
			if (alpha[k] % 2 != 0){
				printf("I'm Sorry Hansoo");
				return 0;
			}
		}
		for (int k = 0; k <= 26; k++){
			if (alpha[k] != 0)
			{
				for (int c = 0; c < alpha[k] / 2; c++)
					printf("%c", k+65);
			}
		}
		for (int k = 26; k >=0; k--){
			if (alpha[k] != 0)
			{
				for (int c = 0; c < alpha[k] / 2; c++)
					printf("%c", k+65);
			}
		}
	}
	else
	{
		int cnt = 0;
		int center;
		for (int k = 0; k <= 26; k++){
			if (alpha[k] % 2 != 0){
				cnt++;
				center = k;
			}
		}
		if (cnt >= 2){
			printf("I'm Sorry Hansoo");
			return 0;
		}
		for (int k = 0; k <= 26; k++){
			if (alpha[k] != 0)
			{
				for (int c = 0; c < alpha[k] / 2; c++)
					printf("%c", k + 65);
			}
		}
		printf("%c", center + 65);
		for (int k = 26; k >= 0; k--){
			if (alpha[k] != 0)
			{
				for (int c = 0; c < alpha[k] / 2; c++)
					printf("%c", k + 65);
			}
		}
	}
}
