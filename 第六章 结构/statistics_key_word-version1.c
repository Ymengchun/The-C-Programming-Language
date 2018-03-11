#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100  
char buf[BUFSIZE];   /*用于ungetch函数的缓冲区*/
int bufp = 0;        /*buf中下一个空闲位置*/

struct key
{
    char *word;			/* 关键字 */
    int count;			/* 关键字出现的次数 */
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}
};

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))			/* keytab[]中关键字的个数 */
															/* 也可以用#define NKEYS (sizeof(keytab) / sizeof(struct key)) */

/* 在tab[]中查找关键字 */
int BinarySearch(char *word, struct key tab[], int length)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = length-1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)	
            high = mid-1;
        else if (cond > 0)
            low = mid+1;
        else
            return mid;
    }
    return -1;												/* 查找失败 */
}


int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*从输入中读取下一个单词或字符*/
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
    {
        ;
    }

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    
    return word[0];
}

/*统计输入中C语言关键字的出现次数*/
main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
            if ((n = BinarySearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    }

    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }

    return 0;
}



