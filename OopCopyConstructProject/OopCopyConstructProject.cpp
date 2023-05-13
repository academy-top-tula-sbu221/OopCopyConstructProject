#include <iostream>

using namespace std;

class MyClass
{
    int value;
    int* pointer;
public:
    int& Value() { return value; }
    
    MyClass(int value = 0) : value { value }
    {
        cout << this << " object construct\n";
        pointer = new int;
    }

    MyClass(const MyClass& obj)
    {
        cout << this << " object copy construct\n";
        value = obj.value;
        pointer = new int;
        *pointer = *obj.pointer;
    }

    ~MyClass()
    {
        cout << this << " object destruct\n";
        delete pointer;
    }
};

void MyClassPrint(MyClass obj)
{
    cout << obj.Value() << "\n";
}

class Vector
{
    int size;
    int* items;
public:
    Vector(int size = 0) : size{ size }, items{ new int[size] } {}
    Vector(const Vector& v)
    {
        this->size = v.size;

        this->items = new int[size];
        for (int i = 0; i < size; i++)
            items[i] = v.items[i];
    }

    Vector operator=(const Vector& v)
    {
        if (&v == this)
            return *this;

        delete[] items;

        this->size = v.size;

        this->items = new int[size];
        for (int i = 0; i < size; i++)
            items[i] = v.items[i];

        return *this;
    }

    ~Vector() { delete[] items; }
    int& operator[](int index) { return items[index]; }
    int Size(){ return size; }

};

//MyClass MyClassCreate(int value = 0)
//{
//    MyClass obj(value);
//    return obj;
//}

int main()
{
    //MyClass obj1(10);

    // 1
    //MyClass obj2(obj1);

    // 2
    //MyClassPrint(obj1);

    // 3
    //MyClass obj3 = MyClassCreate(20);

    Vector v1(10);
    Vector v2, v3;
    v2 = v3 = v1;
}
