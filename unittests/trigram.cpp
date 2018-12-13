#include "gram.hpp"
#include "fmt/format.h"
#include "unordered_set"
#include "set"

int main() {
    using Gram = dbindex::Gram<3>;
    Gram val1{4096};
    Gram val2{1023};
    Gram val3{};

    std::string data("Hello world!");
    Gram val4(data.data());
    Gram val5(data.data() + 1);

    
    fmt::print("val1: {:x}\n", val1.value);
    fmt::print("val2: {:x}\n", val2.value);
    fmt::print("val3: {:x}\n", val3.value);

    fmt::print("val3: {:x}\n", val4.value);
    fmt::print("val3: {}\n", val4.data);

    fmt::print("val3: {:x}\n", val5.value);
    fmt::print("val3: {}\n", val5.data);

    // Test the analysis policy
    using Container = std::unordered_set<unsigned int>;
    dbindex::TrigramAnalysisPolicy<Container, dbindex::Trigram> anal;
    anal.process(data.data(), data.data() + data.size());
    anal.print();
    
    return EXIT_SUCCESS;
}
