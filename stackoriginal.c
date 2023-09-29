#include<stdio.h>
int main()
{
int a[20],top=-1,ch,el;
printf("\n Select your choices");
do
{
printf("\n1. push \n2.pop \n3. exit \n4.Display\n");
scanf("%d",&ch);
if(ch==1)
{
if(top!=20)
{
printf("\nEnter the element");
scanf("%d",&el);
top++;
a[top]=el;
}
else
printf("\nStack overflow");
}


else if(ch==2)
{
if(top!=-1)
{
printf("\nRemoving the last element");
top--;
}
else
printf("\n Stack underflow");
}



else if(ch==4)
{
printf("\nDisplayin elements");
for(int i=0;i<=top;i++)
printf("\t%d",a[i]);
}
}while(ch!=3);
printf("\nExited");
return 0;
}
