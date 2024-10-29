#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     delete j;
//     delete i;
//     return 0;
// }

int main()
{
    const int size = 10; // Define the size of the array
    const Animal* animals[size]; // Create an array of pointers to Animal objects

    // Fill the first half with Dog objects
    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }

    // Fill the second half with Cat objects
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }

    // Loop over the array and delete each Animal object
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    return 0;
}