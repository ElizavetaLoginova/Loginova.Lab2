#include <iostream>

using namespace std;

bool IsDataValid(double, int);
double** AllocMemory(int);
void MatrixA(double **, int, double);
double TheElementOfMatrixA(double, int, int);
void MatrixB(double **, int, double);
double TheElementOfMatrixB(double, int, int);
double Sinus(double, double);
double Difference(double, double);
double MaxDifference(double**, int);
void DisplayMatrix(double**, int);
void FreeHeap(double**, int);


int main()
{
	while (true)
	{
		double eps;
		int n;

		while (true)
		{
			cout << "Enter epsilon:" << endl;
			cin >> eps;
			cout << "Enter n - number of lines: " << endl;
			cin >> n;
			system("cls");
			if (IsDataValid(eps, n)) break;
			cout << "Invalid Data" << endl;
			system("cls");
		}

		cout << "The matrix A is: " << endl;
		double **a = AllocMemory(n);
		MatrixA(a, n, eps);
		DisplayMatrix(a, n);

		cout << endl << endl << "The matrix B is: " << endl;
		double **b = AllocMemory(n);
		MatrixB(b, n, eps);
		DisplayMatrix(b, n);

		double **dif = AllocMemory(n);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dif[i][j] = Difference(a[i][j], b[i][j]);

		cout << endl << endl << " The maximum difference is: " << endl << MaxDifference(dif, n);

		system("pause");
		system("cls");

		FreeHeap(a, n);
		FreeHeap(b, n);
		FreeHeap(dif, n);

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

bool IsDataValid(double eps, int n)
{
	if (eps < 0 || eps >= 1) return false;
	if (n < 0 || n >= 258) return false;
	return true;

}

double** AllocMemory(int n)
{
	double **a = new double *[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	return a;
}

double TheElementOfMatrixA(double eps, int i, int j)
{
	double a = 0;
	a = (Sinus(i*j, eps) + i + 1) / ((1 + j)*(1 + j)*(1 + j));
	return a;
}

double TheElementOfMatrixB(double eps, int i, int j)
{
	double b = 0;
	b = (sin(i*j) + i + 1) / ((1 + j)*(1 + j)*(1 + j));
	return b;
}

void MatrixA(double **a, int n, double eps)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (i != j)
			a[i][j] = TheElementOfMatrixA(eps, i, j);
		else
			a[i][j] = i;
	}
}

void MatrixB(double **b, int n, double eps)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (i != j)
			b[i][j] = TheElementOfMatrixB(eps, i, j);
		else
			b[i][j] = i;
	}
}

double Sinus(double x, double eps)
{
	double sum = 0;
	int k = 1;
	double n = x;

	while (fabs(n) > eps)
	{
		sum += n;
		k += 2;
		n *= (-1.0 * x * x) / ((2 * k) * (2 * k + 1));
	}
	return sum;
}

double Difference(double a, double b)
{
	double x;
	x = fabs(a - b);
	return x;
}

double MaxDifference(double **d, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	if (d[i][j] > max)
		max = d[i][j];
	return max;
}

void DisplayMatrix(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(20);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void FreeHeap(double** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}
