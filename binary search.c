#include <stdio.h>
#include<stdlib.h>
#include <string.h>
void main()
{
 int i,n,low,high,mid;
 char a[50][50],key[20],temp[25];
 printf("enter the number of names to be added\n");
 scanf("%d",&n);
 printf("enter the names\n");
 for(i=0;i<=n-1;i++)
 {
 scanf("%s",&a[i]);
 }
 for(i=0;i<n;++i)
 {
 	for(int j=0;j<n-i;++j)
 	{
 		if(strcmp(a[i],a[j])>0)
 		{
 			strcpy(temp,a[i]);
 			strcpy(a[i],a[j]);
 			strcpy(a[j],temp);
 		}
 	}
 }
 printf("the orderd names \n");
 for(int i=0;i<n;++i)
 {
 	puts(a[i]);
 }
 printf("\n");
 printf("enter the name to be searched\n");
 scanf("%s",&key);
 low=0;
 high=n-1;
 while(low<=high)
 {
 mid=(low+high)/2;
 if (strcmp(key,a[mid])==0)
 {
 printf("key found at the position %d\n",mid+1);
        exit(0);
 }
 else if(strcmp(key,a[mid])>0)
 {
 high=high;
 low=mid+1;
 }
 else
 {
 low=low;
 high=mid-1;
 }
 }
 printf("name not found\n");
 }
