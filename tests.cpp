#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"

TEST_CASE("OList")
{
    OList *o = new OList();

    CHECK(o->toString() == "nullptr");
    CHECK(o->length() == 0);

    o->insert("a");
    CHECK(o->contains("a") == true);
    CHECK(o->toString() == "a-->nullptr");
    CHECK(o->length() == 1);

    o->insert("b");
    o->insert("c");
    o->insert("d");
    CHECK(o->contains("b") == true);
    CHECK(o->contains("c") == true);
    CHECK(o->contains("d") == true);
    CHECK(o->toString() == "a-->b-->c-->d-->nullptr");
    CHECK(o->length() == 4);

    o->insert("b");
    o->insert("k");
    o->insert("0");
    CHECK(o->toString() == "0-->a-->b-->b-->c-->d-->k-->nullptr");
    CHECK(o->length() == 7);
    
    CHECK(o->get(4) == "c");
    o->remove(4);
    CHECK(o->contains("c") == false);
    CHECK(o->toString() == "0-->a-->b-->b-->d-->k-->nullptr");
    CHECK(o->length() == 6);


}

