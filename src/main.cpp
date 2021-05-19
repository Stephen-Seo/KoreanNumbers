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
    puts("  [-l | --list] - list \"base\" numbers (can combine with --alt)");
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

std::ostream& operator<<(std::ostream &os, const std::u8string &str) {
    os.write(reinterpret_cast<const char*>(str.data()), str.size());
    return os;
}

std::ostream& operator<<(std::ostream &os, const char8_t *str8) {
    const char *cstr = reinterpret_cast<const char*>(str8);
    os.write(cstr, strlen(cstr));
    return os;
}

void doPrintBasic(bool isAlt) {
    if(isAlt) {
        std::cout << "\"1\" or \"one\" (alt) is " << hana << std::endl;
        std::cout << "\"2\" or \"two\" (alt) is " << dul << std::endl;
        std::cout << "\"3\" or \"three\" (alt) is " << set << std::endl;
        std::cout << "\"4\" or \"four\" (alt) is " << net << std::endl;
        std::cout << "\"5\" or \"five\" (alt) is " << dasut << std::endl;
        std::cout << "\"6\" or \"six\" (alt) is " << yusut << std::endl;
        std::cout << "\"7\" or \"seven\" (alt) is " << ilgop << std::endl;
        std::cout << "\"8\" or \"eight\" (alt) is " << yudul << std::endl;
        std::cout << "\"9\" or \"nine\" (alt) is " << ahop << std::endl;
        std::cout << "\"10\" or \"ten\" (alt) is " << yul << std::endl;
        std::cout << "\"20\" or \"twenty\" (alt) is " << sumul << std::endl;
        std::cout << "\"30\" or \"thirty\" (alt) is " << suhlun << std::endl;
        std::cout << "\"40\" or \"fourty\" (alt) is " << mahun << std::endl;
        std::cout << "\"50\" or \"fifty\" (alt) is " << shin << std::endl;
        std::cout << "\"60\" or \"sixty\" (alt) is " << yesun << std::endl;
        std::cout << "\"70\" or \"seventy\" (alt) is " << ilhun << std::endl;
        std::cout << "\"80\" or \"eighty\" (alt) is " << yuhdun << std::endl;
        std::cout << "\"90\" or \"ninety\" (alt) is " << ahun << std::endl;
    } else {
        std::cout << "\"1\" or \"one\" is " << il << std::endl;
        std::cout << "\"2\" or \"two\" is " << ee << std::endl;
        std::cout << "\"3\" or \"three\" is " << sam << std::endl;
        std::cout << "\"4\" or \"four\" is " << sa << std::endl;
        std::cout << "\"5\" or \"five\" is " << oh << std::endl;
        std::cout << "\"6\" or \"six\" is " << yuk << std::endl;
        std::cout << "\"7\" or \"seven\" is " << chil << std::endl;
        std::cout << "\"8\" or \"eight\" is " << pal << std::endl;
        std::cout << "\"9\" or \"nine\" is " << gu << std::endl;
        std::cout << "\"10\" or \"ten\" is " << ship << std::endl;
        std::cout << "\"100\" or \"one-hundred\" is " << bec << std::endl;
        std::cout << "\"1000\" or \"one-thousand\" is " << chun << std::endl;
        std::cout << "\"10,000\" or \"ten-thousand\" is " << man << std::endl;
        std::cout << "\"100,000,000\" or \"one-hundred-million\" is " << uc << std::endl;
        std::cout << "\"1,000,000,000,000\" or \"one-trillion\" is " << jo << std::endl;
    }
}

int main(int argc, char **argv) {
    unsigned long long min = 1;
    unsigned long long max = KOREAN_NUMBERS_MAX;
    bool isAlt = false;
    bool reverse = false;
    bool randomizeDigits = true;
    bool printBasic = false;

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
        } else if(std::strcmp(argv[0], "-l") == 0 || std::strcmp(argv[0], "--list") == 0) {
            printBasic = true;
        }
        --argc; ++argv;
    }

    if(printBasic) {
        doPrintBasic(isAlt);
        return 0;
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
        std::cout << value_str << "\"";
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
        std::cout << value_str << std::endl;
    }

    return 0;
}
