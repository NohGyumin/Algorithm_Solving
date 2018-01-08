#include <cstdio>
int T, N, a[1001], ans;
bool visit[1001];
bool f(int s, int n)
{
	visit[n] = true;
	if (a[n] == s) return true;
	if (f(s, a[n])) return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) visit[i] = false;
		for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				if (f(i, a[i])) ans++;
			}
		}
		printf("%d\n", ans);
	}
}