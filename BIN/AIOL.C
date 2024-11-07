#include<stdio.h>
#include<conio.h>
#define MAX 10
void create();
void insert();
void deletion();
void search();
void display();
int a,b[20],n,p,e,f,i,pos;

void main(){
int ch;
char g='y';
clrscr();
do{
printf("\nMain Menu");
printf("\n1.Create\n2.Delete\n3.Search\n4.Insert\n5.Display\n6.Exit\n");
printf("\nEnter your Choice");
scanf("%d",&ch);
switch(ch){
case 1:
create();
break;
case 2:
deletion();
break;
case 3:
search();
break;
case 4:
insert();
break;
case 5:
display();
break;
case 6:
exit();
break;
default:
printf("\nEnter the correct choice:");
}
printf("\nDo you want to continue:");
scanf("\n%c", &g);
}while(g=='y'||g=='Y');
getch();
}

void create(){
printf("\nEnter the number of nodes");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter the Element:",i+1);
scanf("%d",&b[i]);
}
}

void deletion(){
printf("\nEnter the position you want to delete:");
scanf("%d", &pos);
if(pos>=n){
printf("\nInvalid Location:");
}
else{
for(i=pos+1;i<n;i++){
b[i-1]=b[i];
}
n--;
}
printf("\n The Elements after deletion");
for(i=0;i<n;i++){
printf("\t%d",b[i]);
}
}

void search(){
printf("\nEnter the Element to be searched:");
scanf("%d",&e);
for(i=0;i<n;i++){
if(b[i]==e){
printf("Value is in the %d Position", i);
}
else{
printf("Value %d is not in the list", e);
continue;
}
}
}

void insert(){
printf("\nEnter the position u need to insert:");
scanf("%d",&pos);
if(pos>=n){
printf("\ninvalid Location:");
}
else{
for(i=MAX-1;i>=pos-1;i--){
b[i+1]=b[i];
}
printf("\nEnter the element to insert:\n");
scanf("%d",&p);
b[pos]=p;
n++;
}
printf("\nThe list after insertion::\n");
display();
}

void display(){
printf("\nThe Elements of The list ADT are:");
for(i=0;i<n;i++){
printf("\n\n%d", b[i]);
}
}