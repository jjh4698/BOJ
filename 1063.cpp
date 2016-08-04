#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int doll[2];
int king[2];

bool moves(int N, char* direction, int *ch)
{
	if (strcmp(direction, "R") == 0)
	{
		if (ch[0] + 1 > 7)
			return false;
		ch[0]++;
	}
	else if (strcmp(direction, "L") == 0)
	{
		if (ch[0] - 1 <0)
			return false;
		ch[0]--;
	}
	else if (strcmp(direction, "B") == 0)
	{
		if (ch[1] - 1 < 1)
			return false;
		ch[1]--;
	}
	else if (strcmp(direction, "T") == 0)
	{
		if (ch[1] + 1 >N)
			return false;
		ch[1]++;
	}
	else if (strcmp(direction, "RT") == 0)
	{
		if (ch[0] + 1 > 7 || ch[1]+1>N)
			return false;
		ch[0]++;
		ch[1]++;
	}
	else if (strcmp(direction, "LT") == 0)
	{
		if (ch[0] -1 < 0 || ch[1] + 1>N)
			return false;
		ch[0]--;
		ch[1]++;
	}
	else if (strcmp(direction, "RB") == 0)
	{
		if (ch[0] + 1 > 7 || ch[1] -1 < 1)
			return false;
		ch[0]++;
		ch[1]--;
	}
	else if (strcmp(direction, "LB") == 0)
	{
		if (ch[0] - 1 < 0 || ch[1] - 1 < 1)
			return false;
		ch[0]--;
		ch[1]--;
	}
	return true;
}

bool doll_check(int N, char* direction, int *ch)
{
	if (strcmp(direction, "R") == 0)
	{
		if (ch[0] + 1 == doll[0] && ch[1]==doll[1])
			return false;
	}
	else if (strcmp(direction, "L") == 0)
	{
		if (ch[0] -1  == doll[0] && ch[1] == doll[1])
			return false;
	}
	else if (strcmp(direction, "B") == 0)
	{
		if (ch[0]  == doll[0] && ch[1]-1 == doll[1])
			return false;
	}
	else if (strcmp(direction, "T") == 0)
	{
		if (ch[0] == doll[0] && ch[1] + 1 == doll[1])
			return false;
	}
	else if (strcmp(direction, "RT") == 0)
	{
		if (ch[0] +1 == doll[0] && ch[1] +1 == doll[1])
			return false;

	}
	else if (strcmp(direction, "LT") == 0)
	{
		if (ch[0] -1 == doll[0] && ch[1] + 1 == doll[1])
			return false;
	}
	else if (strcmp(direction, "RB") == 0)
	{
		if (ch[0] + 1 == doll[0] && ch[1] - 1 == doll[1])
			return false;

	}
	else if (strcmp(direction, "LB") == 0)
	{
		if (ch[0] -1 == doll[0] && ch[1] - 1 == doll[1])
			return false;

	}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int N;
	char input[3];
	char temp1[3];
	char temp2[3];

	scanf("%s%s%d", temp1,temp2, &N);
	king[0] = temp1[0] - 65;
	king[1] = temp1[1] - 48;
	doll[0] = temp2[0] - 65;
	doll[1] = temp2[1] - 48;


	while (N--)
	{
		scanf("%s", input);
		bool t = doll_check(8, input, king);
		if (t)
			moves(8, input, king);
		else
		{
			if (moves(8, input, doll))
			{
				moves(8, input, king);
			}
		}
	}
	temp1[0] = king[0] + 65;
	temp1[1] = king[1] + 48;
	temp2[0] = doll[0] + 65;
	temp2[1] = doll[1] + 48;

	printf("%s\n%s", temp1, temp2);
}
