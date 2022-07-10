//¬ этом задании вам предлагаетс€ разработать иерархию классов Expression дл€ представлени€ арифметических выражений.
// онкретнее, вам нужно определить три класса : Expression Ч базовый класс иерархии, Number Ч дл€ представлени€ чисел и BinaryOperation Ч класс описывающий
//бинарную операцию(+, ≠ - , *или / ).
// ласс Number должен хранить значение типа double.
// ласс BinaryOperation должен хранить указатель на левый и правый операнды, которые сами €вл€ютс€ арифметическими выражени€ми, а также тип операции(+, ≠ - , *или / ), которую нужно над ними произвести.
//¬о всех классах должен быть метод evaluate, который возвращает значение типа double Ч значение соответствующего арифметического выражени€, например, значение экземпл€ра
//типа Number Ч это число, которое он хранит, а если у вас есть объект BinaryOperation с операцией + , то нужно вычислить значени€ левого и правого операнда и вернуть их сумму.
//¬ данном задании вам нужно расставить ключевое слово virtual там, где это необходимо, определить метод evaluate там, где его не хватает, а также реализовать деструкторы, там где они нужны.
//
//ѕри выполнении этого задани€ учтите, что при уничтожении объекта BinaryOperation он отвечает за уничтожение левого и правого операндов(гарантируетс€, что они выделены в динамической пам€ти).

#include <iostream>

class Expression
{
public:
    virtual double evaluate() const = 0;

    virtual ~Expression()
    {}
};

class Number : public Expression
{
public:

    Number(double value)
        : value(value)
    {}

    double evaluate() const override
    {
        return value;
    }
private:
    double value;
};

class BinaryOperation : public Expression
{
public:

    /*
      «десь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операци€м,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    {}

    double evaluate() const override
    {
        if (op == '+')
            return (left->evaluate() + right->evaluate());            
        else if (op == '*')
            return (left->evaluate() * right->evaluate());
        else if (op == '-')
            return (left->evaluate() - right->evaluate());
        else if (op == '/')
            return (left->evaluate() / right->evaluate());
            
    }

    ~BinaryOperation() override
    {
        delete left;
        delete right;
    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};

int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении дл€ +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисл€ем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаютс€ *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удал€ть не нужно)
    delete expr;
}