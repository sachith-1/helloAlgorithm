int calculateFactorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * calculateFactorial(n - 1);
  }
}

void main() {
  int number = 5; // You can change this number to any value you want.
  int factorial = calculateFactorial(number);
  print("The factorial of $number is $factorial");
}
