#include <stdio.h>
#include <conio.h>
#define max 5
static int stack[max];
int top = -1;

void push(int x){
stack[++top] =x;
}

int pop(){
return (stack[top--]);
}

void view(){
int i;
if (top<0)
printf("\nStack Empty\n");
else{
printf("\nTop-->");
for(i=top;i>=0;i--){
printf("%4d", stack[i]);
}
printf("\n");
}
}

main(){
int ch=0,val;
clrscr();
while(ch != 4){
printf("\nSTACK OPERATION\n");
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.VIEW\n");
printf("4.QUIT\n");
printf("Enter Choice:");
scanf("%d",&ch);
switch(ch){
case 1:
if(top < max-1){
printf("\nEnter Stack element:");
scanf("%d",&val);
push(val);
}
else{
printf("\nStack Overflow\n");
}
break;
case 2:
if(top < 0)
printf("\nStack Underflow\n");
else
val = pop();
printf("\nPopped element is %d\n", val);
break;
case 3:
view();
break;
case 4:
exit(0);
default:
printf("\nInvalid Choice\n");
}
}
return 0;
}