#include <iostream>
#include <vector>
#include <ranges>
#include <string>

int main() {
    std::cout << "--- Modern C++20 Ranges and Structured Bindings Demo ---" << std::endl;

    struct Person {
        std::string name;
        int age;
    };

    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Diana", 28}
    };

    // Filter and transform using C++20 ranges
    auto results = people 
        | std::views::filter([](const Person& p) { return p.age > 27; })
        | std::views::transform([](const Person& p) { return p.name + " (" + std::to_string(p.age) + ")"; });

    std::cout << "People older than 27:\n";
    for (const auto& name_with_age : results) {
        std::cout << " - " << name_with_age << "\n";
    }

    return 0;
}
