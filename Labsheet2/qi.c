#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct studStruct
{
    char mail[38];
    char branch[4];
    char id[14];
};

typedef struct studStruct stud;

void genId(stud *newstud)
{
    int j=0;
    for(int i=1;i<5;i++){
        newstud->id[j] = newstud->mail[i];
        j++;
    }
    if(strcmp(newstud->branch,"CS")==0){
        strcat(newstud->id,"A7PS");
    }
    else if(strcmp(newstud->branch,"ECE")==0){
        strcat(newstud->id,"AAPS");
    }
    else if(strcmp(newstud->branch,"EEE")==0){
        strcat(newstud->id,"A3PS");
    }
    j=8;
    for(int i=5;i<9;i++){
        newstud->id[j] = newstud->mail[i];
        j++;
    }
    strcat(newstud->id,"H");

}





int main(){
    stud mystud;
    scanf("%s\n%s",mystud.mail,mystud.branch);
    genId(&mystud);
    printf("%s",mystud.id);
    return(0);
}