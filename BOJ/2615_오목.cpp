#include <cstdio>
int b[21][21];
int dx[4] = { 1,1,1,0 }, dy[4] = { -1,0,1,1 };
bool f(int n, int y, int x, int d)
{
	if (n == 5)
	{
		if (b[y][x] != b[y + dy[d]][x + dx[d]]) return true;
		return false;
	}
	int ny = y + dy[d], nx = x + dx[d];
	if (b[y][x] == b[ny][nx])
	{
		if (f(n + 1, ny, nx, d)) return true;
		else return false;
	}
	else return false;
}
int main()
{
	for (int i = 1; i < 20; i++)
		for (int j = 1; j < 20; j++)
			scanf("%d", &b[i][j]);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j < 20; j++)
		{
			if (b[i][j])
			{
				for (int d = 0; d < 4; d++)
				{
					if (b[i][j] != b[i - dy[d]][j - dx[d]])
					{
						if (f(1, i, j, d))
						{
							printf("%d\n%d %d", b[i][j], i, j);
							return 0;
						}
					}
				}
			}
		}
	printf("0");
}