#include <ctype.h>

/* atoi函数：将字符串s转换为相应的整型数(版本2) */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)		/* 跳过空白符 */
    {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;		/* 负号转化为-1 */

    if (s[i] == '+' || s[i] == '-') 	/* 跳过加号和减号 */
        i++;
    for (n = 0; isdigit(s[i]); i++)		/* 处理数字 */ 
        n = 10 * n + (s[i] - '0');

    return sign * n;					/* 乘以正号或负号 */
}
