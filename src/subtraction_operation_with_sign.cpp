#include "subtraction_operation_with_sign.h"

#include <algorithm>

#include "addition_operation_without_sign.h"
#include "subtraction_operation_without_sign.h"

std::string SubtractionOperationWithSign::operator()(const std::string& number_a, const std::string& number_b)
{
    std::string result;

    //NOTE:
    //1.
    //(-A) - B = -(A + B)
    //2.
    //A - (-B) = A + B
    //3.
    //(-A) - (-B) = -(A - B)
    //where (without sign) A is bigests of B
    //4.
    //(-A) - (-B) = B - A
    //where (without sign) B is bigests of A

    //Ad. 1.
    if('-' == number_a.at(0) && '-' != number_b.at(0))
    {
        //Delete sign '-'
        std::string number_a_without_sign = number_a;
        number_a_without_sign.erase(0, 1);

        //Calculate
        result = AdditionOperationWithoutSign()(number_a_without_sign, number_b);

        //Add sign '-'
        result = "-" + result;
        return result;
    }
    //Ad. 2.
    else if('-' != number_a.at(0) && '-' == number_b.at(0))
    {
        //Delete sign '-'
        std::string number_b_without_sign = number_b;
        number_b_without_sign.erase(0, 1);

        //Calculate
        result = AdditionOperationWithoutSign()(number_a, number_b_without_sign);

        return result;
    }
    //Ad. 3.
    else if('-' == number_a.at(0) && '-' == number_b.at(0) && SubtractionOperationWithoutSign().numberAIsGreaterThanNumberB(number_a, number_b))
    {
        //Delete sign '-'
        std::string number_a_without_sign = number_a;
        number_a_without_sign.erase(0, 1);

        std::string number_b_without_sign = number_b;
        number_b_without_sign.erase(0, 1);

        //Calculate
        result = SubtractionOperationWithoutSign()(number_a_without_sign, number_b_without_sign);

        //Add sign '-'
        result = "-" + result;
        return result;
    }
    //Ad. 4
    else if('-' == number_a.at(0) && '-' == number_b.at(0) && !SubtractionOperationWithoutSign().numberAIsGreaterThanNumberB(number_a, number_b))
    {
        //Delete sign '-'
        std::string number_a_without_sign = number_a;
        number_a_without_sign.erase(0, 1);

        std::string number_b_without_sign = number_b;
        number_b_without_sign.erase(0, 1);

        //Calculate
        result = SubtractionOperationWithoutSign()(number_b_without_sign, number_a_without_sign);

        return result;
    }

    return result;
}

