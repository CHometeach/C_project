#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 256
#define MEMBER_FILE "member.log"
#define BOOK_FILE "book.log"
#define DATA_FILE "data.log"

void add_book();
void remove_book();
void add_member();
void remove_member();
void member_list();
void book_list();

struct MEMBER
{
	int age;
	char member_name[10];
	char phone[20];
}members[100];
struct BOOK
{
	char book_name[50];
	int state;
}books[500];

void admin()
{
	int choice;
	printf("What function do you want?\n(1)add book\n(2)remove book\n(3)add member\n(4)remove member\n(5)member list\n(6)book list\n(7)exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			add_book();
			break;
		case 2:
			remove_book();
			break;
		case 3:
			add_member();
			break;
		case 4:
			remove_member();
			break;
		case 5:
			member_list();
			break;
		case 6:
			book_list();
			break;
		case 7:
			exit(0);
	system("pause");	
	}
}
void add_book()
{
	char books_temp_name[50],books_temp_log[60];
	FILE *fp;
	fp=fopen(BOOK_FILE,"a+");
	printf("What book do you want to add?\nBook's name:");
	scanf("%s",books_temp_name);	
	sprintf(books_temp_log,"%s 1\n",books_temp_name);
	fwrite(books_temp_log,sizeof(char),sizeof(books_temp_log),fp);
	fclose(fp);
}
void remove_book()
{
	
}
void add_member()
{
	char members_temp_name[50],members_temp_age[20],members_temp_phone[30],members_temp_log[60];
	FILE *fp;
	fp=fopen(MEMBER_FILE,"a+");
	printf("What member do you want to add?\nMember's name:");
	scanf("%s",members_temp_name);
	printf("Member's age:");
	scanf("%s",members_temp_age);
	printf("Member's phone:");
	scanf("%s",members_temp_phone);
	sprintf(members_temp_log,"%s %s %s",members_temp_name,members_temp_age,members_temp_phone);
	fwrite(members_temp_log,sizeof(char),sizeof(members_temp_log),fp);
	fclose(fp);
}
void remove_book()
{
	
}
void member_list()
{
	char members;
	FILE *fp;
	fp=fopen(MEMBER_FILE,"a+");
	while((members=fgetc(fp))!=EOF)
		fputc(members,stdout);
	fclose(fp);
}
void book_list()
{
	char books;
	FILE *fp;
	fp=fopen(BOOK_FILE,"a+");
	while((books=fgetc(fp))!=EOF)
		fputc(books,stdout);
	fclose(fp);
}

void user()
{
		
}

int main()
{
	int mode;
	printf("Who are you?\n(1)admin(2)user\n");
	scanf("%d",&mode);
	if(mode==1)
		admin();
	else if(mode==2)
		user();
	else
		printf("error input !!!\n");
	system("pause");
}