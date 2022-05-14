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
    for (auto x: list){
        output+=x->toString();
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