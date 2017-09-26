#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature() {
    kelvin_ = 0;
}

Temperature::Temperature(double kelvin) {
    kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
/*
   * Constructor #3.
   * Converts the supplied temperature to kelvin and internally stores it.
   * The temperature's unit will be provided in the second argument.
   * If the second argument is not value (i.e. not 'F' or 'C') assume the
   * temperature is in kelvin
   * @param double temp - The value to set the internal kelvin to once
   *                    - converted.
   * @param char unit - The type of unit temp is. Will be either 'F' or 'C',
   *                    case-insensitive
   */
  if (unit== 'f' || unit == 'F') {
    SetTempFromFahrenheit(temp);
  } else if (unit == 'c' || unit == 'C') {
    SetTempFromCelsius(temp);
  } else {
    SetTempFromKelvin(temp);
  }
}
void Temperature::SetTempFromKelvin(double kelvin) {
  kelvin_= kelvin;
}

void Temperature::SetTempFromCelsius(double celsius) {
  kelvin_ = celsius + 273.15;
}
void Temperature::SetTempFromFahrenheit(double fahrenheit) {
  kelvin_ = (((5.0 * (fahrenheit - 32)) / 9) + 273.15);
}
double Temperature::GetTempAsKelvin() const {
  return kelvin_;
}
double Temperature::GetTempAsCelsius() const {
  double tempC;
  tempC = GetTempAsKelvin() - 273.15;
  return tempC;
}
double Temperature::GetTempAsFahrenheit() const {
  double tempF;
  tempF = (((GetTempAsCelsius() * 9.0) / 5) + 32);
  return tempF;
}
string Temperature::ToString(char unit) const {
    /*
   * Get a string representation of the temperature.
   * The string will be formatted as:
   * "TEMP UNIT"
   * where TEMP is the temperature to 2 decimal places and UNIT is either
   * "Kelvin", "Celsius", or "Fahrenheit".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, set the string to:
   * "Invalid Unit"
   * @uses stringstream
   * @param char unit - The conversion to perform, either 'K', 'C' or 'F',
   *                    defaults to 'K' and is case-insensitive
   * @return string - A string representation of the temperature or invalid if
   *                  the provided unit is not recognized
   */
  stringstream ss;
  ss.setf(std::ios::fixed|std::ios::showpoint);
  ss.precision(2);
  if (unit =='F' || unit == 'f') {
    ss << GetTempAsFahrenheit()  <<  " Fahrenheit";
    return ss.str();
  } else if (unit =='C' || unit == 'c') {
    ss <<  GetTempAsCelsius() << " Celsius";
    return ss.str();
  } else if (unit =='K' || unit == 'k') {
    ss <<  GetTempAsKelvin() << " Kelvin";
    return ss.str();
  } else {
    ss << "Invalid Unit";
    return ss.str();
  }
ss.unsetf(std::ios::floatfield);
return 0;
}
