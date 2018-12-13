#pragma once

#include <cstring>
#include "fmt/format.h"

namespace dbindex {
    template <unsigned int N> union Gram {
        Gram() : value(0) {}
        Gram(unsigned int val) : value(val) {}
        Gram(const char *str) : value(0) { memcpy(data, str, N); }
        unsigned char data[N];
        unsigned int value;
    };

    // Trigram is the optimal for code/text search engine.
    using Bigram = Gram<2>;
    using Trigram = Gram<3>;
    using Fourgram = Gram<4>;
    
    template <typename Container,  typename T> struct TrigramAnalysisPolicy {
        // Build the list of found trigrams.
        void process(const char *begin, const char *end) {
            const char *stop = end - 2;
            const char *ptr = begin;
            while (ptr < stop ) {
                T val(ptr++);
                grams.insert(val.value);
            }

        }

        void print() const {
            fmt::print("Dictionary size:  {}\n", grams.size());
            for (auto item : grams) {
                fmt::print("{}\n", T(item).data);
            }
        }
        
        Container grams;
    };
} // namespace dbindex
