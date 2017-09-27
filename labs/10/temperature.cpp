#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature() {
    kelvin_ = 0;
}

Temperature::Temperature(double kelvin) {
    kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
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
