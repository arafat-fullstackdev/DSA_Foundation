#include <bits/stdc++.h>
using namespace std;

struct Person
{
    std::string name;
    int age;

    // A method to display person details
    void display() const
    {
        std::cout << "Name: " << name << " Age:" << age << std::endl;
    }
};

int main()
{
    Person person1;
    person1.name = "Alen Border";
    person1.age = 22;

    person1.display();
    return 0;
}