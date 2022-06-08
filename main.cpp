#include <iostream>
#include <stdlib.h>
#include <matrix.hpp>
#include <gaus.hpp>
#include <kramer.hpp>
using namespace math;
/*
int main()
{
	//Гаусс-Джордано
	int order;
	order = 3;
	Matrix A(3, 3); 
	std::cin >> A;
	A.InverseOfMatrix(order);
	return 0;
}
*/
/*int main()
{
	
	setlocale(LC_ALL, "Rus");
// Операции с матрицей 
	int i = 0;
	int j = 0;
	std::cout<< "Введите кол-во строк матрицы " << std::endl;
	std::cin >> i;
	std::cout<< "Введите кол-во столбцов матрицы " << std::endl;
	std::cin >> j;
	Matrix A(i, j);
	std::cout<< "Введите элементы матрицы A" << std::endl;
	std::cin >> A;
	std::cout << A;
	A.transposition();
	std::cout << A;
	A.transposition();
	std::cout << A;*/
// Метод решения СЛАУ методом Гаусса 
/*int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	std::cout << "Введите кол-во ур-ний: ";
	std::cin >> n;
	std::cout << "Введите кол-во неизвестных: ";
	std::cin >> m;
	Gaus a(n, m);
	a.GausIn();
	a.GausOut();
	return 0;
}*/
/*	// Метод Крамера
int main()
{
	int n;
	std::cout << "Enter a number of variables "; 
	std::cin >> n;
	kramer A(n, n);
	A.Kramer(n);
	return 0;
}
*/