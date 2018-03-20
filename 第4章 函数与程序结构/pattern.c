#include <stdio.h>
#define MAXLINE 1000        										/* ��������г��� */
char pattern[] = "ould";   											/* �����ҵ�ģʽ */

/* getline��������������б��浽s�У������ظ��еĳ��� */
int getline(char s[], int lim){
    int c, i;
    i = 0;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')		/* �ַ������ȴ���0��δ��ĩβ */
        s[i++] = c;

    if (c == '\n')													/* ���� */
        s[i++] = c;													/* ��һ���ַ���Ϊ���з� */
    s[i] = '\0';													/* ��ǰ�ַ���Ϊ������ */

    return i;														/* �����ַ������� */	
}

/* strindex����������t��s�е�λ�ã���δ�ҵ��򷵻�-1 */
int strindex(char s[], char t[]){
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++){									/* ����s[] */
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)	/* ����t[] */
            ;
        if (k >0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* �ҳ�������ģʽƥ����� */
int main(void){
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0){								/* �����ַ������浽line[]�У��������ַ������� */
        if (strindex(line, pattern) >= 0){							/* ����pattern��line[]�е�λ�� */
            printf("%s", line);										/* ��ӡline[] */
            found++;
        }
    }
    
    return found;
}


