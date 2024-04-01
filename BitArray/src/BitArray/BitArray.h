#pragma once

#include <vector>
#include <iostream>


class BitArray{
private:
    std::vector<bool> bits;
public:
    ///Effects: Constructs an bitArray of length size filled with the value "value" (default 0).
    explicit BitArray(int size, unsigned long value = 0);
    ///Effects: Constructs a bitArray that is a copy of the bitset b.
    BitArray(const BitArray& a);
    ///Effects: Releases the memory associated with this bitArray and destroys the bitset object itself.
    ~BitArray();

    ///Effects: This bitset becomes a copy of the bitset b.
    BitArray& operator=(const BitArray& b);
    ///Effects: Bitwise-AND with assignment.
    ///Throws: std::invalid_arguments if this.size != b.size.
    BitArray& operator&=(const BitArray& b);
    ///Effects: Bitwise-OR with assignment.
    ///Throws: std::invalid_arguments if this.size != b.size.
    BitArray& operator|=(const BitArray& b);
    ///Effects: Bitwise-XOR with assignment.
    ///Throws: std::invalid_arguments if this.size != b.size.
    BitArray& operator^=(const BitArray& b);
    ///Effects: Shifts the bits with zero-filling from the end in this set of bits to the left by n bits
    ///with the assignment.
    BitArray& operator<<=(int n);
    ///Effects: Shifts the bits with zero-filling from the begin in this set of bits to the right by n bits
    ///with the assignment.
    BitArray& operator>>=(int n);
    ///Effects: Shifts the bits with zero-filling from the end in this set of bits to the left by n bits.
    BitArray operator<<(int n) const;
    ///Effects: Shifts the bits with zero-filling from the begin in this set of bits to the right by n bits.
    BitArray operator>>(int n) const;
    ///Effects: Returns the bit by index i.
    bool operator[] (int i) const;
    ///Effects: Bitwise inversion.
    BitArray operator~() const;

    ///Effects: Exchanges the values of two bitArrays.
    void swap(BitArray& bitArray);
    ///Effects: Changes the size of the array.
    ///In case of expansion, new elements will be initialized with value.
    void resize(int nBits, bool value = false);
    ///Effects: Clears bitArray
    void clear();
    ///Effects: Adds a new bit to the end of the array. If necessary, memory is redistributed.
    void pushBack(bool bit);
    ///Effects: True, if the bitArray contains a true bit.
    bool any();
    ///Effects: True, if all bits of the bitArray are false.
    bool none();
    ///Effects: Counts the number of true bits.
    int count() const;
    ///Effects: Fills an array with true bits
    BitArray set();
    ///Effects: Sets the bit with index i to the value value.
    BitArray& set(int i, bool value = true);
    ///Effects: Fills an array with false bits
    BitArray& reset();
    ///Effects: Sets the bit with index i to false.
    BitArray& reset(int n);
    ///Effects: Returns the size of bitArray.
    int getSize() const;
    ///Effects: Returns true if the bitArray is empty.
    bool empty() const;
    ///Effects: Returns a string representation of an bitArray.
    std::string toString() const;
};


///Effects: Returns true if bitArrays are the same.
bool operator== (const BitArray& b1, const BitArray& b2);
///Effects: Returns true if bitArrays are not the same.
bool operator!= (const BitArray & b1, const BitArray & b2);
///Effects: Bitwise-AND.
///Throws: std::invalid_arguments if this.size != b.size.
BitArray operator& (const BitArray& b1, const BitArray& b2);
///Effects: Bitwise-OR.
///Throws: std::invalid_arguments if this.size != b.size.
BitArray operator| (const BitArray& b1, const BitArray& b2);
///Effects: Bitwise-XOR.
///Throws: std::invalid_arguments if this.size != b.size.
BitArray operator^ (const BitArray& b1, const BitArray& b2);