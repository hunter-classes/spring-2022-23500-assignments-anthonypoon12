#include <iostream>
#include "Dictionary.h"
int main(){
    std::cout<<"Creating Dictionary...\n";
    Dictionary *dictionary = new Dictionary();
    std::cout<<"Retrieving a random name from dictionary: ";
    if(dictionary->retrieve("random, name")!=nullptr)
        std::cout<<dictionary->retrieve("random, name")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    std::cout<<"All Keys right now: "<<dictionary->allKeys()<<"\n\n\n";
    std::cout<<"Inserting Anthony Poon\n";
    dictionary->insert(new Person("Anthony", "Poon", 1));
    std::cout<<"Inserting Hannibal Lecter\n";
    dictionary->insert(new Person("Hannibal", "Lecter", 2));
    std::cout<<"Inserting Hunter Mascot\n";
    dictionary->insert(new Person("Hunter", "Mascot", 3));
    std::cout<<"Inserting John Boyardee\n";
    dictionary->insert(new Person("John", "Boyardee", 4));
    std::cout<<"Inserting Pikachu Charizard\n";
    dictionary->insert(new Person("Pikachu", "Charizard", 5));
    std::cout<<"Inserting Ash Ketchum\n";
    dictionary->insert(new Person("Ash", "Ketchum", 6));
    std::cout<<"Inserting Kim Hi\n";
    dictionary->insert(new Person("Kim", "Hi", 7));
    std::cout<<"Inserting Mike Make\n";
    dictionary->insert(new Person("Mike", "Make", 8));
    std::cout<<"Inserting Creative Name\n";
    dictionary->insert(new Person("Creative", "Name", 9));
    std::cout<<"Inserting Last One\n";
    dictionary->insert(new Person("Last", "One", 10));
    std::cout<<"All Keys right now: "<<dictionary->allKeys()<<"\n\n\n";
    std::cout<<"The name assosciated with Poon, Anthony is: ";
    if(dictionary->retrieve("Poon, Anthony")!=nullptr)
        std::cout<<dictionary->retrieve("Poon, Anthony")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    std::cout<<"The name assosciated with Make, Mike is: ";
    if(dictionary->retrieve("Make, Mike")!=nullptr)
        std::cout<<dictionary->retrieve("Make, Mike")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    std::cout<<"The name assosciated with NotAReal, Name is: ";
    if(dictionary->retrieve("NotAReal, Name")!=nullptr)
        std::cout<<dictionary->retrieve("NotAReal, Name")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    delete dictionary;
    return 0;
}