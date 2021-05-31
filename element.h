/*  changes in primitive operation
    1. comparing two number
    2. pionter reference
    3. calling function
    4. Assignment to a variable

    improve the o() from multiple opening and scanning for each i
    to single opening and no multiple scanning from start for each i.

    Asymptotic notation
    init() - o(18) 
    all other function remain same to previous version

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdbool.h>


//defining the user-defined datatype by using typedef .

typedef struct group grp ;           //datatype for struct group
typedef struct group* grpP ;          //datatype for struct group*
typedef struct period prd ;           //datatype for struct period
typedef struct period* prdP ;          //datatype for struct period*
typedef struct elm atm ;               //datatype for struct elm
typedef struct elm* atmP ;              //datatype for struct elm*

//structure declaration
/*prop structure is a container of all the imp feature and physical property of an elements
  it is used nested inside the elm structure
*/
struct prop                            
{
    char name[30] ;   //variable for name of the atom
    char sym[3];      //variable for sym of atm
    int atmN ;         //variable for atomic number of atom
    double atmW , atmR ,density , mp ,bp ,en , ip ;   //variable for all other property

};

/*elm structure contains an atoms row col and top(for f-block elements) and also contains an instance of struct prop
  it self-refer to itself by the atmP variable use for built the linked list
*/
struct elm{
    int row ,col ,top ;
    struct prop p ;
    atmP nedo ;

};
/*group structure contains all the information related for an group with an atmP variable which linked to the Head of the 
  linked list of that corresponding group linkedList .also contains anthor atmP variable that pointed to the last of the 
  corresponding linkedList
*/
struct group{
    int col ;
    int s_row ;
    int v_ectn ;
    atmP x ;
    atmP last ;
};

/*period structure contains all the information related for an peroid .
  int variable that represent its row number
  char variable that store the shell character e.g : K , L , M .........
*/
struct period{
    int row ;
    char s_lvl ;

};

//global variable
/*grpArr contaion every detail of correspondinig group simmillarly prdArr contains every details of ane periods in mordern periodic table
  e.g:
  the grp structure present at 2 index represent the group-2 of mordern periodic table
  the prd structure present at 2 index represent the period-2 of mordern periodic table
  Caution-Never use the index 0 of above array it contains only NULL and garbage value
*/
grp grpAr[19] ; prd prdAr[8] ;    //declaration of grpArr and prdArr that represent the array of respective datatype
//FILE *fp ;
FILE *bp ;


//----------------------------------------------------------------------------------------------------------------------------------------
//function defination

void addItem(atmP *last,atmP new) ;
void setData(int i,atmP *last) ;


atmP makeHead(int i) ;

void init() ;

void printTbl(atmP temp) ;

void printData() ;

atmP atInit(int row , int col , int top) ;


//arthmetic operation
atmP addCol(atmP x , int q) ;

atmP addTop(atmP x , int q ) ;
atmP mulRow(atmP x , int q) ;
atmP mulCol(atmP x , int q) ;
atmP mulTop(atmP x , int q) ;
atmP divRow(atmP x , int q) ;
atmP divCol(atmP x , int q) ;
atmP divTop(atmP x , int q) ;

//relational operation
bool isLessOrMore(atmP x ,atmP y) ;
bool isEqual(atmP x, atmP y) ;

void walkVert(atmP* walkman) ;

void walkHor(atmP* walkman) ;

//--------------------------------------------------------------------------------------------------------------------------------------

//function defination

/*addItem function add the atm to the passsed linkedlist that was set by the setData() function
  it add a new node to the last of the corressponding list
*/

void addItem(atmP *last,atmP new){
    atmP temp = (*last)->nedo ;    //saving the next pointer in temp of last node
    //atm w = setData(i) ;
    (*last)->nedo = new ;         //add the passed node to the next of the last node
    (*last)->nedo->nedo = temp ;   //then make temp the next node of the newly added node 
    temp = NULL ;                  //make temp = NULL
    free(temp) ;                   //free the resource
    *last = (*last)->nedo ;        //moving forward the last pointer of the corresponding group
}

/*setData function complete the linked list that is left by the makeHead function by reading all other remain line of the corresponding
  group from txt file and set them in in a newly created instance of atm.

  take a int parameter to represent the col and a atmP variable to represent the last of present linkedlist of group-i
   
  it run loop specific times for specific col that is decided by the if-else condition
  e.g:
  in group peroidic table there ony 6 elements in which first one is already there as head
  remaining 5 elements are intailsed by (memory allocated) and fit into the their respective position
  by the for loop that is running only 5 times

*/ 
void setData(int i,atmP *last){
    atm temp ;                    //a variable of atmP(datatype defined in header file)
   
    
    


    //if-case accord to i ;
    if(i == 1 || i == 18 ){      //for group 1 and 18
        for(int h = 2 ; h <= 7 ; h++){
          atmP a = (atmP)malloc(sizeof(atm)) ;   //allocate memory of size of atm datatype and return a pointer to it
          //taking input from file line by line word by word
          fread(a,sizeof(atm),1,bp);
          //fscanf(fp,"%d %d %d %s %s %d %lf %lf %lf %lf %lf %lf %lf",&a->row,&a->col,&a->top,a->p.name,a->p.sym,&a->p.atmN,&a->p.atmW,&a->p.atmR,&a->p.density,&a->p.mp,&a->p.bp,&a->p.en,&a->p.ip);
          addItem(last , a) ; 
        }
    }
    if(i == 2 || (i >= 13 && i <= 17)){   //for group 2 and 13-17
        for(int h = 3 ; h <= 7 ; h++){
          atmP a = (atmP)malloc(sizeof(atm)) ;    //allocate memory of size of atm datatype and return a pointer to it
          //taking input from file line by line word by word
          fread(a,sizeof(atm),1,bp);
          //fscanf(fp,"%d %d %d %s %s %d %lf %lf %lf %lf %lf %lf %lf",&a->row,&a->col,&a->top,a->p.name,a->p.sym,&a->p.atmN,&a->p.atmW,&a->p.atmR,&a->p.density,&a->p.mp,&a->p.bp,&a->p.en,&a->p.ip);
          addItem(last , a) ;

        }
    
    }
    if(i == 3){      //for group 3
        for(int h = 5 ; h <= 35 ; h++){
          atmP a = (atmP)malloc(sizeof(atm)) ;    //allocate memory of size of atm datatype and return a pointer to it
          //taking input from file line by line word by word
          fread(a,sizeof(atm),1,bp);
          //fscanf(fp,"%d %d %d %s %s %d %lf %lf %lf %lf %lf %lf %lf",&a->row,&a->col,&a->top,a->p.name,a->p.sym,&a->p.atmN,&a->p.atmW,&a->p.atmR,&a->p.density,&a->p.mp,&a->p.bp,&a->p.en,&a->p.ip);
          addItem(last , a) ;

        }
    }
    if(i >=4 && i <= 12){   //for group 4-12
        for(int h = 5 ; h <= 7 ; h++){
          atmP a = (atmP)malloc(sizeof(atm)) ;    //allocate memory of size of atm datatype and return a pointer to it
          //taking input from file line by line word by word
          fread(a,sizeof(atm),1,bp);
          //fscanf(fp,"%d %d %d %s %s %d %lf %lf %lf %lf %lf %lf %lf",&a->row,&a->col,&a->top,a->p.name,a->p.sym,&a->p.atmN,&a->p.atmW,&a->p.atmR,&a->p.density,&a->p.mp,&a->p.bp,&a->p.en,&a->p.ip);
          addItem(last , a) ;

        }
    }
 
    return  ;
}//setData

/*makeHead function when called first read the first line of corresponding cola(value pass as argument) from the txt file provided.
  then make an instance of atm and set all its property and other value from reading to txt file.
  As it create an instance of atm (datatype defined in header file) that is first of corresponding group hence it name as makehead.
  after making of an atm instance and detting all this property
  it return an pointer to this atm (atmP variable) to the called function
*/
atmP makeHead(int i){
    atmP x ;          //a variable of atmP(datatype defined in header file)
    x = (atmP)malloc(sizeof(atm)) ;  //allocate memory of size of atm datatype and return a pointer to it
    fread(x,sizeof(atm),1,bp);
    //fscanf(fp,"%d %d %d %s %s %d %lf %lf %lf %lf %lf %lf %lf",&x->row,&x->col,&x->top,x->p.name,x->p.sym,&x->p.atmN,&x->p.atmW,&x->p.atmR,&x->p.density,&x->p.mp,&x->p.bp,&x->p.en,&x->p.ip);
        
    
   
    //read record
    
    x->nedo = NULL ;    //make the next link node NULL for this time which is linked when we called setData function
           
    return x ;          //return pointer to the head
}//makeHead

/* contains function defination of many utility function
   does not contain main
   Caution - do not run this file as this file does not contain main function
*/

/*init() function as it name suggest it intialise the whole data structure by reading the data from ElemProp.txt file
  and then save all the data inside the data structure in specific manner.
  Caution - You will be not able to use all the utility function without calling this init() function first
  so first call the init() function then use all the defined utility function.
*/
/*Processes
  intialise the grpArr
  Step-1:
        It run an for loop with counter variable starting from 1 to 18.Inside the loop it it set the col value of the grp(datatype define in header file)
        structure present in grpArr(array of size 19 of grp type) at index of value equal to i .
        then it set the s_row(refer to the header file for more info about s_row) value for each grp variable with the help of if-else-if .
        e.g
        for i = 2
        it first refer to the element present in grpArr at index i
        and then set the col value of the grp structure that is pointed.
        and simillarly it also set the value s_row accord to the value of i.
    Step-2:
        With help of makeHead(i) function It make an instance of atm structure and set all the data into it by traversing the txt file provided.
        and make it the head of corresponding group(of value equal to i) by setting the value of x pointer variable present inside grp structure
        to the pointer return by the makeHead(value of i).
    Step-3:
        After making the head it create the instance of atm structure for all the remaining elements present in group of MPD of value equal 
        to i with the help of setData() function.setdata() function built the whole linked list for a group of number represent by value of
        i
    intialise the prdArr
    Step-4:
         It start to intialise the row of the MPD.
         It run a for loop with counter variable starting from 1 to 7 and set the value of row of specified prd structure(datatype define in header file)
         at the index value equal to i in prdArr

    */     
void init(){
    //intialise group(grpArr)
    //fp = fopen("PropListUpdated.txt","r");  //open the txt file
    bp = fopen("BinaryList.bin","rb");
    //for loop
    for(int i = 1  ; i <= 18 ;  i++){
        grpP temp = &grpAr[i] ;   //temp that pointed to the grp at i index of grpArr
        temp->col = i ;           //set the col value to i.
        
        //if else-if condition checking to set s_row according to i
        if(i == 1 || i == 18) 
            temp->s_row = 1 ;   
        else if(i == 2 || i == 13 || i == 14 || i == 15 || i == 16 || i ==17)
            temp->s_row = 2 ;
        else 
            temp->s_row = 4 ;
        
        
        //if else-if condition checking to set v_ectn according to i
        /*as we know in a given group of MPT(Morden Periodic Table) the valence electron of its element are constant
          so setting the valence electron of all the elements of specified group 
        */
        if( i == 1 || i == 2)
              temp->v_ectn = i ;
        else if( i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 ||  i == 10 || i == 11 || i == 12)
              temp->v_ectn = 2 ;
        else 
              temp->v_ectn = (i - 10) ;
        
        //set the x value of present grp to the value of head return from makeHead() function
        atmP head  = makeHead(i) ;      //declare in header file and define in list.c file 
        temp->last = head ;             /*set the value of poiter last to the head of linked list as of now there is now other 
                                          node present in linkedlist  */
        temp->x = head ;

        //function called to set all other node of the linkedList of present group(equal to i) by reading the data in txt file provided.    
        setData(i,&(temp->last)) ;  //declare in header file and define in list.c file    
        
        
         
         
            
         
         
    }//for
   
    
    // intialise period
    char cj = 'J' ;
    int j = cj ; // set the int value of char of J to which is use to set the shell number in prdArr

    //for loop
    for(int i = 1 ; i <= 7 ; i++){
        prdP temp = &prdAr[i] ;   //refer to the prd (datatype define in header file) structure at index i of prdArr
        temp->row = i ;           //set the value of the row of each prd structure at index i of prdArr array to i .
        temp->s_lvl = j + i ;     //set the shell number character to each row e.g : K , L , M ....
                                  //by adding the value of i to the j which is equal to J intially.
        
    }//for


}//init

/*
  atInit function used to intialise an element from the row , col ,and top that are passed as
  arguments. it return a atmP pointer according to the value pass in parameter.
  if there no such element present their in morden periodic table it return NULL value
*/

atmP atInit(int row , int col , int top){
    /*search algorithim
      search the data structure accord to the value 
      given in parameter
    */
    
    atmP head = grpAr[col].x ;    //going to the grp variable present inside the grpArr by col value
    int ref = grpAr[col].s_row ;  //ref is used to tell the program the starting row of the given coloumn
    int i = 1 ;   //intialise the i to 1 used as counter variable in while loop .
    atmP res = head ;
    int limit ;  /*the variable limit used to tell the while loop how much time 
                   it run to get pointer to desire elements.
                   as every elements are implements by linked list
                 */
    //if-else condition to determine the value of the limit
    if(top != 0 || (row == 7 && col == 3) )  //if condition for f-block elements as for them limit calculation is different
      limit = 2 +( 15 * (row - 6) + top ) ;
    else 
      limit = row - ref ;       //for all other block elements

    //while loop that traverse the whole linked-list data structure  starting from head of that given col/group
    while(i <= limit ){
        res = res->nedo ;  //moving forward the res pointer to the next element that is pointed by the nedo variable of present atm that 
                           //that pointed by res.
        i++ ;   //increase the value of i

    }

    return res ; //return the atmP pointer to the desire elements as pass in function . 

}//atInit

/*printTbl function print the the whole property of the element that pointed by 
  the atm pointer that pass as argument in tabular form  */
void printTbl(atmP temp){
            char na[3] = "NA" ;  //string variable for printing NA . NA represent Data Not Available.

            //start of printing the data of element that pointed by the pointer passed as parameter.

            /*as temp is pointer to a structure so every data inside it can be access with -> operator
              also temp is pointer to the structure elm,elm is a nested structure inside it contains 
              anathor structure of type prop that contains all other physical property of a elements
              so we can access all prop by
              e.g:
              temp->p.density  - access the density of the elements that pointed by the atmP pointer 
              passed as arguments

            */
            printf("--------------------------------\n");
            printf("|Name           | %13s|\n",temp->p.name);
            printf("|Symbol         | %13s|\n",temp->p.sym);
            printf("|Atomic Number  | %13d|\n",temp->p.atmN);
            if(temp->p.atmW != -12345) // we use value -12345 in our program to represent the value NA
            printf("|Atomic Weight  | %13.3lf|\n",temp->p.atmW);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.atmR != -12345)  //checking condition for NA values if true then print NA in table
            printf("|Atomic Radius  | %13.3lf|\n",temp->p.atmR);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.density != -12345)
            printf("|Density        | %13.3lf|\n",temp->p.density);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.mp != -12345)
            printf("|Melting Point  | %13.3lf|\n",temp->p.mp);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.bp != -12345)
            printf("|Boiling Point  | %13.3lf|\n",temp->p.bp);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.en != -12345)
            printf("|En             | %13.3lf|\n",temp->p.en);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.ip != -12345)
            printf("|First IP       | %13.3lf|\n",temp->p.ip);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            printf("--------------------------------\n");
            printf("\n");
}//printTbl

  /*
  printData function print the the whole property of the all element are present in
  morden periodic table in tabular form
  
  */

  void printData(){
  
    char na[3] = "NA" ;   //string variable for printing NA . NA represent Data Not Available.

    /*As we describe our data structure that is used to represent all the elements in MPD  (Morden Periodic Table)
      it is a combination of array data structure and linked list
      there is an array of type grp(datatype define in header file) that represent all the group no. uniquely named as grpArr
      of size 19.
      Each grp structure inside the grpArr has a pointer of type atm(datatype define in header file) inside it and pointed to the head of
      linked list that contains all the element order wise of the group number as col value that also a int variable
      inside the grp.
    */
    /*To print all the data of all elements present in MPD  (Morden Periodic Table) we use for loop.starting from the first 
      grp variable present in grpArr that represent the group-1 we loop untill group-18
      on each grp structure we once again loop starting from head of list (pointed by the x variable ) to untill we get a NULL value that represent the end of the 
      group.
    */ 

    //for loop to loop inside the grpArr / loop all the grp inside the grpArr
    for(int i = 1 ; i <= 18 ;i ++){
        atmP temp = grpAr[i].x ;
         
        //while loop to traverse the groups elements that all are implement by linked list
        while(temp != NULL){
            
            //start of printing the data of element that pointed by the pointer passed as parameter.

            /*p is a variable of struct prop type that is nested in elm structure ( see the header file for more information).
              p contains all the physical property value of specified element .
            */
            printf("--------------------------------\n");
            printf("|Name           | %13s|\n",temp->p.name);
            printf("|Symbol         | %13s|\n",temp->p.sym);
            printf("|Atomic Number  | %13d|\n",temp->p.atmN);
            if(temp->p.atmW != -12345)  //checking condition for NA values if true then print NA in table
            printf("|Atomic Weight  | %13.3lf|\n",temp->p.atmW);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.atmR != -12345)
            printf("|Atomic Radius  | %13.3lf|\n",temp->p.atmR);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.density != -12345)
            printf("|Density        | %13.3lf|\n",temp->p.density);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.mp != -12345)
            printf("|Melting Point  | %13.3lf|\n",temp->p.mp);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.bp != -12345)
            printf("|Boiling Point  | %13.3lf|\n",temp->p.bp);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.en != -12345)
            printf("|En             | %13.3lf|\n",temp->p.en);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            if(temp->p.ip != -12345)
            printf("|First IP       | %13.3lf|\n",temp->p.ip);
            else
            printf("|Atomic Weight  | %13s|\n",na);
            printf("--------------------------------\n");
            printf("\n");

            temp = temp->nedo ;
        }//while


    }//for/
}//printData

/*Arthimetic Operation

*/

/*addCol function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by adding 
  q to the col of the atm that is pointed by the atmP pass on argument
*/
atmP addCol(atmP x , int q){
    if(x->col == 18 && x->row == 7)  //checking of the boundary condition and return NULL
        return NULL ;
    
    if(x->col == 18)             //checking the boundary condition for group-18 elements
      return atInit(x->row+1 , 1 , x->top);
    return atInit(x->row , x->col + q , x->top);  //for any other remain elements
}//addCol

/*addRow function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by adding 
  q to the row of the atm that is pointed by the atmP pass on argument
*/
atmP addRow(atmP x , int q ){
    if(x->col == 18 && x->row == 7)   //checking of the boundary condition and return NULL
        return NULL ;
    
    if(x->row == 7){            //checking the boundary condition for last elements in a group and return a the first elements of next col
        int f_col = x->col+1 ;
        int s_row = grpAr[f_col].s_row ;
      return atInit(s_row , f_col , 0);

    }
    
    return atInit(x->row + q , x->col , x->top) ;   //for any other remain elements
}//addRow

/*specially for f-block elements
  addTop function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by adding 
  q to the top of the atm that is pointed by the atmP pass on argument

  we use top to represent the f-block elements position
*/

atmP addTop(atmP x , int q ){
    if(x->top == 14 && x->row == 7)    //checking of the boundary condition
      return atInit(4,x->col+1,0);
    if(x->top == 14)                   //checking of the boundary condition
      return atInit(x->row+1 , x->col , 0 );
    return atInit(x->row , x->col , x->top+q) ;  //for any other remain elements
}

/*mulRow function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by multiply 
  q to the row of the atm that is pointed by the atmP pass on argument
*/
atmP mulRow(atmP x , int q){
    return atInit(x->row * q , x->col , x->top);
}

/*mulCol function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by multiply
  q to the col of the atm that is pointed by the atmP pass on argument
*/
atmP mulCol(atmP x , int q){
    return atInit(x->row, x->col * q , x->top);
}//mulCol

/*mulTop function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by multiply 
  q to the top of the atm that is pointed by the atmP pass on argument
*/
atmP mulTop(atmP x , int q){
    return atInit(x->row , x->col , x->top * q);
}//mulTop

/*divRow function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by dividing 
  q to the row of the atm that is pointed by the atmP pass on argument
*/
atmP divRow(atmP x , int q){
    return atInit(x->row/q , x->col , x->top) ;
}//divRow

/*divCol function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by dividing 
  q to the col of the atm that is pointed by the atmP pass on argument
*/
atmP divCol(atmP x , int q){
    return atInit(x->row , x->col/q , x->top) ;

}//divCol

/*divTop function takes a atmP and int  variable as parameter
  and return a atmP that point to the atm that is occur by dividing 
  q to the top of the atm that is pointed by the atmP pass on argument
*/
atmP divTop(atmP x , int q){
    return atInit(x->row,x->col,x->top/q);
}//divTop

//relational operation

/*
  isLessOrMore function takes two atmP variable and return false if first parameter is less than the second one
  and return true for reverse case

  one atm is less than anathor is defined something different
  let atmP x , y ;
  if col of x is less than col of y
  then x is less than y
  in same column case the one with less row number is the smaller one

*/

bool isLessOrMore(atmP x ,atmP y){
    if(x == NULL || y == NULL){     //condition checking for the NULL value and terminating the program if true evaluate
        printf("NULL cahracter can not comparable\n");
        exit(0);
    }
    if(x->col < y->col)            //return 0 if col of x is less than of y
       return 0 ;
    else if(x->col > y->col)      //return 1 if col of x is more than of y
       return 1 ;
    else                          //else for same column condition
       if(x->row < y->row)       
          return 0 ;
       else if(x->row > y->row)
          return 1 ;
        
}

/*
  isEqual function for checking the equality of two passed atmP variable
  return true if same or false for different
*/
bool isEqual(atmP x, atmP y){
    return (x == y) ;
}


/*walkVert use to forward the pointer that is pointed to an atm(datatype define in header file) vertical wise.
  takes adress of an atmP(datatype define in header file) as parameter and changes its value to next atm
  that present vertically next to it
  Note : 
  At end of a group if you call walkVert() then it takes you to the first elements of the next grp and so on.
*/ 
void walkVert(atmP* walkman){
    
    //while( *walkman != NULL ){
        int row = (*walkman)->row ;    //row contains the value of row of atm(elm structure) that is now pointed by *walkman. 
        int col  = (*walkman)->col ;   //col contains the value of col of atm that is now pointed by *walkman.
        
        //if condition for the f-block elements 
        if( (((*walkman)->row == 6 || (*walkman)->row == 7 ) && (*walkman)->col == 3 )){
            *walkman = addTop(*walkman , 1);   //perform addTop to f-block elements
            return ;

        }
        *walkman = addRow(*walkman , 1);  //perform addRow to the other block elements
        
    //}
 
}//walkvert

void walkHor(atmP* walkman){
    int col = (*walkman)->col ;    //row contains the value of row of atm(elm structure) that is now pointed by *walkman.
    int row = (*walkman)->row ;    //col contains the value of col of atm that is now pointed by *walkman.
    int top = (*walkman)->top ;    //top contains the value of top of atm that is now pointed by *walkman.

    // if else-if condition to check the all boundary condition
    if(top == 14 && (row == 6 || row == 7))
       *walkman = atInit(row, col+1 , 0);  /*ntialise the atm structure according to row , col , top and set the value of *walkman by return a
                                             pointer to it   */
    else if(top)
       *walkman = atInit(row,col,top+1);   /* row , col , top are decided by the value of present value of row,col,top with keeping the boundary
                                              condition in mind.
                                           */
    else if(col == 18 && row == 7)
       *walkman = NULL ;
    else if(col == 18)
       *walkman = atInit(row+1 , 1 ,top);
    else
       *walkman = atInit(row ,col+1,top);
}//walkHor

