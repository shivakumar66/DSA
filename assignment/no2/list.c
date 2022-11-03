#include<stdio.h>
#include<stdlib.h>
void insert_begin(int ele);
void insert_end(int ele);
void rev();
void insert_before(int a,int ele);
void insert_after(int a,int ele);
void forward();
int del_begin();
int del_last();
void del_specific(int a);
void travel_back();
//int display(struct node*curr);
struct node
{
   int data;
   struct node*next;
   
};
struct node*list;
struct node *temp;
struct node*curr;
//struct node*rev;

void insert_begin(int ele)
{
  // struct node*temp;
   temp=(struct node *)malloc(sizeof(struct node *));
   temp->data=ele;
   temp->next=list;
   list=temp;
}

void forward()
{
  curr=list;
   while(curr!=NULL)
   {
     printf("%d\t",curr->data);
     curr=curr->next;
   }
}

void insert_end(int ele)
{
 //  struct node*temp;
   temp=(struct node*)malloc(sizeof(struct node*));
   temp->data=ele;
   temp->next=NULL;
    if(list==NULL)
      list=temp;
    else
      {
        curr=list;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=temp;
         
      }
}

void insert_after(int a,int ele)
{
       curr=list;
       while(curr!=NULL&&curr->data!=a)
         { curr=curr->next; }
       if(curr!=NULL)
        {
           temp=(struct node*)malloc(sizeof(struct node*));
           temp->data=ele;
           temp->next=curr->next;
           curr->next=temp;
        }
       else
        
           printf("element not present");
        
}
  

void insert_before(int a,int ele)
 {
       if(list!=NULL)
        {
          if(list->data==a)
           {
             temp=(struct node*)malloc(sizeof(struct node*));
             temp->data=ele;
             temp->next=list;
             list=temp;
           }
         
          else
           {
             curr=list;
             while(curr!=NULL&&curr->next->data!=a)
                 {
                    curr=curr->next;
                 }
             if(curr==NULL)
             printf("node is not present");
             else
              {
                temp=(struct node*)malloc(sizeof(struct node*));
                temp->data=ele;
                temp->next=curr->next;
                curr->next=temp;
              }
           }
      }
     else
       printf("list is not present");

}

int del_begin()
{
    int x=-1;
     if(list!=NULL)
       {
	 temp=list;
         x=temp->data;
         list=temp->next;
          free(temp);
       }
     else
       
         printf("list is empty");
       
   return x;
 }

int del_last()
 {
	struct node *temp;
	struct node*curr;

   int x=-1;
    if(list!=NULL)
      {  
        if(list->next==NULL)
        {
         temp=list;
         x=temp->data;
         list=NULL;
          free(temp);
        }
       else
       {
        curr=list;
         while(curr->next->next!=NULL)
          {
            curr=curr->next;
          }
        temp=curr->next;
        x=temp->data;
        curr->next=NULL;
        free(temp);
      }
    }//end if
   else
    printf("list is empty\n");
    return x;
 }

void del_specific(int a)
{
   if(list!=NULL)
    {
       if(list->data==NULL)
        {
           temp=list;
           list=temp->next;
           free(temp);
        }
       else
        {
           curr=list;
           while(curr->next!=NULL&&curr->next->data!=a)
                curr=curr->next;
           if(curr->next!=NULL)
           {
           temp=curr->next;
           curr->next=temp->next;
           free(temp);
           }
           else
             printf("element not found\n");
        }
    }
   else
     printf("list is empty");
}

void travel_back()
{
    if(list!=NULL)
      {
          display(list);
      }
    else
       printf("list is empty");
}

int display(struct node*curr)
{
  if(curr==NULL)
   return (display(curr->next));
  printf("%d",curr->data);
}

void rev()
{
    struct node *rev=NULL;
    while(list!=NULL)
     {
        curr=list;
        list=curr->next;
        curr->next=rev;
        rev=curr;
     }
   list=rev;
}
int main()
{
  int i,n,element,c,a;
  
  while(1)
  {
     printf("\nenter your choice");
     printf("\n1.insert at begining\n2.insert at the end\n3.move forward\n4.inser after\n5.insert before");
     printf("\n6.delet begining\n7.delete last\n8.delete specific\n9.reverse\n10travel back\n11.exit");
     scanf("%d",&n);
     switch(n)
      {
        case 1: printf("\nenter the element:");
                scanf("%d",&element);
                insert_begin(element);
                break;
        case 2: printf("\nenter the element:");
                scanf("%d",&element);
                insert_end(element);
                break;
        case 3: forward();
                break;
        case 4:printf("\nenter the search element and new element:");
               scanf("%d%d",&a,&element);
               insert_after(a,element);
                break;
        case 5:printf("\nenter the search element and new element:\n");
               scanf("%d%d",&a,&element);
               insert_before(a,element);
                break;
        case 6:del_begin();
               break;
        case 7: del_last();
                break;
        case 8:printf("which element want to be deleted:\n");
               scanf("%d",&c);
               del_specific(c);
               break;
        case 9:rev();
                break;
        case 10:travel_back();
                break;
        case 11: exit(1);
                break;
        default:printf("worng choice");
                 break;
      }
   }
}
