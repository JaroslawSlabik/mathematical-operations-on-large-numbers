#include "addition.h"

#include "addition_operation_without_sign.h"
#include "addition_operation_with_sign.h"

std::string Addition::perform(const std::string& number_a, const std::string& number_b)
{
    std::string result;

    if('-' != number_a.at(0) && '-' != number_b.at(0))
    {
        return AdditionOperationWithoutSign()(number_a, number_b);
    }
    else if('-' == number_a.at(0) || '-' == number_b.at(0))
    {
        return AdditionOperationWithSign()(number_a, number_b);
    }

    return std::string();
}

MathematicalOperationsTemplate* Addition::getInstance()
{
    static Addition instance;
    return &instance;
}

