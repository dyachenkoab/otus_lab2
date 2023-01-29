#include <string>
#include <iostream>
#include <tuple>
#include <cassert>

auto getPerson()
{
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return std::make_tuple(name, secondName, age, department);
}

template<typename... T>
std::tuple<T&...> custom_tie(T&... args);

int main(int argc, char *argv[])
{
    std::string name, secondName, department;
    std::size_t age = 0;
    custom_tie(name, secondName, age, department) = getPerson();
    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    return 0;
}


template<typename... T>
std::tuple<T&...> custom_tie(T&... args)
{
//    return {args...};
    return std::tuple<T&...>(args...);
}
