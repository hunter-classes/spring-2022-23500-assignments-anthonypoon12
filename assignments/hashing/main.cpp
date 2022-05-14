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
    Person *Anthony = new Person("Anthony", "Poon", 1);
    Person *Hannibal =new Person("Hannibal", "Lecter", 2);
    Person *Hunter =new Person("Hunter", "Mascot", 3);
    Person *John =new Person("John", "Boyardee", 4);
    Person *Pikachu =new Person("Pikachu", "Charizard", 5);
    Person *Ash =new Person("Ash", "Ketchum", 6);
    Person *Kim =new Person("Kim", "Hi", 7);
    Person *Mike = new Person("Mike", "Make", 8);
    Person *Creative =new Person("Creative", "Name", 9);
    Person *Last =new Person("Last", "One", 10);
    std::cout<<"All Keys right now:\n"<<dictionary->allKeys()<<"\n\n\n";
    std::cout<<"Inserting Anthony Poon\n";
    dictionary->insert(Anthony);
    std::cout<<"Inserting Hannibal Lecter\n";
    dictionary->insert(Hannibal);
    std::cout<<"Inserting Hunter Mascot\n";
    dictionary->insert(Hunter);
    std::cout<<"Inserting John Boyardee\n";
    dictionary->insert(John);
    std::cout<<"Inserting Pikachu Charizard\n";
    dictionary->insert(Pikachu);
    std::cout<<"Inserting Ash Ketchum\n";
    dictionary->insert(Ash);
    std::cout<<"Inserting Kim Hi\n";
    dictionary->insert(Kim);
    std::cout<<"Inserting Mike Make\n";
    dictionary->insert(Mike);
    std::cout<<"Inserting Creative Name\n";
    dictionary->insert(Creative);
    std::cout<<"Inserting Last One\n";
    dictionary->insert(Last);
    for (auto x: {Anthony, Hannibal, Hunter, John, Pikachu, Ash, Kim, Mike, Creative, Last}){
        std::cout<<"Hash Function value of "<< x->get_name()<<" is "<< dictionary->hashfunc(x->get_name(), 10)<<'\n';
    }
    std::cout<<"All Keys right now:\n"<<dictionary->allKeys()<<"\n\n\n";
    std::cout<<"The address assosciated with Poon, Anthony is: "<<dictionary->retrieve("Poon, Anthony")<<"\n";
    std::cout<<"The name assosciated with Poon, Anthony is: ";
    if(dictionary->retrieve("Poon, Anthony")!=nullptr)
        std::cout<<dictionary->retrieve("Poon, Anthony")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    std::cout<<"The Address assosciated with Make, Mike is: "<<dictionary->retrieve("Make, Mike")<<"\n";
    std::cout<<"The name assosciated with Make, Mike is: ";
    if(dictionary->retrieve("Make, Mike")!=nullptr)
        std::cout<<dictionary->retrieve("Make, Mike")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    std::cout<<"The Address assosciated with NotAReal, Name is: "<<dictionary->retrieve("NotAReal, Name")<<"\n";
    std::cout<<"The name assosciated with NotAReal, Name is: ";
    if(dictionary->retrieve("NotAReal, Name")!=nullptr)
        std::cout<<dictionary->retrieve("NotAReal, Name")->get_name()<<"\n";
    else
        std::cout<<"Not in dictionary\n";
    delete dictionary;
    return 0;
}