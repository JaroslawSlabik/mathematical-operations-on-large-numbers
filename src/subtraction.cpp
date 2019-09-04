#include "subtraction.h"

#include "subtraction_operation_without_sign.h"
#include "subtraction_operation_with_sign.h"

std::string Subtraction::perform(const std::string& number_a, const std::string& number_b)
{
    if('-' != number_a.at(0) && '-' != number_b.at(0))
    {
        return SubtractionOperationWithoutSign()(number_a, number_b);
    }
    else if('-' == number_a.at(0) || '-' == number_b.at(0))
    {
        return SubtractionOperationWithSign()(number_a, number_b);
    }

    return std::string();
}

MathematicalOperationsTemplate* Subtraction::getInstance()
{
    static Subtraction instance;
    return &instance;
}

