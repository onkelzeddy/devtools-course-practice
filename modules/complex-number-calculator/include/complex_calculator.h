// Copyright 2023 Elistratov Vladimir

#ifndef MODULES_COMPLEX_NUMBER_CALCULATOR_INCLUDE_COMPLEX_CALCULATOR_H_
#define MODULES_COMPLEX_NUMBER_CALCULATOR_INCLUDE_COMPLEX_CALCULATOR_H_

class ComplexNumber {
 public:
  ComplexNumber();
  ComplexNumber(const double real, const double imag);
  ComplexNumber(const ComplexNumber& z);
  ComplexNumber& operator=(const ComplexNumber& z);
  double getRe() const;
  double getIm() const;
  void setRe(const double real);
  void setIm(const double imag);
  ComplexNumber operator+(const ComplexNumber& z) const;
  ComplexNumber operator-(const ComplexNumber& z) const;
  ComplexNumber operator*(const ComplexNumber& z) const;
  ComplexNumber operator/(const ComplexNumber& z) const;
  bool operator==(const ComplexNumber& z) const;
  bool operator!=(const ComplexNumber& z) const;
  double magnitude() const;
  double argument() const;

 private:
  bool equalsZero(const ComplexNumber& z) const;
  double real_;
  double imaginary_;
};

#endif  // MODULES_COMPLEX_NUMBER_CALCULATOR_INCLUDE_COMPLEX_CALCULATOR_H_
