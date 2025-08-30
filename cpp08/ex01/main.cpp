#include "Span.hpp"

int main()
{
    std::cout << "==============================" << std::endl;
    {
        Span sp = Span(5);

        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << "==============================" << std::endl;
	{
		Span sp = Span(20000);
		std::vector<int> Vector;

		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < 20000; i++) {
			Vector.push_back(rand() % 20000 + 1);
		}
		sp.fill(Vector.begin(), Vector.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

    return 0;
}
