#include <iostream>
#include <bitset>

//mask(4, 3) -> 0b01111000

// first thought
std::bitset<8> bitset_mask(size_t length, size_t pos) {
    std::bitset<8> b;
    
    for(size_t i = pos;i<length+pos;++i) {
      b[i] = true;
    }
    
    return b;
}

//second thought
uint32_t mask(size_t length, size_t pos) {
    uint32_t result = 0;
    
    for(size_t i = pos; i<pos+length; ++i) {
      result |= 1<<i;
    }
    
    return result;
}

// possible optimization:
// use inline
inline uint32_t inline_mask(const size_t& length
                          , const size_t& pos) {
    uint32_t result = 0;
    
    for(size_t i = pos; i<pos+length; ++i) {
      result |= 1<<i;
    }
    
    return result;
}


int main() {
  std::cout<<bitset_mask(4,3)<<'\n';
  std::cout<<std::bitset<8>(mask(4,3))<<'\n';
  std::cout<<std::bitset<8>(inline_mask(4,3))<<'\n';
}