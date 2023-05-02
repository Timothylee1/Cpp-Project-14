#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <utility>
#include "array.hpp"

// private functions used in this 
namespace {

// write to output stream a pair<T1,T2>
  template <typename T1, typename T2>
  std::ostream& operator<<(std::ostream& os, std::pair<T1, T2>const& rhs);

// can be called with pair of following ranges:
// cont.begin() and cont.end() OR 
// cont.begin() const and cont.end() const OR
// cont.cbegin() and cont.cend()
template <typename It>
void PRINT_ELEMENTS(It first, It second, std::string const& prefix="", 
                   std::string const& sep=" ", std::string const& postfix="\n");

// uses cont.cbegin() and cont.cend()
template <typename Cont>
void PRINT_ELEMENTS(Cont const& cont, std::string const& prefix="", 
                   std::string const& sep=" ", std::string const& postfix="\n");


template <typename Cont, size_t N>
void PRINT_ELEMENTS(Cont const& cont, std::string const& prefix="",
                  std::string const& sep=" ", std::string const& postfix="\n");

void test_with_string();
void test_with_int();
void test_with_pair();
} // end anonymous namespace

int main(int argc, char **argv) {
  int test_num {0};
  if (argc > 1) {
    test_num = std::stoi(argv[1]);
  }

  using TPF = void (*)();
  int constexpr num_of_tests {3};
  std::array<TPF, num_of_tests> Tests {
    test_with_string, // 1 - correct output is in test-string.txt
    test_with_int,       // 2 - correct output is in test-int.txt
    test_with_pair       // 3 - correct output is in test-pair.txt
  };

  if (test_num == 0) { // correct output when argv[1] is "0" is in test-all.txt
    for (TPF x : Tests) {
      x();
    }
  } else if (test_num > 0 && test_num <= num_of_tests) {
    Tests[test_num - 1]();
  }
}

namespace {

void test_with_string() {
  // Test: default construction with initializer list
  hlp2::Array<std::string, 5> a{"1","2","3","4","5"};
  // Test: begin() and end()
  PRINT_ELEMENTS(a.begin(), a.end(), "a: ", " ");
  // Test: fill()
  a.fill("a");
  // Test: cbegin() and cend()
  PRINT_ELEMENTS(a, "a: ", " ");

  // Test: fill()
  hlp2::Array<std::string, 5> b; b.fill("z");
  // Test: operator[]()
  PRINT_ELEMENTS<hlp2::Array<std::string,5>,5>(b, "b: ", " ");

  // Test: swap()
  a.swap(b);
  PRINT_ELEMENTS(a, "a: ", " ");
  PRINT_ELEMENTS(b, "b: ", " ");

  // Test: empty(), size(), front() and back()
  std::cout << std::boolalpha << b.empty() << '\n';
  if (!b.empty()) {
    b.front() = "front"; b.back() = "back";
    std::cout << "b: ";
    for (size_t i{}; i < b.size(); ++i) {
      std::cout << b[i] << " ";
    }
    std::cout << "\n";
  }

  // Test: default assignment
  hlp2::Array<std::string, 5> const c = b;
  // Test: operator[]() const
  PRINT_ELEMENTS<hlp2::Array<std::string,5>,5>(c, "c: ", " ");
  
}


void test_with_int() {
  // Test: default construction with initializer list
  hlp2::Array<int, 10> a{1,3,5,7,9,11,13,15,17,19};
  // Test: begin() and end()
  PRINT_ELEMENTS(a.begin(), a.end(), "a: ", " ");
  // Test: fill()
  a.fill(99);
  // Test: cbegin() and cend()
  PRINT_ELEMENTS(a, "a: ", " ");

  // Test: fill()
  hlp2::Array<int, 10> b; b.fill(86);
  // Test: operator[]()
  PRINT_ELEMENTS<hlp2::Array<int,10>,10>(b, "b: ", " ");

  // Test: swap()
  a.swap(b);
  PRINT_ELEMENTS(a, "a: ", " ");
  PRINT_ELEMENTS(b, "b: ", " ");

  // Test: empty(), size(), front() and back()
  std::cout << std::boolalpha << b.empty() << '\n';
  if (!b.empty()) {
    b.front() = 0; b.back() = 100;
    std::cout << "b: ";
    for (size_t i{}; i < b.size(); ++i) {
      std::cout << b[i] << " ";
    }
    std::cout << "\n";
  }

  // Test: default assignment
  hlp2::Array<int, 10> const c = b;
  // Test: operator[]() const
  PRINT_ELEMENTS<hlp2::Array<int,10>,10>(c, "c: ", " ");
}


void test_with_pair() {
  using PSS = std::pair<std::string, std::string>;

  // Test: default construction with initializer list
  hlp2::Array<PSS, 4> a;
  a[0] = std::make_pair("Seattle", "WA");   a[1] = std::make_pair("Portland", "OR");
  a[2] = std::make_pair("Vancouver", "BC"); a[3] = std::make_pair("Toronto", "ON");
  // Test: begin() and end()
  PRINT_ELEMENTS(a.begin(), a.end(), "a: ", " ");
  // Test: fill()
  a.fill(PSS("Montreal", "PQ"));
  // Test: cbegin() and cend()
  PRINT_ELEMENTS(a, "a: ", " ");

  // Test: fill()
  hlp2::Array<PSS, 4> b {
    std::make_pair("San Jose", "PR"), std::make_pair("San Antonio", "TX"),
    std::make_pair("San Luis Obispo", "CA"), std::make_pair("San Carlos", "AZ")
  };
  // Test: operator[]()
  PRINT_ELEMENTS<hlp2::Array<PSS,4>,4>(b, "b: ", " ");

  // Test: swap()
  a.swap(b);
  PRINT_ELEMENTS(a, "a: ", " ");
  PRINT_ELEMENTS(b, "b: ", " ");

  // Test: empty(), size(), front() and back()
  std::cout << std::boolalpha << b.empty() << '\n';
  if (!b.empty()) {
    b.front() = std::make_pair("Santa Barbara", "CA");
    b.back()  = std::make_pair("Santa Rosa", "CA");
    std::cout << "b: ";
    for (size_t i{}; i < b.size(); ++i) {
      std::cout << b[i] << " ";
    }
    std::cout << "\n";
  }

  // Test: default assignment
  hlp2::Array<PSS, 4> const c = b;
  // Test: operator[]() const
  PRINT_ELEMENTS<hlp2::Array<PSS,4>,4>(c, "c: ", " ");
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2>const& rhs) {
  os << "<" << rhs.first << ", " << rhs.second << ">";
  return os;
}

template <typename It>
void PRINT_ELEMENTS(It first, It last, std::string const& prefix,
                    std::string const& sep, std::string const& postfix) {
  std::cout << prefix;
  while (first != last) {
    std::cout << *first << sep;
    ++first;
  }
  std::cout << postfix;
}

template <typename Cont>
void PRINT_ELEMENTS(Cont const& cont, std::string const& prefix, 
                    std::string const& sep, std::string const& postfix) {
  std::cout << prefix;
  typename Cont::const_iterator first = cont.cbegin(), last = cont.cend();
  while (first != last) {
    std::cout << *first << sep;
    ++first;
  }
  std::cout << postfix;
}

template <typename Cont, size_t N>
void PRINT_ELEMENTS(Cont const& cont, std::string const& prefix,
                  std::string const& sep, std::string const& postfix) {
  std::cout << prefix;
  for (typename Cont::size_type i{}; i < N; ++i) {
    std::cout << cont[i] << sep;
  }
  std::cout << postfix;
}

} // end anonymous namespace
