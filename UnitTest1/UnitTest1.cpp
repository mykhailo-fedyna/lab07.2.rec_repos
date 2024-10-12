#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Test_SearchMaxInRowRecursive)
		{
			int row[] = { 1, 5, 3, 9, 2 };
			int maxIndex = SearchMaxInRowRecursive(row, 5, 0, 0);
			Assert::AreEqual(3, maxIndex);
		}
		TEST_METHOD(Test_SearchMinInRowRecursive)
		{
			int row[] = { 1, 5, 3, 9, 2 };
			int minIndex = SearchMinInRowRecursive(row, 5, 0, 0);
			Assert::AreEqual(0, minIndex);
		}
		TEST_METHOD(Test_SwapMaxMinRows)
		{
			const int k = 2, n = 5;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			int row1[] = { 1, 5, 3, 9, 2 };
			int row2[] = { 6, 8, 7, 4, 10 };
			for (int i = 0; i < n; i++) {
				a[0][i] = row1[i];
				a[1][i] = row2[i];
			}
			SwapMaxMinRows(a, k, n, 1);
			Assert::AreEqual(10, a[0][0]);
			Assert::AreEqual(1, a[1][4]);
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
