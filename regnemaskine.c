#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//prototypes of functions
double run_calculator ();
void scan_data (char *operator, double *operand);
void do_next_op (double *accumulator, char operator, double operand);


//main program
int main (void) {
    
    //the variable final_result is defined as the return-value of the function run_calculator since the function has the return value of the type double
    double final_result = run_calculator();

    //final_result is printed to the user, when user exits program by typing the unary operation "q"
    printf("\nFinal result is: %lf", final_result);

return 0;
}



//ALL FUNCTION DEFINITIONS - in order of when they are called in main and inside run_calculator

//run_calculator definiton
double run_calculator () {

    double accumulator = 0.0, operand;
    char operator;
    
    //infinite for-loop that only breaks when user types in 'q' as the operator
    for (; ;) {

        //prompting user for an operator and an operand
        scan_data (&operator, &operand);
        
        //making sure loop breaks if user types in 'q' as the operator
        if (operator == 'q')
        {
            break;
        }
    
        //making the requested calculation and overwrites value of accumulator with result of said calculation
        do_next_op (&accumulator, operator, operand);

        
        //"result so far" is printed to the user
        printf("\nThe result so far is: %lf\n\n", accumulator);
    }
    
    //value of "result so far" is returned to main
    return accumulator;
}

//scan_data definition
void scan_data (char *operator, double *operand) {

   char new_operator;
   double new_operand;

   printf("Enter an optional operator and enter an optional operand: ");
   scanf(" %c", &new_operator);
   
   //setting new_operand to 0 if user types in unary operator and not allowing further entry
   if (new_operator == '#' || new_operator == '!' || new_operator == '%' || new_operator == 'q') {
    
    new_operand = 0;

    } else {

        scanf("%lf",&new_operand);

        }

   //a recap of what the operator and operand for the calculation was
   printf("\n(%c %lf)\n", new_operator, new_operand);
   
   //the current values of the operator and operand is overwritten with the new ones
   *operand  = new_operand;
   *operator = new_operator;
   
}

//do_next_op definition 
void do_next_op (double *accumulator, char operator, double operand) {

    double new_accumulator;
    
    //switch for every single operation
    switch (operator) {

        //binary cases

        case'+':
         new_accumulator = *accumulator + operand;
         *accumulator = new_accumulator;
        break;

        case'-':
        new_accumulator = *accumulator - operand;
        *accumulator = new_accumulator;
        break;

        case'*':
        new_accumulator = *accumulator * operand;
        *accumulator = new_accumulator;
        break;

        case'/':

        if (operand != 0) //making sure we don't divide by zero 
        {
            new_accumulator = *accumulator / operand;
            *accumulator = new_accumulator;
            break;

        } else {
            break;
            }

        case'^':
        new_accumulator = pow(*accumulator, operand);
        *accumulator = new_accumulator;
        break;
    
        //unary cases

        case'#':
        if (*accumulator > 0) //making sure we don't sqrt a negative number
        {
            new_accumulator = sqrt(*accumulator);
            *accumulator = new_accumulator;
            break;
            } else {
                break;
                }
        
        case'%':
        new_accumulator = *accumulator * (-1);
        *accumulator = new_accumulator;
        break;

        case'!': 
        if ( *accumulator != 0 ) //making sure we don't divide by 0
        {
            new_accumulator = (1 / *accumulator);
            *accumulator = new_accumulator;
            break;
            } else {
                break;
                }

        case'q': //just underscoring that the the value of accumulator doesn't change when user enters q as the operator
        new_accumulator = *accumulator;
        *accumulator = new_accumulator;
        break; 
    }
        
}

