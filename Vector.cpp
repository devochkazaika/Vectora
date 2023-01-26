#include <iostream>

template <typename T>
class Vector{
    private:
        T* array = new T[1];
        int size_ = 0;
    public:
        Vector(T mas[], int s){
            this->size_ = s;
            this->array = new T[s];
            this->array = mas;
        }
        ~Vector(){
        }
        void print(int a=0, int b=-999){
            if (b == -999){b = this->size_;}
            for (int i=a; i<b; i++){
                std::cout<<array[i] << " ";
            }
            std::cout << "\n";
        }
        void add(T elem){
            T* tmp = new T[this->size_ + 1];
            for (int i = 0; i<this->size_; i++) tmp[i] = this->array[i];
            this->size_++;
            tmp[this->size_] = elem;
            this->array = tmp;
        }
};
