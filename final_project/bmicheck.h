#ifndef BMICHECK_H
#define BMICHECK_H
#include <QString>

class BMICheck
{
public:
    BMICheck() = default;
    static QString check(double result);
};

#endif // BMICHECK_H
