#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,cnt=0;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==c)
       {
            printf("0 %d\n",d-b);
            continue;
       }
        else if(b==d)
        {
            printf("%d 0\n",c-a);
            continue;
        }
        else if(d>b)
        {
                cnt+=60-b;
                cnt+=d;
                printf("%d %d\n",c-a,(cnt%60));
                continue;
        }       
        else 
        {
            printf("%d ",c-a-1);
        }
        
        
        
        if(b>d)
        {
            cnt+=60-b;
            cnt+=d;
            printf("%d\n",cnt);
        }
        
    }
}
