#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "mathematical_operations_template.h"

class Subtraction : public MathematicalOperationsTemplate
{
    private:
        Subtraction() = default;

    public:
        virtual std::string perform(const std::string& number_a, const std::string& number_b) override;

        static MathematicalOperationsTemplate* getInstance();

};

#endif // SUBTRACTION_H
