#include<stdio.h>
#include<string.h>
void uni(char*,char*,char*);
void inter(char*,char*,char*);
void diff(char*,char*,char*);
void main()
{
  char s1[20],s2[20],s3[20];
  printf("enter the first string:");
  scanf("%s",s1);
  printf("enter the second string:");
  scanf("%s",s2);
  
  inter(s1,s2,s3);
  printf("intersection is: %s\n",s3);
  uni(s1,s2,s3);
  printf("union is: %s\n",s3);
  diff(s1,s2,s3);
  printf("difference is: %s\n",s3);
}

void uni(char*s1,char*s2,char*s3)
{
  int i,l;
  l=strlen(s1);
  for(i=0;i<l;i++)
  {
    if(s1[i]=='0' && s2[i]=='0')
      s3[i]='0';
    else
       s3[i]='1';
  }
  s3[i]='\0';
}

void inter(char*s1,char*s2,char*s3)
{
  int i,l;
  l=strlen(s1);
  for(i=0;i<l;i++)
  {
    if(s1[i]=='1' && s2[i]=='1')
      s3[i]='1';
    else
       s3[i]='0';
  }
  s3[i]='\0';
}

void diff(char*s1,char*s2,char*s3)
{
  int i,l;
  l=strlen(s1);
  for(i=0;i<l;i++)
  {
    if(s1[i]=='1' && s2[i]=='0')
      s3[i]='1';
    else
       s3[i]='0';
  }
  s3[i]='\0';
}