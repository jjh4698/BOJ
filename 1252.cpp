#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#define INF 987654321

using namespace std;

char str1[85];
char str2[85];
vector<int> ans;

void erase_zero(char* str, int len)
{
	int temp = -1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != '0')
		{
			temp = i;
			break;
		}
	}
	for (int i = 0; i < len - temp; i++)
	{
		str[i] = str[i + temp];
	}
	str[len - temp] = '\0';
	if (temp == -1)
		str = NULL;

}

int main()
{
	freopen("input.txt", "r", stdin);
	int len1, len2,m,olim=0;
	scanf("%s%s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	erase_zero(str1, len1);
	erase_zero(str2, len2);

	if (strcmp(str1, "") == 0 && strcmp(str2, "") == 0)
	{
		printf("0");
		return 0;
	}

	len1 = strlen(str1);
	len2 = strlen(str2);
	m = min(len1, len2);

	for (int i = 0; i < m; i++)
	{
		int a = str1[len1 - 1 - i]-48;
		int b = str2[len2 - 1 - i]-48;

		if (a + b + olim == 3)
		{
			ans.push_back(1);
		}
		else if (a + b + olim == 2)
		{
			ans.push_back(0);
			olim = 1;
		}
		else if (a + b + olim <=1)
		{
			ans.push_back(a + b + olim);
			olim = 0;
		}
	}
	if (len1 > len2){
		int k = len1 - len2;
		while (k--)
		{
			int a = str1[k] - 48;
			if (a + olim == 2)
			{
				ans.push_back(0);
			}
			else if(a+olim<=1){
				ans.push_back(a+olim);
				olim = 0;
			}
		}
	}
	else
	{
		int k = len2 - len1;
		while (k--)
		{
			int a = str2[k] - 48;
			if (a + olim == 2)
			{
				ans.push_back(0);
			}
			else if (a + olim <= 1){
				ans.push_back(a + olim);
				olim = 0;
			}
		}
	}

	if (olim == 1)
		ans.push_back(1);
	for (int i = ans.size() - 1; i >= 0; i--)
		printf("%d", ans[i]);
	

}