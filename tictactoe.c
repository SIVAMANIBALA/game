#include<stdio.h>
void pattern(char a[5][5])
{
    int n=5;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i==0)||(i==n-1))
            a[i][j]='-';
            else if((j==0)||(j==n-1))
            a[i][j]='|';
            else
            a[i][j]=' ';
        }
    }
}
int check(char a[5][5])
{
    int k=0,q=0;
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(a[i][j]=='x')
                k=k+1;
            else if(a[i][j]=='o')
                q=q+1;
        }
    }
    if(k+q==9)
    return 1;
    else 
    return 0;
}
int main()
{
    char a[5][5];
    int y,b,c=0,x=0,o=0,k=0,q=0;
    pattern(a);
    while(1)
    {
        printf("\n");
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                printf("%2c",a[i][j]);
            }
        printf("\n");
        }
        printf("give the place to fill ");
        scanf("%d",&y);
        scanf("%d",&b);
        if(((y<0)||(y>3))||((b<0)||(b>3)))
        {
            printf("give dimention between 0-3");
            continue;
        }
        if(a[y][b]==' ')
        {
            if(c==0)
            {
                a[y][b]='x';
                c=1;
            }
            else
            {
                a[y][b]='o';
                c=0;
            }
        }
        else
        {
            printf("already filled");
            continue;
        }
        int h=check(a);
        if(h==1)
        {
            printf("game ovr");
            break;
        }
        for(int i=1;i<4;i++)
        {
            x=0;
            o=0;
            for(int j=1;j<4;j++)
            {
                if(a[i][j]=='x')
                x++;
                else if(a[i][j]=='o')
                o++;
            }
            if(x==3)
            {
                
                break;
            }
            else if(o==3)
            {
         
                break;
            }    
        }
        if(x==3)
        {
            printf("x wins");
            break;
        }
        else if(o==3)
        {
            printf("o wins");
            break;
        }
        for(int i=1;i<4;i++)
        {
            x=0;
            o=0;
            for(int j=1;j<4;j++)
            {
                if(a[j][i]=='x')
                x++;
                else if(a[j][i]=='o')
                o++;
            }
            if(x==3)
            {
                
                break;
            }
            else if(o==3)
            {
                
                break;
            }
        }
        if(x==3)
        {
            printf("x wins");
            break;
        }
        else if(o==3)
        {
            printf("o wins");
            break;
        }
        x=0;
        o=0;
        for(int i=1;i<4;i++)
        {
            
            for(int j=1;j<4;j++)
            {
                if(i==j)
                {
                    if(a[i][j]=='x')
                    x++;
                    else if(a[i][j]=='o')
                    o++;
                }
            }
        }
        if(x==3)
        {
            printf("x wins");
            break;
        }            
        else if(o==3)
        {
            printf("o wins");
            break;
        }   
        x=0;
        o=0;     
        for(int i=1;i<4;i++)
        {    
            for(int j=1;j<4;j++)
            {
                if(i+j==4)
                {
                    if(a[i][j]=='x')
                    x++;
                    else if(a[i][j]=='o')
                    o++;
                }
            }   
        }
        if(x==3)
        {
            printf("x wins");
            break;
        }
        else if(o==3)
        {
            printf("o wins");
            break;
        }
    }
    printf("\n");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%c",a[i][j]);
        }
    printf("\n");
    }
    return 0;
}