#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <random>
#include <chrono>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

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

const char8_t* yul = u8"열";
const char8_t* sumul = u8"스물";
const char8_t* suhlun = u8"서른";
const char8_t* mahun = u8"마흔";
const char8_t* shin = u8"쉰";
const char8_t* yesun = u8"예순";
const char8_t* ilhun = u8"일흔";
const char8_t* yuhdun = u8"여든";
const char8_t* ahun = u8"아흔";

void help() {
    puts("Usage:");
    puts("  --max <integer> - set maximum value for generated value (default 999,999,999,999)");
    puts("  [-a | --alt] - use alternate Korean Numbers (up to 99)");
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

int main(int argc, char **argv) {
    unsigned long long max = 9999999999999;
    bool isAlt = false;

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
        }
        --argc; ++argv;
    }

    if(isAlt) {
        printf("Using alternate Korean numbers, ");
        if(max > 99) { max = 99; }
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
    auto value_str = isAlt ? value_to_korean_alt(value) : value_to_korean(value);
    std::cout.write((char*)value_str.c_str(), value_str.size());
    std::cout << std::endl;

    return 0;
}
