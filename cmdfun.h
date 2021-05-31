//#include "element.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void propMap(atmP elm,char *prop){
    if(!strcmp(prop,"density")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.density);
        printf("-----------------------------\n");

    }
    else if(!strcmp(prop,"mp")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.mp);
        printf("-----------------------------\n");

    }
    else if(!strcmp(prop,"bp")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.bp);
        printf("-----------------------------\n");

    }
    else if(!strcmp(prop,"en")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.en);
        printf("-----------------------------\n");

    }
    else if(!strcmp(prop,"ip")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.ip);
        printf("-----------------------------\n");
        
    }
    else if(!strcmp(prop,"atmN")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13d|\n",elm->p.name,elm->p.atmN);
        printf("-----------------------------\n");
        
    }
    else if(!strcmp(prop,"atmR")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.atmR);
        printf("-----------------------------\n");
        
    }
    else if(!strcmp(prop,"name")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13s|\n",elm->p.name,elm->p.name);
        printf("-----------------------------\n");
        
    }
    else if(!strcmp(prop,"sym")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13s|\n",elm->p.name,elm->p.sym);
        printf("-----------------------------\n");
        
    }
    else if(!strcmp(prop,"atmW")){
        if(elm->p.density == -12345){
             printf("|%13s|%13s|\n",elm->p.name,"NA");
             printf("-----------------------------\n");
             return ;
        }
        printf("|%13s|%13.3lf|\n",elm->p.name,elm->p.atmW);
        printf("-----------------------------\n");
        
    }
    else if(!strcmp(prop,"all")){
        printf("|%10s|%13s|%13d|%13.3lf|%13.3lf|%13.3lf|%10.3lf|%10.lf|%10.3lf|%10.3lf|\n",elm->p.name,elm->p.sym,elm->p.atmN,elm->p.atmW,elm->p.atmR,elm->p.density,elm->p.ip,elm->p.en,elm->p.mp,elm->p.bp);
        printf("------------------------------------------------------------------------------------------------------------------------------\n");

    
    }
    else{
        printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);

    }
}

void sersMapper(char *series,char *prop){
    if(!strcmp(series,"3d")){
        atmP sc = atInit(4,3,0);
        atmP zn = atInit(4,12,0);
        if(!strcmp(prop,"all")){
            printf("------------------------------------------------------------------------------------------------------------------------------\n");
            printf("|%10s|%13s|%13s|%13s|%13s|%13s|%10s|%10s|%10s|%10s|\n","Name","Symbol","Atomic Number","Atomic Weight","Atomic Radius","Density","IP","EN","MP","BP");
            printf("------------------------------------------------------------------------------------------------------------------------------\n");
            //for loop starting from sc to zn and print the mp and bp
            for(atmP temp = sc ; temp != zn ; walkHor(&temp)){
                propMap(temp,"all");
            }
        }
        else{
            printf("-----------------------------\n");
            printf("|%13s|%13s|\n","Name",prop);
            printf("-----------------------------\n");
            for(atmP temp = sc ; temp != zn ; walkHor(&temp)){
                propMap(temp,prop);
            }

        }
        

    }
}
void upData(atmP a,char *prp, char *value){
    if(!strcmp(prp,"name"))
        strcpy(a->p.name,value);
    else if(!strcmp(prp,"sym"))
        strcpy(a->p.sym,value);
    else if(!strcmp(prp,"atmN"))
        a->p.atmN = atoi(value);
    else if(!strcmp(prp,"atmW"))
        a->p.atmW = atof(value);
    else if(!strcmp(prp,"bp"))
        a->p.bp = atof(value);
    else if(!strcmp(prp,"mp"))
        a->p.mp = atof(value);
    else if(!strcmp(prp,"en"))
        a->p.en = atof(value);
    else if(!strcmp(prp,"ip"))
        a->p.ip = atof(value);
    else if(!strcmp(prp,"density"))
        a->p.density = atof(value);
    else if(!strcmp(prp,"atmR"))
        a->p.atmR = atof(value);
    else{
        printf("\tWrong property name\n");
        return;
    }
    printf("\tValue Updated succesfully\n");
     
        
    
}
/*======================================
  Mathmatics tool
  ======================================
*/
void insertionSort(int *arr,int n){
    int temp ;
    for(int i = 1 ; i < n ; i++){
        temp = arr[i];
        int j ;
        for(j = i-1 ; j >= 0 && arr[j] > temp ; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp ;


    }
}
int mde(int *arr,int n){
    int *frq_arr  = (int *)malloc(sizeof(int)*n);
    for(int i = 0 ; i < n ; i++){
        int frq_count = 1 ;
        for(int j = i+1 ; j < n ; j++)
          if(arr[j] == arr[i])
            frq_count++;
        frq_arr[i] = frq_count ;
    }
    int max = 0 ;
    for(int i = 0 ; i < n ; i++)
        if(frq_arr[i] > frq_arr[max])
            max = i ;
    return max ;
}
void statics(int *arr,int n,double *mean,double *mode,double *median){
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++)
        sum += arr[i] ;
    *mean = ((double)sum/n) ;
    insertionSort(arr,n);
    *median = arr[n/2];
    int index = mde(arr,n);
    *mode = arr[index] ;

    

    

}
/*======================================
  Mathmatics tool end
  ======================================
*/

//=======================================
//graphing tool
//=======================================



void setMap(int *arr,int n,char map[50][50]){
    //printf("\nCount inside the setMap %d",n);
    //printf("\nArray Content inside setMap.\n");
    
    //small CLI work here :)
    

    printf("\n");
    printf("--------------------------Graph (C)GCC---------------------------\n");
    printf("Plotted Datas :\t\t");
    for(int i = 0 ; i < n ; i++)
        printf("%d ",arr[i]) ;
    printf("\n");
    printf("Data are approximated to near integer from real data.\n");

    //set all corrdinate of matrix to ' '    
    for(int i = 0 ; i < 50 ; i++)
        for(int j = 0 ; j < 50 ; j++)
            map[i][j] = ' ' ;

    //for(int i = 0 ; i < 50 ; i++)
      // mapper[i][0] = '' ;

    //drawing x-axis
    for(int i = 0 ; i < 50 ; i++)
       if(i == 25)
            map[49][i] = 'x' ;
       else
            map[49][i] = '-' ;

    
    int x_div_50 ;
    if(n < 50)
        x_div_50 = 50/n;
    else
        x_div_50 = n / 50 ;
    //printf("\nx_div_50 %d\n",x_div_50) ;
    
    int max = arr[0];
    for(int i = 0 ; i < n ; i++)
      if(arr[i] > max)
         max = arr[i] ;
    
    int floor_50 = max / 50 ;
    //printf("floor_50 %d\n",floor_50);
    int ceil_50 = floor_50+1 ; 
    int div_block = ceil_50 ;
    
    
    
    int rnd_flag,temp ;
    for(int i = 0 ; i < n ; i++){
        temp = arr[i] ;
        int mod_ceil_50 = temp % ceil_50 ;
        if(mod_ceil_50 >= (ceil_50/2))
            rnd_flag = 1 ;
        else
            rnd_flag = 0 ;
        int div_ceil_50 = temp / ceil_50 ;
        if(rnd_flag)
            div_ceil_50++ ;
        //printf("%d %d\n",49-div_ceil_50,i*x_div_50);
        map[49-div_ceil_50][i*x_div_50] = 'O' ;
        for(int k = 49-div_ceil_50+1; k < 49 ; k++)
            map[k][i*x_div_50] = '*';
        
        
    }
        //small CLI work here :)
        //local variable
        double mean,mode,median ;
        statics(arr,n,&mean,&mode,&median);
        //small CLI work here :)
        printf("maximum       :\t\t%d\n", max) ;
        printf("mean          :\t\t%lf\n", mean) ;
        printf("median        :\t\t%lf\n", median) ;
        printf("mode          :\t\t%lf\n", mode) ;
        printf("\nUnit per Division\n");
        printf("Y axis        :\t\t%d\n", div_block) ;
        printf("X axis        :\t\t%d\n",x_div_50) ;


}//setMapper
void printMap(char map[50][50]){
    //printf("\n");
    //printf("--------------------------Graph (C)GCC---------------------------\n");
    //printf("\n");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0 ; i < 50 ; i++){
        for(int j = 0 ; j < 50 ; j++)
            printf("%c",map[i][j]) ;

        printf("\n");
    }
    printf("\n");
}

void grphMapper(char *srs, char *prop){
    char map[50][50] ;
    if(!strcmp(srs,"3d")){
        int count = 0 ;
        atmP sc = atInit(4,3,0);
        atmP zn = atInit(4,12,0);
        for(atmP temp = sc ; temp != zn ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;
        //int rnd_flg = 0 ;

        //printf("Array contents\n");
        for(atmP temp = sc; temp != zn ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                  
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);
        
    }
    else if(!strcmp(srs,"4d")){
        int count = 0 ;
        atmP yt = atInit(5,3,0);
        atmP cd = atInit(5,12,0);
        for(atmP temp = yt ; temp != cd ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = yt; temp != cd ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                arr[i++] = temp->p.atmN ;
                
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"5d")){
        int count = 0 ;
        atmP la = atInit(6,3,0);
        atmP hg = atInit(6,12,0);
        for(atmP temp = la ; temp != hg ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = la; temp != hg ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
               arr[i++] = temp->p.atmN ;
               
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"6d")){
        int count = 0 ;
        atmP ac = atInit(7,3,0);
        atmP cp = atInit(7,12,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                  
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"2p")){
        int count = 0 ;
        atmP ac = atInit(2,13,0);
        atmP cp = atInit(2,18,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"3p")){
        int count = 0 ;
        atmP ac = atInit(3,13,0);
        atmP cp = atInit(3,18,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                  
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"4p")){
        int count = 0 ;
        atmP ac = atInit(4,13,0);
        atmP cp = atInit(4,18,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                  
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"5p")){
        int count = 0 ;
        atmP ac = atInit(5,13,0);
        atmP cp = atInit(5,18,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
            
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"6p")){
        int count = 0 ;
        atmP ac = atInit(6,13,0);
        atmP cp = atInit(6,18,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                  
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"7p")){
        int count = 0 ;
        atmP ac = atInit(7,13,0);
        atmP cp = atInit(7,18,0);
        for(atmP temp = ac ; temp != cp ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = ac; temp != cp ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                
                  arr[i++] = temp->p.atmN ;
                  
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"6f")){
        int count = 0 ;
        atmP yt = atInit(6,3,1);
        atmP cd = atInit(6,3,14);
        for(atmP temp = yt ; temp != cd ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = yt; temp != cd ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                arr[i++] = temp->p.atmN ;
                
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else if(!strcmp(srs,"7f")){
        int count = 0 ;
        atmP yt = atInit(7,3,1);
        atmP cd = atInit(7,3,14);
        for(atmP temp = yt ; temp != cd ; walkHor(&temp)){
                count++ ;
        }
        int *arr = (int *)malloc(sizeof(int)*count);
        int i = 0 ;

        //printf("Array contents\n");
        for(atmP temp = yt; temp != cd ; walkHor(&temp)){
            if(!strcmp(prop,"density")){
                double _f = temp->p.density ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"mp")){
                double _f = temp->p.mp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }
            else if(!strcmp(prop,"bp")){
                double _f = temp->p.bp ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;

            }   
            else if(!strcmp(prop,"en")){
                double _f = temp->p.en ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
            }
            else if(!strcmp(prop,"ip")){
                double _f = temp->p.ip ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ; ;
        
            }
            else if(!strcmp(prop,"atmN")){
                arr[i++] = temp->p.atmN ;
                
        
            }
            else if(!strcmp(prop,"atmR")){
                double _f = temp->p.atmR ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
                //printf("%d ",arr[i++]);
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                double _f = temp->p.atmW ;
                if(_f == -12345){
                    arr[i++] = 0 ;
                    continue ;
                }
                int int_f = _f ;
                double dec_f = _f - int_f ;
                if(dec_f >= 0.500)
                  arr[i++] = int_f + 1 ;
                else
                  arr[i++] = int_f ;
        
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                return ;
            }
            
            


                
        }
        
        setMap(arr,count,map);
        printMap(map);

    }
    else
        printf("\t%s neither a series or group.\n\tenter --help to know about commands.\n",srs);
    
    
    
    
}

/*
======================================
graphing tools end
======================================
*/
void series_Mapper(atmP *start,atmP *last,char *srs){
    if(!strcmp(srs,"3d")){
        *start = atInit(4,3,0);
        *last = atInit(4,12,0);
    }
    else if(!strcmp(srs,"4d")){
        *start = atInit(5,3,0);
        *last = atInit(5,12,0);

    }
    else if(!strcmp(srs,"5d")){
        *start = atInit(6,3,0);
        *last = atInit(6,12,0);

    }
    else if(!strcmp(srs,"6d")){
        *start = atInit(7,3,0);
        *last = atInit(7,12,0);

    }
    else if(!strcmp(srs,"6f")){
        *start = atInit(6,3,1);
        *last = atInit(6,3,14);

    }
    else if(!strcmp(srs,"7f")){
        *start = atInit(5,3,1);
        *last = atInit(5,3,14);

    }
    else if(!strcmp(srs,"2p")){
        *start = atInit(2,13,0);
        *last = atInit(2,18,0);

    }
    else if(!strcmp(srs,"3p")){
        *start = atInit(3,13,0);
        *last = atInit(3,18,0);

    }
    else if(!strcmp(srs,"4p")){
        *start = atInit(4,13,0);
        *last = atInit(4,18,0);

    }
    else if(!strcmp(srs,"5p")){
        *start = atInit(5,13,0);
        *last = atInit(5,18,0);

    }
    else if(!strcmp(srs,"6p")){
        *start = atInit(6,13,0);
        *last = atInit(6,18,0);

    }
    else if(!strcmp(srs,"7p")){
        *start = atInit(7,13,0);
        *last = atInit(7,18,0);

    }
    else 
        return ;
}
double prop_Mapper(atmP temp,char * prop){
            if (!strcmp(prop,"density")){
                return temp->p.density ;

            }
            
            
            else if(!strcmp(prop,"mp")){
                return temp->p.mp ;

            }
            else if(!strcmp(prop,"bp")){
                return temp->p.bp ;

            }   
            else if(!strcmp(prop,"en")){
                return temp->p.en ;
            }
            else if(!strcmp(prop,"ip")){
                return temp->p.ip ;
        
            }
            else if(!strcmp(prop,"atmN")){
                return temp->p.atmN ;
                
        
            }
            else if(!strcmp(prop,"atmR")){
               return temp->p.atmR ;
        
            }
            else if(!strcmp(prop,"name")){
    
                printf("Graph Could Not Possible\n");
                //return ;
            }
            else if(!strcmp(prop,"sym")){
                printf("Graph Could Not Possible\n");
                //return ;
        
            }
            else if(!strcmp(prop,"atmW")){
                return temp->p.atmW ;
            }
    
            else{
                printf("%s is not a recognisable property command\nEnter a correct peoperty\nType help for reference\n",prop);
                //return ;
            }
    

}
void sort(atmP *arr, int count, char *prop){
    atmP temp ;
    double temp_prop ;
    for(int i = 1 ; i < count ; i++){
        temp_prop = prop_Mapper(arr[i],prop);
        temp = arr[i] ;
        int j ;
        for(j = i-1 ; j >= 0 && prop_Mapper(arr[j],prop) > temp_prop ; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp ;


    }
    

}
void print_sorted(atmP *arr,int count,char *prop){
  printf("\n-----------------------------\n");
    printf("|%13s|%13s|\n","Name",prop);
    printf("-----------------------------\n");
    for(int i = 0 ; i < count ; i++){
        propMap(arr[i],prop);
    }

}

int IncSort(char *srs,char *prop){
    atmP strt , lst ;
    series_Mapper(&strt,&lst,srs) ;
    int count = 0 ;
    for(atmP temp = strt ; temp != lst ; walkHor(&temp)){
        count++ ;

    }
    atmP *arr = (atmP *)malloc(sizeof(atmP)*count);
    int i = 0 ;
    for(atmP temp = strt ; temp != lst ; walkHor(&temp)){
        arr[i++] = temp ;

    }
    sort(arr,count,prop);
    print_sorted(arr,count,prop);

    return 1 ;
    
}