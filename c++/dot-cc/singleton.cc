#include <iostream>

namespace singleton {
class ston {
  static ston* inst;
  std::string name;

 public:
  static ston* get_instance();
  void set_name(std::string n) { name = n; }
  std::string get_name(void) { return name; }
};
}  // namespace singleton

singleton::ston* singleton::ston::inst = nullptr;

singleton::ston* singleton::ston::get_instance() {
  if (inst == nullptr) {
    inst = new singleton::ston();
  }

  return inst;
}

void some_func(void) {
  std::string name{"Nidagatta"};
  singleton::ston* s = s->get_instance();
  if (s == nullptr) {
    std::cout << "singleton is nullptr" << std::endl;
  } else {
    std::cout << "singleton data before (in some_func) : " << s->get_name() << std::endl;
    s->set_name(name);
    std::cout << "singleton data after (in some_func) : " << s->get_name() << std::endl;
  }
}

int main(void) {
  std::string name{"Sidde Gowda"};
  singleton::ston* s = s->get_instance();
  if (s == nullptr) {
    std::cout << "singleton is nullptr" << std::endl;
  } else {
    s->set_name(name);
    some_func();
    std::cout << "singleton data : " << s->get_name() << std::endl;
  }

  return 0;
}
