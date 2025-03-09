#include<stdio.h>

char a,b,again; /*input*/

int playagain();
void printscore();

int main(){

    int y;
    int c,d=0;
    int *cptr=&c;
    int *dptr=&d;
    char option[] = {'r','p','r','s','p','r','s','r','s','p','s'};

    printf("\nEnter q to quit or");

    while(1){
        start:
        printf("\nenter [r]ock/[p]aper/[s]cissor: [ ]\b\b");
        scanf(" %c",&a);
        
        if(a>=65&&a<=90) a=a+32;
        if((a!='r')&&(a!='p')&&(a!='s')){
            if (a=='q'||a=='Q') {
                return 0;
            }
            printf("Invalid option\n");
            goto start;
        }
            b = option[y];
            printf("you:(%c) computer:(%c)\nresult: ",a,b);
            y++;
            if(y==11) y=0;
            
            
           if(a==b) printf("Tie\n");
            else
            {
                if (a=='r'&&b=='p') {printf("Computer +1 \n");d++;}
                else if (a=='p'&&b=='s') {printf("Computer +1 \n");d++; }
                else if (a=='s'&&b=='r') {printf("Computer +1 \n");d++;}
                else {printf("Player +1 \n"); c++;}

            }

          printscore(cptr,dptr);

    }

    return 0;
}

int playagain(){
    printf("Would you play again:(Y/N): [ ]\b\b");
          scanf(" %c",&again);
          if(again>=65&&again<=90) again=again+32;
          if(again == 'n') {printf("Bye\n"); return 0;}
          else printf("\n\033c\033[91;4;mNew game\033[0m");
    
}

void printscore(int *cptr,int *dptr){
        printf("\033[95;1m");
        printf("Score: You:(%d) Computer:(%d)\n",*cptr,*dptr);
        printf("\033[0m");
        if (*cptr==3){
          printf("\033[92;1m");
          puts("You win");
          printf("\033[0m");  
          *cptr=*dptr=0;
          playagain();
        }else if(*dptr==3){
          printf("\033[91;1m");
          puts("You loose");
          printf("\033[0m");
          *cptr=*dptr=0;
          playagain();
        }

}