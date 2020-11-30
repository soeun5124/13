#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
is_whitespace(char c)
{
	if (c == ' ' ||
	    c == '\n' ||
	    c == '\r' ||
	    c == '\t')
	    return 1;
	
	return 0;
	    
	
	
	
}
int fget_word(FILE *fp, char* word) {
	
	char c;
	int cnt; 
	
	while((c=fgetc(fp) )!= EOF ){
		if(is_whitespace(c) == 0)
		break;
	}
	
	if (c == EOF)
	  return 0;
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	
	while( (word[cnt]=fgetc(fp) )!= EOF) {
		if(is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	
	return cnt;
	
}
int main(int argc, char *argv[]) {
	
	 FILE *fp;
	 char filename[100];
	 char word[100];
	 
	 int cnt;
	 
	 printf("input the file name:");
	 scanf("%s",filename);
	 
	 if((fp=fopen(filename, "r")) == NULL)
	{
		printf("input filname is invaild (%s)\n", filename);
	    return -1;
	
	}
	cnt = fget_word(fp,word);
	printf("%s (%i)\n", word, cnt);
	
	cnt = fget_word(fp,word);
	printf("%s (%i)\n", word, cnt);
	
	cnt = fget_word(fp,word);
	printf("%s (%i)\n", word, cnt);

	

	fclose(fp);
	
	return 0;
}
