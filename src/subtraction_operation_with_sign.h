#ifndef SUBTRACTION_OPERATION_WITH_SIGN_H
#define SUBTRACTION_OPERATION_WITH_SIGN_H
#include <string>

class SubtractionOperationWithSign
{
    public:
        SubtractionOperationWithSign() = default;
        std::string operator()(const std::string& number_a, const std::string& number_b);

};

#endif // SUBTRACTION_OPERATION_WITH_SIGN_H
