int a, b, c;
float m, n;
char p, q;
int fibo(int a)
{
	if (a == 1 || a == 2)
		return 1;
	return fibo(a - 1) + fibo(a - 2);
}
int main()
{
	int m, n, i;
	char pp, qq;
	pp = '\'';
	m = read();
	i = 1;

	for (i = 0; i < 2; i = i + 1)
	{
		read();
	}
	while (i <= m)
	{
		n = fibo(i);
		write(n);
		i = i + 1;
	}
	return 1;
}