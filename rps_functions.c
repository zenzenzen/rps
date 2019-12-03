#include "rps_functions.h"





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


  checker = strcmp(input, "quit");
  if(checker != 0){
    return false;
  }
  else{ return true; }


}

void showScores(const struct scores input){
  printf(SCORES, input.player, input.computer);
}