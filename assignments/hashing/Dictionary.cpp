#include "Dictionary.h"

Dictionary::Dictionary(){
    for (int i = 0; i < 10; i++){
        list[i]= new List();
    }
}
Dictionary::~Dictionary(){

}
void Dictionary::insert(Person *person){
    
}
Person* Dictionary::retrieve(int id){
    return nullptr;
}
std::string Dictionary::allKeys(){
    return "";
}