#include "performs_mathematical_operations.h"

#include "addition.h"
#include "subtraction.h"

PerformsMathematicalOperations::PerformsMathematicalOperations(const std::string& number_a, const std::string& number_b, OperationsEnum operation)
{
    setMathematicalOperation(operation);

    m_result = m_operation->perform(number_a, number_b);
}

void PerformsMathematicalOperations::setMathematicalOperation(OperationsEnum operation)
{
    switch(operation)
    {
        case OperationsEnum::addition:
            m_operation = Addition::getInstance();
            break;
        case OperationsEnum::subtraction:
            m_operation = Subtraction::getInstance();
            break;
        case OperationsEnum::multiplication:
            
            break;
        case OperationsEnum::division:
            
            break;
        default:
            break;
    };
}

void PerformsMathematicalOperations::setMathematicalOperation(MathematicalOperationsTemplate *operation)
{
    m_operation = operation;
}

std::string PerformsMathematicalOperations::perform(const std::string& number_a, const std::string& number_b, OperationsEnum operation)
{
    if(operation != OperationsEnum::unknown)
    {
        setMathematicalOperation(operation);
    }

    if(m_operation == nullptr)
    {
        throw "Not choice mathematical operation";
    }

    m_result = m_operation->perform(number_a, number_b);

    return m_result;
}

std::string PerformsMathematicalOperations::getResult()
{
    return m_result;
}
