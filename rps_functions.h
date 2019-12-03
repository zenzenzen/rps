#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "displayheaders.h"


void checkWinner(int player, int puter, struct scores * players);
void displayCPU(int PUTER);
void showScores(const struct scores input);
bool exitProgram(void);