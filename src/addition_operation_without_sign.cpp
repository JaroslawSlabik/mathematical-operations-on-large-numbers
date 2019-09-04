#include "addition_operation_without_sign.h"

#include <algorithm>

std::string AdditionOperationWithoutSign::operator()(const std::string& number_a, const std::string& number_b)
{
    std::string result;

    std::string first_number;
    std::string second_number;

    int diff = 0;

    if(number_a.length() <= number_b.length())
    {
        first_number = number_b;
        diff = number_b.length() - number_a.length();
        second_number = number_a;
    }
    else
    {
        first_number = number_a;
        diff = number_a.length() - number_b.length();
        second_number = number_b;
    }

    std::reverse(first_number.begin(), first_number.end());
    std::reverse(second_number.begin(), second_number.end());

    second_number.append(diff, '0');

    short next = 0;
    for(unsigned int i = 0; i < first_number.length(); ++i)
    {
        short sum = (first_number.at(i) - 48) + (second_number.at(i) - 48) + next;
        if(sum > 9)
        {
            next = sum / 10 % 10;
            sum = sum % 10;
        }
        else
        {
            next = 0;
        }

        result += (sum + 48);
    }

    if(0 != next)
    {
        result += (next + 48);
    }

    std::reverse(result.begin(), result.end());

    return result;
}

