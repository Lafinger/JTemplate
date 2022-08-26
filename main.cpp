

#include <iostream>
#include <memory>

using namespace std;

// partial specialization 
template <typename T, typename U = void> struct X { int id = 0; };
template <typename T> struct X< T, T > { int id = 1; };
template <typename T> struct X< T*, T > { int id = 2; };
template <typename T> struct X< T, T* > { int id = 3; };
template <typename U> struct X< U, int> { int id = 4; };
template <typename U> struct X< U*, int> { int id = 5; };
template <typename U, typename T> struct X< U*, T* > { int id = 6; };
template <typename U, typename T> struct X< U, T* > { int id = 7; };
template <typename T> struct X< unique_ptr<T>, shared_ptr<T> > { int id = 8; };
template <typename T> struct X< T*, T* > { int id = -1; };

// full specialization "<>"
template <> struct X< int*, int > { int id = -2; };


int main()
{
    cout << X<float*, int>().id << endl; // 5 
    cout << X<double*, int>().id << endl; // 5
    cout << X<double, double>().id << endl; // 1
    cout << X<double>().id << endl; // 0 !!!
    cout << X<float*, double*>().id << endl; // 6
    cout << X<float*, float*>().id << endl; // -1 !!!
    cout << X<double, float*>().id << endl;  // 7
    cout << X<int, double*>().id << endl; // 7
    cout << X<int*, int>().id << endl; // -2 !!!
    cout << X<double*, double>().id << endl; // 2

    return 0;
}