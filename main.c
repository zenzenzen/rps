
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "displayheaders.h"
#include "rps_functions.h"

enum RPS{
      NADA,
      ROCK,
      PAPER,
      SCISSOR
}RPS;

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