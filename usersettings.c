#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "usersettings.h"
#include "typesandpatterns.h"

//Defines
#define SIZEOFBYTE 8

//Function definitions
void printAviableDataTypes();
void getDataTypeSelection();

void printAviableDataPatterns();
void getDataPatternSelection();

void getDataLength();
void getDeliminator();

void printUserSettings();

//Typedefs
typedef struct settings{
    bool isArrayLike;
    uint8_t dataType;
    uint8_t dataPattern;
    double nrOfElements;
    char *deliminator;
}Settings;

//Global Vars
Settings GlobalSettings = {0};


//Function declarations
void printAviableDataTypes()
{
    uint8_t nrOfTypes = sizeof(dataType)/SIZEOFBYTE;
 
    printf("Choose one of the following Datatypes by entering the associated number\n");
   
    for(int i = 0; i < nrOfTypes; i++)
        printf("[%2u]: %s\n", i, dataType[i]);
}

void getDataTypeSelection()
{
    unsigned int temp; 

    scanf("%u", &temp);
    if(temp > 255)
        temp = 255;
    GlobalSettings.dataType = temp;
}

void printAviableDataPatterns()
{
    uint8_t nrOfPatterns = sizeof(dataPattern)/SIZEOFBYTE;
 
    printf("Choose one of the following Datapatterns by entering the associated number\n");
 
    for(int i = 0; i < nrOfPatterns; i++)
        printf("[%2u]: %s\n", i, dataPattern[i]);
       
}

void getDataPatternSelection()
{
    unsigned int temp;

    scanf("%u", &temp);
    if(temp > 255)
        temp = 255;
    GlobalSettings.dataType = temp;
    GlobalSettings.dataPattern = temp;
}


void getDataLength()
{
    double temp; 
    printf("Enter Nr. of Elements to be created in Testdata: ");
    scanf("%lf", &temp);

    GlobalSettings.nrOfElements = temp;
}

void getDeliminator()
{
    char *temp = malloc(300*sizeof(char));
    printf("Enter deliminator: ");
    scanf("%s", temp);
    GlobalSettings.deliminator = temp;
}

void printUserSettings()
{
    printf("Datatypes: %s\nDatapattern: %s\nNr of Elements:%lf\nDeliminator: %s",
    dataType[GlobalSettings.dataType], dataPattern[GlobalSettings.dataPattern], GlobalSettings.nrOfElements, GlobalSettings.deliminator);
}


void readAllUserSettings()
{
    printf("Should data be generated in C array like fashion ? (y/n)\n");
    char selection = getchar();

    if(selection == 'Y' | selection == 'y')
        GlobalSettings.isArrayLike = true;
    else
        GlobalSettings.isArrayLike = false;


    printAviableDataPatterns();
    getDataPatternSelection();

    printAviableDataTypes();
    getDataTypeSelection();

    getDataLength();

    if(!GlobalSettings.isArrayLike)
        getDeliminator();

    printUserSettings();
}