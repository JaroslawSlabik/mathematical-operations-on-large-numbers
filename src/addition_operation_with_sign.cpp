#include "addition_operation_with_sign.h"

#include <algorithm>
#include "addition_operation_without_sign.h"
#include "subtraction_operation_without_sign.h"

std::string AdditionOperationWithSign::operator()(const std::string& number_a, const std::string& number_b)
{
    //Delete sign '-' if exists
    std::string number_a_without_sign = number_a;
    number_a_without_sign.erase(remove(number_a_without_sign.begin(), number_a_without_sign.end(), '-'), number_a_without_sign.end());

    std::string number_b_without_sign = number_b;
    number_b_without_sign.erase(remove(number_b_without_sign.begin(), number_b_without_sign.end(), '-'), number_b_without_sign.end());

    std::string result;

    //NOTE:
    //1.a.
    //(-A) + A = 0
    //1.b.
    //A + (-A) = 0
    //2.
    //(-A) + (-B) = -(A + B)
    //
    //3.a.
    //Abig + (-Bsmall) = Abig - Bsmall
    //3.b.
    //(-Asmall) + Bbig = Bbig - Asmall
    //
    //4.a.
    //Asmall + (-Bbig) = -(Bbig - Asmall)
    //4.b.
    //(-Abig) + Bsmall = -(Abig - Bsmall)

    //Ad. 1.a. and 1.b.
    if((('-' == number_a.at(0) && '-' != number_b.at(0)) || ('-' != number_a.at(0) && '-' == number_b.at(0))) &&
            number_a_without_sign == number_b_without_sign)
    {
        return std::string("0");
    }
    //Ad. 2.
    else if('-' == number_a.at(0) && '-' == number_b.at(0))
    {
        //Calculate
        result = AdditionOperationWithoutSign()(number_a_without_sign, number_b_without_sign);

        //Add sign '-'
        result = "-" + result;
        return result;
    }
    //Ad. 3.a.
    else if(SubtractionOperationWithoutSign().numberAIsGreaterThanNumberB(number_a_without_sign, number_b_without_sign) && '-' != number_a.at(0) && '-' == number_b.at(0))
    {
        //Calculate
        result = SubtractionOperationWithoutSign()(number_a_without_sign, number_b_without_sign);
        return result;
    }
    //Ad. 3.b.
    else if(SubtractionOperationWithoutSign().numberAIsGreaterThanNumberB(number_b_without_sign, number_a_without_sign) && '-' == number_a.at(0) && '-' != number_b.at(0))
    {
        //Calculate
        result = SubtractionOperationWithoutSign()(number_b_without_sign, number_a_without_sign);
        return result;
    }
    //Ad. 4.a.
    else if(SubtractionOperationWithoutSign().numberAIsGreaterThanNumberB(number_b_without_sign, number_a_without_sign) && '-' != number_a.at(0) && '-' == number_b.at(0))
    {
        //Calculate
        result = SubtractionOperationWithoutSign()(number_b_without_sign, number_a_without_sign);

        //Add sign '-'
        result = "-" + result;

        return result;
    }
    //Ad. 4.b.
    else if(SubtractionOperationWithoutSign().numberAIsGreaterThanNumberB(number_a_without_sign, number_b_without_sign) && '-' == number_a.at(0) && '-' != number_b.at(0))
    {
        //Calculate
        result = SubtractionOperationWithoutSign()(number_a_without_sign, number_b_without_sign);

        //Add sign '-'
        result = "-" + result;

        return result;
    }

    //throw ""; //TODO: make Exception class

    return std::string();
}

