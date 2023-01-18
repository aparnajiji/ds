#include<stdio.h>
#include<stdlib.h>
void insertb();
void inserte();
void insertm();
void delb();
void dele();
void delm();
void display();
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node *head=NULL,*ptr=NULL,*new=NULL,*temp=NULL ;
void main()
{
int n,i,opt;
printf("enter the no.of node to be created: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
new=(struct node*)malloc(sizeof(struct node));
printf("enter the data to be inserted: ");
scanf("%d",&new->data);
new->prev=NULL;
new->next=NULL;
if(head==NULL)
head=new;
else{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new;
new->prev=ptr;
}
}
do
{
printf("\n enter your choice: \n1.insert at beginning \n2.insert at end \n3.insert at middle \n4.delete at beginning \n5.delete at end \n6.delete at middle \n7.display \n8.exit ");
scanf("%d",&opt);
switch(opt)
{
  case 1:insertb();
	 break;
  case 2:inserte();
	 break;
  case 3:insertm();
	 break;
  case 4:delb();
	 break;
  case 5:dele();
	 break; 
  case 6:delm();
	 break;
  case 7:display();
	 break;
  case 8:printf("exit");
         break;
  default:printf("invalid");
}
}
while(opt!=8);
}

void insertb()
{
new=(struct node*)malloc(sizeof(struct node));
printf("\n enter the data to be inserted at beginning: ");
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
new->next=head;
head=new;
}
void inserte()
{
new=(struct node*)malloc(sizeof(struct node));
printf("\n enter the data to be inserted at end: ");
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
if(head== NULL)
head=new;
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
new->prev=ptr;
ptr->next=new;
}
}
void insertm()
{
 int key;
printf("enter the key:");
scanf("%d",&key);
new=(struct node*)malloc(sizeof(struct node));
printf("\n enter the data to be inserted at middle: ");
scanf("%d",&new->data);
new->next=NULL;
new->prev=NULL;
if(head== NULL)
head=new;
else
{
ptr=head;
while(ptr->next!=NULL &&ptr->data!=key)
{
ptr=ptr->next;
}
}
if(ptr->next==NULL)
{
ptr->next=new;
new->next=ptr;
}
else
{
  temp=ptr->next;
  new->next=temp;
  new->prev=ptr;
  ptr->next=new;
  temp->prev=new;
}
}

void display()
{
 printf("list is:");
 ptr=head;
 while(ptr!=NULL)
 {
  printf("%d",ptr->data);
  ptr=ptr->next;
}
} 

void delb()
{
  if(head!=NULL)
  {
    printf("\n %d is deleted",head->data);
    head=head->next;
  }
}

void dele()
{
 ptr=head;
 while(ptr->next!=NULL)
 {
  ptr=ptr->next;
 }
if(ptr->next==NULL)
{
 temp=ptr->prev;
 temp->next=NULL;
 ptr->prev=NULL;
 printf("\n %d is deleted",ptr->data);
}
}

void delm()
{
 int key;
 printf("enter the key to be deleted:");
 scanf("%d",&key);
 if(head->data==key)
  {
    head=head->next;
}
temp=head;
ptr=head->next;
while(ptr!=NULL)
{
 if(ptr->data==key)
  {
    temp->next=ptr->next;
    temp->prev=ptr->prev;
    free(ptr);
    printf("\n %d is deleted",key);
}
else
{
 temp=ptr;
 ptr=ptr->next;
}
}
}