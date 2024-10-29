#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    // const AAnimal* animal = new AAnimal();

    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!

    delete j;
    delete i;

    return 0;
}