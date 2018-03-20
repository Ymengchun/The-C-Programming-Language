#include <stdio.h>
#define MAXLINE 1000        										/* 最大输入行长度 */
char pattern[] = "ould";   											/* 待查找的模式 */

/* getline函数：将输入的行保存到s中，并返回该行的长度 */
int getline(char s[], int lim){
    int c, i;
    i = 0;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')		/* 字符串长度大于0且未到末尾 */
        s[i++] = c;

    if (c == '\n')													/* 换行 */
        s[i++] = c;													/* 下一个字符记为换行符 */
    s[i] = '\0';													/* 当前字符记为结束符 */

    return i;														/* 返回字符串长度 */	
}

/* strindex函数：返回t在s中的位置，若未找到则返回-1 */
int strindex(char s[], char t[]){
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++){									/* 遍历s[] */
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)	/* 遍历t[] */
            ;
        if (k >0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* 找出所有与模式匹配的行 */
int main(void){
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0){								/* 输入字符串保存到line[]中，并返回字符串长度 */
        if (strindex(line, pattern) >= 0){							/* 返回pattern在line[]中的位置 */
            printf("%s", line);										/* 打印line[] */
            found++;
        }
    }
    
    return found;
}


