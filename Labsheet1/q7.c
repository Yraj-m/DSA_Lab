#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[1000]="";
    char word[1000]="";

    int lb=0,ub=0,i,j,k;

    fgets(str,1000,stdin);
    scanf("%s",word);

    int* arr = calloc(strlen(word),sizeof(int));

    int min = strlen(str);
    int word_len = strlen(word);

    for(i=0;i<strlen(str);i++){

        // hel
            
        for(j=0;j<word_len;j++){
            arr[j]=0;
        }

        for(j=i;j<=i+min-1;j++)
        {
            for(k=0;k<word_len;k++)
            {
                if(str[j]==word[k] && arr[k]==0)
                {   
                    arr[k]=1;
                    break;
                }
            }

                
            int tok = 0;
            for(k=0;k<word_len;k++)
            {
                if(arr[k]==0){
                    tok=1;
                    break;
                }
            }
            if(tok==0){
                min = j-i;
                lb=i;
                ub=j;
                break;
            }
        }
    }

    if(ub==0 && lb==0){
        printf("NO WINDOW");
    }
    else{
        printf("%d %d\n",lb,ub);
        for(i=lb;i<=ub;i++){
            printf("%c",str[i]);
        }
    }

    free(arr);

    return(0);


}