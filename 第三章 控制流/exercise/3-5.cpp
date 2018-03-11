/* ��д����itob(n,s,b)��������nת��Ϊ��bΪ�׵���������ת�������
�ַ�����ʽ���浽�ַ���s�С����磬itob(n,s,16)������n��ʽ����ʮ��
��������������s�С� */
void itob(int n, char s[], int b){
	int i = 0, j, sign;
	void reverse(char s[]);
	
	if((sign = n) < 0)							/* sign�����ж����������Ǹ��� */
		n = -n;
	do{
		j = n % b;								/* b��ȡ�� */
		s[i++] = (j <= 9) ? j+'0' : j+'a'-10; 	/* ʮ�������ַ���ʾ */
	}while((n /= b > 0));
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);	
}
