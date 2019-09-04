#ifndef ADDITION_H
#define ADDITION_H

#include "mathematical_operations_template.h"

class Addition : public MathematicalOperationsTemplate
{
    private:
        Addition() = default;

    public:
        virtual std::string perform(const std::string& number_a, const std::string& number_b) override;

        static MathematicalOperationsTemplate* getInstance();

};

#endif // ADDITION_H
