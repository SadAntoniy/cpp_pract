//� ���� ������� ��� ������������ ����������� �������� ������� Expression ��� ������������� �������������� ���������.
//����������, ��� ����� ���������� ��� ������ : Expression � ������� ����� ��������, Number � ��� ������������� ����� � BinaryOperation � ����� �����������
//�������� ��������(+, � - , *��� / ).
//����� Number ������ ������� �������� ���� double.
//����� BinaryOperation ������ ������� ��������� �� ����� � ������ ��������, ������� ���� �������� ��������������� �����������, � ����� ��� ��������(+, � - , *��� / ), ������� ����� ��� ���� ����������.
//�� ���� ������� ������ ���� ����� evaluate, ������� ���������� �������� ���� double � �������� ���������������� ��������������� ���������, ��������, �������� ����������
//���� Number � ��� �����, ������� �� ������, � ���� � ��� ���� ������ BinaryOperation � ��������� + , �� ����� ��������� �������� ������ � ������� �������� � ������� �� �����.
//� ������ ������� ��� ����� ���������� �������� ����� virtual ���, ��� ��� ����������, ���������� ����� evaluate ���, ��� ��� �� �������, � ����� ����������� �����������, ��� ��� ��� �����.
//
//��� ���������� ����� ������� ������, ��� ��� ����������� ������� BinaryOperation �� �������� �� ����������� ������ � ������� ���������(�������������, ��� ��� �������� � ������������ ������).

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
      ����� op ��� ���� �� 4 ��������: '+', '-', '*' ��� '/', ��������������� ���������,
      ������� ��� ����� �����������.
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
    // ����� ���������� ��� � ��������� ��� +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    // ��������� � ������� ���������: 25.5
    std::cout << expr->evaluate() << std::endl;

    // ��� ������������� *���* ���������� �������
    // (��������, sube ����� ������ ��������� expr, ������� ��� ������� �� �����)
    delete expr;
}