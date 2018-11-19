#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE1   1024
#define SIZE2   2048
#define SIZE3   4096
#define SIZE4   8192
#define SIZE5   16384
#define POW2    2
#define POW3    3

/****************************************************************************/
/* All algorithms and cases. Each defined by their own id.
/****************************************************************************/
#define     id_BUBBLESORT       1
#define     id_INSERSION        2
#define     id_QUICKSORT        3
#define     id_LINEARSEARCH     4
#define     id_BINARYSEARCH     5

#define     id_BESTCASE         1
#define     id_RANDOMCASE       2
#define     id_WORSTCASE        3


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
void tableDisplay(double times[],int alg,char CaseChoice);
void FE_BubbleSort_BestCase();
void initArray(int algID,int caseID);
void runAlgorithm(int algID, int caseID);

//BE_Functions
void error();
void startTimer();
void stopTimer();
void resetTimer();
void calc(double N[],double T[],int algID);
void printName(int algID);
void printCase(int caseID);
void bubbleSort(int array[],int size);
float BE_BubbleSort_BestCase(int size);
double loopGivenTime(int algID,int caseID,int array[],int size, int searchedValue);
void insertion(int array[], int size);
int partition(int A[],int lo,int hi, int caseID);
void quicksort(int A[],int lo,int hi, int caseID);
int calcMid(int A[],int lo, int hi);
void swap(int *a, int *b);
void printCol(int algID, int *check);
void linearSearch(int list[], int size, int searchedValue);

