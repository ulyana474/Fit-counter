#include "bodyindex.h"
#include <exception>
#include <QMessageBox>

BodyIndex::BodyIndex(float height, float weight)
    : p_height(height)
    , p_weight(weight)
{
    if(p_height < 50 || p_height > 250){
        throw std::exception("invalid height");
    }
    if(p_weight <= 0 || p_weight > 350){
        throw std::exception("invalid weight");
    }
}

float BodyIndex::getBMI() {
    float result_BMI = p_weight / (p_height * p_height) * 10000;
    return result_BMI;
}
