#ifndef SUBTRACTION_OPERATION_WITHOUT_SIGN_H
#define SUBTRACTION_OPERATION_WITHOUT_SIGN_H
#include <string>

class SubtractionOperationWithoutSign
{
    public:
        SubtractionOperationWithoutSign() = default;
        std::string operator()(const std::string& number_a, const std::string& number_b);
        bool numberAIsGreaterThanNumberB(const std::string& number_a, const std::string& number_b);
        short borrowFrom(std::string& number, unsigned int position_start);
        void deleteFirst0(std::string& number);


};

#endif // SUBTRACTION_OPERATION_WITHOUT_SIGN_H
