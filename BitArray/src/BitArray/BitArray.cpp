#include "BitArray.h"
#include <exception>



BitArray::BitArray(int size, unsigned long value){
    this->bits = std::vector<bool>(size);
    bool val = value != 0;
    for (int i {}; i < size; ++i){
        this->bits[i] = val;
    }
}
BitArray::BitArray(const BitArray& b) = default;
BitArray::~BitArray() = default;

BitArray& BitArray::operator=(const BitArray& b)= default;
BitArray& BitArray::operator&=(const BitArray& b){
    if (b.bits.size() != this->bits.size()){
        throw std::invalid_argument("Not the same sizes\n");
    }else{
        int size = (int)this->bits.size();
        for (int i {}; i < size; ++i){
            this->bits[i] = this->bits[i] && b.bits[i];
        }
        return *this;
    }
}
BitArray& BitArray::operator|=(const BitArray& b){
    if (b.bits.size() != this->bits.size()){
        throw std::invalid_argument("Not the same sizes\n");
    }else{
        int size = (int)this->bits.size();
        for (int i {}; i < size; ++i){
            this->bits[i] = this->bits[i] || b.bits[i];
        }
        return *this;
    }
}
BitArray& BitArray::operator^=(const BitArray& b){
    if (b.bits.size() != this->bits.size()){
        throw std::invalid_argument("Not the same sizes\n");
    }else{
        int size = (int)this->bits.size();
        for (int i {}; i < size; ++i){
            this->bits[i] = this->bits[i] ^ b.bits[i];
        }
        return *this;
    }
}
BitArray& BitArray::operator<<=(int n){
    int size = (int)this->bits.size();
    int c = size - n;
    for (int i = 0; i < c; ++i){
        this->bits[i] = this->bits[i + n];
    }
    for (int i = 0; i < n; ++i){
        this->bits[size - 1 - i] = false;
    }
    return *this;
}
BitArray& BitArray::operator>>=(int n){
    int size = (int)this->bits.size();
    int c = size - n;
    for (int i = 0; i < c; ++i){
        this->bits[size - 1 - i] = this->bits[c - 1 - i];
    }
    for (int i = 0; i < n; ++i){
        this->bits[i] = false;
    }
    return *this;
}
BitArray BitArray::operator<<(int n) const{
    return BitArray(*this) <<= n;
}
BitArray BitArray::operator>>(int n) const{
    return BitArray(*this) >>= n;
}
BitArray BitArray::operator~() const{
    auto temp = new BitArray(*this);
    int size = (int)this->bits.size();
    for (int i {}; i < size; ++i){
        temp->bits[i] = !temp->bits[i];
    }
    return *temp;
}
bool BitArray::operator[] (int i) const{
    return this->bits[i];
}


void BitArray::swap(BitArray& bitArray){
    this->bits.swap(bitArray.bits);;
}
void BitArray::resize(int nBits, bool value){
    int size = (int)this->bits.size();
    if (nBits > size){
        int needToPush = nBits - size;
        for (int i {}; i < needToPush; ++i){
            this->bits.push_back(value);
        }
        return;
    }else{
        int needToPop = size - nBits;
        for (int i {}; i < needToPop; ++i){
            this->bits.pop_back();
        }
    }
}
void BitArray::clear(){
    this->bits.clear();
}
void BitArray::pushBack(bool bit){
    this->bits.push_back(bit);
}
bool BitArray::any(){
    int size = (int)this->bits.size();
    for (int i {}; i < size; ++i){
        if (this->bits[i]){
            return true;
        }
    }
    return false;
}
bool BitArray::none(){
    return !any();
}
int BitArray::count() const{
    int count {};
    int size = (int)this->bits.size();
    for (int i {}; i < size; ++i){
        count += this->bits[i];
    }
    return count;
}
BitArray BitArray::set(){
    int size = (int)this->bits.size();
    for (int i {}; i < size; ++i){
        this->bits[i] = true;
    }
    return *this;
}
BitArray& BitArray::set(int i, bool value){
    this->bits[i] = value;
    return *this;
}
BitArray& BitArray::reset(){
    int size = (int)this->bits.size();
    for (int i {}; i < size; ++i){
        this->bits[i] = false;
    }
    return *this;
}
BitArray& BitArray::reset(int n){
    return set(n, false);
}
int BitArray::getSize() const{
    return (int)this->bits.size();
}
bool BitArray::empty() const{
    if (this->bits.empty()){
        return true;
    }
    return false;
}
std::string BitArray::toString() const{
    std::string toReturn;
    int size = (int)this->bits.size();
    for (int i {}; i < size; ++i){
        if (this->bits[i]){
            toReturn += '1';
        }else{
            toReturn += '0';
        }
    }
    return toReturn;
}


bool operator== (const BitArray& b1, const BitArray& b2){
    if (b1.getSize() != b2.getSize()){
        return false;
    }
    int abSize = b1.getSize();
    for (int i {}; i < abSize; ++i){
        if (b1[i] != b2[i]){
            return false;
        }
    }
    return true;
}
bool operator!= (const BitArray & b1, const BitArray & b2){
    return !(b1 == b2);
}
BitArray operator& (const BitArray& b1, const BitArray& b2){
    if (b1.getSize() != b2.getSize()){
        throw std::invalid_argument("b1.size != b2.size\n");
    }
    BitArray temp = b1;
    int size_ = b1.getSize();
    for (int i {}; i < size_; ++i){
        temp.set(i, b1[i] && b2[i]);
    }
    return temp;
}
BitArray operator| (const BitArray& b1, const BitArray& b2){
    if (b1.getSize() != b2.getSize()){
        throw std::invalid_argument("b1.size != b2.size\n");
    }
    BitArray temp = b1;
    int size_ = b1.getSize();
    for (int i {}; i < size_; ++i){
        temp.set(i, b1[i] || b2[i]);
    }
    return temp;
}
BitArray operator^ (const BitArray& b1, const BitArray& b2){
    if (b1.getSize() != b2.getSize()){
        throw std::invalid_argument("b1.size != b2.size\n");
    }
    BitArray temp = b1;
    int size_ = b1.getSize();
    for (int i {}; i < size_; ++i){
        temp.set(i, b1[i] ^ b2[i]);
    }
    return temp;
}