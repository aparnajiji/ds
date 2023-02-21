#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*head;
void beginsert()
{
struct node*newnode;
int x;
newnode=(struct node*)malloc(sizeof(struct node*));
printf("\n enter data:");
scanf("%d",&x);
if(head==NULL)
{
newnode->data=x;
newnode->next=NULL;
head=newnode;
}
else
{
newnode->data=x;
newnode->next=head;
head=newnode;
}
}
void lastinsert()
{
struct node*newnode,*temp;
int x;
newnode=(struct node*)malloc(sizeof(struct node*));
printf("\n enter data:");
scanf("%d",&x);
newnode->data=x;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
newnode->next=NULL;
}
}
void posdel()
{
struct node*newnode,*prev;
int pos,i,x;
newnode=head;
if(newnode==NULL)
{
printf("\n the list is empty");
}
else
{
printf("\n enter the position");
scanf("%d",&pos);
if(pos==1)
{
newnode=head;
head=newnode->next;
x=newnode->data;
free(newnode);
printf("\n %d is deleted",x);
}
else
{
for(i=1;i<pos;i++)
{
prev=newnode;
newnode=newnode->next;
if(newnode==NULL)
{
printf("\n can't delete");
return;
}
}
prev->next=newnode->next;
x=newnode->data;
free(newnode);
printf("\n %d is deleted",x);
}
}
}

void search()
{
    struct node*ptr;
    int val,flag=0;
    printf("\n enter the value to be searched");
    scanf("%d",&val);
    if(head==NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->data==val)
            {
                printf("Item Found in List");
        flag =1;
        break;
              
            }
          
            ptr=ptr->next;
        }
        if(flag ==0)
        {
        printf("item not found");
    }
    }
}

void display()
{
struct node*ptr;
ptr=head;
if(ptr==NULL)
{
printf("list is");
}
else
{
while(ptr!=NULL)
{
printf("%d->",ptr->data);
ptr=ptr->next;
}
printf("null");
}
}
void main()
{


 int opt;

 do

  {

   printf("\nEnter your choice:\n1. Insert at beginning\n2.Insert at end \n3.delete at position \n4.search \n5.display\n6.Exit");

   scanf("%d",&opt);

   switch (opt)

   {

    case 1:beginsert();

           break;

  

    case 2:lastinsert();

           break;
 
    case 3:posdel();

           break;
 
    case 4:search();

           break;
  
    case 5:display();

           break;
    case 6:exit(0);

           break;


  
    default:printf("invalid choose");

   }

  }

 while(opt!=7);

}