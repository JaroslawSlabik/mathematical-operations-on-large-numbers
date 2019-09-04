#include <iostream>
#include <string>
#include <algorithm>

#include "performs_mathematical_operations.h"
#include "addition_operation_without_sign.h"
#include "subtraction_operation_with_sign.h"


int main()
{
    std::cout << "5 - (-3) = ";

    std::string result;
    //bool was_ok = false;
    //PerformsMathematicalOperations mathematical_operations;
    //result = mathematical_operations.perform("5", "6", &was_ok, PerformsMathematicalOperations::OperationsEnum::addition);
    //if(!was_ok)
    //{
    //    std::cout << "Error: " << mathematical_operations.getError() << '\n';
    //    return 0;
    //}
    //result = SubtractionOperationWithoutSign()("6", "3");

    std::string aa = "-5";
    std::string bb = "-3";


    result = SubtractionOperationWithSign()(aa, bb);


    std::cout << result << '\n';

    return 0;
}

