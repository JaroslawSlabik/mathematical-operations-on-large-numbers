#include <iostream>
#include <string>

#define IS_NOT_EQUAL_EXCEPTIOM(name, x, y)                                                  \
{                                                                                           \
    std::cout << name << ": ";                                                              \
    if(x != y )                                                                             \
    {                                                                                       \
        std::cout << "Failed!\n";                                                           \
        std::cout << __FILE__ << ":" << __LINE__ << " in " << __PRETTY_FUNCTION__ << ": ";  \
        std::cout << x << " != " << y << '\n';                                              \
        std::exit(1);                                                                       \
    }                                                                                       \
                                                                                            \
    std::cout << "Success!\n";                                                              \
}                                                                                           \

#define IS_EQUAL_EXCEPTIOM(x, y)                                                            \
{                                                                                           \
    if(x == y )                                                                             \
    {                                                                                       \
        std::cout << __FILE__ << ":" << __LINE__ << " in " << __PRETTY_FUNCTION__ << ": ";  \
        std::cout << x << " == " << y << '\n';                                              \
        std::exit(1);                                                                       \
    }                                                                                       \
}                                                                                           \

#define EXCEPTIOM(name)                                                                     \
{                                                                                           \
    std::cout << name << ": ";                                                              \
    std::cout << "Failed!\n";                                                               \
    std::cout << __FILE__ << ":" << __LINE__ << " in " << __PRETTY_FUNCTION__ << ": ";      \
    std::exit(1);                                                                           \
}                                                                                           \


#include "performs_mathematical_operations.h"

#include "addition_operation_without_sign.h"
#include "addition_operation_with_sign.h"
#include "subtraction_operation_without_sign.h"
#include "subtraction_operation_with_sign.h"

int main()
{
    std::string result;

    //AdditionOperationWithoutSign
    std::cout << "AdditionOperationWithoutSign:\n";

    result = AdditionOperationWithoutSign()("5", "8");
    IS_NOT_EQUAL_EXCEPTIOM("5 + 8 = 13", result, "13")

    result = AdditionOperationWithoutSign()("99", "99");
    IS_NOT_EQUAL_EXCEPTIOM("99 + 99 = 198", result, "198")

    result = AdditionOperationWithoutSign()("9995", "18");
    IS_NOT_EQUAL_EXCEPTIOM("9995 + 18 = 10013", result, "10013")

    //AdditionOperationWithSign
    std::cout << "AdditionOperationWithSign:\n";

    result = AdditionOperationWithSign()("-5", "-7");
    IS_NOT_EQUAL_EXCEPTIOM("(-5) + (-7) = -12", result, "-12")

    result = AdditionOperationWithSign()("120", "-99");
    IS_NOT_EQUAL_EXCEPTIOM("120 + (-99) = 21", result, "21")

    result = AdditionOperationWithSign()("-99", "120");
    IS_NOT_EQUAL_EXCEPTIOM("(-99) + 120 = 21", result, "21")

    result = AdditionOperationWithSign()("5", "-7");
    IS_NOT_EQUAL_EXCEPTIOM("5 + (-7) = -2", result, "-2")

    result = AdditionOperationWithSign()("-7", "5");
    IS_NOT_EQUAL_EXCEPTIOM("-7 + 5 = -2", result, "-2")

    //SubtractionOperationWithoutSign
    std::cout << "SubtractionOperationWithoutSign:\n";

    result = SubtractionOperationWithoutSign()("77", "19");
    IS_NOT_EQUAL_EXCEPTIOM("77 - 19 = 58", result, "58")

    try
    {
        result = SubtractionOperationWithoutSign()("19", "77");

        //Bad
        EXCEPTIOM("19 - 77")
    }
    catch(...)
    {
        //Good
    }

    //SubtractionOperationWithSign
    std::cout << "SubtractionOperationWithSign:\n";

    result = SubtractionOperationWithSign()("-90", "19");
    IS_NOT_EQUAL_EXCEPTIOM("-90 - 19 = -109", result, "-109")

    result = SubtractionOperationWithSign()("44", "-123");
    IS_NOT_EQUAL_EXCEPTIOM("44 - (-123) = 167", result, "167")

    result = SubtractionOperationWithSign()("-1357", "-123");
    IS_NOT_EQUAL_EXCEPTIOM("(-1357) - (-123) = -1234", result, "-1234")

    result = SubtractionOperationWithSign()("-987", "-1000");
    IS_NOT_EQUAL_EXCEPTIOM("(-987) - (-1000) = 13", result, "13")

    //Zero
    std::cout << "Zero mix:\n";

    result = SubtractionOperationWithSign()("-987", "000");
    IS_NOT_EQUAL_EXCEPTIOM("-987 - 000 = -987", result, "-987")

    result = SubtractionOperationWithSign()("-987", "-987");
    IS_NOT_EQUAL_EXCEPTIOM("SubtractionOperationWithSign (-A) - (-A)", result, "0")

    result = SubtractionOperationWithoutSign()("987", "000");
    IS_NOT_EQUAL_EXCEPTIOM("987 - 000 = 987", result, "987")

    result = SubtractionOperationWithoutSign()("987", "987");
    IS_NOT_EQUAL_EXCEPTIOM("987 - 987 = 0", result, "0")

    result = AdditionOperationWithoutSign()("5", "0");
    IS_NOT_EQUAL_EXCEPTIOM("5 + 0 = 5", result, "5")

    result = AdditionOperationWithSign()("-543", "0");
    IS_NOT_EQUAL_EXCEPTIOM("-543 + 0 = -543", result, "-543")

    result = AdditionOperationWithSign()("-543", "543");
    IS_NOT_EQUAL_EXCEPTIOM("-543 + 543 = 0", result, "0")

    return 0;
}
