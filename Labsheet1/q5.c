#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,i,j,k;

    scanf("%d",&num);

    int size = (2*num)-1;

    int** arr = (int**)malloc(size * sizeof(int*));

    for(i=0;i<size;i++){
        arr[i] = (int*)calloc(size,sizeof(int));
    }

    int r,c;

    if(num%2==0)
    {
        r=num;
        c=num-2;
    }
    else
    {
        r = num-1;
        c = num-1;
    }

    int des=1;

    int dir=0,counter=1;

    while(des<=num*num)
    {
        switch(dir%4)
        {
            case 0 :
                for(k=counter;k>0;k--)
                {
                    arr[r][c] = 2*des;
                    c=c+1;
                    arr[r][c] = -1;
                    c=c+1;
                    des++;
                    
                }
                dir++;
            break;
            case 1 :
                for(k=counter;k>0;k--)
                {
                    arr[r][c] = 2*des;
                    r=r-1;
                    arr[r][c] = -2;
                    r=r-1;
                    des++;
                   
                }
                counter++;
                dir++;
            break;
            case 2 :
                for(k=counter;k>0;k--)
                {
                    arr[r][c] = 2*des;
                    c=c-1;
                    arr[r][c] = -1;
                    c=c-1;
                    des++;

                }
                dir++;
            break;
            case 3 :
                for(k=counter;k>0;k--)
                {
                    arr[r][c] = 2*des;
                    r=r+1;
                    arr[r][c] = -2;
                    r=r+1;
                    des++;
                }
                counter++;
                dir++;
            break;
        }
    }







    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++){

            switch(arr[i][j])
            {
                case 0 :
                    printf("%5s"," ");
                break;
                case -1 :
                    printf("%5s","-----");
                break;
                case -2 :
                    printf("%5s","|");
                break;
                default:
                    printf("%5d",arr[i][j]);
            }
        }
        printf("\n");
    }


    for(i=0;i<size;i++)
        free(arr[i]);

    free(arr);

    return(0);

}