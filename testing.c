#include<stdio.h>
#include<string.h>


int main()
{
    char a[100];int s,n,t;
   int t1;
   scanf("%d",&t1);
   while(t1--)
   {
        scanf("%s",a);
    scanf("%d",&t);
    int p=t;
    s=strlen(a);
    int i;
    for(i=0;i<s;i++)
    {
        t=t%26;
        if(a[i]>=65&&a[i]<=90)
            {
                if(a[i]+t>90)
                {
                    a[i]=64+(a[i]+t-90);
                }
                else
                a[i]+=t;
            }
            else if(a[i]>=97&&a[i]<=122)
            {
                if(a[i]+t>122)
                {
                    a[i]=96+(a[i]+t-122);
                }
                else
                a[i]+=t;
            }
             else if(a[i]>='0'&&a[i]<='9')
            {
                n=p;
               if(p>9)
                n=(n%10);
                else
                n=p;
              //  printf("%d %d\n",p,n);
                a[i]+=n;

                if(a[i]>57)
                a[i]-=10;

            }

    }
    printf("%s\n",a);
   }
    return 0;
}

