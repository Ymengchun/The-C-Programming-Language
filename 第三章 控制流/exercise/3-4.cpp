/* 在数的对二的补码表示中，我们编写的itoa函数不能处理最大的负数，
即n等于-2^(字长-1)的情况，修改该函数，使它在任何机器上运行时都
能打印出正确的值。 */
#define abs(x) ((x < 0) ? -(x) : (x))

void itoa(int n, char s[]){
	int i, sign;
	void reverse(char s[]);
	
	sign = n;
	i = 0;
	do{
		s[i++] = abs(n % 10) + '0';
	} while((n /= 10) != 0);			/* 避免n为负数时使函数陷入无限循环 */
	if(sign < 0)
		s[i++] = '-';
	reverse(s);
}
