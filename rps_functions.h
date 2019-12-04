#ifndef displayheaders_h
#define displayheaders_h

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "displayheaders.h"

enum RPS{
      NADA,
      ROCK,
      PAPER,
      SCISSOR
}RPS;

struct scores{
  int computer;
  int player;
};

void displayGreet(void);
void checkWinner(int player, int puter, struct scores * players);
void displayCPU(int PUTER);
void showScores(const struct scores input);
bool exitProgram(void);

#endif