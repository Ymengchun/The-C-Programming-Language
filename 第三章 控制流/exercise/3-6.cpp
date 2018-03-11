/* �޸�itoa������ʹ�øú������Խ����������������У��������ֶ�Ϊ��С�ֶο�ȡ�
Ϊ�˱�֤ת�������õĽ�����پ��е���������ָ������С��ȣ��ڱ�ҪʱӦ������
�����������һ���Ŀո� */
#define abs(x) ((x < 0) ? (-x) : (x))
void itoa(int n, char s[], int wide){
	int i, sign;
	void reverse(char s[]);
	
	sign = n;
	i = 0;
	
	do{
		s[i++] = abs(n % 10) + '0';
	} while((n /= 10) != 0);
	if(sign < 0)
		s[i++] = '-';
	while(i < wide)
		s[i++] = ' ';
	s[i] = '/0';
	reverse(s);
} 
