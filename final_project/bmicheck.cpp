#include "bmicheck.h"



QString BMICheck::check(double result)
{
    if(result < 16)
        return("BMI less than normal! Eat more!");
    if(result < 18.5)
        return("BMI less than normal! Eat more!");
    if(result < 25)
        return("normal BMI");
    if(result < 30)
        return("BMI is higher than normal! Eat less!");
    if(result < 35)
        return("You have first stage of obesity! Go to doctor!");
    if(result < 40)
        return("You have second stage of obesity! Go to doctor!");
    return("You have third stage of obesity! Go to doctor!");
}
