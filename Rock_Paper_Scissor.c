#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void computer(int choice,int *uScore, int *cScore){

    int compNum, send;
    char compChoice1[]="Rock", compChoice2[]="Paper", compChoice3[]="Scissors";

    srand(time(NULL));
    compNum = rand()%100;

    if(compNum>=0 && compNum<33){
        send=1;   //rock
    }
    else if(compNum>=33 && compNum<66){
        send=2;   //ppr
    }
    else{
        send=3;   //sci
    }

    if(choice==send){
        printf("Oops! It's a Draw\n");
        if(choice==1)
            printf("You both have chosen Rock!\n");
        else if(choice==2)
            printf("You both have chosen Paper!\n");
        else
            printf("You both have chosen Scissors!\n");
    }

    else if(choice==1 && send==2){
        printf("Mr. Computer has chosen PAPER\n");
        printf("Uh oh! Tough luck, Mr. Computer has won :(\n");
        (*cScore)++;
    }

    else if(choice==1 && send==3){
        printf("Mr. Computer has chosen SCISSORS\n");
        printf("Hooray! You have won!\(*v*)/\n");
        (*uScore)++;
    }

    else if(choice==2 && send==1){
        printf("Mr. Computer has chosen ROCK\n");
        printf("Looks like we're up for a Party!!\n");
        (*uScore)++;
    }

    else if(choice==2 && send==3){
        printf("Mr. Computer has chosen SCISSORS\n");
        printf("Better luck next time buddy...\n");
        (*cScore)++;
    }

    else if(choice==3 && send==1){
        printf("Mr. Computer has chosen ROCK\n");
        printf("Alas...Give this poor soul some luck...\n");
        (*cScore)++;
    }
    else{
        printf("Mr. Computer has chosen PAPER\n");
        printf("Did I smell luck? You have WON!\n\n");
        (*uScore)++;
    }
}

int main(){
    int choice,i, uScore=0, cScore=0;
    char ans;
    char userName[50];

    printf("Enter a classy name: ");
    scanf("%[^\n]s", &userName);
    printf("\n");

    printf("         HELLO %s!\n", userName);
    printf("WELCOME TO ROCK PAPER AND SCISSORS!\n");


do{
    for(i=0;i<3;i++){
        printf("\n1. Rock\n2. Paper\n3. Scissors\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice>3 || choice<1){
            printf("\nWrong choice buddy. See you next time!!\n");
            exit(0);
        }
        else{
            computer(choice, &uScore, &cScore);
            printf("\n------------------ SCORE ------------------\n");
            printf("%s: %d", userName, uScore);
            printf("           Mr. Computer: %d\n", cScore);
            printf("\n-------------------------------------------\n\n");

        }
    }


    printf("\n-------------- OVERALL SCORE --------------\n");
    printf("%s: %d               Mr. Computer: %d\n\n", userName, uScore, cScore);

    if(uScore>cScore){
        printf("Winner Winner CHICKEN DINNERRR!!\n");
    }
    else if(uScore==cScore){
        printf("It's a DRAW. Guess %s and Mr. Computer are soulmates (;\n", userName);
    }
    else{
        printf("Uhhh...Failure is the first step to success...ig\n");
    }

    printf("\n-------------------------------------------\n\n");
    
    printf("Missing me already? How about a rematch?[y/n]: ");
    while ((getchar()) != '\n');
    scanf("%c", &ans);

    switch(ans){
        case'y': printf("\nSo, it has come to a rematch huh? ^_^\n");
                 break;
        
        case'n': printf("\nWe'll miss you terribly... :<\n");
                 exit(0);

        default: printf("\nINVALID CHOICE. You gotta go! BYEE\n");
                 exit(0);
    }
}
while(ans=='y');

    return 0;
}
