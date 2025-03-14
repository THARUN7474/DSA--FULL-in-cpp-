Object-Oriented Programming (OOP) is a programming paradigm based on the concept of **"objects"** that contain both **data** (attributes) and **methods** (functions). It provides a structured and modular approach to building programs.

Let’s explore **OOP from basics to advanced concepts** step-by-step:

---

## **1. Basics of OOP**

### **1.1 Class and Object**
- **Class**: A blueprint or template for creating objects.
- **Object**: An instance of a class.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

class Car {  // Class declaration
public:
    string brand;    // Attribute
    int speed;       // Attribute

    void drive() {   // Method
        cout << brand << " is driving at " << speed << " km/h." << endl;
    }
};

int main() {
    Car myCar;         // Create an object of the Car class
    myCar.brand = "BMW"; // Set attributes
    myCar.speed = 120;
    myCar.drive();       // Call the method
    return 0;
}
```

### Key Points:
- `myCar` is an **object** of the class `Car`.
- **Attributes** (`brand`, `speed`) store data.
- **Methods** (`drive()`) perform actions.

---

## **2. Key Principles of OOP**

### **2.1 Encapsulation**
Encapsulation is the bundling of data and methods into a single unit (class) while restricting direct access to some of the object's components.

#### Code Example:
```cpp
class BankAccount {
private:
    double balance;  // Private: Cannot be accessed directly

public:
    void deposit(double amount) {  // Public method to modify balance
        balance += amount;
    }
    double getBalance() const {    // Public method to read balance
        return balance;
    }
};
```

### Why Encapsulation?
- Protects sensitive data.
- Allows controlled access via **getters** and **setters**.

---

### **2.2 Inheritance**
Inheritance allows a class (child) to inherit attributes and methods from another class (parent).

#### Code Example:
```cpp
class Animal {
public:
    void eat() {
        cout << "This animal is eating." << endl;
    }
};

class Dog : public Animal {  // Dog inherits from Animal
public:
    void bark() {
        cout << "The dog is barking." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();   // Inherited from Animal
    myDog.bark();  // Defined in Dog
    return 0;
}
```

### Why Inheritance?
- Promotes code reuse.
- Establishes a hierarchical relationship.

---

### **2.3 Polymorphism**
Polymorphism means "many forms." It allows a single function, method, or operator to behave differently based on the context.

#### **Types of Polymorphism**:
1. **Compile-Time Polymorphism** (Method Overloading)
2. **Run-Time Polymorphism** (Method Overriding)

---

#### **2.3.1 Compile-Time Polymorphism**
Achieved via **function overloading** or **operator overloading**.

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {  // Overloaded function
        return a + b;
    }
};

int main() {
    Calculator calc;
    cout << calc.add(2, 3) << endl;       // Calls int version
    cout << calc.add(2.5, 3.5) << endl;  // Calls double version
    return 0;
}
```

---

#### **2.3.2 Run-Time Polymorphism**
Achieved via **virtual functions** (overriding behavior in derived classes).

```cpp
class Animal {
public:
    virtual void speak() {  // Virtual function
        cout << "This is an animal." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {  // Overrides the base class method
        cout << "The dog barks." << endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog myDog;
    animalPtr = &myDog;
    animalPtr->speak();  // Calls Dog's speak() due to runtime polymorphism
    return 0;
}
```

---

### **2.4 Abstraction**
Abstraction means hiding complex implementation details and showing only the necessary features of an object.

#### Achieved via:
1. **Abstract Classes** (contains at least one pure virtual function).
2. **Interfaces** (in C++: abstract classes with only pure virtual methods).

```cpp
class Shape {  // Abstract class
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();
    shape1->draw();  // Calls Circle's draw()
    shape2->draw();  // Calls Rectangle's draw()
    delete shape1;
    delete shape2;
    return 0;
}
```

---

### **2.5 Composition**
Composition is a "has-a" relationship where one class contains an object of another class.

#### Code Example:
```cpp
class Engine {
public:
    void start() {
        cout << "Engine started." << endl;
    }
};

class Car {
private:
    Engine engine;  // Car "has an" engine

public:
    void drive() {
        engine.start();
        cout << "Car is driving." << endl;
    }
};
```

---

## **3. Advanced OOP Concepts**

### **3.1 Constructors and Destructors**
- **Constructor**: Special method called when an object is created.
- **Destructor**: Special method called when an object is destroyed.

#### Code Example:
```cpp
class MyClass {
public:
    MyClass() {
        cout << "Constructor called." << endl;
    }
    ~MyClass() {
        cout << "Destructor called." << endl;
    }
};
int main() {
    MyClass obj;  // Constructor automatically called
    return 0;     // Destructor automatically called when object goes out of scope
}
```

---

### **3.2 Operator Overloading**
Allows you to redefine the behavior of operators for custom types.

#### Code Example:
```cpp
class Complex {
    int real, imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {  // Overload + operator
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;  // Calls overloaded + operator
    c3.display();
    return 0;
}
```

---

### **3.3 Virtual Destructors**
Ensures proper cleanup in inheritance when deleting a derived class object through a base class pointer.

```cpp
class Base {
public:
    virtual ~Base() {  // Virtual destructor
        cout << "Base destructor called." << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor called." << endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls both Base and Derived destructors
    return 0;
}
```

---

### **3.4 Multiple Inheritance**
A class can inherit from multiple base classes.

#### Code Example:
```cpp
class A {
public:
    void showA() { cout << "A" << endl; }
};

class B {
public:
    void showB() { cout << "B" << endl; }
};

class C : public A, public B {
    // Inherits both A and B
};

int main() {
    C obj;
    obj.showA();
    obj.showB();
    return 0;
}
```

---

### **3.5 Static Members and Methods**
Static members belong to the class, not any specific object.

#### Code Example:
```cpp
class MyClass {
public:
    static int count;  // Static member
    MyClass() { count++; }
    static int getCount() { return count; }  // Static method
};

int MyClass::count = 0;  // Define static member outside class

int main() {
    MyClass obj1, obj2;
    cout << "Count: " << MyClass::getCount() << endl;  // Access static method
    return 0;
}
```

Let’s dive into **other advanced OOP concepts and principles** to expand your understanding:

---

### **3.6 Friend Functions and Classes**

#### **Friend Function**
- A function declared as a `friend` of a class can access its private and protected members.
- Used to allow specific non-member functions to access a class's private data.

#### Code Example:
```cpp
class Box {
private:
    int length;

public:
    Box() : length(0) {}
    friend void setLength(Box& b, int len);  // Declare friend function
};

void setLength(Box& b, int len) {
    b.length = len;  // Access private member
    cout << "Box length is set to: " << b.length << endl;
}

int main() {
    Box b;
    setLength(b, 10);  // Call friend function
    return 0;
}
```

---

#### **Friend Class**
- A class declared as `friend` can access the private/protected members of another class.

#### Code Example:
```cpp
class A {
private:
    int data;

public:
    A() : data(0) {}
    friend class B;  // Declare B as a friend class
};

class B {
public:
    void setData(A& obj, int value) {
        obj.data = value;  // Access private member of class A
    }

    void displayData(A& obj) {
        cout << "Data from class A: " << obj.data << endl;
    }
};

int main() {
    A objA;
    B objB;
    objB.setData(objA, 42);
    objB.displayData(objA);
    return 0;
}
```

---

### **3.7 Static Polymorphism (Template Classes and Functions)**

Templates allow writing generic code for different data types. They provide flexibility without rewriting code for each data type.

---

#### **Template Function**
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum (int): " << add(3, 4) << endl;          // Works with integers
    cout << "Sum (double): " << add(2.5, 4.1) << endl;  // Works with doubles
    return 0;
}
```

---

#### **Template Class**
```cpp
template <typename T>
class Box {
private:
    T value;

public:
    void setValue(T val) {
        value = val;
    }
    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox;      // Box for integers
    Box<double> doubleBox;  // Box for doubles

    intBox.setValue(5);
    doubleBox.setValue(10.5);

    cout << "Integer value: " << intBox.getValue() << endl;
    cout << "Double value: " << doubleBox.getValue() << endl;

    return 0;
}
```

---

### **3.8 Namespaces**
- Namespaces prevent name conflicts in large projects by grouping related code into separate scopes.

#### Code Example:
```cpp
#include <iostream>
using namespace std;

namespace Math {
    int add(int a, int b) {
        return a + b;
    }

    namespace Advanced {
        int multiply(int a, int b) {
            return a * b;
        }
    }
}

int main() {
    cout << "Addition: " << Math::add(3, 4) << endl;
    cout << "Multiplication: " << Math::Advanced::multiply(3, 4) << endl;
    return 0;
}
```

---

### **3.9 Virtual Tables (vtable)**
- Used to implement **run-time polymorphism**.
- Each class with virtual functions has a `vtable` (virtual table) that holds pointers to the virtual functions.

---

### **4. Memory Management in OOP**

Memory management in OOP focuses on efficient allocation and deallocation of resources to avoid **memory leaks**.

#### **4.1 new and delete**
`new` dynamically allocates memory; `delete` frees it.

```cpp
class MyClass {
public:
    MyClass() {
        cout << "Constructor called" << endl;
    }
    ~MyClass() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    MyClass* obj = new MyClass();  // Dynamically allocate
    delete obj;  // Free memory
    return 0;
}
```

---

#### **4.2 Smart Pointers**
- Smart pointers manage the lifetime of dynamically allocated objects automatically.
- C++ offers:
  1. **std::unique_ptr**: Exclusive ownership.
  2. **std::shared_ptr**: Shared ownership.
  3. **std::weak_ptr**: Non-owning reference.

```cpp
#include <memory>
#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor called" << endl; }
    ~MyClass() { cout << "Destructor called" << endl; }
};

int main() {
    unique_ptr<MyClass> ptr1 = make_unique<MyClass>();  // Unique ownership
    shared_ptr<MyClass> ptr2 = make_shared<MyClass>();  // Shared ownership
    return 0;  // Automatic memory deallocation
}
```

---

### **5. Advanced Design Patterns**

Design patterns are reusable solutions to common problems in software design.

---

#### **5.1 Singleton Pattern**
Ensures a class has only one instance.

```cpp
class Singleton {
private:
    static Singleton* instance;  // Static instance
    Singleton() {}               // Private constructor

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;  // Initialize static member

int main() {
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    cout << "Are obj1 and obj2 the same? " << (obj1 == obj2) << endl;  // Output: 1 (true)
    return 0;
}
```

---

#### **5.2 Factory Pattern**
Creates objects without exposing the instantiation logic.

```cpp
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

class ShapeFactory {
public:
    static Shape* createShape(const string& type) {
        if (type == "circle")
            return new Circle();
        else if (type == "rectangle")
            return new Rectangle();
        return nullptr;
    }
};

int main() {
    Shape* circle = ShapeFactory::createShape("circle");
    circle->draw();
    delete circle;

    Shape* rectangle = ShapeFactory::createShape("rectangle");
    rectangle->draw();
    delete rectangle;

    return 0;
}
```

---

### **6. Miscellaneous OOP Features**

#### **6.1 Typecasting in OOP**
- **Static Casting**: Compile-time conversion.
- **Dynamic Casting**: Used with polymorphism.
- **const_cast**: Removes `const` from variables.
- **reinterpret_cast**: Converts any pointer type to another.

#### Code Example:
```cpp
class Base { virtual void func() {} };
class Derived : public Base {};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Safe casting
    if (derivedPtr)
        cout << "Successfully casted!" << endl;
    delete basePtr;
    return 0;
}
```

---