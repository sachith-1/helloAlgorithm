average(List numbers) {
  int sum = 0;
  for (int x in numbers) {
    sum += x;
  }
  double avg = sum / numbers.length;
  print(avg);
  return avg;
}

void main() {
  average([2, 8, 6, 90, 60]);
}