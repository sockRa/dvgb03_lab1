#include "driver.h"

//@   Inför uppsatsen, lägg in resultaten i en graf för att visa att det stämmer överens med big O!

/****************************************************************************/
/* Global data objects                                                      */
/****************************************************************************/


static int numTest = 5;                                         /*how many times should the loop go*/ 
static int arrayOfSizes[] = {SIZE1,SIZE2,SIZE3,SIZE4,SIZE5};    /*Init array*/  

/****************************************************************************/
/* Result table                                                            
/****************************************************************************/


void tableDisplay(int times[],int algID,char caseID){

   int check = 0;

    printf("-------------------------------------------------------------------------\n");
    printf("--- %s-%s                                            ---\n",setName(algID),setCase(caseID));
    printf("-------------------------------------------------------------------------\n");
    printf("---     N     Time          %s            %s        %s         ---\n",setCol(algID,&check),setCol(algID,&check),setCol(algID,&check));
    printf("-------------------------------------------------------------------------\n");
    printf("---  %d       %d    %E    %E    %E    ---\n",SIZE1,times[0],calc(times[0],arrayOfSizes[0],1), calc(times[0],arrayOfSizes[0],2), calc(times[0],arrayOfSizes[0],3));
    printf("---  %d       %d    %E    %E    %E    ---\n",SIZE2,times[1],calc(times[1],arrayOfSizes[1],1), calc(times[1],arrayOfSizes[1],2), calc(times[1],arrayOfSizes[1],3));
    printf("---  %d       %d    %E    %E    %E    ---\n",SIZE3,times[2],calc(times[2],arrayOfSizes[2],1), calc(times[2],arrayOfSizes[2],2), calc(times[2],arrayOfSizes[2],3));
    printf("---  %d       %d    %E    %E    %E    ---\n",SIZE4,times[3],calc(times[3],arrayOfSizes[3],1), calc(times[3],arrayOfSizes[3],2), calc(times[3],arrayOfSizes[3],3));
    printf("---  %d       %d    %E    %E    %E    ---\n",SIZE5,times[4],calc(times[4],arrayOfSizes[4],1), calc(times[4],arrayOfSizes[4],2), calc(times[4],arrayOfSizes[4],3));
    printf("-------------------------------------------------------------------------\n");
}



void initArray(int algID,int caseID){

    int i,j,random,*list,size,times[numTest],searchValue;
    int boolean = 1;
    
    srand(time(NULL));

    for(j=0;j<numTest;j++){

        size = arrayOfSizes[j];             //For every iteration, size gets a new value 
        list = malloc(sizeof(int*) * size);
            
            //Special cases

            if(algID == id_LINEARSEARCH || algID == id_BINARYSEARCH){
                switch(caseID){
                        case 1:     for(i=0;i<size;i++) {*(list + i) = i;}    searchValue = 0;                                          break;
                        case 2:     for(i=0;i<size;i++) {random = rand() % size;    *(list + i) = random;}   searchValue = random;      break;
                        case 3:     for(i=0;i<size;i++) {*(list + i) = size - i;}   searchValue = -1;                                   break;   
                }

            }else{

                //Standard cases
                switch(caseID){
                    case 1:     for(i=0;i<size;i++) *(list + i) = i;                                    break;      //Best-case, sorted order.          
                    case 2:     for(i=0;i<size;i++){random = rand() % size; *(list + i) = random;}      break;      //Random-case
                    case 3:     for(i=0;i<size;i++) *(list + i) = size - i;                             break;      //Worst-case, decending order 
                }
            }
            
            //Run algorithms
                switch(algID){

                    case 1:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);      break;       //Bubblesort
                    case 2:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);      break;       //Insertionsort      
                    case 3:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);      break;       //Quicksort      
                    case 4:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);      break;       //LinearSearch
                    case 5:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);      break;       //BinarySearch      
                }
                free(list);
    }
    tableDisplay(times,algID,caseID);
}

void runAll(){
    int algID,caseID,i;

}
/*
@   algID 1 = BUBBLESORT
@   algID 2 = INSERSION
@   algID 3 = QUICKSORT
@   algID 4 = LINEARSEARCH
@   algID 5 = BINARYSEARCH

@   caseID 1 = BESTCASE
@   caseID 2 = RANDOMCASE
@   caseID 3 = WORSTCASE
*/

