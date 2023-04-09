#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void makeBrack(char temp[],char arr[] , int left, int right, int n)
{
    if( left == 1 && right ==3 )
    {
        strcpy(temp,"");
        return;
    }
    if(left > (n/2) || right > (n/2) )
    {
        strcpy(temp,"");
        return;
    }
    if(left == (n/2) && right == (n/2) )
    {
        strcat(arr,temp);
        strcpy(temp,"");
        return;

    }
    char my[14] = "";
    strcpy(my,temp);

    makeBrack(strcat(my,"("),arr,left+1,right,n);
    makeBrack(strcat(my,")"),arr,left,right+1,n);

}

int main()
{
    int k;
    scanf("%d",&k);
    char temp[14] = "";
    char arr[20000] = "";
    makeBrack(temp,arr,1,1,k);
    int st_len = strlen(arr);
    int num = st_len / (k-2) ; 
    printf("%d\n",num);

    for(int i = 0 ; i<st_len;i++)
    {
        printf("(");
        for(int j=0;j<k-2;j++)
        {
            printf("%c",arr[st_len-i-1]);
            i++;
        }
        printf(")\n");
    }
    return(0);
}