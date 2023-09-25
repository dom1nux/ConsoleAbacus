#include "Main.h"

int main(int, char**)
{
    char op{ ' ' };
    double result{ 0.0 };
    fmt::print("**********Calculator**********\n\n");
    while (true)
    {
        std::string input;
        fmt::print(": ");
        std::cin >> input;

        if (input == "q" || input == "Q")
        {
            fmt::print("\n*******App Terminated*******\n");
            break;
        }
        else if (input == "+" || input == "-" || input == "*" || input == "/")
        {
            op = input[0];
        }
        else if (IsNumber(input))
        {
            double number = std::stod(input);
            if (op != ' ')
            {
                result = CalcLogic(op, result, number);
                fmt::print("\n= {}\n\n", result);
                op = ' ';
            }
            else
            {
                result = number;
            }
        }
        else
        {
            fmt::print("Invalid input, try again!\n");
        }
    }

    return 0;
}

bool IsNumber(const std::string& input)
{
    std::istringstream iss(input);
    double number;
    return (iss >> number) && (iss.peek() == EOF || iss.peek() == '\n');
    ;
}
double CalcLogic(char op, double x, double y)
{
    switch (op)
    {
    case '+':
        return add(x, y);
    case '-':
        return subtract(x, y);
    case '*':
        return multiply(x, y);
    case '/':
        if (y != 0)
        {
            return divide(x, y);
        }
        else
        {
            fmt::print("Division by 0 is not allowed.");
            return 0.0;
        }
    default:
        fmt::print("Invalid operator.");
        return 0.0;
    }
}
double add(double x, double y)
{
    return x + y;
}
double subtract(double x, double y)
{
    return x - y;
}
double multiply(double x, double y)
{
    return x * y;
}
double divide(double x, double y)
{
    return x / y;
}
