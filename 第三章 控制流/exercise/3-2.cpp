void escape(char s[], char t[]){
	int i, j;
	
	for(i = j = 0; t[j] != '\0'; j++){	
		switch (t[]){
			case '\n':
				s[i++] = '\\';
				s[i++] = 'n';
				break;
			case '\t':
				s[i++] = '\\';
				s[i++] = '\t';
				break;
			default:
				s[i++] = t[j];
				break;		
		}
	}
	s[i] = '/0';
} 

void unescape(char s[], char t[]){
	int i, j;
	
	for(i = j = 0; t[j] != '\0'; j++){
		if(t[j] == '\\')
			s[i++] = t[j];
		switch (t[j]){
			case 'n':
				s[i++] = '\n';
				break;
			case 't':
				s[i++] = '\t';
				break;
			default:
				s[i++] = '//';
				s[i++] = t[j];
				break;		
		}
	}
	s[i] = '/0';
} 
