#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <random>
#include <chrono>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

#define KOREAN_NUMBERS_MAX 9999999999999llu
#define KOREAN_NUMBERS_ALT_MAX 99llu

const char8_t* il = u8"일";
const char8_t* ee = u8"이";
const char8_t* sam = u8"삼";
const char8_t* sa = u8"사";
const char8_t* oh = u8"오";
const char8_t* yuk = u8"육";
const char8_t* chil = u8"칠";
const char8_t* pal = u8"팔";
const char8_t* gu = u8"구";

const char8_t* ship = u8"십";
const char8_t* bec = u8"백";
const char8_t* chun = u8"천";
const char8_t* man = u8"만";
const char8_t* uc = u8"억";
const char8_t* jo = u8"조";
//const char8_t* won = u8"원";

const char8_t* hana = u8"하나";
const char8_t* dul = u8"둘";
const char8_t* set = u8"셋";
const char8_t* net = u8"넷";
const char8_t* dasut = u8"다섯";
const char8_t* yusut = u8"여섯";
const char8_t* ilgop = u8"일곱";
const char8_t* yudul = u8"여덟";
const char8_t* ahop = u8"아홉";

const char8_t* yul = u8"열";        // 10
const char8_t* sumul = u8"스물";    // 20
const char8_t* suhlun = u8"서른";   // 30
const char8_t* mahun = u8"마흔";    // 40
const char8_t* shin = u8"쉰";       // 50
const char8_t* yesun = u8"예순";    // 60
const char8_t* ilhun = u8"일흔";    // 70
const char8_t* yuhdun = u8"여든";   // 80
const char8_t* ahun = u8"아흔";     // 90

void help() {
    puts("Usage:");
    puts("  --min <integer> - set minimum value for generated value (default 1)");
    printf("  --max <integer> - set maximum value for generated value (default %llu, alt default %llu)\n",
            KOREAN_NUMBERS_MAX, KOREAN_NUMBERS_ALT_MAX);
    puts("  [-a | --alt] - use alternate Korean Numbers (up to 99)");
    puts("  [-r | --reverse] - display Korean form first");
    puts("  [-d | --digits] - do not randomize digits when non-alternate");
}

const char8_t* digit_to_kword(int n) {
    switch(n) {
    case 9:
        return gu;
    case 8:
        return pal;
    case 7:
        return chil;
    case 6:
        return yuk;
    case 5:
        return oh;
    case 4:
        return sa;
    case 3:
        return sam;
    case 2:
        return ee;
    case 1:
        return il;
    default:
        return u8"";
    }
}

std::u8string value_to_korean(unsigned long long value) {
    std::u8string s;

    unsigned long long temp;
    if(temp = (value / 1000000000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(jo);
    }
    if(temp = (value / 100000000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(chun);
    }
    if(temp = (value / 10000000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(bec);
    }
    if(temp = (value / 1000000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(ship);
    }
    if(temp = (value / 100000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(uc);
    } else if(!s.empty()) {
        if(!s.empty()) { s.push_back(' '); }
        s.append(il);
        s.append(uc);
    }
    if(temp = (value / 10000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(chun);
    }
    if(temp = (value / 1000000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(bec);
    }
    if(temp = (value / 100000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(ship);
    }
    if(temp = (value / 10000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(man);
    } else if(!s.empty()) {
        s.append(man);
    }
    if(temp = (value / 1000) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(chun);
    }
    if(temp = (value / 100) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(bec);
    }
    if(temp = (value / 10) % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        if(temp != 1) { s.append(digit_to_kword(temp)); }
        s.append(ship);
    }
    if(temp = value % 10; temp > 0) {
        if(!s.empty()) { s.push_back(' '); }
        s.append(digit_to_kword(temp));
    }
    if(s.empty()) {
        s.push_back('0');
    }
//    s.append(won);

    return s;
}

std::u8string value_to_korean_alt(unsigned long long value) {
    std::u8string s;

    switch(value / 10) {
    case 9:
        s.append(ahun);
        break;
    case 8:
        s.append(yuhdun);
        break;
    case 7:
        s.append(ilhun);
        break;
    case 6:
        s.append(yesun);
        break;
    case 5:
        s.append(shin);
        break;
    case 4:
        s.append(mahun);
        break;
    case 3:
        s.append(suhlun);
        break;
    case 2:
        s.append(sumul);
        break;
    case 1:
        s.append(yul);
        break;
    default:
        break;
    }

    switch(value % 10) {
    case 9:
        if(!s.empty()) { s.push_back(' '); }
        s.append(ahop);
        break;
    case 8:
        if(!s.empty()) { s.push_back(' '); }
        s.append(yudul);
        break;
    case 7:
        if(!s.empty()) { s.push_back(' '); }
        s.append(ilgop);
        break;
    case 6:
        if(!s.empty()) { s.push_back(' '); }
        s.append(yusut);
        break;
    case 5:
        if(!s.empty()) { s.push_back(' '); }
        s.append(dasut);
        break;
    case 4:
        if(!s.empty()) { s.push_back(' '); }
        s.append(net);
        break;
    case 3:
        if(!s.empty()) { s.push_back(' '); }
        s.append(set);
        break;
    case 2:
        if(!s.empty()) { s.push_back(' '); }
        s.append(dul);
        break;
    case 1:
        if(!s.empty()) { s.push_back(' '); }
        s.append(hana);
        break;
    default:
        break;
    }

    return s;
}

void printValue(unsigned long long value) {
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

unsigned long long clamp_digits(unsigned int digits, unsigned long long value) {
    if(digits == 0) {
        digits = 1;
    }

    unsigned long long temp = 0;
    while(digits-- > 0) {
        temp = temp * 10 + 9;
    }
    if(temp < value) {
        return temp;
    } else {
        return value;
    }
}

int main(int argc, char **argv) {
    unsigned long long min = 1;
    unsigned long long max = KOREAN_NUMBERS_MAX;
    bool isAlt = false;
    bool reverse = false;
    bool randomizeDigits = true;

    --argc; ++argv;
    while(argc > 0) {
        if(std::strcmp(argv[0], "--help") == 0 || std::strcmp(argv[0], "-h") == 0) {
            help();
            return 0;
        } else if(std::strcmp(argv[0], "--max") == 0 && argc > 1) {
            --argc; ++argv;
            max = std::strtoull(argv[0], nullptr, 0);
        } else if(std::strcmp(argv[0], "-a") == 0 || std::strcmp(argv[0], "--alt") == 0) {
            isAlt = true;
        } else if(std::strcmp(argv[0], "-r") == 0 || std::strcmp(argv[0], "--reverse") == 0) {
            reverse = true;
        } else if(std::strcmp(argv[0], "--min") == 0 && argc > 1) {
            --argc; ++argv;
            min = std::strtoull(argv[0], nullptr, 0);
        } else if(std::strcmp(argv[0], "-d") == 0 || std::strcmp(argv[0], "--digits") == 0) {
            randomizeDigits = false;
        }
        --argc; ++argv;
    }

    if(min == 0) {
        min = 1;
    }

    if(isAlt) {
        printf("Using alternate Korean numbers, ");
        if(max > KOREAN_NUMBERS_ALT_MAX) { max = KOREAN_NUMBERS_ALT_MAX; }
        else if(max == 0) { max = 1; }
    } else {
        if(max > KOREAN_NUMBERS_MAX) {
            max = KOREAN_NUMBERS_MAX;
        } else if(max == 0) {
            max = 1;
        }
    }

    if(min > max) {
        min = max;
    }
    printf("Min value is set to %llu, Max value is set to %llu\n", min, max);

    unsigned int digits = 0;
    if(!isAlt && randomizeDigits) {
        unsigned long long temp = max;
        while(temp > 0) {
            ++digits;
            temp /= 10;
        }
        if(digits == 0) { digits = 1; }
        printf("%u digits detected for max value, "
               "randomizing the number of digits...\n",
                digits);
    }

    unsigned long long value;
    {
        std::default_random_engine r_eng(std::chrono::steady_clock::now().time_since_epoch().count());
        if(!isAlt && randomizeDigits) {
            std::uniform_int_distribution<unsigned int> d_dist(1, digits);
            digits = d_dist(r_eng);
        }
        std::uniform_int_distribution<unsigned long long> r_dist(
            min,
            isAlt || !randomizeDigits ?
                max :
                clamp_digits(digits, max)
            );
        value = r_dist(r_eng);
    }

    if(reverse) {
        auto value_str = isAlt ? value_to_korean_alt(value) : value_to_korean(value);
        printf("\nGot Korean form \"");
        std::cout.write((char*)value_str.c_str(), value_str.size());
        std::cout << "\"";
    } else {
        printf("\nGot value \"");
        printValue(value);
        printf("\"");
    }
    printf(", hit enter to continue...");

    std::cin.get();

    std::cout << "Result: ";
    if(reverse) {
        printValue(value);
        std::cout << std::endl;
    } else {
        auto value_str = isAlt ? value_to_korean_alt(value) : value_to_korean(value);
        std::cout.write((char*)value_str.c_str(), value_str.size());
        std::cout << std::endl;
    }

    return 0;
}
