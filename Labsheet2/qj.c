#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct countryStruct
{
    char name[20];
    int gold;
    int silver;
    int bronze;
};

typedef struct countryStruct country;

int main()
{
    int token;
    scanf("%d",&token);
    country* arr = (country*)malloc(token * sizeof(country));
    for(int i=0;i<token;i++)
    {
        scanf("%s %d %d %d",arr[i].name,&arr[i].gold,&arr[i].silver,&arr[i].bronze);
    }
    
    int last=token;
    int flag=0;

    while(flag==0)
    {   
        flag=1;
        for(int i=0;i<last-1;i++)
        {
            country tempCount1 = arr[i];
            country tempCount2 = arr[i+1];
            if(tempCount1.gold>tempCount2.gold)
            {
                country temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=0;
            }
            else if(tempCount1.gold==tempCount2.gold && tempCount1.silver>tempCount2.silver)
            {
                country temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=0;
            }
            else if(tempCount1.silver==tempCount2.silver && tempCount1.bronze>tempCount2.bronze)
            {
                country temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=0;
            }
        }
        last--;
    }
    for(int i=token-1;i>=0;i--)
    {
        printf("%s\n",arr[i].name);
    }
    free(arr);
    return(0);
}
