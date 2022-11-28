#ifndef ELEMENTARY_FUNCTION_H
#define ELEMENTARY_FUNCTION_H

typedef struct polynom {
  int exponent;
  float coefficient;
} polynom;

class ElementaryFunction
{
public:
  ElementaryFunction(unsigned int degree);
  ElementaryFunction(ElementaryFunction &&) = default;
  ElementaryFunction(const ElementaryFunction &) = default;
  ElementaryFunction &operator=(ElementaryFunction &&) = default;
  ElementaryFunction &operator=(const ElementaryFunction &) = default;
  ~ElementaryFunction();
  void FillPolynom(float *coefficients);
  void Display();
  char Type; // 'p' stands for polynomial function

private:
  unsigned int degree;
  polynom *monomArray;
};

#endif // !ELEMENTARY_FUNCTION_H
