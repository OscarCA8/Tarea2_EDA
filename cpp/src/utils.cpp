#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "linkedList.hpp"
using namespace std;

static int partition(Poscode *A, int low, int high) {
    Poscode pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {  
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[high]);
    return i + 1;
}

static void quick_sort_rec(Poscode *A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quick_sort_rec(A, low, pi - 1);
        quick_sort_rec(A, pi + 1, high);
    }
}

void quick_sort(Poscode *A, size_t n) {
    if (n > 1)
        quick_sort_rec(A, 0, n - 1);
}

static void merge(Poscode *A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Poscode> L(n1);
    vector<Poscode> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

static void merge_sort_rec(Poscode *A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_rec(A, left, mid);
        merge_sort_rec(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void merge_sort(Poscode *A, size_t n) {
    if (n > 1)
        merge_sort_rec(A, 0, n - 1);
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