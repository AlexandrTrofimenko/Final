#include <iostream>
#include <stdlib.h>
#include <matrix.hpp>
#include <gaus.hpp>
#include <kramer.hpp>
using namespace math;
/*
int main()
{
	//�����-��������
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
// �������� � �������� 
	int i = 0;
	int j = 0;
	std::cout<< "������� ���-�� ����� ������� " << std::endl;
	std::cin >> i;
	std::cout<< "������� ���-�� �������� ������� " << std::endl;
	std::cin >> j;
	Matrix A(i, j);
	std::cout<< "������� �������� ������� A" << std::endl;
	std::cin >> A;
	std::cout << A;
	A.transposition();
	std::cout << A;
	A.transposition();
	std::cout << A;*/
// ����� ������� ���� ������� ������ 
/*int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	std::cout << "������� ���-�� ��-���: ";
	std::cin >> n;
	std::cout << "������� ���-�� �����������: ";
	std::cin >> m;
	Gaus a(n, m);
	a.GausIn();
	a.GausOut();
	return 0;
}*/
/*	// ����� �������
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