#include "nutrition.h"
#include <exception>

Nutrition::Nutrition(int age, float height, float weight)
    : BodyIndex(height, weight)
    , p_age(age)
{
    if (p_age < 1 || p_age > 120){
        throw std::exception("invalid age");
    }
}

float Nutrition::getNutrition() {
    int nutrition = 6.25 * p_height + 10 * p_weight - 4.92 * p_age;
    return nutrition;
}
