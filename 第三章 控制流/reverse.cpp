#include <string.h>

/* reverse�����������ַ���s�и����ַ���λ�� */
void reverse(char s[]){
	int temp, i, j;
	
	for(i = 0, j = strlen(s)-1; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
