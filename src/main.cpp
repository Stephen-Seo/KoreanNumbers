#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <random>
#include <chrono>
#include <memory>
#include <string>
#include <iostream>

const wchar_t* won = L"원";
const wchar_t* ship = L"십";
const wchar_t* bec = L"백";
const wchar_t* chun = L"천";
const wchar_t* man = L"만";
const wchar_t* uc = L"억";

void help() {
    puts("Usage:");
    puts("  --max <integer> - set maximum value for generated value (default 999,999,999,999)");
}

std::wstring value_to_korean(unsigned long long value) {
    return L"UNIMPLEMENTED";
}

int main(int argc, char **argv) {
    unsigned long long max = 999999999999;

    --argc; ++argv;
    while(argc > 0) {
        if(std::strcmp(argv[0], "--max") == 0 && argc > 1) {
            --argc; ++argv;
            max = std::strtoull(argv[0], nullptr, 0);
        }
        --argc; ++argv;
    }

    printf("Maximum value is set to %llu\n", max);

    unsigned long long value;
    {
        std::default_random_engine r_eng(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<unsigned long long> r_dist(0, max);
        value = r_dist(r_eng);
    }

    printf("\nGot value \"%llu\", hit enter to continue...", value);
    std::cin.get();

    std::wcout << "Result: " << value_to_korean(value) << std::endl;

    return 0;
}
