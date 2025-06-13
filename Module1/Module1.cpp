// Module1.cpp : Defines the entry point for the application.
//

#include "Module1.h"
#include <format>

using namespace std;

float convertToFahrenheit(float celsius)
{
	return (celsius * 9.0 / 5.0) + 32;
}

float convertToCelsius(float fahrenheit)
{
	return (fahrenheit - 32) * 5.0 / 9.0;
}

float getTemperature(char choice)
{
	float temp = 0.0f;

	if (choice == 'f')
	{
		cout << "Enter temperature in Celsius: ";
		cin >> temp;
	}
	else if (choice == 'c')
	{
		cout << "Enter temperature in Fahrenheit: ";
		cin >> temp;
	}
	else
	{
		return 0.0f;
	}

	return temp;
}

void formatOutput(float temp, char choice)
{
	cout << format("Converted temperature: {:.1f} {}", temp, choice) << endl;
}

int main()
{
	char choice = 0;
	float temperature = 0.0f;


	while (choice != 'f' && choice != 'c' && choice != 'q')
	{
		cout << "----- Temperature Converter -----" << endl;
		cout << "Convert to...[f/c] | [q]uit: ";
		cin >> choice;

		switch (choice)
		{
			case 'f':
				temperature = convertToFahrenheit(getTemperature(choice));
				formatOutput(temperature, choice);
				break;

			case 'c':
				temperature = convertToCelsius(getTemperature(choice));
				formatOutput(temperature, choice);
				break;

			default:
				system("cls");
				break;
		}
	}

	cout << "Fun fact: " << temperature << " in Kelvin is : " << temperature + 273.15f << " K" << endl;

	return 0;
}
