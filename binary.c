#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *root=NULL,*ptr=NULL,*new=NULL,*ptr1=NULL,*parent=NULL,*p=NULL;

void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(struct node*);
void delete(int);
void main()
{
   int opt,x;
   do
    {
       printf("\n enter your choice:\n1.insert \n2.inorder \n3.preorder \n4.postorder \n5.search \n6.delete \n7.exit \n");
       scanf("%d",&opt);
       switch(opt)
	{
          case 1: insert();
		  break;
	  case 2: inorder(root);
		  break;
	  case 3: preorder(root);
		  break;
	  case 4: postorder(root);
		  break;
	  case 5: search(root);
		  break;
	  case 6: printf("\n Enter the element to be deleted:");
		  scanf("%d",&x);
		  delete(x);
		  break;
	  case 7: exit(0);
		  break;
	  default:printf("invalid");	
	} 
	
    }
  while(opt!=7);
}

void insert()
{
    int key;
    new=(struct node*)malloc(sizeof(struct node));
    printf("\n enter the data to be inserted:");
    scanf("%d",&key);
    if(new==NULL)
	{
	  printf("insufficient memory");
	}
    else
	{
	  new->prev=NULL;
	  new->next=NULL;
          new->data=key;
	  if(root==NULL)
	     {
                root=new;          
             }
	  else{
          ptr=root;
	  while(ptr!=NULL)
          {
	  if(key==ptr->data)
	    {
		printf("item present in the tree");
		break;
	    } 
	  else if(key>ptr->data)
		{
                  ptr1=ptr;
		  ptr=ptr->next;		
		}
	       else
		{
			ptr1=ptr;
			ptr=ptr->prev;
		}
	  }
      
     if(ptr==NULL)
	{
          if(key>ptr1->data)
		ptr1->next=new;
	  else
		ptr1->prev=new;
	}
	}
}    
}

void inorder(struct node *ptr)
{
  if(ptr!=NULL)
    {
    inorder(ptr->prev);
    printf("%d ",ptr->data);
    inorder(ptr->next);
    }
}

void preorder(struct node *ptr)
{
  if(ptr!=NULL)
    {
     printf("%d ",ptr->data);
     preorder(ptr->prev);
     preorder(ptr->next);
    }
}

void postorder(struct node *ptr)
{
  if(ptr!=NULL)
    {
     postorder(ptr->prev);
     postorder(ptr->next);
     printf("%d ",ptr->data);
    }
}

void search(struct node *ptr)
{
    int data ,flag=0;
    if(ptr==NULL)
     printf("\n empty tree");
    else{
	  printf("enter the element to find:");
	  scanf("%d",&data);
	  while(ptr!=NULL)
	    {
		if(data==ptr->data)
		{
		 printf("\n element found");
		 ptr=NULL;
	     	 flag=1;
                }
                else if(data>ptr->data)
		   ptr=ptr->next;
	        else
		    ptr=ptr->prev;
	    }
        
         if(flag==0)
            printf("\n element not found");
       }
}

void delete(int x)
{
	int data;
	if(root==NULL)
	{
           printf("\n tree is empty");
        }
    	else{
     	parent=NULL;
     	ptr=root;
     	while(ptr!=NULL)
     	{
		if(ptr->data==x)
	  		break;
		parent=ptr;
		if(x>ptr->data)
	  	{
             		ptr=ptr->next;
         	 }
		else
         	{
	   		ptr=ptr->prev;
         	}	
     }
     if(ptr==NULL)
      {
	printf("item not present");
      }
	else{
     		if(ptr->next==NULL&&ptr->prev==NULL)
     		{
			if(parent==NULL)
	  		{
            		root=NULL;
          		}
			else if(parent->next==ptr)
		  	{
                    	parent->next=NULL;
                  	}
        		else{
	   		parent->prev=NULL;
			}
			printf("element deleted");
     			free(ptr);
    		 }
    else if(ptr->next!=NULL && ptr->prev!=NULL)
    {
      p=ptr->next;
    while(p->prev!=NULL)
    {
      p=p->prev;
    }
     data=p->data;
     delete(p->data);
     ptr->data=data;
    }
    else if(ptr->next!=NULL && ptr->prev==NULL || ptr->next==NULL && ptr->prev!=NULL)
    {
    if(parent==NULL)
    {
	if(ptr->next==NULL)
	   {
		root=ptr->prev;
	    }
	else{
            root=ptr->next;
        }
    }
    else
    {
	if(parent->next==ptr)
	{
	  if(ptr->next==NULL)
		parent->prev=ptr->prev;
	  else
		parent->next=ptr->next;
        }
        else
	{
	   if(ptr->prev==NULL)
		parent->prev=ptr->next;
	   else
	    	parent->prev=ptr->prev;
        }
    }
    printf("element deleted");
    free(ptr);
    }
}
}
}