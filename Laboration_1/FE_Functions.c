#include "driver.h"

/****************************************************************************/
/* Global data objects                                                      */
/****************************************************************************/


static int numTest = 5;                                         /*how many times should the loop go*/ 
static int arrayOfSizes[] = {SIZE1,SIZE2,SIZE3,SIZE4,SIZE5};    /*Init array*/    

/****************************************************************************/
/* Result table                                                            
/****************************************************************************/


void tableDisplay(int time[],int alg,char CaseChoice){

    
    int times[numTest],i;

    char *name = setName(alg);
    char *Case = setCase(CaseChoice);

    printf("-------------------------------------------------------------------------\n");
    printf("--- %s-%s                                            ---\n",name,Case);
    printf("-------------------------------------------------------------------------\n");
    printf("---     N     Time          T/N            T/N^2        T/N^3         ---\n");
    printf("-------------------------------------------------------------------------\n");
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[0],times[0],calc(times[0],arrayOfSizes[0],1), calc(times[0],arrayOfSizes[0],2), calc(times[0],arrayOfSizes[0],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[1],times[1],calc(times[1],arrayOfSizes[1],1), calc(times[1],arrayOfSizes[1],2), calc(times[1],arrayOfSizes[1],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[2],times[2],calc(times[2],arrayOfSizes[2],1), calc(times[2],arrayOfSizes[2],2), calc(times[2],arrayOfSizes[2],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[3],times[3],calc(times[3],arrayOfSizes[3],1), calc(times[3],arrayOfSizes[3],2), calc(times[3],arrayOfSizes[3],3));
    printf("---  %d       %d    %e    %e    %e    ---\n",arrayOfSizes[4],times[4],calc(times[4],arrayOfSizes[4],1), calc(times[4],arrayOfSizes[4],2), calc(times[4],arrayOfSizes[4],3));
    printf("-------------------------------------------------------------------------\n");
}
    
/****************************************************************************/
/* Bubble Sort - All cases                                                            
/****************************************************************************/

void FE_BubbleSort_BestCase(){

    int i;
    int time[numTest];
    for(i=0;i<numTest;i++){
     time[i] = BE_BubbleSort_BestCase(arrayOfSizes[i]);
     }

    tableDisplay(time,1,'b');
}

/****************************************************************************/
/* Insertion Sort - All cases                                                            
/****************************************************************************/

/****************************************************************************/
/* Quicksort Sort - All cases                                                             
/****************************************************************************/

/****************************************************************************/
/* Linear Search - All cases                                                            
/****************************************************************************/

/****************************************************************************/
/* Binary Search - All cases                                                             
/****************************************************************************/
