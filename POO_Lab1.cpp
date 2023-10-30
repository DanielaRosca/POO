#include <iostream>
struct Vector {
    double* data;  // Pointer către tabloul de valori double
    int size;      // Numărul de elemente din vector
    // Constructor pentru inițializarea unui vector
    Vector(int initialSize) {
        data = new double[initialSize];
        size = initialSize;
    }
    // Destructor pentru eliminarea vectorului și eliberarea memoriei
    ~Vector() {
        delete[] data;
    }
    // Funcție pentru modificarea dimensiunii vectorului
    void resize(int newSize) {
        double* newData = new double[newSize];
        int minSize = (size < newSize) ? size : newSize;
        for (int i = 0; i < minSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }
    // Funcție pentru accesarea elementului din vector
    double& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            std::cerr << "Index invalid." << std::endl;
            exit(1);
        }
    }
    // Funcție pentru calculul sumei elementelor pare din vector
    double sumOfEvenElements() {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                sum += data[i];
            }
        }
        return sum;
    }
};
int main() {
    int size;
    std::cout << "Introduceți dimensiunea vectorului: ";
    std::cin >> size;
    Vector vec(size);
    // Inițializare vector cu date introduse de la tastatură
    for (int i = 0; i < vec.size; i++) {
        std::cout << "Introduceți valoarea pentru vec[" << i << "]: ";
        std::cin >> vec[i];
    }
    // Afișarea elementelor vectorului
    for (int i = 0; i < vec.size; i++) {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }
    // Calculul sumei elementelor pare din vector
    double sum = vec.sumOfEvenElements();
    std::cout << "Suma elementelor pare din vector: " << sum << std::endl;

    // Modificarea dimensiunii vectorului (opțional)
    int newSize;
    std::cout << "Introduceți noua dimensiune a vectorului: ";
    std::cin >> newSize;
    vec.resize(newSize);
    // Adunarea unui număr la toate elementele vectorului
    double numberToAdd;
    std::cout << "Introduceți numărul pe care doriți să-l adăugați la vector: ";
    std::cin >> numberToAdd;
    for (int i = 0; i < vec.size; i++) {
        vec[i] += numberToAdd;
    }
    // Afișarea elementelor vectorului după adunare
    for (int i = 0; i < vec.size; i++) {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }
    return 0;
}
