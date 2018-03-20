#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int getline(char line[], int max);								/* ���������ݴ���line[]�������ַ������� */
double atof(char s[]);											/* ���ַ���s[]ת��Ϊ˫���ȸ����� */


/* �򵥼��������� */
int main(void)
{
    double sum = 0;
    char line[MAXLINE];
    
    while (getline(line, MAXLINE) > 0){ 
        printf("\t%g\n", sum += atof(line));
    }
    
    return 0;
}

/* getline����:���б��浽s�У������ظ��еĳ��� */
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

/* atof����:���ַ���sת��Ϊ��Ӧ��˫���ȸ����� */
double atof(char s[]){
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++){							/* ����ո� */
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;								/* ������� */
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)							/* �������� */
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')											/* ����С���� */
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;											/* power��¼С��λ */
    }

    return sign * val / power;
}
