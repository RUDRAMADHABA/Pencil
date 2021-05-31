#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdbool.h>
#include<string.h>
//#include "element.h"
#include "cmdfun.h"

#define FLUSH while(getchar()!= '\n'){}

void printHeader(){
    printf("Pencil v1.0.0.10\t\t\t(c) GCC\n\n");
    printf("                 ____    _______   _        _   _______   _______   _        \n");
    printf("               | |__  | | |_____| | |\\     | | | |_____| |_______| | |       \n");
    printf("               | |__| | | |_____  | |\\\\    | | | |          | |    | |       \n");
    printf("               | |____| | |_____| | | \\\\   | | | |          | |    | |       \n");
    printf("               | |      | |_____  | |  \\\\  | | | |_____   __| |__  | |______ \n");
    printf("               |_|      |_|_____| |_|   \\\\ |_| |_|_____| |_______| |________|\n");
    printf("\nAll right reserved to (c) GCC.\n");
    printf("\nPress Enter to start shell. \n\n");
}
int tok(char *line,char delim, char result[][20]){
    int len,t = 0;
    char *token;
    token = strtok(line,&delim);
    while(token){
        strcpy(result[t++],token);
        token = strtok(NULL,&delim);

    }

    return t ;
}
void strtshell(){
    char cmd[50]; char token[10][20];int argc;
    //printf("pencil>");
    while(1){
        FLUSH;
        *cmd = '\0' ;
        for(int i = 0 ; i < 10 ; i++)
             *token[i] = '\0' ;

        printf("Pencil>");
        
        fscanf(stdin,"%[^\n]s",cmd);
        printf("Showing result for query \"%s\"\n",cmd);
        argc = tok(cmd,' ',token);
        //printf("%s\n",cmd);
        
        if(!strcmp(token[0],"\0")){
            //printf("Pencil>");
            continue; 
        }
        else if(!strcasecmp(token[0],"exit") || !strcasecmp(token[0],"quit")){
            printf("\tGood Bye!\n");
            break;
        }
        else if(!strcmp(token[0],"set")){
            upData(atInit(atoi(token[1]),atoi(token[2]),atoi(token[3])),token[4],token[5]);
            continue;
        }

        
        else if(!strcmp(token[0],"get")){
            if(strlen(token[1]) == 1){
                int a[] = {atoi(token[1]),atoi(token[2]),atoi(token[3])} ;
                atmP temp = atInit(a[0],a[1],a[2]);
                if(argc == 4){
                
                    printTbl(temp);
                    printf("\n");
                    continue ;
                }
                else if(argc == 5){
                    printf("-----------------------------\n");
                    printf("|%13s|%13s|\n","Name",token[4]);
                    printf("-----------------------------\n");
                    propMap(temp,token[4]);
                    continue ;
                
                }
            }
            else if(strlen(token[1]) == 2){
                
                if(argc == 2){
                    
                    sersMapper(token[1],"all");
                    continue ;

                  
                }
                else if(argc == 3){
                    sersMapper(token[1],token[2]);
                    continue ;

                }
            }

        }


        else if(!strcmp(token[0],"plot")){
            
            grphMapper(token[1],token[2]);
            
            continue ;
            //printf("\tWrong Commands.\n\tEnter --help to know more about commands.\n");

        }
        else if(!strcmp(token[0],"sort")){
                int flag = 0 ;
                flag = IncSort(token[1],token[2]);
                if(flag)
                    continue ;

            
            
            
                printf("\tWrong Commands.\n\tEnter --help to know more about commands.\n");


        }
        else if(!strcmp(token[0],"--help")){
            printf("\t\tWelcome to Pencil Command Guides.\n");
            printf("\tPossible combinations of Commands in this version are\n");
            
            printf("\tCommand\t\t\t\tDescription\n\n");
            printf("\tget <p> <q> <r>                        Give all the property value of an element specified with row,column,f-block element or not. e,g : get 1 1 0.\n");
            printf("\t                                       p = period number, q = group number, r = 1 if element is in f-block else 0. \n");
            printf("\tget <p> <q> <r> <property name>        Same as above but shows only specific property value as given their. e,g: get 1 1 0 mp.\n");
            printf("\tget <series name>                      Shows all the property of all the elements of given series. e,g: get 3d.\n");
            printf("\tget <series name> <property name>      Shows given property value of all the element of given series. e,g: get 3d density.\n");
            printf("\tset <p> <q> <r> <property> <newValue>  Setting of new value of given property of given elements\n\n");
            printf("\tgraph <series> <property>              Making Graph of given series of given property\n\n");
            printf("\tsort <series> <property>               Sorting element of given series with respect to given property value\n");
            continue ;
        }
        printf("\tNot A Correct Command.\n\tEnter --help to know list of possible commands.\n");
        

        
        
    }
       
}