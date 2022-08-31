#include<iostream>

class Equation_Roots
{
protected:
	double* coefficients;
	int size;
	double* roots;
	int root_numbers;
public:
	virtual void find_roots() = 0;
	void print_roots();
	void show();
	int get_root_numbers();
	double* get_roots();
};

int Equation_Roots::get_root_numbers()
{
	return root_numbers;
}
double* Equation_Roots::get_roots()
{
	return roots;
}
void Equation_Roots::print_roots()
{
	for (size_t i = 0; i < root_numbers; i++)
	{
		std::cout << "Root " << i << " is equal to " << roots[i] << std::endl;
	}
	std::cout << std::endl;
}
void Equation_Roots::show()
{
	for (size_t i = size -1; i > 0; i--)
	{
		std::cout << coefficients[i] << "x^" << i << "+";
	}
	std::cout << coefficients[0] << std::endl;
}

class Linear_Equation : public Equation_Roots
{
public:
	Linear_Equation(double aP, double bP);
	~Linear_Equation();
	virtual void find_roots();
};
Linear_Equation::Linear_Equation(double aP, double bP) 
{
	coefficients = new double[2];
	coefficients[0] = aP;
	coefficients[1] = bP;
	size = 2;
	root_numbers = 1;
	roots = new double[1];
}
Linear_Equation::~Linear_Equation()
{
	delete[] roots;
	delete[] coefficients;
}
void Linear_Equation::find_roots()
{
	coefficients[1] != 0 ? roots[0] = 
		- coefficients[0] / coefficients[1] : roots[0] = 0;
}



int main()
{
	Linear_Equation e1(3, 5);
	e1.show();
	e1.find_roots();
	e1.print_roots();

	return 0;
}