#include <cstdio>
int N, M, PR, PC, ans;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
char map[500][501], cans;
char dd(int i)
{
	char ret;
	if (i == 0) ret = 'U';
	else if (i == 1) ret = 'R';
	else if (i == 2) ret = 'D';
	else ret = 'L';
	return ret;
}
int dir(int d, char c)
{
	int ret;
	if ((c == '\\'&&d == 3) || (c == '/'&&d == 1)) ret = 0;
	else if ((c == '\\'&&d == 0) || (c == '/'&&d == 2)) ret = 3;
	else if ((c == '\\'&&d == 1) || (c == '/'&&d == 3)) ret = 2;
	else if ((c == '\\'&&d == 2) || (c == '/'&&d == 0)) ret = 1;
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);
	scanf("%d %d", &PR, &PC);
	for (int i = 0; i < 4; i++)
	{
		int r = PR - 1, c = PC - 1, d = i, s = 0;
		while (r >= 0 && c >= 0 && r < N&&c < M && map[r][c] != 'C')
		{
			r = r + dy[d], c = c + dx[d];
			if (map[r][c] == '/' || map[r][c] == '\\') d = dir(d, map[r][c]);
			s++;
			if (s > N*M)
			{
				cans = dd(i);
				ans = -1;
				break;
			}
		}
		if (ans == -1) break;
		if (s > ans)
		{
			cans = dd(i);
			ans = s;
		}
	}
	if (ans == -1) printf("%c\nVoyager", cans);
	else printf("%c\n%d", cans, ans);
}