#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MYmatrix.h"

struct Point
{
	int x;
	int y;
	int z;

	Point operator+=(const Point p)
	{
		x = x + p.x;
		y = y + p.y;
		z = z + p.z;
		return *this;
	}
};

int main() {

	printf("\nINT TEST:\n");

	// create and fill test m1 matrix
	matrix<int> m_int1(2, 3);

	printf("Matrix m1 random fill\n");
	printf("rows: %d columns: %d\n", m_int1.rows(), m_int1.ñolumns());
	for (size_t i = 0; i < m_int1.rows(); i++)
	{
		for (size_t j = 0; j < m_int1.ñolumns(); j++)
		{
			m_int1.set(i, j, rand() % 10);
			printf("%5d ", m_int1.get(i, j));
		}
		printf("\n");
	}
	printf("\n");

	// test: copy constuctor  - create and fill test m2 matrix
	matrix<int> m_int2(m_int1);

	printf("Matrix m2 copy from m1\n");
	printf("rows: %d columns: %d\n", m_int2.rows(), m_int2.ñolumns());
	for (size_t i = 0; i < m_int2.rows(); i++)
	{
		for (size_t j = 0; j < m_int2.ñolumns(); j++)
		{
			printf("%5d ", m_int2.get(i, j));
		}
		printf("\n");
	}
	printf("\n");

	// test: matrix sum
	matrix<int> m_int3 = m_int1.sum(m_int2);

	printf("Matrix m1 += m2\n");
	printf("rows: %d columns: %d\n", m_int3.rows(), m_int3.ñolumns());
	for (size_t i = 0; i < m_int3.rows(); i++)
	{
		for (size_t j = 0; j < m_int3.ñolumns(); j++)
		{
			printf("%5d ", m_int3.get(i, j));
		}
		printf("\n");
	}
	printf("\n");

	printf("\nEXCEPTION TEST:\n");

	// test exception: get
	try {
		int k = m_int1.get(-1, 1);
	}
	catch (const char* e) {
		printf("%s\n", e);
	}

	// test exception: set
	try {
		m_int1.set(1, 100000, 123);
	}
	catch (const char* e) {
		printf("%s\n", e);
	}

	matrix<int> m_int4(44, 55);
	// test exception: sum
	try {
		m_int2.sum(m_int4);
	}
	catch (const char* e) {
		printf("%s\n", e);
	}

	printf("\nPOINT TEST:\n");

	// create and fill test m1 matrix
	matrix<Point> m_point1(2, 3);
	Point p1;

	printf("Matrix m_point1 random fill\n");
	printf("rows: %d columns: %d\n", m_point1.rows(), m_point1.ñolumns());
	for (size_t i = 0; i < m_point1.rows(); i++)
	{
		for (size_t j = 0; j < m_point1.ñolumns(); j++)
		{
			p1.x = rand() % 10;
			p1.y = rand() % 10;
			p1.z = rand() % 10;

			m_point1.set(i, j, p1);

			p1 = m_point1.get(i, j);

			printf("(%5d,%5d,%5d) ", p1.x, p1.y, p1.z);
		}
		printf("\n");
	}
	printf("\n");

	// test: copy constuctor  - create and fill test m2 matrix
	matrix<Point> m_point2(m_point1);

	printf("Matrix m2 copy from m1\n");
	printf("rows: %d columns: %d\n", m_point2.rows(), m_point2.ñolumns());
	for (size_t i = 0; i < m_point2.rows(); i++)
	{
		for (size_t j = 0; j < m_point2.ñolumns(); j++)
		{
			p1 = m_point1.get(i, j);
			printf("(%5d,%5d,%5d) ", p1.x, p1.y, p1.z);
		}
		printf("\n");
	}
	printf("\n");

	matrix<Point> m_point3(m_point1.sum(m_point2));

	printf("Matrix m1 += m2\n");
	printf("rows: %d columns: %d\n", m_point3.rows(), m_point3.ñolumns());
	for (size_t i = 0; i < m_point1.rows(); i++)
	{
		for (size_t j = 0; j < m_point1.ñolumns(); j++)
		{
			p1 = m_point1.get(i, j);
			printf("(%5d,%5d,%5d) ", p1.x, p1.y, p1.z);
		}
		printf("\n");
	}
	printf("\n");

}
