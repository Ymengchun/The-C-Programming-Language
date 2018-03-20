#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>		/* 为了使用atof函数 */

#define MAXOP 100  		/* 操作数或运算符的最大长度 */
#define NUMBER '0'  	/* 标识找到一个数 */
#define MAXVAL 100    	/* 栈val的最大深度 */
int sp = 0;            	/* 栈顶的下一个位置 */
double val[MAXVAL];    	/* 栈 */

void push(double);	   	/* 入栈 */
double pop(void);	   	/* 出栈 */

#define BUFSIZE 100  
char buf[BUFSIZE];   	/* 用于ungetch函数的缓冲区 */
int bufp = 0;        	/* buf中下一个空闲位置 */

int getch(void);
void ungetch(int);

int getop(char []);

/* 逆波兰计算器 */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

/* push函数：f入栈 */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;							
    else
        printf("错误：栈满，不能入栈%g\n", f);
}

/* pop函数：出栈 */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("错误：空栈\n");
        return 0.0;
    }
}

/* getch函数:取一个字符(可能是压回的字符) */
int getch(void)
    return (bufp > 0) ? buf[--bufp] : getchar();		/* 缓冲区不为空，从缓冲区读取字符；否则读取输入的字符 */

/* ungetch函数:把字符压回到输入中 */
void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*getop函数:获取下一个运算符或数值操作数*/
int getop(char s[]){
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;               						/*不是数*/

    i = 0;
    if (isdigit(c))            							/*收集整数部分*/
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')            						  	/*收集小数部分*/
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

