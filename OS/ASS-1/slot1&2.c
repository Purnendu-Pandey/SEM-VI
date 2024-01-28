//Q1
#include<stdio.h>
#include<stdlib.h>
int max[10][10];
int alloc[10][10];
int need[10][10];
int avail[10];
int n, r;
int sq[10];
int work[10];
void input() 
{
    int i, j;
    printf("Enter the no of Processes : ");
    scanf("%d",&n);
    printf("Enter the no of resources instances : ");
    scanf("%d",&r);
    printf("Enter the Max Matrix\n");
    for (i=0;i<n;i++) 
    {
        for (j=0;j<r;j++) 
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i=0;i<n;i++) 
    {
        for (j=0;j<r;j++) 
        {
           scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the available Resources\n");
    for (j=0;j<r;j++) 
    {
        printf("For R[%d] : ",j+1);
        scanf("%d", &avail[j]);
    }
    printf("\n");
}
void show()
{
    printf("PID\tAlloc\tMax\tneed\n");
    for(int i=0; i<n; i++)
    {
        printf("P[%d]\t",i);
        for(int j=0;j<r;j++)
            printf("%d ",alloc[i][j]);
        printf("\t");
        for(int j=0;j<r;j++)
            printf("%d ",max[i][j]);
        printf("\t");
        for(int j=0;j<r;j++)
            printf("%d ",need[i][j]=(max[i][j]-alloc[i][j]));
        printf("\n");
    }
}
int safety()
{
    int finish[10];
    for(int i=0;i<r;i++)
    {
        work[i]=avail[i];
    }
    for(int i=0; i<n; i++)
        finish[i]=0;

    int proceed=1;
    int k=0;
    int c=0;
    while(proceed)
    {
        proceed=0;
        for(int i=0;i<n;i++)
        {
            int flag=1;
            if(finish[i]==0)
            {

                for(int j=0; j<r; j++)
                {
                    if(need[i][j] <= work[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    continue;
                for(int j=0; j<r; j++)
                    work[j]=work[j]+ alloc[i][j];
                finish[i]=1;
                sq[k++]=i;
                proceed=1;
            }
        }
    } 
    int i;
    for( i=0; i<n ; i++)
    {
       if(finish[i]==1)
           c++;
    }
    if(c==n)
    {
        printf("\n** System  is in safe state **\n");
        printf("* Ssafe seq. is **\n ");
        for(int i=0; i<n; i++)
            printf("p%d-->",sq[i]);
        printf("\n");
        printf("\n** Total Resources are ** \n");
        for(int i=0; i<r; i++)
        {
            printf("\nFor R[%d] : ",i+1);
            printf("%d\n",work[i]);
        }
        printf("\n");
    }
    else
    {
        printf(" System is unsafe\n");
        printf("* Deadlock Occurred **\n");

    }
}
void main()
{
    input();
    show();
    safety();
}


//Q2
#include<stdio.h>
#include<string.h>

int n,m,i,j,l,k,flag,safe;
int a[50][50],av[15],max[50][50],finish[10],need[50][50],req[10],tot[20];
char s[50],str[5];

void get_data()
{
     printf("\nEnter number of processes : ");
     scanf("%d",&n);
     printf("\nEnter number of resources : ");
     scanf("%d",&m);
     printf("\nEnter allocation matrix : \n");
     for (i=0;i<n;i++)
     {
        for (j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter MAX matrix : \n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
           scanf("%d",&max[i][j]);
        }
    } 
    printf("Enter total instances : ");
    for (i=0;i<m;i++)
    {
      scanf("%d",&tot[i]);
    } 
    for (i=0;i<n;i++)
        finish[i]=0;
}
void put_data()
{
    printf("\n\nAllocation matrix is : \n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\nMax Matrix is : \n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
           printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    printf("\n\nAvailable Array is : \n");
    for (i=0;i<m;i++)
        printf("%d\t",av[i]);
}
void calc_need()
{
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
           need[i][j] = max[i][j] - a[i][j];
        }
    }
    printf("\n\nNeed Array is : \n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
           printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
}
int check_need(int i)
{
    flag=0;
    for (j=0;j<m;j++)
    {
        if(need[i][j]>av[j])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
void safe_state()
{
    printf("\n\n");
    strcpy (s,"\0");
    for (i=0;i<n;i++)
    {
        if (check_need(i)==0)
        {
            for (k=0;k<m;k++)
                av[k]=av[k]+a[i][k];
            sprintf(str,"%d",i);
            strcat(s,"P");
            strcat(s,str);
            strcat(s," ");
            puts(s);
        }
        else
            finish[i]=1;
    }
}
void calc_avail()
{
         
    for (i=0;i<m;i++)
    {
        l=0;
        for (j=0;j<n;j++)
        {
            l+=a[j][i];
        }
        av[i]=tot[i]-l;
    }
}
void res_req()
{
    safe = 0;
    printf("Enter the process number : ");
    scanf("%d",&i);
    printf("\nEnter the request : ");
    for (k=0;k<m;k++)
        scanf("%d",&req[k]);
    printf("\nEnter available array : ");
    for (j=0;j<m;j++)
          scanf("%d",&av[j]);
    for (k=0;k<m;k++)
    {
        if (req[k]>need[i][k] || req[k]>av[k])
        {
            safe = 1;
            break;
        }
    } 
    if (safe == 0)
    {
        for (k=0;k<m;k++)
        {
            av[k] = av[k] - req[k];
            a[i][k] = a[i][k] + req[k];
            need[i][k] = need[i][k] - req[k];
        }
        printf("\nNeed array is : \n");
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                printf("%d\t",need[i][j]);
            }
            printf("\n");
        }
        put_data();
        printf("The request can be granted.....\n");
    }
    else
        printf("\nThe request can not be granted immediately....\n");
}
void main()
{
    int p,f;
    f=0;
    get_data();
    calc_avail();
    aaa : 
    put_data();
    calc_need();
    safe_state();
     
    for (k=0;k<m;k++)
    {
        if (finish[k]==1)
        {
            if (check_need(k)==0)
            {
                for (p=0;p<m;p++)
                    av[p] = av[p] + a[k][p];
                sprintf(str,"%d",k);
                strcat(s,"P");
                strcat(s,str);
                strcat(s," ");
                finish[k]=1;
            }
            else
                f=1;
        }
    }
    if (f==0)
    {
        printf("System is in safe state.....\n");
        printf("\nSafe Sequence\n");
        puts(s);
    }
    else
        printf("System is not in safe state\n");
    res_req();
    goto aaa;    
}