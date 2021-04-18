#include <stdio.h>
#include <stdlib.h>
struct student {
char name [2][50];
int id;
int birthday[3];
int score;};

struct Node {
    struct student data;
    struct Node* next;
};
void add (struct Node* ptr){
 printf("\nThe name of the student:\n ");
  printf("The first name : ");
    scanf("%s",ptr->data.name[0]);
    printf("\nThe last name : ");
     scanf("%s",ptr->data.name[1]);
   printf("\nThe id of the student: ");
   scanf("%d",&ptr->data.id);
   printf("\nThe date of birth of the student: \n");
   printf("the day : ");
   scanf("%d",&ptr->data.birthday[0]);
   printf("\nthe month : ");
   scanf("%d",&ptr->data.birthday[1]);
   printf("\nthe year : ");
   scanf("%d",&ptr->data.birthday[2]);
   printf("\nThe score of student: ");
   scanf("%d",&ptr->data.score);
   printf("\n");
}
void display (struct Node* ptr,int num){
for (int i=1;i<=num;i++){
    printf("\n\nThe information of student #%d:\n",i);
    printf("The name: ");
    printf("%s",ptr->data.name[0]);
    printf(" ");
    printf("%s",ptr->data.name[1]);
   printf("\nThe id: ");
   printf("%d\n",ptr->data.id);
   printf("The date of birth: %d/%d/%d \n",ptr->data.birthday[0],ptr->data.birthday[1],ptr->data.birthday[2]);
   printf("The score of student: ");
   printf("%d\n",ptr->data.score);
   ptr=ptr->next;
}
}
struct Node* make_list( struct Node* ptr,int num){
   struct Node* p;
    printf("\nPlease enter the information of the student #1\n");
    add(ptr);

for (int i=2;i<=num;i++){
 p=ptr;
 ptr = (struct Node*)malloc(sizeof(struct Node));
   printf("\nPlease enter the information of the student #%d\n",i);
 add(ptr);
 p->next=ptr;

}
printf("-------------------------------------------------------------\n");
 return ptr;
}
struct Node* insert_begin(struct Node* ptr_h){
struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
new_node->next=ptr_h;
add(new_node);
    return new_node;

}
struct Node* insert_end(struct Node* ptr_t){
 struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
ptr_t->next=new_node;
add(new_node);
return new_node;

}
void insert_middle(struct Node* ptr_h,int num){
struct Node* ptr_e=ptr_h->next;
printf("After which node do you want to insert the new student:\nEnter valid inputs from 1 to %d\n",num-1);
int n;
scanf("%d",&n);
if ((n<num)&(n>0))
{
 struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
 add(new_node);
 for (int i=2;i<=n;i++)
 {
     ptr_h=ptr_h->next;
     ptr_e=ptr_e->next;}
     new_node->next=ptr_e;
ptr_h->next=new_node;
}

else printf("invalid input");
}
int main()
{

   printf("Welcome to our repo\n");
   printf("please complete the following informations.\n ");
 struct Node* head = NULL;
    struct Node* tail = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    int N;
    printf("Enter the number of student:\n");
    scanf("%d",&N);
   tail=make_list(head,N);

  printf("the list you entered:\n");

    display(head,N);

while(1){

            printf("-------------------------------------------------------------\n");
printf("\nchoose :\n 1-to insert at the beginning \n 2-to insert at the end \n 3-to insert in the middle \n 4-if you don't want to do any modifications \n");
int d;
scanf("%d",&d);
switch (d){
     case 1:head= insert_begin(head);
     N=N+1;
     printf("-------------------------------------------------------------\n");
     printf("the list after modification\n");
      display(head
              ,N);
     printf("-------------------------------------------------------------\n");
     break;
     case 2:tail=insert_end(tail);
     N=N+1;
     printf("-------------------------------------------------------------\n");
     printf("the list after modification\n");
      display(head,N);
     printf("-------------------------------------------------------------\n");
     break;
     case 3:insert_middle(head,N);
     N=N+1;
     printf("-------------------------------------------------------------\n");
     printf("the list after modification\n");
      display(head,N);
     printf("-------------------------------------------------------------\n");
     break;
     default: break;
     }
     printf("do you want to do any other modification (y or n)?");
char s='n';
scanf("%s",&s);
if (s!='y')break;

}
   free(head);
    return 0;
}

