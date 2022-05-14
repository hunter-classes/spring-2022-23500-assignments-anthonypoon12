#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

Dictionary *dictionary = new Dictionary();
Person *Anthony = new Person("Anthony", "Poon", 1);
Person *Hunter = new Person("Hunter", "College", 2);
Person *Baruch = new Person("Baruch", "School", 2);
Person *idkman = new Person("IDK", "Man", 2);
Person *whatdoiput = new Person("WhatDo", "IPut", 2);
Person *arandomname = new Person("ARandomfawdafeg", "Name", 2);
TEST_CASE("Hash function"){
    CHECK(dictionary->hashfunc(Anthony->get_name(),10)==5);
    CHECK(dictionary->hashfunc(Hunter->get_name(),10)==5);
    CHECK(dictionary->hashfunc(Baruch->get_name(),10)==9);
    CHECK(dictionary->hashfunc(idkman->get_name(),10)==6);
    CHECK(dictionary->hashfunc(whatdoiput->get_name(),10)==5);
    CHECK(dictionary->hashfunc(arandomname->get_name(),10)==6);
}
TEST_CASE("insert and allKeys"){
    dictionary->insert(Anthony);
    dictionary->insert(Hunter);
    dictionary->insert(Baruch);
    dictionary->insert(idkman);
    dictionary->insert(whatdoiput);
    dictionary->insert(arandomname);
}
TEST_CASE("Retrieve"){
    CHECK(dictionary->retrieve("Poon, Anthony")==Anthony);
    CHECK(dictionary->retrieve("College, Hunter")==Hunter);
    CHECK(dictionary->retrieve("School, Baruch")==Baruch);
    CHECK(dictionary->retrieve("Man, IDK")==idkman);
    CHECK(dictionary->retrieve("IPut, WhatDo")==whatdoiput);
    CHECK(dictionary->retrieve("Name, ARandomfawdafeg")==arandomname);
    delete dictionary;
}