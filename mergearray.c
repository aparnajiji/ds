#include<stdio.h>
void main()
{
int a[10],b[10],c[10],i,j,k,m,n;
printf("enter the limit of first array= ");
scanf("%d",&m);
for(i=0;i<m;i++)
{
 scanf("%d",&a[i]);
}
printf("enter the limit of second array= ");
scanf("%d",&n);
for(j=0;j<n;j++)
{
scanf("%d",&b[j]);
}
i=0;
j=0;
k=0;
while(i<m && j<n)
{
if(a[i]<=b[j])
 {
  c[k]=a[i];
  i++;
  k++;
 }
else if(a[i]>b[j])
 {
  c[k]=b[j];
  j++;
  k++;
 }
}
if (i<m)
{
while(i<m)
{
 c[k]=a[i];
 i++;
 k++;
}
}
else if (j<n)
{
while(j<n)
{
 c[k]=b[j];
 j++;
 k++;
}
}
printf("the merged array : ");
for(i=0;i<k;i++)
{
 printf("%d",c[i]);
}
}