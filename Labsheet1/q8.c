#include<stdio.h>
#include<string.h>

int main(){

    char str[1001]="";
    char palindromes[1001]="";

    fgets(str,1000,stdin);
    
    int letters=strlen(str)-1;

    int i=0;

    while(letters--){
        
        char temp[1001]="";
        int size=0;
        while(str[i]!=' ' && str[i]!='\0' && str[i]!='\n'){
            strncat(temp,&str[i],1);
            size++;
            i++;
        }
        for(int j=size-1;j>=0;j--){
            printf("%c",temp[j]);
        }
        printf(" ");

        int token=1;

        for(int j = 0;j<size/2;j++){
            if(temp[j]!=temp[size-1-j])
                token=0;
        }
        if(token==1 && size>1){
            strcat(palindromes,temp);
            strcat(palindromes," ");
        }
        
        i++;
    }

    if(strlen(palindromes)==0){
        printf("\nNO PALINDROMES");
    }
    else{
        printf("\n%s",palindromes);
    }

    return(0);

}