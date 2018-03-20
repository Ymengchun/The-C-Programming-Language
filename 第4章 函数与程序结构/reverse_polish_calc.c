#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>		/* Ϊ��ʹ��atof���� */

#define MAXOP 100  		/* �����������������󳤶� */
#define NUMBER '0'  	/* ��ʶ�ҵ�һ���� */
#define MAXVAL 100    	/* ջval�������� */
int sp = 0;            	/* ջ������һ��λ�� */
double val[MAXVAL];    	/* ջ */

void push(double);	   	/* ��ջ */
double pop(void);	   	/* ��ջ */

#define BUFSIZE 100  
char buf[BUFSIZE];   	/* ����ungetch�����Ļ����� */
int bufp = 0;        	/* buf����һ������λ�� */

int getch(void);
void ungetch(int);

int getop(char []);

/* �沨�������� */
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

/* push������f��ջ */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;							
    else
        printf("����ջ����������ջ%g\n", f);
}

/* pop��������ջ */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("���󣺿�ջ\n");
        return 0.0;
    }
}

/* getch����:ȡһ���ַ�(������ѹ�ص��ַ�) */
int getch(void)
    return (bufp > 0) ? buf[--bufp] : getchar();		/* ��������Ϊ�գ��ӻ�������ȡ�ַ��������ȡ������ַ� */

/* ungetch����:���ַ�ѹ�ص������� */
void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*getop����:��ȡ��һ�����������ֵ������*/
int getop(char s[]){
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;               						/*������*/

    i = 0;
    if (isdigit(c))            							/*�ռ���������*/
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')            						  	/*�ռ�С������*/
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

