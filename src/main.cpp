#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <random>
#include <chrono>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

const char8_t* won = u8"원";
const char8_t* ship = u8"십";
const char8_t* bec = u8"백";
const char8_t* chun = u8"천";
const char8_t* man = u8"만";
const char8_t* uc = u8"억";

void help() {
    puts("Usage:");
    puts("  --max <integer> - set maximum value for generated value (default 999,999,999,999)");
}

std::u8string value_to_korean(unsigned long long value) {
    std::u8string s;

    unsigned long long temp;
    if(temp = (value / 1000000000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(man);
    }
    if(temp = (value / 100000000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(chun);
    }
    if(temp = (value / 10000000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(bec);
    }
    if(temp = (value / 1000000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(ship);
    }
    if(temp = (value / 100000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(uc);
    } else if(!s.empty()) {
        s.append(uc);
    }
    if(temp = (value / 10000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(chun);
    }
    if(temp = (value / 1000000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(bec);
    }
    if(temp = (value / 100000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(ship);
    }
    if(temp = (value / 10000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(man);
    } else if(!s.empty()) {
        s.append(man);
    }
    if(temp = (value / 1000) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(chun);
    }
    if(temp = (value / 100) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(bec);
    }
    if(temp = (value / 10) % 10; temp > 0) {
        if(temp != 1) {
            s.push_back('0' + temp);
        }
        s.append(ship);
    }
    if(temp = value % 10; temp > 0) {
        s.push_back('0' + temp);
    }
    if(s.empty()) {
        s.push_back('0');
    }
    s.append(won);

    return s;
}

int main(int argc, char **argv) {
    unsigned long long max = 999999999999;

    --argc; ++argv;
    while(argc > 0) {
        if(std::strcmp(argv[0], "--help") == 0 || std::strcmp(argv[0], "-h") == 0) {
            help();
            return 0;
        } else if(std::strcmp(argv[0], "--max") == 0 && argc > 1) {
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

    printf("\nGot value \"");
    {
        std::string s;
        unsigned long long temp = value;
        unsigned char count = 0;
        while(temp > 0) {
            ++count;
            s.push_back('0' + temp % 10);
            temp /= 10;
            if(count == 3 && temp > 0) {
                s.push_back(',');
                count = 0;
            }
        }
        std::reverse(s.begin(), s.end());
        std::cout << s;
    }
    printf("\", hit enter to continue...");

    std::cin.get();

    std::cout << "Result: ";
    auto value_str = value_to_korean(value);
    std::cout.write((char*)value_str.c_str(), value_str.size());
    std::cout << std::endl;

    return 0;
}
