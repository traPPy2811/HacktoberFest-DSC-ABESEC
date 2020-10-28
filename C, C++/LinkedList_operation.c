//main

// Single Linked List operations 
#include<stdio.h>
struct list{
 int data;
 struct list *link;
 };
 void insert_f(list);
 void insert_L(list);
 void insert_p(list);
 void insert_a(list);
 void del_f(list);
void del_l(list);
void del_info(list);
void del_p(list);
 void display(list);
 void search(list);
 void main()
{
    struct list *start=NULL;
    int select;
    do
    {
    printf("\n\nPress \n1 for insert as first node\n2 for insert as last node\n3 for insert at nth position\n4 for insert after given item\n");
    printf("5 for delete first node\n6 for delete last node\n7 for delete node having given info\n8 for delete node at particular position");
    printf("\n9 for Display\n10 for search item.\n0 for Exit\n");
    scanf("%d",&select);
    switch(select)
    {
    case 1:
     insert_f(&start);
     break;
    case 2:
    insert_L(&start);
    break;
    case 3:
    insert_p(&start);
    break;
    case 4:
    insert_a(&start);
    break;
    case 5:
    del_f(&start);
    break;
    case 6:
    del_l(&start);
    break;
    case 7:
    del_info(&start);
    break;
    case 8:
    del_p(&start);
    break;
    case 9:
    display(start);
    break;
    case 10:
    search(&start);
    break;
    }
    }
    while(select!=0);


}


////insert a node as first node.
void insert_f(struct list **ptr)
{
    int item;
    struct list *new1;
    printf("Enter the value");
    scanf("%d",&item);
    new1=(struct list*)malloc(sizeof(struct list));
    new1->data=item;
    new1->link=*ptr;
    *ptr=new1;
}


////insert a node as last node.
void insert_L(struct list **ptr)
 {
     struct list *tptr,*new1;
     int item;
     tptr=*ptr;
     if(tptr==NULL)
     insert_f(ptr);
     else{
        while(tptr->link!=NULL)
            tptr=tptr->link;
    printf("Enter the value");
    scanf("%d",&item);
    new1=(struct list*)malloc(sizeof(struct list));
    new1->data=item;
    new1->link=tptr->link;
    tptr->link=new1;
     }
 }

 ////insert a node at particular position.
 void insert_p(struct list **ptr)
{
    int n,c=1,item;
      struct list *new1,*tptr,*tptr2;
    printf("Enter the value of position");
    scanf("%d",&n);
    if(n==1)
        insert_f(ptr);
    else{
         tptr=*ptr;
        while(c!=n && tptr!=NULL)
        {
            tptr2=tptr;
            tptr=tptr->link;
            c++;
        }
            if(n>c)
            printf("Invalid position");
            else{
            printf("Enter the value");
            scanf("%d",&item);
            new1=(struct list*)malloc(sizeof(struct list));
            new1->data=item;
            new1->link=tptr;
            tptr2->link=new1;
            }
        }
    }
    //insert a node after given item
void insert_a(struct list **ptr)
{
    int item,item1;
    struct list *new1,*tptr;
    printf("enter the item after which new node insert");
    scanf("%d",&item1);
    tptr=*ptr;
    while(tptr!=NULL && tptr->data!=item1)
    {
        tptr=tptr->link;
    }
     if(tptr==NULL)
            printf("item is not found");
            else{
            printf("Enter the new node data value");
            scanf("%d",&item);
            new1=(struct list*)malloc(sizeof(struct list));
            new1->data=item;
            new1->link=tptr->link;
            tptr->link=new1;
            }
}
//Delete first node
void del_f(struct list **ptr)
{
      struct list *tptr;
    if(*ptr==NULL)
        printf("List is empty");
    else{
    tptr=*ptr;
    *ptr=tptr->link;
    free(tptr);
    }
}

//Delete last node


void del_l(struct list **ptr)
{
    struct list *tptr,*tptr2;
    tptr=*ptr;
    tptr2=*ptr;
    if(*ptr==NULL)
        printf("List is empty");
    else{
        if(tptr2->link==NULL)
        del_f(ptr);
    else{

    while(tptr->link!=NULL)
    {
        tptr2=tptr;
        tptr=tptr->link;
    }
    tptr2->link=tptr->link;
    free(tptr);
   }
   }
}
//delete node having given info
void del_info(struct list **ptr)
{
    int item;
    struct list *tptr,*tptr2;
    tptr=*ptr;
     tptr2=*ptr;
     if(tptr2==NULL)
     {
         printf("List is empty");
     }
     else{
    printf("Enter the value of node which you want to delete ");
    scanf("%d",&item);
     if(tptr2->data==item)
        del_f(ptr);
     else{
    while(tptr!=NULL && tptr->data!=item)
    {
        tptr2=tptr;
        tptr=tptr->link;
    }
    if(tptr==NULL)
        printf("Given value node is not found");
    else{
    tptr2->link=tptr->link;
    free(tptr);
    }
    }
}}

//delete node at particular position

void del_p(struct list **ptr)
{
   int n,c=1;
    struct list *tptr,*tptr2;
    tptr=*ptr;
    tptr2=*ptr;
    if(tptr2==NULL)
    {
        printf("list is empty");
    }
    else
    {
         printf("Enter the position");
         scanf("%d",&n);
         if(n==1)
            del_f(ptr);
         else{
            while(c!=n && tptr!=NULL)
            {
                tptr2=tptr;
                tptr=tptr->link;
                c++;
            }
            if(tptr==NULL)
            {
                printf("position is not valid");
            }
            else
            {
                 tptr2->link=tptr->link;
                 free(tptr);
            }
         }
    }
}
//for display
void display(struct list *start)
{
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start=start->link;
    }
}

// Search a item in linked list
void search(struct list **ptr)
{
    int item;
    struct list *tptr;
    tptr=*ptr;
    printf("Enter the item for search");
    scanf("%d",&item);
    while(tptr!=NULL)
    {
        if(tptr->data==item)
        {
            printf("Item found");
            break;
        }
        tptr=tptr->link;
    }
    if(tptr==NULL)
    {
        printf("Not found");
    }
}
