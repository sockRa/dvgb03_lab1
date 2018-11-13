#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE1  1024
#define SIZE2  2048
#define SIZE3  4096
#define SIZE4  8192
#define SIZE5  16384


/****************************************************************************/
/*  Function prototypes                                                     */
/****************************************************************************/
//Driver_Functions
void UI_runmenu();

//Menu_Functions
void UI_invalidChoice();
void UI_exit();
static char UI_get_choice();
static void UI_dispmenu();

//FE_Functions
int doubleSize(int size);
void tableDisplay(int times[],int alg,char CaseChoice);
void FE_BubbleSort_BestCase();
void initArray(int algID,int caseID);
void runAlgorithm(int algID, int caseID);

//BE_Functions
void error();
void startTimer();
void stopTimer();
void resetTimer();
double calc(double t, double n, int toPower);
char *setName(int algID);
char *setCase(int caseID);
void bubbleSort(int array[],int size);
float BE_BubbleSort_BestCase(int size);
int loopGivenTime(int algID,int array[],int size);
void insertion(int array[], int size);

