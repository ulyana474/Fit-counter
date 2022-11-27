#ifndef NUTRITION_H
#define NUTRITION_H
#include <bodyindex.h>

class Nutrition : public BodyIndex {
public:
    Nutrition(int age, float height, float weight);
    float getNutrition();

private:
    int p_age;
};
#endif // NUTRITION_H
