#include "fmt/format.h"
#include "tsl/hopscotch_set.h"
#include <algorithm>
#include <cstring>

namespace index_engine {
static constexpr std::array<char, 3> special_characters = {{'*', '.', '\\'}};
static constexpr std::array<char, 70> valid_characters = {
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
     'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B',
     'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
     '4', '5', '6', '7', '8', '9', ':', ' ', '/', '"', '<', '>', '[', ']'}};

class RegexToTrie {
public:
  void operator()(const char *pattern) {
    for (auto ch : valid_characters) {
      fmt::print("{}, ", ch);
    }
    fmt::print("\n");
    for (auto ch : special_characters) {
      fmt::print("{}, ", ch);
    }
    fmt::print("\n");
  }

private:
  const tsl::hopscotch_set<std::string> special_char_table;
};
} // namespace index_engine

int main() {
  index_engine::RegexToTrie eng;
  eng("Hello world");
}
