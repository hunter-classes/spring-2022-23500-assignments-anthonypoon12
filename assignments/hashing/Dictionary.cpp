#include "Dictionary.h"
Dictionary::Dictionary(){
    for (int i = 0; i < 10; i++){
        list[i]= new List();
    }
}
Dictionary::~Dictionary(){
    for (auto x: list)
        delete x;
}
void Dictionary::insert(Person *person){
    list[hashfunc(person->get_name(), 10)]->insert(person);
}
Person* Dictionary::retrieve(std::string name){
    return list[hashfunc(name, 10)]->findByName(name);
}
std::string Dictionary::allKeys(){
    std::string output = "";
    for (int x = 0; x < 10; x++){
        output+="List " + std::to_string(x) + ": " + list[x]->toString() + "\n";
    }
    return output.substr(0,output.size()-2);
}
int Dictionary::hashfunc(std::string x, int M) {
    int xlength = x.length();
    int i, sum;
    for (sum=0, i=0; i < x.length(); i++)
    sum += x[i];
    return sum % M;
}