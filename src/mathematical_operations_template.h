#ifndef MATHEMATICAL_OPERATIONS_TEMPLATE_H
#define MATHEMATICAL_OPERATIONS_TEMPLATE_H

#include <string>

class MathematicalOperationsTemplate
{
    public:
        std::string doPerform(const std::string& number_a, const std::string& number_b)
        {
            if(number_a.empty() || number_b.empty())
            {
                throw "";
            }

            return perform(number_a, number_b);
        }

        virtual std::string perform(const std::string& number_a, const std::string& number_b) = 0;
};


#endif // MATHEMATICAL_OPERATIONS_TEMPLATE_H
