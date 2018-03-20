#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int getline(char line[], int max);								/* 将输入内容存入line[]并返回字符串长度 */
double atof(char s[]);											/* 将字符串s[]转换为双精度浮点数 */


/* 简单计算器程序 */
int main(void)
{
    double sum = 0;
    char line[MAXLINE];
    
    while (getline(line, MAXLINE) > 0){ 
        printf("\t%g\n", sum += atof(line));
    }
    
    return 0;
}

/* getline函数:将行保存到s中，并返回该行的长度 */
int getline(char s[], int lim){
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';												

    return i;
}

/* atof函数:把字符串s转换为相应的双精度浮点数 */
double atof(char s[]){
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++){							/* 处理空格 */
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;								/* 处理符号 */
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)							/* 处理数字 */
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')											/* 处理小数点 */
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;											/* power记录小数位 */
    }

    return sign * val / power;
}
