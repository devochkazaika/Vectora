#include main.cpp
#include <Vector.h>

int main(){
    int k[5] = {1, 2, 3, 4, 5};
    Vector <int> a(k, 5);
    a.print();
    a.add(10);
    a.print();
}