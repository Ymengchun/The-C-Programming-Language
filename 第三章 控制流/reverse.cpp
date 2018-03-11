#include <string.h>

/* reverse函数：倒置字符串s中各个字符的位置 */
void reverse(char s[]){
	int temp, i, j;
	
	for(i = 0, j = strlen(s)-1; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
