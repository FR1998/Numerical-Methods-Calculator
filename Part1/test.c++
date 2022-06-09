#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//////////////////            NON LINEAR FUNCTIONS
//#define f(x) cos(x) - x * exp(x)
#define f(x) x *x *x - 2 * x - 5
#define g(x) 3 * x *x - 2

///////////////////////////    LINEAR FUNCTIONS
#define f1(x, y, z) (17 - y + 2 * z) / 20
#define f2(x, y, z) (-18 - 3 * x + z) / 20
#define f3(x, y, z) (25 - 2 * x + 3 * y) / 20

//////////////////////////////   INTEGRATION
#define f4(x) 1 / (1 + pow(x, 2))

////////////////////////////////////// ODL
#define f5(x, y) x + y

int factorial(int n)
{
	int fact = 1;
	while (n)
	{

		fact = fact * n;
		n--;
	}
	return fact;
}
/////////////////////////////////  NON LINEAR FUNCTIONS   ////////////////////////

void bisection()
{
	float x0, x1, x, f0, f1, f, e;
	int step = 1;

	cout << setprecision(6) << fixed;

up:
	cout << "Enter first guess: ";
	cin >> x0;
	cout << "Enter second guess: ";
	cin >> x1;
	cout << "Enter tolerable error: ";
	cin >> e;

	f0 = f(x0);
	f1 = f(x1);

	if (f0 * f1 > 0.0)
	{
		cout << "Incorrect Initial Guesses." << endl;
		goto up;
	}

	cout << endl
		 << "****************" << endl;
	cout << "Bisection Method" << endl;
	cout << "****************" << endl;
	do
	{

		x = (x0 + x1) / 2;
		f = f(x);

		cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

		if (f0 * f < 0)
		{
			x1 = x;
		}
		else
		{
			x0 = x;
		}
		step = step + 1;
	} while (fabs(f) > e);

	cout << endl
		 << " Root = " << x << endl;
}

void NR()
{
	float x, x1, f0, f1, g, e;
	int step = 1, N;

	cout << setprecision(6) << fixed;

	cout << "Enter initial guess: ";
	cin >> x;
	cout << "Enter tolerable error: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	cout << endl
		 << "*********************" << endl;
	cout << "Newton Raphson Method" << endl;
	cout << "*********************" << endl;
	do
	{
		g = g(x);
		f0 = f(x);
		if (g == 0.0)
		{
			cout << "Mathematical Error.";
			exit(0);
		}

		x1 = x - f0 / g;

		cout << "Iteration-" << step << ":\t x = " << setw(10) << x1 << " and f(x) = " << setw(10) << f(x1) << endl;
		x = x1;

		step = step + 1;

		if (step > N)
		{
			cout << "Not Convergent.";
			break;
		}

		f1 = f(x1);

	} while (fabs(f1) > e);

	cout << endl
		 << "Root is: " << x1;
}

void Secant()
{
	float x, x1, x2, f0, f1, f2, e;
	int step = 1, N;

	cout << setprecision(6) << fixed;

	cout << "Enter first guess: ";
	cin >> x;
	cout << "Enter second guess: ";
	cin >> x1;
	cout << "Enter tolerable error: ";
	cin >> e;
	cout << "Enter maximum iteration: ";
	cin >> N;

	cout << endl
		 << "**************" << endl;
	cout << "Secant Method" << endl;
	cout << "**************" << endl;
	do
	{
		f0 = f(x);
		f1 = f(x1);
		if (f0 == f1)
		{
			cout << "Mathematical Error.";
			break;
		}

		x2 = x1 - (x1 - x) * f1 / (f1 - f0);
		f2 = f(x2);

		cout << "Iteration-" << step << ":\t x2 = " << setw(10) << x2 << " and f(x2) = " << setw(10) << f(x2) << endl;

		x = x1;
		f0 = f1;
		x1 = x2;
		f1 = f2;

		step = step + 1;

		if (step > N)
		{
			cout << "Not Convergent.";
			break;
		}
	} while (fabs(f2) > e);

	cout << endl
		 << "Root is: " << x2;
}

void RF()
{

	float x0, x1, x, f0, f1, f, e;
	int step = 1;

	cout << setprecision(6) << fixed;

up:
	cout << "Enter first guess: ";
	cin >> x0;
	cout << "Enter second guess: ";
	cin >> x1;
	cout << "Enter tolerable error: ";
	cin >> e;

	f0 = f(x0);
	f1 = f(x1);

	if (f0 * f1 > 0.0)
	{
		cout << "Incorrect Initial Guesses." << endl;
		goto up;
	}

	cout << endl
		 << "*********************" << endl;
	cout << "False Position Method" << endl;
	cout << "*********************" << endl;
	do
	{

		x = x0 - (x0 - x1) * f0 / (f0 - f1);
		f = f(x);

		cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

		if (f0 * f < 0)
		{
			x1 = x;
			f1 = f;
		}
		else
		{
			x0 = x;
			f0 = f;
		}
		step = step + 1;
	} while (fabs(f) > e);

	cout << endl
		 << "Root is: " << x << endl;
}

void iterative()
{
	int step = 1, N;
	float x, x1, e;

	cout << setprecision(6) << fixed;

	cout << "Enter initial guess: ";
	cin >> x;

	cout << "Enter tolerable error: ";
	cin >> e;

	cout << "Enter maximum iteration: ";
	cin >> N;

	cout << endl
		 << "**************************" << endl;
	cout << "Fixed Point Iteration Method" << endl;
	cout << "**************************" << endl;
	do
	{
		x1 = g(x);
		cout << "Iteration-" << step << ":\t x1 = " << setw(10) << x1 << " and f(x1) = " << setw(10) << f(x1) << endl;

		step = step + 1;

		if (step > N)
		{
			cout << "Not Convergent.";
			break;
		}

		x = x1;

	} while (fabs(f(x1)) > e);

	cout << endl
		 << "Root is " << x1;
}

//////////////////////             LINEAR FUNCTIONS     //////////////////////////////

void Jac()
{
	float x = 0, y = 0, z = 0, x1, y1, z1, e1, e2, e3, e;
	int step = 1;

	cout << setprecision(6) << fixed;

	cout << "Enter tolerable error: ";
	cin >> e;

	cout << endl
		 << "Count\tx\t\ty\t\tz" << endl;
	do
	{

		x1 = f1(x, y, z);
		y1 = f2(x, y, z);
		z1 = f3(x, y, z);
		cout << step << "\t" << x1 << "\t" << y1 << "\t" << z1 << endl;

		e1 = fabs(x - x1);
		e2 = fabs(y - y1);
		e3 = fabs(z - z1);

		step++;

		x = x1;
		y = y1;
		z = z1;
	} while (e1 > e && e2 > e && e3 > e);

	cout << endl
		 << "Solution: x = " << x1 << ", y = " << y1 << " and z = " << z1;
}

void GS()
{
	float x = 0, y = 0, z = 0, x1, y1, z1, e1, e2, e3, e;
	int step = 1;

	cout << setprecision(6) << fixed;

	cout << "Enter tolerable error: ";
	cin >> e;

	cout << endl
		 << "Count\tx\t\ty\t\tz" << endl;

	do
	{

		x1 = f1(x, y, z);
		y1 = f2(x1, y, z);
		z1 = f3(x1, y1, z);

		cout << step << "\t" << x1 << "\t" << y1 << "\t" << z1 << endl;

		e1 = fabs(x - x1);
		e2 = fabs(y - y1);
		e3 = fabs(z - z1);

		step++;

		x = x1;
		y = y1;
		z = z1;

	} while (e1 > e && e2 > e && e3 > e);

	cout << endl
		 << "Solution: x = " << x1 << ", y = " << y1 << " and z = " << z1;
}

////////////////////////////////     INTEGRATION     /////////////////////////////

void Trap()
{
	float LowLim, UpLim, Integrate = 0.0, stepSize, k;
	int i, subInterval;

	cout << "Enter lower limit of Integration: ";
	cin >> LowLim;
	cout << "Enter upper limit of integration: ";
	cin >> UpLim;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	stepSize = (UpLim - LowLim) / subInterval;

	Integrate = f4(LowLim) + f4(UpLim);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = LowLim + i * stepSize;
		Integrate = Integrate + 2 * (f4(k));
	}

	Integrate = Integrate * stepSize / 2;

	cout << endl
		 << "Required value of integration is: " << Integrate;
}

////////////////////////              INTERPOLATION      ////////////////////////////////

void NF()
{
	float x[10], y[20][20], p[10], diff[10];
	float X, f, f2 = 0, u, h;
	int i, j = 1, n, k = 1;
	cout << "Enter the number of observations: ";
	cin >> n;
	cout << "\nEnter the values of xi's and f(xi's)\n";
	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "]: ";
		cin >> x[i];
		cout << "f[" << i << "]: ";
		cin >> y[i][0];
	}

	cout << "\nx[i's]\tf[i's]\n";
	for (i = 1; i <= n; i++)
	{
		cout << x[i] << "\t" << y[i] << "\n";
	}
	cout << "\nEnter the value of x at which you want to interpolate: ";
	cin >> X;
	int m = n;
	h = x[2] - x[1];
	u = (X - x[1]) / h;

	f = y[1][0];
	cout << fixed << setprecision(2);
	cout << "Forward Difference table for the given set of points is\n";
	do
	{
		cout << "diff.(" << j++ << ") f(x)\n";
		for (i = 1; i < n; i++)
		{
			p[i] = ((y[i + 1] - y[i]));
			cout << p[i] << "\n";
			y[i][j] = p[i];
		}
		diff[k++] = p[1];
		n--;
		cout << "\n";
	} while (n != 1);

	float df = u;
	float l = 1;
	for (int i = 1; i < m; i++)
	{
		if (i > 1)
			df = df / factorial(i);

		f2 = f2 + (df * diff[i]);
		for (int j = 0; j <= i; j++)
		{
			l = l * (u - j);
		}
		df = l;
	}
	f = f + f2;
	cout << "\nf(" << X << ") = " << f;
}

void NB()
{
	float x[20], y[20][20];
	int i, j, n;

	cout << "Enter number of data : " << endl;
	cin >> n;

	cout << "Enter data: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i][0];
	}

	for (i = 1; i < n; i++)
	{
		for (j = n - 1; j > i - 1; j--)
		{
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
		}
	}

	cout << endl
		 << "BACKWARD DIFFERENCE TABLE" << endl;

	for (i = 0; i < n; i++)
	{
		cout << x[i];
		for (j = 0; j <= i; j++)
		{
			cout << "\t" << y[i][j];
		}
		cout << endl;
	}
}

//////////////////////////           DIFFERENTITATION      /////////////////////////////////

void NFD()
{
	float x[20], y[20][20], xp, h, sum = 0.0, term, first_der;
	int i, j, n, ind_temp, flag = 0, sign = 1;

	cout << "Enter number of data: ";
	cin >> n;

	cout << "Enter data: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i][0];
	}

	cout << "Enter at what value of x you want to calculate derivative: ";
	cin >> xp;
	for (i = 0; i < n; i++)
	{
		if (fabs(xp - x[i]) < 0.0001)
		{

			ind_temp = i;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "Invalid calculation point. Program exiting...";
		exit(0);
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
		}
	}

	h = x[1] - x[0];

	for (i = 1; i < n - ind_temp; i++)
	{
		term = pow(y[ind_temp][i], i) / i;
		sum = sum + sign * term;
		sign = -sign;
	}

	first_der = sum / h;

	cout << "First derivative at x = " << xp << "  "
		 << "is"
		 << "  " << first_der;
}

void NBD()
{
	float x[20], y[20][20], xp, h, sum = 0.0, first_der, term;
	int i, j, n, ind_temp, flag = 0;

	cout << "Enter number of data: ";
	cin >> n;

	cout << "Enter data: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i][0];
	}

	cout << "Enter at what value of x you want to calculate derivative: ";
	cin >> xp;

	for (i = 0; i < n; i++)
	{
		if (fabs(xp - x[i]) < 0.0001)
		{
			ind_temp = i;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "Invalid calculation point. Program exiting...";
		exit(0);
	}

	for (i = 1; i < n; i++)
	{
		for (j = n - 1; j > i - 1; j--)
		{
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
		}
	}

	h = x[1] - x[0];

	for (i = 1; i <= ind_temp; i++)
	{
		term = pow(y[ind_temp][i], i) / i;
		sum = sum + term;
	}

	first_der = sum / h;

	cout << "First derivative at x = " << xp << "  "
		 << "is"
		 << "  " << first_der;
}
//////////////////////////     ODL      ///////////////////////////////////

void Eular()
{
	float x, y, xn, h, yn, FuncSlope;
	int i, n;

	cout << "Enter Initial Condition" << endl;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "Enter calculation point xn = ";
	cin >> xn;
	cout << "Enter number of steps: ";
	cin >> n;

	h = (xn - x) / n;

	cout << "\nx\ty\tSlope\tyn\n";
	cout << "------------------------------\n";

	for (i = 0; i < n; i++)
	{
		FuncSlope = f5(x, y);
		yn = y + h * FuncSlope;
		cout << x << "\t" << y << "\t" << FuncSlope << "\t" << yn << endl;
		y = yn;
		x = x + h;
	}

	cout << "\nValue of y at x = " << xn << " is " << yn;
}

int main()
{
	int choice1;
	int choice2;

	while (true)
	{
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------";
		cout << endl;
		cout << endl;
		cout << "          ***********************"
			 << " Numerical Methods "
			 << "**************************" << endl;
		cout << "                  ******************************************************";
		cout << endl;
		cout << endl;

		cout << "Please pick one option:" << endl;
		cout << "1. Non - Linear." << endl;
		cout << "2. Linear." << endl;
		cout << "3. Integration." << endl;
		cout << "4. Interpolation." << endl;
		cout << "5. Differentitation." << endl;
		cout << "6. ODL." << endl;
		cout << "7. Exit" << endl;
		cout << "Press Key to enter your option : ";
		cin >> choice1;
		system("cls");

		switch (choice1)
		{
		case 1:
			cout << "Please select the method:" << endl;
			cout << "1. Bisection." << endl;
			cout << "2. Newton Raphson." << endl;
			cout << "3. Secant." << endl;
			cout << "4. Regular Falsi." << endl;
			cout << "5. Iterative. " << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				bisection();
				continue;
			case 2:
				NR();
				continue;
			case 3:
				Secant();
				continue;
			case 4:
				RF();
				continue;
			case 5:
				iterative();
				continue;
			}

			continue;

		case 2:
		{
			cout << "Please select the method:" << endl;
			cout << "1. Jacobi Iteration." << endl;
			cout << "2. Gauss Seidel Iteration." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				Jac();
				continue;
			case 2:
				GS();
				continue;
			}
			continue;
		}

		case 3:
		{

			cout << "Please select the method:" << endl;
			cout << "1. Trapezoidal Rule." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				Trap();
				continue;
			}
			continue;
		}

		case 4:
		{
			cout << "Please select the method:" << endl;
			cout << "1. Newton Forward." << endl;
			cout << "2. Newton Backword." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				NF();
				continue;
			case 2:
				NB();
				continue;
			}

			continue;
		}

		case 5:
		{
			cout << "Please select the method:" << endl;
			cout << "1. Newton Forward Differentitation." << endl;
			cout << "2. Newton Backword Differentitation." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				NFD();
				continue;
			case 2:
				NBD();
				continue;
			}

			continue;
		}

		case 6:
		{
			cout << "Please select the method:" << endl;
			cout << "1. Euler Rule." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				Eular();
				continue;
			}
			continue;
		}

		case 7:
			cout << "Thank You!" << endl;
			break;
		}
		::exit(0);
	}
	return 0;
}
