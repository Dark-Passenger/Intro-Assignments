#include "shared.h"

/*Function performs addition of the provided variables*/
int sharedclass::add(int a, int b)
{
    return (a + b);
}
/*
Function performs subtraction of the provided variables,
to keep a positive output only
*/
int  sharedclass::subtract(int a, int b)
{
    if(a<b)
        {
            return (b - a);
        }
    else
        {
            return (a - b);
        }

}
/*Function performs multiplication of the provided variables*/
int  sharedclass::multiply(int a, int b)
{
    return (a * b);
}
/*
Function performs division of the provided variables
To reduce probablity of fractions numerator is always
*/
int  sharedclass::divide(int a, int b)
{
    if(a<b)
        {
            return (b / a);
        }
    else
        {
            return (a / b);
        }

}

