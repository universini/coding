#include<iostream>

class base_class {
    public:
        base_class() {std::cout << "Base constructor" << std::endl;}
        virtual ~base_class() {std::cout << "Base destructor" << std::endl;}
        virtual int get_sum(void) {return 0;}
};

class derived_class : public base_class {
    public:
        derived_class(int a, int b) : x(a), y(b) {std::cout << "Derived constructor" << std::endl;}
        ~derived_class() {std::cout << "Derived destructor" << std::endl;}
        int get_sum(void) { return x+y; }

    private:
        int x, y;
};

int main(void)
{
    derived_class *dc = new derived_class(5,4);
    std::cout << "Sum: " << dc->get_sum() << std::endl;
    delete dc;
}
