#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define NORTH 1
#define RIGHT 2
#define SOUTH 3
#define LEFT 4

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<vector<int> > v;

int main()
{
	freopen("input.txt", "r", stdin);
	int t_case;
	char input[501];
	int len;

	scanf("%d", &t_case);
	while (t_case--)
	{
		v.clear();
		v.resize(1001);
		v[500].push_back(500);
		int min_x=2000, max_x=0;
		int min_y = 2000, max_y = 0;
		int x = 500, y = 500;
		int direction = NORTH;
		scanf("%s", input);
		len = strlen(input);
		for (int i = 0; i < len; i++)
		{
			if (input[i] == 'F')
			{
				if (direction ==  NORTH)
					x++;
				else if (direction == SOUTH)
					x--;
				else if (direction == LEFT)
					y--;
				else if (direction == RIGHT)
					y++;
				v[x].push_back(y);
			}
			else if (input[i] == 'B')
			{
				if (direction == NORTH)
					x--;
				else if (direction == SOUTH)
					x++;
				else if (direction == LEFT)
					y++;
				else if (direction == RIGHT)
					y--;
				v[x].push_back(y);
			}
			else if (input[i] == 'L')
			{
				if (direction == NORTH)
					direction = LEFT;
				else
					direction--;
			}
			else if (input[i] == 'R')
			{
				if (direction == LEFT)
					direction = NORTH;
				else
					direction++;
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (!v[i].empty()){
				sort(v[i].begin(), v[i].end());
				min_x = min(min_x, i);
				max_x = max(max_x, i);
				min_y = min(min_y, v[i][0]);
				max_y = max(max_y, v[i][v[i].size() - 1]);
			}
		}
		printf("%d\n", (max_x-min_x) * (max_y-min_y));

	}
}