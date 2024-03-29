#pragma once
#include <iostream>
namespace math
{
	class Matrix
	{
	public:
		Matrix(int n, int m)
		{
			std::cout << "Constructor" << std::endl;
			m_n = n;
			m_m = m;
			m_mat = new double* [m_n];
			for (int i = 0; i < m_n; i++)
			{
				m_mat[i] = new double[m_m];
			}
		}
		Matrix(const Matrix& mat)
		{
			std::cout << "Copy constructor" << std::endl;
			m_n = mat.m_n;
			m_m = mat.m_m;
			m_mat = new double* [m_n];
			for (int i = 0; i < m_n; i++)
			{
				m_mat[i] = new double[m_m];
			}
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					m_mat[i][j] = mat.m_mat[i][j];
				}
			}
		}
		Matrix& operator=(const Matrix& mat)
		{
			std::cout << "Operator = " << std::endl;
			m_n = mat.m_n;
			m_m = mat.m_m;
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					m_mat[i][j] = mat.m_mat[i][j];
				}
			}
			return *this;
		}
		Matrix operator+(const Matrix& mat)
		{
			std::cout << "Operator+" << std::endl;
			Matrix tmp(m_n, m_m);
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
				}
			}
			return tmp;
		}
		Matrix operator-(const Matrix& mat)
		{
			std::cout << "Operator-" << std::endl;
			Matrix tmp(m_n, m_m);
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
				}
			}
			return tmp;
		}
		Matrix operator*(const Matrix& mat)
		{
			std::cout << "Operator*" << std::endl;
			Matrix tmp(m_n, m_m);
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < mat.m_m; j++)
				{
					tmp.m_mat[i][j] = 0;
					for (int k = 0; k < m_m; k++)
					{
						tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
					}
				}
			}
			return tmp;
		}
		int Matrix::Det()
		{
			if ((m_n != m_m) || m_n > 3 || m_m > 3)
			{
				std::cout << "�������� �� ��������������" << std::endl;
				return -1;
			}


			if (m_n == 2 && m_m == 2)
			{
				std::cout << "2x2" << std::endl;
				return m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
			}

			if (m_n == 3 && m_m == 3)
			{
				std::cout << "3x3" << std::endl;
				return m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
					+ m_mat[1][0] * m_mat[2][1] * m_mat[0][2] - (m_mat[2][0] * m_mat[1][1] * m_mat[0][2] +
						m_mat[2][1] * m_mat[1][2] * m_mat[0][0] + m_mat[1][0] * m_mat[0][1] * m_mat[2][2]);
			}
		}
		Matrix Matrix::inversion()
		{
			int Det1 = Det();
			Matrix tmp(m_n, m_m);
			if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3))
			{
				if (Det1 == 0)
				{
					std::cout << "������������ ����� ����" << std::endl;
				}
				else
				{
					if (m_n == 2)
					{
						tmp.m_mat[0][0] = m_mat[1][1] / Det1;
						tmp.m_mat[0][1] = -m_mat[0][1] / Det1;
						tmp.m_mat[1][0] = -m_mat[1][0] / Det1;
						tmp.m_mat[1][1] = m_mat[0][0] / Det1;
						return tmp;
					}
					if (m_n == 3)
					{
						tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / Det1;
						tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / Det1;
						tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / Det1;
						tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / Det1;
						tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / Det1;
						tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / Det1;
						tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / Det1;
						tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / Det1;
						tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / Det1;
						return tmp;
					}
				}
			}
			else
			{
				std::cout << "�������� �� ��������������" << std::endl;
			}
		}
		void Matrix::transposition()
		{
			std::swap(m_n, m_m);
			Matrix tmp(m_n, m_m);
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					tmp.m_mat[i][j] = m_mat[j][i];
				}
			}
			m_mat = (double**)malloc(m_n * sizeof(double*));
			for (int i = 0; i < m_n; i++)
			{
				m_mat[i] = (double*)malloc(m_m * sizeof(double));
			}
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					m_mat[i][j] = tmp.m_mat[i][j];
				}
			}
		}
		void Matrix::OutMatrix(int n, int m)

		{
			for (int i = 0; i < n; i++)
			{

				for (int j = 0; j < m; j++)
				{
					std::cout << m_mat[i][j] << "  ";
				}
				std::cout << ("\n");
			}
		}
		void Matrix::OutInverse(int n, int m)

		{

			for (int i = 0; i < n; i++)
			{

				for (int j = n; j < m; j++)
				{
					std::cout << m_mat[i][j] << " ";
				}
				std::cout << "\n";
			}
			return;

		}   
		void Matrix::InverseOfMatrix(int order)
		{
			double temp;
			std::cout << "=== Matrix ===\n";
			OutMatrix(order, order);
			for (int i = 0; i < order; i++)
			{
				for (int j = 0; j < 2 * order; j++)
				{
					if (j == (i + order))
						m_mat[i][j] = 1;
				}
			}
			for (int i = order - 1; i > 0; i--)
			{
				if (m_mat[i - 1][0] < m_mat[i][0])
					for (int j = 0; j < 2 * order; j++)
					{
						temp = m_mat[i][j];
						m_mat[i][j] = m_mat[i - 1][j];
						m_mat[i - 1][j] = temp;
					}
			}
			std::cout << "\n=== Augmented Matrix ===\n";
			OutMatrix(order, order * 2);
			for (int i = 0; i < order; i++)
			{
				for (int j = 0; j < order; j++)
				{
					if (j != i)
					{
						temp = m_mat[j][i] / m_mat[i][i];
						for (int k = 0; k < 2 * order; k++)
						{
							m_mat[j][k] -= m_mat[i][k] * temp;
						}
					}
				}
			}
			for (int i = 0; i < order; i++)
			{
				temp = m_mat[i][i];
				for (int j = 0; j < 2 * order; j++)
				{
					m_mat[i][j] = m_mat[i][j] / temp;
				}
			}
			std::cout << "\n=== Inverse Matrix ===\n";
			OutInverse(order, 2 * order);
		}
		// ����������
		~Matrix()
		{
			std::cout << "Destructor" << std::endl;
			for (int i = 0; i < m_n; i++)
			{
				delete[] m_mat[i];
			}
			delete m_mat;
		}
		friend std::istream& operator>>(std::istream& in, Matrix& mat);
		friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);
	private:
		int m_n, m_m;
		double** m_mat;
	};
	std::istream& operator>>(std::istream& in, Matrix& mat)
	{
		for (int i = 0; i < mat.m_n; i++)
		{
			for (int j = 0; j < mat.m_m; j++)
			{
				in >> mat.m_mat[i][j];
			}
		}
		return in;
	}
	std::ostream& operator<<(std::ostream& out, const Matrix& mat)
	{
		out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
		for (int i = 0; i < mat.m_n; i++)
		{
			for (int j = 0; j < mat.m_m; j++)
			{
				out << mat.m_mat[i][j] << " ";
			}
			out << std::endl;
		}
		return out;
	}
}