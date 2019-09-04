#ifndef ADDITION_OPERATION_WITH_SIGN_H
#define ADDITION_OPERATION_WITH_SIGN_H
#include <string>

class AdditionOperationWithSign
{
    public:
        AdditionOperationWithSign() = default;
        std::string operator()(const std::string& number_a, const std::string& number_b);
};

#endif // ADDITION_OPERATION_WITH_SIGN_H
