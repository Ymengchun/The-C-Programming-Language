#include <string.h>

void reverse(char s[]){
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa����:������nת��Ϊ�ַ��������浽s��*/
int itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0)				/* ��¼���� */
        n = -n;						/* ʹn��Ϊ���� */ 
    i = 0;
    do{								/* ������������ */
        s[i++] = n % 10 + '0';		/* ȡ��һ������ */	
    }while ((n /= 10) > 0);			

    if (sign < 0)					/* ԭ���Ǹ�������ĩβ��ӷ��� */
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);						/* ת�� */
}
