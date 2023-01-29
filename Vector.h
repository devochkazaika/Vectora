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
            for (int i=0; i<this->size_; i++) this->array[i] = mas[i];
        }
        ~Vector(){
            delete[] array;
        }
        void print(int a=0, int b=-999){
            if (b == -999){b = this->size_;}
            for (int i=a; i<b; i++){
                std::cout<<this->array[i] << " ";
            }
            std::cout << "\n";
        }
        int* r_print(){
            return this->array;
        }
        size_t size(){
            return this->size_;
        }
        void add(T elem){
            T* tmp = array;
            this->size_++;
            this->array = new T[size_];
            for (int i = 0; i < (this->size_) -1; i++) this->array[i] = tmp[i];
            this->array[size_-1] = elem;
            tmp = this->array;
        }
        void del_id(int id){
            T* tmp = this->array;
            this->array = new int[size_-1];
            for (int i=0; i<id; i++) this->array[i] = tmp[i];
            for (int i=id + 1; i<this->size_; i++) this->array[i-1] = tmp[i];
            delete[] tmp;
            size_--;
        }
        void remove(T d){
            T* tmp = new T[this->size_-1];
            bool k = false;
            for (int i=0; i<this->size_; i++){
                if (k == true){
                    tmp[i-1] = this->array[i];
                }
                else{
                    if (this->array[i] != d){
                        tmp[i] = this->array[i];}
                    else{
                        k = true;
                    }
                }
            }
            T* array = new int[this->size_-1];
            for (int i=0; i<this->size_; i++) this->array[i] = tmp[i];
            if (k){this->size_--;}
            delete[] tmp;
        }
        void remove_all(T d){
            T* tmp = new T[this->size_];
            int b = 0;
            for (int i=0; i<this->size_; i++){
                if (this->array[i] != d){
                    tmp[b] = this->array[i];
                    b = b + 1;
                }
            }
            this->array = new T[b];
            for (int i=0; i<b; i++){
                this->array[i] = tmp[i];
            }
            this->size_ = b;
            delete[] tmp;
        }
        void operator[](int a){
            std::cout << this->array[a] << std::endl;
            }
        void operator=(Vector &b){
            delete[] this->array;
            this->array = new T[b.size()];
            for (int i=0; i<b.size(); i++) this->array[i] = b.r_print()[i];
        }
};
