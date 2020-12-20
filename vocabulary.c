#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define NOINPUTFILE 1
#define CANTOPENFILE 2
#define INVALIDFILE 3
#define OUTOFMEMORY 4
#define MAXINPUT 255

struct _mystruct {
  char* first;
  char* second;
};  

int main( int argc, char *argv[] )
{
  FILE* fp;
  int check = 0;
  struct _mystruct *structPointer;
  int spaceMiddle = 0;
  int spaceAfter = 0;
  int unvalid = 0;
  int capacity = 0;
  int spaceLast = 0;
  int structCounter = 0;
  int charCounter = 0;
  int increaseStructArray = 1;
  char input[MAXINPUT];
  int correctAnswers = 0;

  // Array to save the struct addresses
  struct _mystruct **structArray = calloc(10, sizeof(struct _mystruct*));
    if (structArray == NULL)
      {
        printf("ERROR: Out of Memory\n");
        return OUTOFMEMORY;
      }
  // Pointer of the first charachter of the file
  char* word1 = (char*)malloc(sizeof(char) * 1);
    if (word1 == NULL)
      {
        printf("ERROR: Out of Memory\n");
        return OUTOFMEMORY;
      }
  char* word2 = (char*)malloc(sizeof(char) * 1);
    if (word2 == NULL)
      {
        printf("ERROR: Out of Memory\n");
        return OUTOFMEMORY;
      }      

  if( argc < 2 )
  {
    printf("usage: [%s] filename\n", argv[0]);
    return NOINPUTFILE;
  }
  else
  {
    fp = fopen(argv[1], "r"); // read mode
    if (fp == NULL)
    {
      printf("ERROR: cannot open file [%s]\n", argv[1]);
      return CANTOPENFILE;
    }
    else
    {
      structPointer = (struct _mystruct *) malloc(sizeof(struct _mystruct) * 1);
      if (structPointer == NULL)
      {
        printf("ERROR: Out of Memory\n");
        return OUTOFMEMORY;
      }
      else
      {
      structArray[structCounter] = structPointer;
      structPointer->first = word1;
      structPointer->second = word2;
        while((check = getc(fp)) != EOF)
        {
          check = tolower(check);
          check = tolower(check);

          if (check == '\n')
          {
            if (capacity == 10)
            {
              increaseStructArray++;
              structArray = realloc(structArray, (sizeof(struct _mystruct*) * 10) * increaseStructArray);
              capacity = 0;
            }
            spaceMiddle = 0;
            spaceAfter = 0;
            spaceLast = 0;
            unvalid = 0;
            charCounter = 0;
            structCounter++;
            structPointer = (struct _mystruct *) malloc(sizeof(struct _mystruct) * 1);
            structPointer->first = (char*)malloc(sizeof(char) * 1);
            structPointer->second = (char*)malloc(sizeof(char) * 1);
            structArray[structCounter] = structPointer;
            capacity++;
            continue;
          }
          if((check == ' ') && (spaceMiddle == 0) && (unvalid == 0))
          {
           continue; 
          }
          else if((check != ' ') && (spaceMiddle == 0 || spaceMiddle == 1) && (spaceAfter == 0) && (unvalid == 0) && (spaceLast == 0))
          {
            structPointer->first[charCounter] = check;
            charCounter++;
            structPointer->first = (char*)realloc(structPointer->first, charCounter + 1);
            spaceMiddle = 1;
          }
          else if ((check == ' ') && (spaceMiddle == 1) && (unvalid == 0)
            && (spaceLast == 0))
          {
            charCounter = 0;
            spaceAfter = 1;
            continue;
          }
          else if((check != ' ') && (spaceAfter == 1) && (unvalid == 0))
          {
            structPointer->second[charCounter] = check;
            charCounter++;
            structPointer->second = (char*)realloc(structPointer->second, charCounter + 1);
            spaceLast = 1;
          }
          else if((check == ' ') && (spaceLast = 1) && (spaceAfter == 1))
          {
            unvalid = 1;
            continue;
          }
          if ((check != ' ') && (unvalid == 1))
          {
            printf("ERROR: file [%s] invalid\n", argv[1]);
            return INVALIDFILE;
          }

        }
        for (int i = 0; i < structCounter; ++i)
        {
          if (i%2 == 0)
          {
            printf("%s-", structArray[i]->first);
            fgets(input, MAXINPUT, stdin);
            size_t length = strlen(input);
            if(input[length-1] == '\n')
            {
              if (length>1)
              {
              input[length-1] = 0;
              }
            }
            for (int i = 0; i < strlen(input); ++i)
            {
              input[i] = tolower(input[i]);
            }
              if((strcmp(input, structArray[i]->second)) == 0 )
                {
                  correctAnswers++;
                }
          }
          else
          {
            printf("%s-", structArray[i]->second);
            fgets(input, MAXINPUT, stdin);
            size_t length = strlen(input);
            if(input[length-1] == '\n')
            {
              if (length>1)
              {
              input[length-1] = 0;
              }
            }
            for (int i = 0; i < strlen(input); ++i)
            {
              input[i] = tolower(input[i]);
            }
            if((strcmp(input, structArray[i]->first)) == 0 )
              {
                correctAnswers++;
              }
          }
        }
      }
    }
  }
  for (int i = 0; i < structCounter; ++i)
  {
    free(structArray[i]->first);
    free(structArray[i]->second);
    free(structArray[i]);
  }
  free(structArray);
  fclose(fp);
  printf("%d / %d\n", correctAnswers, structCounter);
  return SUCCESS;
}

