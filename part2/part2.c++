#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

////////////////           Declared Functions       ///////////////////////

//   INTEGRATION
#define f4(x) 1 / (1 + pow(x, 2))

// ODL
#define f(x, y) (y * y - x * x) / (y * y + x * x)

// FOR BESSELS
float BesselCall(float u, int n)
{
	if (n == 0)
		return 1;
	float result = u;
	for (int i = 1; i <= n / 2; i++)
		result = result * (u - i);
	for (int i = 1; i < n / 2; i++)
		result = result * (u + i);
	return result;
}

int factorial(int n)
{
	int fact = 1;
	while (n == 1)
	{

		fact = fact * n;
		n--;
	}
	return fact;
}
////////////////      INTERPOLATION EQUALLY SPACED     //////////////////////////

void GF()
{
	int n, i, j;
	float x1[10];
	float ay1[10];
	float x;
	float nr, dr;
	float y = 0;
	float h;
	float p;
	float diff[20][20];
	float y1, y2, y3, y4;

	system("cls");

	cout << "\nEnter the no. of terms : ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "\n Enter the value of x" << i + 1 << " = ";
		cin >> x1[i];
	}

	cout << "\n Now enter the value in the form of y " << endl;

	for (i = 0; i < n; i++)
	{
		cout << "\n Enter the value of y" << i + 1 << " = ";
		cin >> ay1[i];
	}

	cout << "\n\n Enter the value of x for which u want the value of y = ";
	cin >> x;

	h = x1[1] - x1[0];
	for (i = 0; i < n - 1; i++)
		diff[i][1] = ay1[i + 1] - ay1[i];

	for (j = 2; j <= 4; j++)
		for (i = 0; i < n - j; i++)
			diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

	i = 0;
	do
	{
		i++;
	} while (x1[i] < x);

	i--;
	p = (x - x1[i]) / h;
	y1 = p * diff[i][1];
	y2 = p * (p - 1) * diff[i - 1][2] / 2;
	y3 = (p + 1) * p * (p - 1) * diff[i - 2][3] / 6;
	y4 = (p + 1) * p * (p - 1) * (p - 2) * diff[i - 3][4] / 24;

	y = ay1[i] + y1 + y2 + y3 + y4;

	cout << " At " << x << "\t\t"
		 << "Value is : " << y;

	getch();
}

void GB()
{
	int n;
	int i, j;
	float ax[10];
	float ay[10];
	float x;
	float y = 0;
	float h;
	float p;
	float diff[20][20];
	float y1, y2, y3, y4;

	system("cls");

	cout << "\n\n Enter the no. of terms = ";
	cin >> n;

	cout << "\n\n Enter the value in the form of x " << endl;

	for (i = 0; i < n; i++)
	{
		cout << "\n Enter the value of x -> " << i + 1;
		cin >> ax[i];
	}

	cout << "\n\n Enter the value in the form of y " << endl;

	for (i = 0; i < n; i++)
	{
		cout << "\n Enter the value of y -> " << i + 1;
		cin >> ay[i];
	}

	cout << "\n\n Enter the value of x for which u want the value of y = ";
	cin >> x;

	h = ax[1] - ax[0];
	for (i = 0; i < n - 1; i++)
		diff[i][1] = ay[i + 1] - ay[i];

	for (j = 2; j <= 4; j++)
		for (i = 0; i < n - j; i++)
			diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

	i = 0;
	do
	{
		i++;
	} while (ax[i] < x);

	i--;
	p = (x - ax[i]) / h;
	y1 = p * diff[i - 1][1];
	y2 = p * (p + 1) * diff[i - 1][2] / 2;
	y3 = (p + 1) * p * (p - 1) * diff[i - 2][3] / 6;
	y4 = (p + 2) * (p + 1) * p * (p - 1) * diff[i - 3][4] / 24;

	y = ay[i] + y1 + y2 + y3 + y4;

	cout << " At " << x << "\t\t"
		 << "Value is : " << y;

	cout << "\n\n\n\t\t\t !! PRESS ENTER TO EXIT !! ";
	getch();
}

void bes()
{
	float x[20], y[20][20];
	float value;
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
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	cout << "Enter interpolation point: ";
	cin >> value;

	float sum = (y[2][0] + y[3][0]) / 2;
	int index;
	if (n % 2)
		index = n / 2;
	else
		index = n / 2 - 1;
	float u = (value - x[index]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++)
	{
		if (i % 2)
			sum += (((u - (0.5)) * BesselCall(u, i - 1) * y[index][i]) / factorial(i));
		else
			sum += ((BesselCall(u, i) * (y[index][i] + y[--index][i]) / (factorial(i) * 2)));
	}
	cout << "Value at " << value << " found using Bessels's interpolation is " << sum;
}

////////////////               INTERPOLATION FOR UNEQUAL SPACES        /////////////////////////

void Lag()
{
	float x[100], y[100], xp, yp = 0, p;
	int i, j, n;

	cout << "Enter number of data: ";
	cin >> n;
	cout << "Enter data:" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i];
	}
	cout << "Enter interpolation point: ";
	cin >> xp;

	for (i = 1; i <= n; i++)
	{
		p = 1;
		for (j = 1; j <= n; j++)
		{
			if (i != j)
			{
				p = p * (xp - x[j]) / (x[i] - x[j]);
			}
		}
		yp = yp + p * y[i];
	}
	cout << endl
		 << "Interpolated value at " << xp << " is " << yp;
}

//////////////////////////////     INTEGRATION    ///////////////////////////////

void Trap()
{
	float lowLim, upLim, integration = 0.0, stepSize, k;
	int i, subInterval;

	cout << "Enter lower limit of integration: ";
	cin >> lowLim;
	cout << "Enter upper limit of integration: ";
	cin >> upLim;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	stepSize = (upLim - lowLim) / subInterval;

	integration = f4(lowLim) + f4(upLim);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = lowLim + i * stepSize;
		integration = integration + 2 * (f4(k));
	}

	integration = integration * stepSize / 2;

	cout << endl
		 << "Required value of integration is: " << integration;
}

void Sim1()
{
	float lowLim, upLim, integration = 0.0, stepSize, k;
	int i, subInterval;

	cout << "Enter lower limit of integration: ";
	cin >> lowLim;
	cout << "Enter upper limit of integration: ";
	cin >> upLim;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	stepSize = (upLim - lowLim) / subInterval;

	integration = f4(lowLim) + f4(upLim);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = lowLim + i * stepSize;

		if (i % 2 == 0)
		{
			integration = integration + 2 * (f4(k));
		}
		else
		{
			integration = integration + 4 * (f4(k));
		}
	}

	integration = integration * stepSize / 3;

	cout << endl
		 << "Required value of integration is: " << integration;
}

void Sim3()
{
	float lowLim, upLim, integration = 0.0, stepSize, k;
	int i, subInterval;

	cout << "Enter lower limit of integration: ";
	cin >> lowLim;
	cout << "Enter upper limit of integration: ";
	cin >> upLim;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	stepSize = (upLim - lowLim) / subInterval;

	integration = f4(lowLim) + f4(upLim);

	for (i = 1; i <= subInterval - 1; i++)
	{
		k = lowLim + i * stepSize;

		if (i % 3 == 0)
		{
			integration = integration + 2 * (f4(k));
		}
		else
		{
			integration = integration + 3 * (f4(k));
		}
	}

	integration = integration * stepSize * 3.0 / 8.0;

	cout << endl
		 << "Required value of integration is: " << integration;
}

//////////////////////////     ODL   //////////////////////////////////

void RK()
{
	float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
	int i, n;

	cout << "Enter Initial Condition" << endl;
	cout << "x0 = ";
	cin >> x0;
	cout << "y0 = ";
	cin >> y0;
	cout << "Enter calculation point xn = ";
	cin >> xn;
	cout << "Enter number of steps: ";
	cin >> n;

	h = (xn - x0) / n;

	cout << "\nx0\ty0\tyn\n";
	cout << "------------------\n";
	for (i = 0; i < n; i++)
	{
		k1 = h * (f(x0, y0));
		k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
		k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
		k4 = h * (f((x0 + h), (y0 + k3)));
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		yn = y0 + k;
		cout << x0 << "\t" << y0 << "\t" << yn << endl;
		x0 = x0 + h;
		y0 = yn;
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
		cout << "1. Interpolation equally spaced." << endl;
		cout << "2. Interpolation un-equally spaced." << endl;
		cout << "3. Integration." << endl;
		cout << "4. ODL." << endl;
		cout << "5. Exit" << endl;
		cout << "Press Key to enter your option : ";
		cin >> choice1;
		system("cls");

		switch (choice1)
		{
		case 1:
			cout << "Please select the method:" << endl;
			cout << "1. Guass Forward." << endl;
			cout << "2. Guass Backward." << endl;
			cout << "3. Bessels." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				GF();
				continue;
			case 2:
				GB();
				continue;
			case 3:
				bes();
				continue;
			}

			continue;

		case 2:
		{
			cout << "Please select the method:" << endl;
			cout << "1. Lagrange." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				Lag();
				continue;
			}
			continue;
		}

		case 3:
		{

			cout << "Please select the method:" << endl;
			cout << "1. Trapezoidal Rule." << endl;
			cout << "2. Simpson 1/3." << endl;
			cout << "3. Simpson 3/8." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				Trap();
				continue;
			case 2:
				Sim1();
				continue;
			case 3:
				Sim3();
				continue;
			}
			continue;
		}

		case 4:
		{
			cout << "Please select the method:" << endl;
			cout << "1. Runge Kutta Method." << endl;
			cout << "Press Key to select your method : ";
			cin >> choice2;
			system("cls");

			switch (choice2)
			{
			case 1:
				RK();
				continue;
			}
			continue;
		}

		case 5:
			cout << "Thank You!" << endl;
			break;
		}
		::exit(0);
	}
	return 0;
}
