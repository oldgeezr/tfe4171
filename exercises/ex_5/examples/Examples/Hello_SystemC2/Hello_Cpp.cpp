#include <iostream>
struct Hello_Cpp {
  void main_method(void) {
    std::cout << "Hello C++" << std::endl;
  }
};
int main(int argc, char* argv[]) {
  Hello_Cpp iHello_Cpp;
  iHello_Cpp.main_method();
  return 0;
}
