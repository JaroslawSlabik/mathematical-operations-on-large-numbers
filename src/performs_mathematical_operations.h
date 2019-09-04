#ifndef PERFORMS_MATHEMATICAL_OPERATIONS_H
#define PERFORMS_MATHEMATICAL_OPERATIONS_H
#include <string>

class MathematicalOperationsTemplate;

class PerformsMathematicalOperations
{
    public:
        enum class OperationsEnum {unknown = 0, addition = 1, subtraction = 2, multiplication = 3, division = 4};

        PerformsMathematicalOperations() = default;
        PerformsMathematicalOperations(const std::string& number_a, const std::string& number_b, OperationsEnum operation);

        void setMathematicalOperation(OperationsEnum operation);
        void setMathematicalOperation(MathematicalOperationsTemplate *operation);

        std::string perform(const std::string& number_a, const std::string& number_b, OperationsEnum operation = OperationsEnum::unknown);

        std::string getResult();

    private:
        MathematicalOperationsTemplate *m_operation;
        std::string m_result;

};

#endif // PERFORMS_MATHEMATICAL_OPERATIONS_H
