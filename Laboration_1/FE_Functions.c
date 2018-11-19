#include "driver.h"

//@   Inför uppsatsen, lägg in resultaten i en graf för att visa att det stämmer överens med big O!

/*To-do
1.  Kasta bort de två-tre första mätningarna på tiden
2.  fixa display  

/****************************************************************************/
/* Global data objects                                                      */
/****************************************************************************/


static int numAlg = 5;     //Number of algorithms present
static int numCases = 3;    //Number of cases present                                         
static double arrayOfSizes[] = {SIZE1,SIZE2,SIZE3,SIZE4,SIZE5};     /*Init array*/  



/****************************************************************************/
/* Result table                                                            
/****************************************************************************/


void tableDisplay(double times[],int algID,char caseID){

   int check = 0;

    printf("-------------------------------------------------------------------------\n");
    printName(algID);         printCase(caseID);
    printf("-------------------------------------------------------------------------\n");
    printf("N\t");  printf("Time\t");  printCol(algID,&check);   printCol(algID,&check);   printCol(algID,&check);
    printf("-------------------------------------------------------------------------\n");
    calc(arrayOfSizes,times,algID);
    printf("-------------------------------------------------------------------------\n");
}

void initArray(int algID,int caseID){

    int i,j,random,*list,size,searchValue;
    double times[numAlg];
    
    srand(time(NULL));

    for(j=0;j<numAlg;j++){

        size = arrayOfSizes[j];             //For every iteration, size gets a new value 
        list = malloc(sizeof(int*) * size);
            
                //Linear/Binary-search list prep
                if(algID == id_LINEARSEARCH || algID == id_BINARYSEARCH){  
                    switch(caseID){
                        case 1:     for(i=0;i<size;i++) {*(list + i) = i;}    searchValue = 0;                                          break;  //Best
                        case 2:     for(i=0;i<size;i++) {random = rand() % size;    *(list + i) = random;}   searchValue = random;      break;  //Random
                        case 3:     for(i=0;i<size;i++) {*(list + i) = size - i;}   searchValue = -1;                                   break;  //Worst
                    }
                }
                else{
                    //Standard cases
                        switch(caseID){
                            case 1:     for(i=0;i<size;i++) *(list + i) = i;                                    break;      //Best-case, sorted order.          
                            case 2:     for(i=0;i<size;i++){random = rand() % size; *(list + i) = random;}      break;      //Random-case
                            case 3:     for(i=0;i<size;i++) *(list + i) = size - i;                             break;      //Worst-case, decending order 
                        }
                }
            //Run algorithms
                switch(algID){
                    case 1:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);       break;  //Bubblesort
                    case 2:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);       break;  //Insertionsort      
                    case 3:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);       break;  //Quicksort      
                    case 4:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);       break;  //LinearSearch    
                    case 5:     times[j] = loopGivenTime(algID,caseID,list,size,searchValue);       break;  //BinarySearch  
                }
                free(list);
    }
    tableDisplay(times,algID,caseID);
}

void runAll(){
    int algID = 0,caseID = 0, i;
    int maxRuns = numAlg * numCases;
    
    for(i = 0; i < maxRuns; i++){
        initArray(algID,caseID);
        if(caseID != numCases) caseID ++;
        else{
            caseID = 0;
            algID++;
        }
    }
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
