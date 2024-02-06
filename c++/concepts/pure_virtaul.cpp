#include<iostream>

class base_class {
    public:
        base_class() {std::cout << "Base constructor" << std::endl;}
        virtual ~base_class() {std::cout << "Base destructor" << std::endl;}
        virtual int calculate_sum(void) = 0;
};

class derived_class : public base_class {
    public:
        derived_class(void) {std::cout << "Derived constructor" << std::endl;}
        ~derived_class() {std::cout << "Derived destructor" << std::endl;}
        int calculate_sum(void) override;
        int calculate_sum(int a, int b) const;

    private:
        int x, y;
};

int derived_class::calculate_sum(int x, int y) const
{
    return x+y;
}

int derived_class::calculate_sum(void) {return 0;}

int main(void)
{
    derived_class *dc = new derived_class(); // can pass parameters
    std::cout << "Sum: " << dc->calculate_sum(4, 5) << std::endl;
    delete dc;
}
