#include <iostream>
#include <cstring>
// Structura pentru produsul software
struct ProdusSoftware {
    char* denumire;
    char* firmaProducere;
    int anulEditarii;
    double versiune;
};
// Functie pentru a inițializa un produs software
void InitializareProdus(ProdusSoftware& produs, const char* denumire, const char* firma, int an, double versiune) {
    produs.denumire = new char[strlen(denumire) + 1];
    strcpy(produs.denumire, denumire);
    produs.firmaProducere = new char[strlen(firma) + 1];
    strcpy(produs.firmaProducere, firma);
    produs.anulEditarii = an;
    produs.versiune = versiune;
}
// Functie pentru a modifica versiunea produsului software
void ModificareVersiune(ProdusSoftware& produs, double nouaVersiune) {
    produs.versiune = nouaVersiune;
}
// Functie pentru a compara doua produse software
bool ComparareProduse(const ProdusSoftware& produs1, const ProdusSoftware& produs2) {
    return (produs1.versiune == produs2.versiune);
}
// Functie pentru a elibera memoria alocata pentru un produs software
void EliberareMemorie(ProdusSoftware& produs) {
    delete[] produs.denumire;
    delete[] produs.firmaProducere;
}
int main() {
    ProdusSoftware produs1;
    // Citim datele de la tastatura
    char denumire1[256];
    char firma1[256];
    int an1;
    double versiune1;
    std::cout << "Introduceti denumirea produsului: ";
    std::cin.getline(denumire1, sizeof(denumire1));
    std::cout << "Introduceti firma de producere: ";
    std::cin.getline(firma1, sizeof(firma1));
    std::cout << "Introduceti anul editarii: ";
    std::cin >> an1;
    std::cout << "Introduceti versiunea: ";
    std::cin >> versiune1;
    std::cin.ignore();  // Pentru a citi newline dupa versiune
    InitializareProdus(produs1, denumire1, firma1, an1, versiune1);
    ProdusSoftware produs2;
    InitializareProdus(produs2, "Produs2", "Firma2", 2022, 2.5);
    // Modificam versiunea produsului 1
    ModificareVersiune(produs1, 1.5);
    // Comparam cele doua produse
    if (ComparareProduse(produs1, produs2)) {
        std::cout << "Cele doua produse au aceeasi versiune." << std::endl;
    }
    else {
        std::cout << "Cele doua produse au versiuni diferite." << std::endl;
    }
    // Eliberam memoria alocata
    EliberareMemorie(produs1);
    EliberareMemorie(produs2);
    return 0;
}
