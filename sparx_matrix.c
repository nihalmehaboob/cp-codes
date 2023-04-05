#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int val;
}sparse;
void main()
{
    sparse s1[25],s2[25],t[25],add[25];
    int i,j,k=1,l=1,m,n,p,q;
    int a[5][5],b[5][5];
    printf("Enter size of Matrix A: ");
    scanf("%d %d",&m,&n);
    printf("Enter size of Matrix B: ");
    scanf("%d %d",&p,&q);
    printf("Enter values of Matrix A: \n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);

            if(a[i][j]!=0){
            s1[k].row=i;
            s1[k].col=j;
            s1[k].val=a[i][j];
            k++;
            }
        }
    s1[0].row=m,s1[0].col=n,s1[0].val=k;
    printf("Enter values of Matrix B: \n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j]!=0){
            s2[l].row=i;
            s2[l].col=j;
            s2[l].val=b[i][j];
            l++;
            }
        }

    s2[0].row=m,s2[0].col=n,s2[0].val=k;
    printf("\nTuple form of Matrix A \n");
    for(i=0;i<k;i++)
    		printf("<%d,%d,%d> \n",s1[i].row,s1[i].col,s1[i].val);
    printf("\nTuple form of Matrix B \n");
    for(i=0;i<l;i++)
    		printf("<%d,%d,%d> \n",s2[i].row,s2[i].col,s2[i].val);
   
    //transpose
    t[0].row=s1[0].col;
    t[0].col=s1[0].row;
    t[0].val=s1[0].val;
    m=1;
    for(i=0;i<s1[0].col;i++)
        for(j=0;j<s1[0].val;j++)
            if(s1[j].col==i){
            t[m].row=s1[j].col;
            t[m].col=s1[j].row;
            t[m].val=s1[j].val;
            m++;
            }
    printf("\nTranspose of Matrix A \n");
    for(i=0;i<k;i++)
    		printf("<%d,%d,%d> \n",t[i].row,t[i].col,t[i].val);
    //adding
    i=1,j=1,m=1;
    while(i<k&&j<l){
        if((s1[i].col==s2[j].col)&&(s1[i].row==s2[j].row)){
            add[m].val=s1[i].val+s2[j].val;
            add[m].row=s1[i].row;
            add[m].col=s1[i].col;
            i++;j++;
        }
        else if(((s1[i].row<s2[j].row))||((s1[i].row==s2[j].row)&&(s1[i].col<s2[j].col)))
        {
            add[m].val=s1[i].val;
            add[m].row=s1[i].row;
            add[m].col=s1[i].col;
            i++;
        }
        else if(((s1[i].row>s2[j].row))||((s1[i].row==s2[j].row)&&(s1[i].col>s2[j].col)))
        {
            add[m].val=s2[j].val;
            add[m].row=s2[j].row;
            add[m].col=s2[j].col;
            j++;
        }
        //printf("i %d j %d ",i,j);
        m++;
    }
    while(i<k){
    add[m].val=s1[i].val;
    add[m].row=s1[i].row;
    add[m].col=s1[i].col;
    i++;
    m++;
    }
    while(j<l){
    add[m].val=s2[j].val;
    add[m].row=s2[j].row;
    add[m].col=s2[j].col;
    j++;
    m++;
    }
    printf("\nSum: \n");
    for(i=1;i<m;i++)
    printf("<%d,%d,%d> \n",add[i].row,add[i].col,add[i].val);
}

