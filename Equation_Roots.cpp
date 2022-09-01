#include<iostream>

//Задание 1.
//
//Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.
//Создать производные классы : класс линейных уравнений и класс квадратных уравнений.
//Определить функцию вычисления корней уравнений.

class Equation_Roots
{
protected:
	double* coefficients;
	int size;
	double* roots;
	int root_numbers;
public:
	Equation_Roots(int sizeP);
	~Equation_Roots();
	virtual void find_roots() = 0;
	void print_roots();
	void show();
	int get_root_numbers();
	double* get_roots();
};
Equation_Roots::Equation_Roots(int sizeP)
{
	size = sizeP;
	coefficients = new double[size];
	root_numbers = size - 1;
	roots = new double[root_numbers];
}
Equation_Roots::~Equation_Roots()
{
	delete[] coefficients;
	delete[] roots;
}
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
	if (root_numbers > 0)
	{
		for (size_t i = 0; i < root_numbers; i++)
		{
			std::cout << "Root " << i + 1 << " is equal to " << roots[i] << std::endl;
		}
	}
	else
		std::cout << "There are no roots!" << std::endl;

	std::cout << std::endl;
}
void Equation_Roots::show()
{
	std::cout << "Equation: ";
	for (size_t i = size -1; i > 0; i--)
	{
		std::cout << coefficients[i] << "x^" << i << "+";
	}
	std::cout << coefficients[0] << std::endl;
}

class Linear_Equation : public Equation_Roots
{
public:
	Linear_Equation(double* coefP);
	virtual void find_roots();
};
Linear_Equation::Linear_Equation(double* coefP) :Equation_Roots(2)
{
	coefficients[0] = coefP[0];
	coefficients[1] = coefP[1];

}
void Linear_Equation::find_roots()
{
	coefficients[1] != 0 ? roots[0] = 
		- coefficients[0] / coefficients[1] : roots[0] = 0;
}

class Quadratic_Equation : public Equation_Roots
{
public:
	Quadratic_Equation(double* coefP);
	virtual void find_roots();
	double Discreamenant();
};
Quadratic_Equation::Quadratic_Equation(double* coefP) :Equation_Roots(3)
{
	for (size_t i = 0; i < size; i++)
	{
		coefficients[i] = coefP[i];
	}
}
double Quadratic_Equation::Discreamenant()
{
	return (coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2]);
}
void Quadratic_Equation::find_roots()
{
	if (Discreamenant() > 0)
	{
		roots[0] = ((-coefficients[1] + sqrt(Discreamenant())) / 2 / coefficients[2]);
		roots[1] = ((-coefficients[1] - sqrt(Discreamenant())) / 2 / coefficients[2]);
	}
	else if (Discreamenant() == 0)
	{
		delete[] roots;
		root_numbers = 1;
		roots = new double[1];
		roots[0] = ((-coefficients[1]) / 2 / coefficients[2]);
	}
	else
	{
		delete[] roots;
		root_numbers = 0;
		roots = nullptr;
	}

}

int main()
{
	double* coef1 = new double[2]{ 3,5 };
	Linear_Equation e1(coef1);
	e1.show();
	e1.find_roots();
	e1.print_roots();

	double* coef2 = new double[3]{ 10, -6, 1};
	Quadratic_Equation e2(coef2);
	e2.show();
	e2.find_roots();
	e2.print_roots();

	double* coef3 = new double[3]{ 9, -6, 1};
	Quadratic_Equation e3(coef3);
	e3.show();
	e3.find_roots();
	e3.print_roots();

	double* coef4 = new double[3]{ 4, -5, 1 };
	Quadratic_Equation e4(coef4);
	e4.show();
	e4.find_roots();
	e4.print_roots();

	delete[] coef1;
	delete[] coef2;
	delete[] coef3;
	delete[] coef4;
	return 0;
}