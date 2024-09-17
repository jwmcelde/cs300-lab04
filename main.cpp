#include "stack.h"
#include <iostream>

int main() {
  Stack s;

  std::cout << "pop: " << s.pop() << std::endl;
  std::cout << "peak: " << s.peak() << std::endl;

  s.push(10);
  s.push(45);
  s.push(300);
  s.push(5);

  std::cout << "pop: " << s.pop() << std::endl;
  std::cout << "peak: " << s.peak() << std::endl;
  std::cout << "pop: " << s.pop() << std::endl;
  std::cout << "pop: " << s.pop() << std::endl;

  s.removeAll();

  std::cout << "pop: " << s.pop() << std::endl;
  std::cout << "peak: " << s.peak() << std::endl;
  return 0;
}
