/**
 * @brief Concepts
 * https://en.cppreference.com/w/cpp/language/constraints
 */

#include <concepts>
#include <string>

/**
 * @brief Declaration of the concept "Hashable", which is satisfied by any type 'T'
 *      such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
 *      compiles and its result is convertible to std::size_t
 */
template<typename T>
concept Hashable = requires(T a)
{
  { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

template<Hashable T>
void f1(T) {}

template<typename T>
requires Hashable<T>
void f2(T) {}

template<typename T>
void f3(T) requires Hashable<T> {}

struct meow {};

int main() {
  f1("abc");
  f2("abc");
  f3("abc");
  // f(meow{});
}
