#include "utils.hpp"
#include <iostream>
#include <fstream>


void quick_sort(Poscode *A, size_t n){

}

void merge_sort(Poscode *A, size_t n){

}
static void counting_sort(Poscode* A, size_t n, size_t p, int M) {
    vector<LinkedList> L(M);

    for (size_t i = 0; i < n; i++) {
        char c = A[i].getValue(p);
        int bucket;
        if (isdigit(c))
            bucket = c - '0';
        else
            bucket = c - 'A';
        L[bucket].insertLast((int)i);
    }

    Poscode* tmp = new Poscode[n];
    size_t k = 0;

    for (int b = 0; b < M; b++) {
        Node* ptr = L[b].getHead();
        while (ptr != nullptr) {
            int idx = ptr->getData();
            tmp[k++] = A[idx];
            ptr = ptr->getNext();
        }
    }

    for (size_t i = 0; i < n; i++) {
        A[i] = tmp[i];
    }

    delete[] tmp;
    for (int b = 0; b < M; b++) {
        L[b].removeAll();
    }
}

void radix_sort(Poscode* A, size_t n) {
    counting_sort(A, n, 5, 26);
    counting_sort(A, n, 4, 26);
    counting_sort(A, n, 3, 10);
    counting_sort(A, n, 2, 10);
    counting_sort(A, n, 1, 10);
    counting_sort(A, n, 0, 10);
}

Poscode *readCodes(const std::string &strfile, size_t n){
    // Replace "example.txt" with the actual path to your text file.
    Poscode *codes = new Poscode[n];

    std::ifstream inputFile(strfile);    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file!" << std::endl;        
        return nullptr;
    }
    // 3. Read the file content line by line.
    std::string line;
    for(size_t i = 0; i < n; i++){
        std::getline(inputFile, line); 
        codes[i] = Poscode(line);
    }
    
    inputFile.close();
    return codes;
}

void deleteCodes(Poscode *codes){
    if (codes != nullptr) {
        delete[] codes;
    }    
}