#include <cstdint>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
  uint64_t summ = a + b;
  if(summ == 0) return std::string("0");
  std::string result;
  while(summ != 0) {
    result.insert(result.begin(), ((((summ & 1) == 1) ? 1 : 0) + '0')  ) , summ >>= 1;
  }
    return result;
}