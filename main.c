
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define GREETING1 "\n|||||||||WELCOME TO RPS||||||||||\n 1 = ROCK ! 2 = PAPER ! 3 = SCISSORS !"
#define GREETING2 "\nCHOOSE YOUR WEAPON, KNAVE: "
#define RECEIVECHOICE "\n\nYOU HAVE CHOSEN...%s"
#define SHOWPUTER "\nAND PUTER HAS CHOSEN...%s"
#define BLAAAM1 "\n++++++++++++-------++++++++++++\n-----------+++++++++-----------\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
#define TIE "\nYOU SHALL LIVE, BUT NEITHER SHALL YOU WIN..."
#define WIN "\n\nYOU HAVE WON. WIPE THE BLOOD OFF AND CELEBRATE WITH BOOZE AND BED\nOH GREAT CHAMPION...."
#define LOSE "\nYOU HAVE DIED."

#define SHAMEFULDEFEAT "\nYOU HAVE FAILED TO CHOOSE A WEAPON.\nYOU ARE KILLED WHERE YOU STAND!"
#define EXITPROMPT "\n\nDo you want to continue or quit?\n[PRESS ANY OTHER KEY TO CONTINUE]\nType 'quit' to stop this program: "
#define QUITTING "\n\nQuitting program. Have a nice day!"
#define SCORES "\n\nSCORES:\tPlayer: %d\t\tPuter: %d"
enum RPS{
      NADA,
      ROCK,
      PAPER,
      SCISSOR
};
#define rock "ROCK"
#define paper "PAPER"
#define scissor "SCISSORS"

struct scores{
  int computer;
  int player;
};

void checkWinner(int player, int puter, struct scores * players);
void displayCPU(int PUTER);
void showScores(const struct scores input);
bool exitProgram(void);


int main(void) {
  int choice;
  struct scores players;
  players.player = 0;
  players.computer = 0;
  bool continuePlaying = true;

  while(continuePlaying){
    printf(GREETING1);
    printf(BLAAAM1);
    printf(GREETING2);

    scanf("%d", &choice);

    srand(time(0));
    int PUTER = rand()%3;

    if(choice == ROCK){
      printf(RECEIVECHOICE, rock);
    }
    else if(choice == PAPER){
      printf(RECEIVECHOICE, paper);
    }
    else if(choice == SCISSOR){
      printf(RECEIVECHOICE, scissor);
    }

    displayCPU(PUTER);
    checkWinner(choice, PUTER, &players);
    showScores(players);
    
    int checker;
    char input[16];
    printf(EXITPROMPT);
    scanf("%s",input);

   
    checker = strcmp(input, "quit");
    if(checker > 0 || checker < 0){
      continue;
    }
    else{ break; }

    /*
    continuePlaying = exitProgram();
    */
  }
  printf(QUITTING);
  return 0;
}



void checkWinner(int player, int puter, struct scores * players){
  if(player==ROCK){
      if(puter==ROCK){
        printf(TIE);
      }
      else if(puter==PAPER){
        printf(LOSE);
        players->computer += 1;
      }
      else{
        printf(WIN);
        players->player += 1;
      }
  }
  if(player==PAPER){
      if(puter==ROCK){
        printf(WIN);
        players->player += 1;
      }
      else if(puter==PAPER){
        printf(TIE);
      }
      else{
        printf(LOSE);
        players->computer += 1;
      }
  }
  if(player==SCISSOR){
      if(puter==ROCK){
        printf(LOSE);
        players->computer += 1;
      }
      else if(puter==PAPER){
        printf(WIN);
        players->player += 1;
      }
      else{
        printf(TIE);
      }
  }
}


void displayCPU(int PUTER){
  if(PUTER == ROCK){
    printf(SHOWPUTER, rock);
  }
  else if(PUTER == PAPER){
    printf(SHOWPUTER, paper);
  }
  else if(PUTER == SCISSOR){
    printf(SHOWPUTER, scissor);
  }
}

bool exitProgram(){
  int checker;
  char input[16];
  printf(EXITPROMPT);
  scanf("%s",input);
  //input[15] = '\0'; //forcefully terminate any entry that's too long.

/*
  for(int i = 0; input[i] != '\0'; i++){
    input[i] = tolower(input[i]);
  } // massage input
*/

  checker = strcmp(input, "quit");
  if(checker > 0 || checker < 0){
    return false;
  }
  else{ return true; }


}

void showScores(const struct scores input){
  printf(SCORES, input.player, input.computer);
}
