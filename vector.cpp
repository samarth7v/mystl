#include <iostream>
#include <memory>

template<typename T>
class vector{
    public:

    //constructors for vector
        vector(size_t size, T _value):size_(size),csize_(size),data_(std::make_unique<T[]>(size_))
        {
            for(int i=0;i<csize_;i++){
                data_[i] = _value;
            }
        }
        vector():size_(2), csize_(0), data_(std::make_unique<T[]>(2)) {}
    
    //push back
        void push_back(const T& value)
        {
            if(csize_+1>size_){
                nsize(2);
            }
            data_[csize_] = value;
            csize_ ++;
        }
        T back()
        {
            return data_[csize_-1];
        }
        void pop_back()
        {
            csize_--;
            data_[csize_]=none;
        }
        size_t size(){
            return csize_;
        }
        T& operator[](size_t index){
            if(index>=csize_){
                std::cout<<"Index exceeded size of vector\n";
                return none;
            }
            return data_[index];
        }
    private:
        size_t size_;
        size_t csize_;
        std::unique_ptr<T[]> data_;

        void nsize(int n){
            auto newdata = std::make_unique<T[]>(n*size_);
            for(int i=0; i<csize_ ; i++){
                newdata[i] = std::move(data_[i]);
            }
            data_ = std::move(newdata);
            size_ = n*size_;
        }
        T none;
};
int main(){
    vector<std::string> vec(5,"abc");
    vec[15] = "jab";
    vec.push_back("this is pushed back");
    for(int i=0;i<vec.size();i++){
        std::cout << vec[i] << "\n";
    }
    std::cout << "back = " << vec.back()<<"\n";
    vec.pop_back();
    std::cout << "back = " << vec.back()<<"\n";
    vector<int>vec2;
    vec2.push_back(5);
    std::cout << "this is push back = "<<vec2[0];
    


}