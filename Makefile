COMMON_CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++20
ifdef DEBUG
	CXXFLAGS = -O0 -g ${COMMON_CXXFLAGS}
else
	CXXFLAGS = -O3 ${COMMON_CXXFLAGS}
endif

all: KoreanNumbers

KoreanNumbers: src/main.o
	$(CXX) $(CXXFLAGS) -o KoreanNumbers $^

.PHONY:

clean:
	rm -f KoreanNumbers
	rm -f src/*.o
