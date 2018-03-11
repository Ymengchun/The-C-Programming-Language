#include <string.h>

void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa函数:将数字n转换为字符串并保存到s中*/
int itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0)				/* 记录符号 */
        n = -n;						/* 使n成为正数 */ 
    i = 0;
    do{								/* 反序生成数字 */
        s[i++] = n % 10 + '0';		/* 取下一个数字 */	
    }while ((n /= 10) > 0);			

    if (sign < 0)					/* 原来是负数再在末尾添加符号 */
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);						/* 转置 */
}
