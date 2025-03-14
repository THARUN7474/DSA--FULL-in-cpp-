#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
        string name;
        int health;
        char level;

        static int time;
        Hero() {
        }

        Hero(int health) {
            this->health = health;
        }

        Hero(int health, char level) {
            this->health = health;
            this->level = level;
        }

        Hero(int health, char level, string name) {
            this->health = health;
            this->level = level;
            this->name = name;
        }

        Hero(Hero &temp) {
            this->health = temp.health;
            this->level = temp.level;
            this->name = temp.name;
        }

        ~Hero() {
            cout << "\tDestructor Called !" << endl;
        }

        static int random() {
            return time;
        }


        void print() {
            cout << "[Name : " << this->name << " , Health : ";
            cout << this->health << " , Level : " << this->level << "]" << endl;
        }
};
int Hero::time = 10; 
class Teacher
{
private:
    string name;
    int age;

public:
    string dept;
    Teacher(string name, int age)
    {
        this->name = name;
        this->age = age;
        cout << "i will print evrytime obj creats" << endl;
    }
    void display()
    {
        cout << "Name: " << name << " Age: " << age << endl;
    }
};

int main()
{
    // Hero h1;//static object creation

    // h1.name = "Akash Gautam";
    // h1.health = 100;
    // h1.level  = 'A';

    // cout << "h1.name : " << h1.name << endl;
    // cout << "h1.health : " << h1.health << endl;
    // cout << "h1.level : " << h1.level << endl;


    // Hero *h2 = new Hero;//dynamic object creation
    
    // h2->name = "Akash Gautam"; // or else *h2.name = "Akash Gautam";---  (*h2). == h2->
    // h2->health = 100;
    // h2->level  = 'A';

    // cout << "h2->name : " << h2->name << endl;
    // cout << "h2->health : " << h2->health << endl;
    // cout << "h2->level : " << h2->level << endl;


    //  Hero *h1 = new Hero();
    // cout << "For h1 : " << endl;
    // cout << "h1->health = " << h1->health << endl;
    // cout << "h1->level = " << h1->level << endl;
    // cout << "h1->name = " << h1->name << endl << endl;
    
    // Hero *h2 = new Hero(30);
    // cout << "For h2 : " << endl;
    // cout << "h2->health = " << h2->health << endl;
    // cout << "h2->level = " << h2->level << endl;
    // cout << "h2->name = " << h2->name << endl << endl;

    // Hero *h3 = new Hero(40, 'A');
    // cout << "For h3 : " << endl;
    // cout << "h3->health = " << h3->health << endl;
    // cout << "h3->level = " << h3->level << endl;
    // cout << "h3->name = " << h3->name << endl << endl;

    // Hero *h4 = new Hero(50, 'B', "Akash");
    // cout << "For h4 : " << endl;
    // cout << "h4->health = " << h4->health << endl;
    // cout << "h4->level = " << h4->level << endl;
    // cout << "h4->name = " << h4->name << endl << endl;

    Hero *h1 = new Hero(80, 'A', "Akash");
    cout << "For h1 : ";
    h1->print();
    
    Hero *h2 = new Hero(*h1);
    cout << "For h2 : ";
    h2->print();

    Hero h3(*h2);
    cout << "For h3 : ";
    h3.print();

    //add code for deep copy and shallow copy detailed example 

    //   // Dynamic Allocation
    // Hero *h1 = new Hero(150, 'A', "Akash");
    // h1->print();
    // delete h1;      // Calling destructor manually

    // cout << endl;

    // // Static Allocation
    // Hero h2(250, 'G', "Gautam");
    // h2.print();
    // // Destructor called automatically

      cout << "Hero::time -> " << Hero::time << endl;

    cout << "Hero::random() -> " << Hero::random() << endl;

    Teacher t1("Rahul", 25);
    t1.dept = "CSE";
    cout << t1.dept << endl;
    // cout<< t1.name << endl; // This will give error as name is private
    t1.display();

    Teacher t2("Rohit", 30);
    t2.dept = "ECE";
    cout << t2.dept << endl;
    t2.display();

    Teacher t3("Raj", 35);  
    t3.dept = "ME";
    cout << t3.dept << endl;
    t3.display();
    

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class Human {
    public:
    int height;
    int weight;
    int age;
};

class Male : public Human {

};

class Female : protected Human {

};

int main() {
    Male m;

    cout << "m.height : " << m.height << endl;
    cout << "m.weight : " << m.weight << endl;
    cout << "m.age : " << m.age << endl;

    Female f;
    // Not possible
    // cout << "f.height : " << f.height << endl;
    // cout << "f.weight : " << f.weight << endl;
    // cout << "f.age : " << f.age << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child_property1;
    int child_property2;
};

int main() {
    B b1;
    
    b1.base_property1 = 10;
    b1.base_property2 = 15;
    b1.child_property1 = 20;
    b1.child_property2 = 25;

    cout << "b1.base_property1 : " << b1.base_property1 << endl;
    cout << "b1.base_property2 : " << b1.base_property2 << endl;
    cout << "b1.child_property1 : " << b1.child_property1 << endl;
    cout << "b1.child_property2 : " << b1.child_property2 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child_property1;
    int child_property2;
};

class C : public B {
    public:
    int new_child_property1;
    int new_child_property2;
};

int main() {
    C c1;
    
    c1.base_property1 = 10;
    c1.base_property2 = 15;
    c1.child_property1 = 20;
    c1.child_property2 = 25;
    c1.new_child_property1 = 30;
    c1.new_child_property2 = 35;

    cout << "c1.base_property1 : " << c1.base_property1 << endl;
    cout << "c1.base_property2 : " << c1.base_property2 << endl << endl;
    cout << "c1.child_property1 : " << c1.child_property1 << endl;
    cout << "c1.child_property2 : " << c1.child_property2 << endl << endl;
    cout << "c1.new_child_property1 : " << c1.new_child_property1 << endl;
    cout << "c1.new_child_property2 : " << c1.new_child_property2 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base1_property1;
    int base1_property2;
};

class B {
    public:
    int base2_property1;
    int base2_property2;
};

class C : public A, public B {
    public:
    int child_property1;
    int child_property2;
};

int main() {
    C c1;
    
    c1.base1_property1 = 10;
    c1.base1_property2 = 15;
    c1.base2_property1 = 20;
    c1.base2_property2 = 25;
    c1.child_property1 = 30;
    c1.child_property2 = 35;

    cout << "c1.base1_property1 : " << c1.base1_property1 << endl;
    cout << "c1.base1_property2 : " << c1.base1_property2 << endl << endl;
    cout << "c1.base2_property1 : " << c1.base2_property1 << endl;
    cout << "c1.base2_property2 : " << c1.base2_property2 << endl << endl;
    cout << "c1.child_property1 : " << c1.child_property1 << endl;
    cout << "c1.child_property2 : " << c1.child_property2 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child1_property1;
    int child1_property2;
};

class C : public A {
    public:
    int child2_property1;
    int child2_property2;
};

class D : public B, public C {
    public:
    int new_child_property1;
    int new_child_property2;
};

int main() {
    D d1;
    
    // d1.base_property1 = 50;
    // d1.base_property2 = 55;
    d1.child1_property1 = 60;
    d1.child1_property2 = 65;
    d1.child2_property1 = 70;
    d1.child2_property2 = 75;
    d1.new_child_property1 = 80;
    d1.new_child_property2 = 85;

    // cout << "d1.base_property1 : " << d1.base_property1 << endl;
    // cout << "d1.base_property2 : " << d1.base_property2 << endl << endl;
    cout << "d1.child1_property1 : " << d1.child1_property1 << endl;
    cout << "d1.child1_property2 : " << d1.child1_property2 << endl << endl;
    cout << "d1.child2_property1 : " << d1.child2_property1 << endl;
    cout << "d1.child2_property2 : " << d1.child2_property2 << endl << endl;
    cout << "d1.new_child_property1 : " << d1.new_child_property1 << endl;
    cout << "d1.new_child_property2 : " << d1.new_child_property2 << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child1_property1;
    int child1_property2;
};

class C : public A {
    public:
    int child2_property1;
    int child2_property2;
};

int main() {
    B b1;
    C c1;
    
    b1.base_property1 = 50;
    b1.base_property2 = 55;
    b1.child1_property1 = 60;
    b1.child1_property2 = 65;

    c1.base_property1 = 10;
    c1.base_property2 = 15;
    c1.child2_property1 = 20;
    c1.child2_property2 = 25;

    cout << "b1.base_property1 : " << b1.base_property1 << endl;
    cout << "b1.base_property2 : " << b1.base_property2 << endl << endl;
    cout << "b1.child1_property1 : " << b1.child1_property1 << endl;
    cout << "b1.child1_property2 : " << b1.child1_property2 << endl << endl;
    
    cout << "c1.base_property1 : " << c1.base_property1 << endl;
    cout << "c1.base_property2 : " << c1.base_property2 << endl << endl;
    cout << "c1.child2_property1 : " << c1.child2_property1 << endl;
    cout << "c1.child2_property2 : " << c1.child2_property2 << endl << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child1_property1;
    int child1_property2;
};

class C : public A {
    public:
    int child2_property1;
    int child2_property2;
};

class D : public B, public C {
    public:
    int new_child_property1;
    int new_child_property2;
};

int main() {
    D d1;
    
    d1.B::base_property1 = 50;
    d1.B::base_property2 = 55;
    d1.C::base_property1 = 60;
    d1.C::base_property2 = 65;
    d1.child1_property1 = 70;
    d1.child1_property2 = 75;
    d1.child2_property1 = 80;
    d1.child2_property2 = 85;
    d1.new_child_property1 = 90;
    d1.new_child_property2 = 95;

    cout << "d1.B::base_property1 : " << d1.B::base_property1 << endl;
    cout << "d1.B::base_property2 : " << d1.B::base_property2 << endl << endl;
    cout << "d1.C::base_property1 : " << d1.C::base_property1 << endl;
    cout << "d1.C::base_property2 : " << d1.C::base_property2 << endl << endl;
    cout << "d1.child1_propertn y1 : " << d1.child1_property1 << endl;
    cout << "d1.child1_property2 : " << d1.child1_property2 << endl << endl;
    cout << "d1.child2_property1 : " << d1.child2_property1 << endl;
    cout << "d1.child2_property2 : " << d1.child2_property2 << endl << endl;
    cout << "d1.new_child_property1 : " << d1.new_child_property1 << endl;
    cout << "d1.new_child_property2 : " << d1.new_child_property2 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int a, b;

    int add() {
        return a+b;
    }

    void operator + (A &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Output : " << value2 - value1 << endl;
    }

    void operator () () {
        cout << "Bracket is called by " << this->a << endl;
    }
};

int main() {
    A obj1, obj2;

    obj1.a = 2;
    obj2.a = 7;

    obj1 + obj2;

    obj1();

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    void func() {
        cout << "Inside Parent Class" << endl;
    }
};

class B : public A {
    public:
    void func() {
        cout << "Inside Child Class" << endl;
    }
};

int main() {
    A obj1;
    B obj2;

    obj1.func();
    obj2.func();

    return 0;
}