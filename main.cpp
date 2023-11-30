#include "adder.h"



int main() {
    auto *first = new HashedArray<string>();

    first->add("DAWID");
    first->add("DASHA");
    first->add("VLADICK");
    first->add("dasha");
    first->add("Mikhail");
    first->add("AnToM");
    first->searchData("VLADICK");
    first->add("Zalupa");
    first->add("Uzumaki");
    first->add("Sisi");
    first->add("Sisik");
    first->add("Sisikk");
    first->add("Sisidsadgfdgkk");
    first->add("Sisdsadsadikk");
    first->add("Sisidsadsakk");
    first->add("Sisiksadk");
    first->add("Sisidsadsadkk");
    first->add("Sisikk");
    first->add("Sdsadsadsad");
    first->add("Sisdsfdsikk");
    first->add("Sisifdewkk");
    first->add("Sisigfdgkk");
    first->add("Sisdsfikk");
    first->add("Siscxvxikk");
    first->show();

    first->erase();
    first->add("DAWID");
    first->add("Sisidsadsakk");
    first->add("Sisiksadk");
    first->add("Sisidsadsadkk");
    first->add("Sisikk");
    first->add("Sdsadsadsad");
    first->add("Sisdsfdsikk");
    std::cout << first->size;

    first->add("Sisdsfdsikk");
    first->add("Sisdsfdsikk");
    first->add("Sisdsfdsikk");
    std::cout << first->size;
}