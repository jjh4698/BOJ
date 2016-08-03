#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, B,x,y;

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &R, &B);
	for (int i = 1; i <= B; i++)
	{
		int width, height,temp;
		if (B%i == 0)
		{
			width = B / i;
			height = i;

			if (width * 2 + height * 2 + 4 == R)
			{
				if (width > height)
					printf("%d %d", width+2, height+2);
				else
					printf("%d %d", height+2, width+2);
				break;
			}
		}
	}
}