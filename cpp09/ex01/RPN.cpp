
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	*this = other;
}


RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->stack = other.stack;
		this->error_token = other.error_token;
	}
	return (*this);
}

RPN::~RPN() {}

std::string&	RPN::getErrorToken()
{
	if (error_token.empty())
		std::cout << "No errors present" << std::endl;
	return (error_token);
}

const char*	RPN::InvalidEntryOption::what() const throw()
{
	return ("Invalid entry option -> ");
}

const char*	RPN::InvalidRPNOperation::what() const throw()
{
	return ("Invalid RPN operation");
}

static bool	is_operator(std::string& str)
{
	std::string operations = "+-/*";

	if (str.size() > 1 || operations.find(str) == std::string::npos)
		return false;
	return true;
}

static bool is_integer(const std::string& str) {
    try {
        size_t pos;
        std::stoi(str, &pos);
        return pos == str.size(); // make sure whole string is a number
    } catch (...) {
        return false;
    }
}

void	RPN::calculate(char *argv[])
{

	std::string 			token_list = argv[1];
	if (token_list.empty())
        throw(InvalidRPNOperation()); // empty input
	std::istringstream 		stream(token_list);
	std::string				token;

	while (stream >> token) {
		// std::cout << "token : " << token << "." << std::endl;
		if (!is_integer(token) && !is_operator(token)) {
			error_token = token;
			throw (InvalidEntryOption());
		}
		if (is_integer(token))
			stack.push(atoi(token.c_str()));
		else if (is_operator(token))
		{
			int result;
			int store;

			if (stack.size() < 2)
				throw(InvalidRPNOperation());
			store = stack.top();
			stack.pop();//Remove the second top element.
			if (token == "*")
				result = stack.top() * store;
			else if (token == "/")
			{
				if (store == 0)
					throw(InvalidRPNOperation());
				result = stack.top() / store;
			}
			else if (token == "+")
				result = stack.top() + store;
			else if (token == "-")
				result = stack.top() - store;
			stack.pop();
			stack.push(result);
		}
	}
	if (stack.size() > 1)
		throw(InvalidRPNOperation());

	std::cout << stack.top() << std::endl;
}

/*Takes the expression from the command line (argv[1]).

Wraps it in a std::istringstream so we can split it into tokens (3, 4, +, 2, *).
Steps:

Read "3" → push 3 → stack: [3]

Read "4" → push 4 → stack: [3, 4]

Read "+" → pop 4, pop 3, calculate 3 + 4 = 7, push 7 → stack: [7]

Read "2" → push 2 → stack: [7, 2]

Read "*" → pop 2, pop 7, calculate 7 * 2 = 14, push 14 → stack: [14]

End of input → stack size = 1 → print 14.
/////

Splits the input into tokens.

Uses a stack container to evaluate them according to RPN rules.

Throws exceptions if the input is invalid.

Prints the result if valid.*/