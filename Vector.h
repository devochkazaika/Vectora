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
            delete[] array;
        }
        void print(int a=0, int b=-999){
            if (b == -999){b = this->size_;}
            for (int i=a; i<b; i++){
                std::cout<<array[i] << " ";
            }
            std::cout << "\n";
        }
        void add(T elem){
            T* tmp = this->array;
            this->size_++;
            this->array = new T[this->size_];
            for (int i = 0; i < (this->size_) -1; i++) this->array[i] = tmp[i];
            this->array[size_-1] = elem;
            tmp = this->array;
        }
        void del_id(int id){
            T* tmp = array;
            array = new int[size_-1];
            for (int i=0; i<id; i++) array[i] = tmp[i];
            for (int i=id + 1; i<this->size_; i++) array[i-1] = tmp[i];
            tmp = array;
            size_--;
        }
};
