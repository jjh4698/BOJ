#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

int R, C;
char maps[21][21];
vector<string> v;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", maps[i]);

	for (int i = 0; i < R; i++){
		int cnt = 0;
		int len = 0;
		while (cnt < C){
			int temp = 0;
			char temp_str[21];
			while (maps[i][cnt] != '#' && cnt < C)
			{
				temp_str[temp++] = maps[i][cnt++];
			}
			temp_str[temp] = '\0';
			cnt++;
			len = strlen(temp_str);
			if (len>=2)
				v.push_back(temp_str);
		}
	}

	for (int i = 0; i < C; i++){
		int cnt = 0;
		int len = 0;
		while (cnt < R){
			int temp = 0;
			char temp_str[21];
			while (maps[cnt][i] != '#' && cnt < R)
			{
				temp_str[temp++] = maps[cnt++][i];
			}
			temp_str[temp] = '\0';
			cnt++;
			len = strlen(temp_str);
			if (len >= 2)
				v.push_back(temp_str);
		}
	}
	sort(v.begin(), v.end());
	if (!v.empty())
		cout << v[0];

}