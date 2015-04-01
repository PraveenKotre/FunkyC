/*
LIMITATION:

1. Declaration statement should be at most 200 letters
2. Variable name not allowed more than 11
3. Not more than 100 variables can be declared in a statement

NOTE: Errors and pointers not dealt yet.

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void declaration(int ,FILE* );


char GivenString[1000][1000];
int main()
{
FILE *f;


strcpy(GivenString[0],"char youbitch, ngB,kokf;");

declaration(1, f);


return 0;
}

void declaration(int linenum, FILE* fp)
{	int i;
	char* token;
	char split[100][20];
	int Count;
	char result[200];
	printf("%s\n",GivenString[linenum-1]);
		
//DEVIDE THE STRING INTO TOKENS
        token = strtok(GivenString[linenum-1]," ");
        for(i=0; token != NULL;i++ ) 
        {
        strcpy(split[i], token );
	printf("%s%d\n", split[i],i);
        token = strtok(NULL, ",;");
	
        }
	Count=i;
		
	
//FOR BIGINT 	
	if(strcmp(split[0],"bigInt")==0)
		{
			strcpy(split[0],"int");
			for(i=1;i<Count;i++)
			strcat(split[i],"[1000000]");
		}

//FOR CHARACTER

	if(strcmp(split[0],"char")==0);

//FOR INTEGER
	
	if(strcmp(split[0],"int")==0);
		

//RESULTANT LINE

			strcpy(result, split[0]);
			strcat(result," ");
			for(i=1;i<Count;i++)
			{
				strcat(result,split[i]);
				if(i==(Count-1))
					strcat(result,";");
				else
					strcat(result,", ");			
			}
			strcat(result,"\n");
			printf("%s", result);
			
//FOR WRITING INTO FILE
	fp=fopen("sometextfile.txt", "w+");
	
	if(fp == NULL)
    {
        perror("Error opening the file.\n");
        exit(EXIT_FAILURE);         
    }

	fputs(result, fp);
	fclose(fp);

}


