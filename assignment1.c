#include <stdio.h>
#include <math.h>

//****************************************************  case 1  **************************************************************************
void int_Exponention(int x, int y)
{
 /*
 Algorithm : 
1> Divide y successively by 2, also keep on generating powers of 2 in the order x^l, x^2, x^4,, X^8, x^16.
2> If y % 2 =  1 then  consider the current power of X in the partial answer which is productt term  Else Ignore */
    int product, term;
    product = 1;
    term = x;
    while (y> 0)
    {   
        if (y % 2 == 1) //condition where we consider current power of x if remainder is 1
        {
            product = product* term;
        }
        term*=term;
        y=y/2;
        
    }
    printf(" \n %d \n", product);
}


//***************************************************  case 2  ***********************************************************************


double calculate_ylogx(int x, float y)
{
/* expantion formula :
      y*log x =y * 2* {(x-1\x+1) + ((x-1\x+1)^3)/3  + ((x-1\x+1)^5)/5..... }
      
 */ 
    
    int i = 1;
    double term, log, temp;
    log = (double) (x-1)/(x+1);

    // using term and temp for creating next term like  ex. ((x-1\x+1)^3)/3 by multiplying
    // term by temp * ((2*i)-1) i.e 1 /((2*i)+1) i.e 3 bye using previous term 
    
    term = (double)(x-1)/(x+1);
    temp = (double)(x-1)/(x+1);
    temp =temp*temp;
    while(i<100)
    {   
        term = term*temp*((2*i)-1)/((2*i)+1);
        log = log + term;
        i++;
    }
    log =log*2*y;
    return log;
}

void eraisedtok(double k)
{
/*
let k= y*logx ,now for calculating e raised 
to power k we apply tailor series again 

expantion : e^x = 1 + x + x^2/2! + x^3/3! + .....

*/
    int i;
    double term, exp;
    i = 1;
    term = 1, exp = 1;
    while (i<100)
    {   
        term = (term * k)/i;
        exp = exp + term;
        i++;
    }
    printf(" %lf ", exp);
}

int main()
{
    int x;
    float y;
    scanf("%d %f", &x, &y);
    int check =(int)y;
    if(x==0 && y<0 ){
        printf("zero raised to negative number is not defined ");
    }
    else if(check==y){
        // case 1
        int_Exponention(x, (int)y);
    }
    else{
        // case 2
 /* we can't calculate x raised to real power using above int_Exponention function
 so here we calculate it bye following method : 
       1> applying log and converting x ^ y  into e ^ y * log x
       2> now using tailor series expantion for calculating log x
       3> and after getting the value of the  k=y*log x we will calculate e ^ k and find the
          required value 
   */
       double k = calculate_ylogx(x, y);
       eraisedtok(k);  
    }
    return 0;
}