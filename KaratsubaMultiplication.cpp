// KaratsubaMultiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>
std::vector<int> slicing(std::vector<int>& arr,
    int X, int Y)
{

    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    // To store the sliced vector
    std::vector<int> result(Y - X + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}

int kMultiply(std::vector<int> x, std::vector<int> y)
{
    int n1 = x.size();
    int n2 = y.size();

    // base case
    if (n1 == 1 && n2 == 1)
        return x[0] * y[0];

    else if (n1 == 1 && n2 != 1)
    {
        std::vector<int> a;
        a.push_back(0);
        std::vector<int> c = slicing(y, 0, floor((n2 - 1) / 2));
        std::vector<int> b = slicing(x, floor(n1 / 2), n1 - 1);
        std::vector<int> d = slicing(y, n2 / 2, n2 - 1);

        int ac = kMultiply(a, c);
        int bd = kMultiply(b, d);
        int ad = kMultiply(a, d);
        int bc = kMultiply(b, c);

        return pow(10, n1) * ac + pow(10, 1) * (ad + bc) + bd;
    }

    else if (n2 == 1 && n1 != 1)
    {
        std::vector<int> a = slicing(x, 0, floor((n1 - 1) / 2));
        std::vector<int> c;
        c.push_back(0);
        std::vector<int> b = slicing(x, n1 / 2, n1 - 1);
        std::vector<int> d = slicing(y, n2 / 2, n2 - 1);

        int ac = kMultiply(a, c);
        int bd = kMultiply(b, d);
        int ad = kMultiply(a, d);
        int bc = kMultiply(b, c);

        return pow(10, n1) * ac + pow(10, 1) * (ad + bc) + bd;
    }

    else
    {
        std::vector<int> a = slicing(x, 0, floor((n1 - 1) / 2));
        std::vector<int> c = slicing(y, 0, floor((n2 - 1) / 2));
        std::vector<int> b = slicing(x, n1 / 2, n1 - 1);
        std::vector<int> d = slicing(y, n2 / 2, n2 - 1);

        int ac = kMultiply(a, c);
        int bd = kMultiply(b, d);
        int ad = kMultiply(a, d);
        int bc = kMultiply(b, c);

        return pow(10, n1) * ac + pow(10, n1 / 2) * (ad + bc) + bd;
    }
}



int main()
{
    // Create an empty vector
    std::vector<int> vect1;

    vect1.push_back(2);
  
   
    

    std::vector<int> vect2;
    vect2.push_back(4);
    vect2.push_back(3);
    vect2.push_back(2);
    vect2.push_back(1);
    
    std::cout << "The product is: " << kMultiply(vect1, vect2);

}

