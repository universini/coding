#include <iostream>
#include <memory>

// A design without factory pattern
#include <iostream>
using namespace std;

// Factory Method is a creational design pattern that provides an interface for
// creating objects in a superclass, but allows subclasses to alter the type of
// objects that will be created. Factory method simply as a function that takes
// care of the creation of class objects while abstracting the implementation details.
class Battleship {
public:
    Battleship() {
        std::cout << "Battleship Created" << std::endl;
    }
    virtual void Fire() = 0;
    virtual void Steer() = 0;
};

class Destroyer : public Battleship {
public:
    Destroyer(){
        std::cout << "Destroyer Created" << std::endl;
    }
    void Fire() override {
        std::cout << "Destoryer Fire" << std::endl;
    }
    void Steer() override {
        std::cout << "Destroyer Steer" << std::endl;
    }
};

class Carrier : public Battleship {
public:
    Carrier(){
        std::cout << "Carrier Created" << std::endl;
    }
    void Fire() override {
        std::cout << "Carrier Fire" << std::endl;
    }
    void Steer() override {
        std::cout << "Carrier Steer" << std::endl;
    }
};

enum class ShipType{
    Destroyer,
    Carrier,
};

Battleship* CreateShipFactory(ShipType type){
    Battleship* pShip = nullptr;
    if(type == ShipType::Carrier) {
        pShip = new Carrier();
    }
    else if(type == ShipType::Destroyer) {
        pShip = new Destroyer();
    }
    return pShip;
}

int main() {
    Battleship* d = CreateShipFactory(ShipType::Destroyer);
    Battleship* c = CreateShipFactory(ShipType::Carrier);
    d->Fire();
    c->Fire();
    return 0;
}

/////////////////////////////////////////////////////////////////
// Library classes
class Vehicle {
public:
	virtual void printVehicle() = 0;
};
class TwoWheeler : public Vehicle {
public:
	void printVehicle()
	{
		cout << "I am two wheeler" << endl;
	}
};
class FourWheeler : public Vehicle {
public:
	void printVehicle()
	{
		cout << "I am four wheeler" << endl;
	}
};

// Client (or user) class
class Client {
public:
	Client(int type)
	{

		// Client explicitly creates classes according to
		// type
		if (type == 1)
			pVehicle = new TwoWheeler();
		else if (type == 2)
			pVehicle = new FourWheeler();
		else
			pVehicle = NULL;
	}

	~Client()
	{
		if (pVehicle) {
			delete pVehicle;
			pVehicle = NULL;
		}
	}

	Vehicle* getVehicle() { return pVehicle; }

private:
	Vehicle* pVehicle;
};

// Driver program
int main()
{
	Client* pClient = new Client(1);
	Vehicle* pVehicle = pClient->getVehicle();
	pVehicle->printVehicle();
	return 0;
}

/////////////////////////////////////////////////////////

// Abstract Product
class Product {
public:
    virtual void operation() = 0;
    virtual ~Product() {}
};

// Concrete Products
class ConcreteProduct1 : public Product {
public:
    void operation() override {
        std::cout << "Operation of ConcreteProduct1" << std::endl;
    }
};

class ConcreteProduct2 : public Product {
public:
    void operation() override {
        std::cout << "Operation of ConcreteProduct2" << std::endl;
    }
};

// Abstract Factory
class Factory {
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
    virtual ~Factory() {}
};

// Concrete Factories
class ConcreteFactory1 : public Factory {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProduct1>();
    }
};

class ConcreteFactory2 : public Factory {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProduct2>();
    }
};

int main() {
    // Create a factory object
    std::unique_ptr<Factory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<Factory> factory2 = std::make_unique<ConcreteFactory2>();

    // Use the factory to create products
    std::unique_ptr<Product> product1 = factory1->createProduct();
    std::unique_ptr<Product> product2 = factory2->createProduct();

    // Use the products
    product1->operation();
    product2->operation();

    return 0;
}
