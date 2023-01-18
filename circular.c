#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
int a[10],size=5,item,f=-1,r=-1;
void main()
{
int opt;
do
{
printf("\n enter your choice\n1.insert \n2.delete \n3.display \n4.exit\n");
scanf("%d",&opt);
printf("the choice is %d\n",opt);
switch(opt)
{
case 1:insert();
       break;
case 2:delete();
       break;
case 3:display();
       break;
case 4:exit(0);
       break;
default:printf("invalid choice");
}
}while(opt!=4);
}
void insert()
{
	if(f==(r+1)%size)
  	{
    		printf("Queue is full");
  	}
	else
	{
	printf("enter the item:");
	scanf("%d",&item);
	if(f==-1 && r==-1)
	{
		f=0,r=0;
		a[r]=item;
	}
	else
	{
		r=(r+1)%size;
		a[r]=item;
	}
	}
}

void delete()
{
	if(f==-1)
	{
		printf("Underflow");
	}
	else if(f==r)
	{
		printf("the element to be deleted is %d",a[f]);
		f=r=-1;
	}
	else
	{
	printf("element to be deleted is %d",a[f]);
	f=(f+1)%size;
	}
}
void display()
{
	int temp;
	temp=f;
	if(temp==-1 && r==-1)
	{
		printf("no element");
	}
	else{
		printf("queue elements:");
		while(temp>-1)
		{
			printf("%d",a[temp]);
			if (temp==r)
			{
				break;
			}
			temp=(temp+1)%size;
		}
	}
}
