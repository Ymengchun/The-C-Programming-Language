/* 编写函数itob(n,s,b)，将整数n转换为以b为底的数，并将转换结果以
字符的形式保存到字符串s中。例如，itob(n,s,16)把整数n格式化成十六
进制整数保存在s中。 */
void itob(int n, char s[], int b){
	int i = 0, j, sign;
	void reverse(char s[]);
	
	if((sign = n) < 0)							/* sign用于判断是正数还是负数 */
		n = -n;
	do{
		j = n % b;								/* b除取余 */
		s[i++] = (j <= 9) ? j+'0' : j+'a'-10; 	/* 十六进制字符表示 */
	}while((n /= b > 0));
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);	
}
