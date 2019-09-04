#include "subtraction_operation_without_sign.h"

#include <algorithm>

std::string SubtractionOperationWithoutSign::operator()(const std::string& number_a, const std::string& number_b)
{
    std::string result;

    if(number_a == number_b)
    {
        return std::string("0");
    }

    if(!numberAIsGreaterThanNumberB(number_a, number_b))
    {
        throw "TODO: make Exception class"; //TODO: make Exception class
    }

    std::string first_number = number_a;
    std::string second_number = number_b;

    //Calculate diffrent lenght
    unsigned int diff = first_number.length() - second_number.length();

    //Reverse first_number and second_number
    std::reverse(first_number.begin(), first_number.end());
    std::reverse(second_number.begin(), second_number.end());

    //Append '0' to end second_number string
    second_number.append(diff, '0');

    for(unsigned int i = 0; i < first_number.length(); ++i)
    {
        short back = 0;
        // If A < B then borrow from next digit
        if(first_number.at(i) - 48 < second_number.at(i) - 48)
        {
            back = borrowFrom(first_number, i + 1);
        }

        short sub = ((first_number.at(i) - 48) + back) - (second_number.at(i) - 48);

        result += (sub + 48);
    }

    //Reverse result
    std::reverse(result.begin(), result.end());

    //Delete first '0'
    deleteFirst0(result);

    return result;
}

bool SubtractionOperationWithoutSign::numberAIsGreaterThanNumberB(const std::string& number_a, const std::string& number_b)
{
    bool a_is_larger = false;

    if(number_a.length() > number_b.length())
    {
        a_is_larger = true;
    }
    else if(number_a.length() < number_b.length())
    {
        a_is_larger = false;
    }
    else if(number_a.length() == number_b.length())
    {
        for(unsigned int i = 0; i < number_a.length(); ++i)
        {
            if ((number_a[i] - '0') > (number_b[i] - '0'))
            {
                a_is_larger = true;
                break;
            }
            else if ((number_a[i] - '0') < (number_b[i] - '0'))
            {
                a_is_larger = false;
                break;
            }
        }
    }

    return a_is_larger;
}

short SubtractionOperationWithoutSign::borrowFrom(std::string& number, unsigned int position_start)
{
    unsigned int borrow_position = 0;
    for(unsigned int i = position_start; i < number.length(); ++i)
    {
        if(0 == (number[i] - 48))
        {
            continue;
        }
        else
        {
            number[i] = number[i] - 1;
            borrow_position = i;
            break;
        }
    }

    if(borrow_position == position_start)
    {
        return 10;
    }

    for(unsigned int i = borrow_position - 1; i >= position_start; --i)
    {
        number[i] = '9';
    }

    return 10;
}

void SubtractionOperationWithoutSign::deleteFirst0(std::string& number)
{
    //Change first '0' to 'X'
    for(unsigned int i = 0; i < number.length(); ++i)
    {
        if('0' == number[i])
        {
            number[i] = 'X';
        }
        else
        {
            break;
        }
    }

    //Delete all 'X'
    number.erase(remove(number.begin(), number.end(), 'X'), number.end());

    //If result string is empty then set '0'
    if(0 == number.length())
    {
        number = '0';
    }
}
