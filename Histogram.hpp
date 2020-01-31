#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

template <typename Type>
struct Item
{

    Type element;
    int number;
};

template <typename Type>
class Histogram
{

private:
    Type *elements;
    int *num_of_ele;
    int amount;

    int alr_in_list(Type x);

public:
    Histogram();
    ~Histogram();
    Item<Type> get_ele(int i);
    int get_num();
    Histogram<Type> operator+(Histogram<Type> &h);
    void operator=(Histogram<Type> h);
    Histogram<Type> &operator<<(Type x);
    Item<Type> operator[](int i);
    void set_value(Type x, int y);
    void add_ele(Type x);
    void from_file(string file_name);
};

template <typename Type>
Histogram<Type>::Histogram()
{

    num_of_ele = nullptr;
    elements = nullptr;
    amount = 0;
}

template <typename Type>
Histogram<Type>::~Histogram()
{
    delete[] num_of_ele;
    delete[] elements;
}

template <typename Type>
void Histogram<Type>::add_ele(Type x)
{

    int k = alr_in_list(x);
    if (k != -1)
        num_of_ele[k]++;
    else
    {
        int *tmp_num_of_ele;
        tmp_num_of_ele = new int[amount + 1];
        for (int i = 0; i < amount; ++i)
            tmp_num_of_ele[i] = num_of_ele[i];

        Type *tmp_elements;
        tmp_elements = new Type[amount + 1];
        for (int i = 0; i < amount; ++i)
            tmp_elements[i] = elements[i];

        delete[] num_of_ele;
        num_of_ele = tmp_num_of_ele;

        delete[] elements;
        elements = tmp_elements;

        num_of_ele[amount] = 1;
        elements[amount] = x;
        amount++;
    }
}

template <typename Type>
int Histogram<Type>::alr_in_list(Type x)
{
    if (amount == 0)
        return -1;
    else
    {
        Type a;
        for (int i = 0; i < amount; i++)
        {
            a = elements[i];
            if (x == a)
                return i;
        }
        return -1;
    }
}

template <typename Type>
Histogram<Type> &Histogram<Type>::operator<<(Type x)
{

    add_ele(x);

    return *this;
}

template <typename Type>
Item<Type> Histogram<Type>::get_ele(int i)
{
    if ( i < amount )
        return {elements[i], num_of_ele[i]};
    else
        return { (Type)0, -1 };
}

template <typename Type>
Item<Type> Histogram<Type>::operator[](int i)
{

    return get_ele(i);
}

template <typename Type>
int Histogram<Type>::get_num()
{

    return amount;
}

template <typename Type>
Histogram<Type> Histogram<Type>::operator+(Histogram<Type> &h)
{

    Histogram<Type> h2;

    for (int i = 0; i < amount; i++)
    {
        int a = (*this)[i].number;
        Type x = (*this)[i].element;
        int k = h.alr_in_list(x);
        if (k != -1)
        {
            int b = h[k].number;
            for (int c = 0; c < a + b; c++)
            {
                h2 << x;
            }
        }
        else
        {
            for (int c = 0; c < a; c++)
                h2 << x;
        }
    }

    for (int i = 0; i < h.amount; i++)
    {
        int a = h[i].number;
        Type x = h[i].element;
        int k = h2.alr_in_list(x);
        if (k == -1)
            for (int c = 0; c < a; c++)
                h2 << x;
    }

    return h2;
}

template <typename Type>
void Histogram<Type>::from_file(string file_name)
{

    Type s;

    ifstream f(file_name.c_str());
    if (f.is_open())
    {

        while (!f.eof())
        {
            f >> s;
            (*this) << s;
        }
    }
}

template <typename Type>
void Histogram<Type>::set_value(Type x, int y)
{

    int k = alr_in_list(x);

    if (k == -1)
        cout << "Cannot set value of element that doesn't exist in histogram" << endl;
    else
    {
        num_of_ele[k] = y;
    }
}

template <typename Type>
void Histogram<Type>::operator=(Histogram<Type> h)
{
    int *tmp_num_of_ele;
    tmp_num_of_ele = new int[h.get_num()];
 //   cout << endl << this->get_num() << " " << h.get_num() << endl;
    for (int i = 0; i < h.get_num(); ++i)
        tmp_num_of_ele[i] = h.num_of_ele[i];

    Type *tmp_elements;
    tmp_elements = new Type[h.get_num()];
    for (int i = 0; i < h.get_num(); ++i)
        tmp_elements[i] = h.elements[i];

    delete[] this->num_of_ele;
    this->amount = h.amount;
    this->num_of_ele = tmp_num_of_ele;
    tmp_num_of_ele = nullptr;

    delete[] this->elements;
    this->elements = tmp_elements;
    tmp_elements = nullptr;
}
