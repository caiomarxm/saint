/*
 * This module defines the basic structure for an elementary function
 *
 * Current version: 0.0.1 (alpha)
 * Only supports polynomials
 * */
#include <iostream>
#include <ostream>

typedef struct monom {
  int exponent;
  float coefficient;
} monom;

class ElementaryFunction
{
public:
  ElementaryFunction(unsigned int degree);
  ElementaryFunction(ElementaryFunction &&) = default;
  ElementaryFunction(const ElementaryFunction &) = default;
  ElementaryFunction &operator=(ElementaryFunction &&) = default;
  ElementaryFunction &operator=(const ElementaryFunction &) = default;
  ~ElementaryFunction();
  void Display();
  void FillPolynom(float *coefficients);
  char Type; // 'p' stands for polynomial function

private:
  unsigned int degree;
  monom *monomArray;
};

ElementaryFunction::ElementaryFunction(unsigned int degree)
{
  this->Type = 'p';
  this->degree = degree;
  this->monomArray = new monom[degree+1];
  for (unsigned int i = 0; i <= degree; i++) {
    this->monomArray[i].exponent = i;
    this->monomArray[i].coefficient = 0;
  }
}

ElementaryFunction::~ElementaryFunction()
{
  delete this->monomArray;
}

void ElementaryFunction::Display()
{
  for (int i = this->degree; i >= 0; i--) {
    std::cout << "(" << this->monomArray[i].coefficient << ")";
    if (i != 0) {
      std::cout << "*" << "x^" << this->monomArray[i].exponent;
      std::cout << "+";
    }
  }
  std::cout << std::endl;
}

void ElementaryFunction::FillPolynom(float *coefficients)
{
  for (int i = this->degree; i >= 0; i--) {
    this->monomArray[3-i].coefficient = coefficients[i];
  }
}

