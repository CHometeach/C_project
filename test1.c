#include <stdio.h>
#include <string.h>

int main()
{
	char book[20];
	FILE *fp;
	char line[50];
	char temp_book[20];
	char changeString[32];
	int state;
	char *delete_string="$$$$$$$$$$$$$$$$";
	fp=fopen("test1.log","r+");
	scanf("%s",book);
	fseek(fp,0,SEEK_SET);
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		sscanf(line,"%s %d\n",temp_book,&state);
		if(strcmp(book,temp_book)==0)
		{
			sprintf(changeString, "%s %d\n", book,9);
			fseek(fp, -strlen(line), SEEK_CUR);
			fwrite(changeString,sizeof(char),strlen(line),fp);
		}
	}
	fclose(fp);
	return 0;
}
