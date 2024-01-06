#include <iostream>

using namespace std;

double celsiusToFahrenheit(double celsius);

double fahrenheitToCelsius(double fahrenheit);

double celsiusToKelvin(double celsius);

double kelvinToCelsius(double kelvin);

void showConvertedTemperature(double temperature);

int main()
{
    int choice;
    double temperature, convertedTemperature;

    cout << "Temperature Converter" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Celsius to Kelvin" << endl;
    cout << "4. Kelvin to Celsius" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "Enter the temperature: ";
    cin >> temperature;

    switch (choice)
    {
    case 1:
        showConvertedTemperature(celsiusToFahrenheit(temperature));
        break;
    case 2:
        showConvertedTemperature(fahrenheitToCelsius(temperature));
        break;
    case 3:
        showConvertedTemperature(celsiusToKelvin(temperature));
        break;
    case 4:
        showConvertedTemperature(kelvinToCelsius(temperature));
        break;
    default:
        break;
    }

    return 0;
}

double celsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsiusToKelvin(double celsius)
{
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}

void showConvertedTemperature(double temperature)
{
    cout << "The converted temperature is: " << temperature;
}