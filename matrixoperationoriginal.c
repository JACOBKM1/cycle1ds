#include<stdio.h>
int main()
{
int m1[10][10],m2[10][10],i,j,k,n,ch,mul[10][10];
printf("\nEnter the required row or column number");
scanf("%d",&n);
printf("\nEnter the elements of 1'st matrix");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&m1[i][j]);
printf("\nEnter the elements of 2'nd matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&m2[i][j]);

printf("\nMatrix 1\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("\t%d",m1[i][j]);
printf("\n");
}

printf("\nMatrix 2\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("\t%d",m2[i][j]);
printf("\n");
}

do{
printf("\nEnter the choice\n 1. add matrix\n2. Multiply matrix\n3. Transpose\n4.Exit \t");
scanf("%d",&ch);

switch(ch)
{
case 1:printf("\nMatrix addition\n");
       for(i=0;i<n;i++)
       {
       for(j=0;j<n;j++)
       printf("\t%d",m1[i][j]+m2[i][j]);
       printf("\n");
       }
       break;
case 2:printf("\nMatrix multiplication\n");
       for(i=0;i<n;i++)    
       {
       for(j=0;j<n;j++)
       {
       mul[i][j]=0;
       for(k=0;k<n;k++)
       mul[i][j]+=m1[i][k]*m2[k][j];
       }
       }
       for(i=0;i<n;i++)
       {
       for(j=0;j<n;j++)
       printf("\t%d",mul[i][j]);
       printf("\n");
       }
       break;
case 3:printf("\nMatrix transpose of 1st matrix\n");
       for(i=0;i<n;i++)
       {
       for(j=0;j<n;j++)
       printf("\t%d",m1[j][i]);
       printf("\n");
       }
       printf("\nMatrix transpose of 2nd matrix\n");
       for(i=0;i<n;i++)
       {
       for(j=0;j<n;j++)
       printf("\t%d",m2[j][i]);
       printf("\n");
       }
default:printf("\nWrong choice");
}
}while(ch!=4);
return 0;
}
