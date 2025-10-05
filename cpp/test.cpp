#include "poscode.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

void showSample(Poscode* data, size_t n, int sampleSize = 10) {
    for (size_t i = 0; i < sampleSize && i < n; i++)
        cout << data[i].getData() << endl;
}

double mean(const vector<double>& v) {
    double sum = 0;
    for (double x : v) sum += x;
    return sum / v.size();
}

double stddev(const vector<double>& v, double mu) {
    double sum = 0;
    for (double x : v) sum += (x - mu) * (x - mu);
    return sqrt(sum / v.size());
}

int main() {
    vector<pair<string, size_t>> datasets = {
        {"/home/pbn/Documents/EDA2/Tarea2_EDA/codes_500K.txt", 500000},
        {"/home/pbn/Documents/EDA2/Tarea2_EDA/codes_1M.txt", 1000000},
        {"/home/pbn/Documents/EDA2/Tarea2_EDA/codes_10M.txt", 10000000}
    };

    for (auto& d : datasets) {
        string file = d.first;
        size_t n = d.second;
        cout << "==========================================\n";
        cout << "Archivo: " << file << " (" << n << " elementos)\n";

        // RadixSort
        vector<double> timesR;
        for (int i = 0; i < 5; i++) {
            Poscode* data = readCodes(file, n);
            if (i == 0) {
                cout << "Antes de ordenar (RadixSort):\n";
                showSample(data, n);
            }
            auto start = high_resolution_clock::now();
            radix_sort(data, n);
            auto end = high_resolution_clock::now();
            timesR.push_back(duration<double, milli>(end - start).count());
            if (i == 0) {
                cout << "\nDespués de ordenar (RadixSort):\n";
                showSample(data, n);
            }
            deleteCodes(data);
        }
        double muR = mean(timesR);
        double sigmaR = stddev(timesR, muR);
        cout << "RadixSort: (" << muR << " ± " << sigmaR << ") ms\n";

        // QuickSort
        vector<double> timesQ;
        for (int i = 0; i < 5; i++) {
            Poscode* data = readCodes(file, n);
            if (i == 0) {
                cout << "\nAntes de ordenar (QuickSort):\n";
                showSample(data, n);
            }
            auto start = high_resolution_clock::now();
            quick_sort(data, n);
            auto end = high_resolution_clock::now();
            timesQ.push_back(duration<double, milli>(end - start).count());
            if (i == 0) {
                cout << "\nDespués de ordenar (QuickSort):\n";
                showSample(data, n);
            }
            deleteCodes(data);
        }
        double muQ = mean(timesQ);
        double sigmaQ = stddev(timesQ, muQ);
        cout << "QuickSort: (" << muQ << " ± " << sigmaQ << ") ms\n";

        // MergeSort
        vector<double> timesM;
        for (int i = 0; i < 5; i++) {
            Poscode* data = readCodes(file, n);
            if (i == 0) {
                cout << "\nAntes de ordenar (MergeSort):\n";
                showSample(data, n);
            }
            auto start = high_resolution_clock::now();
            merge_sort(data, n);
            auto end = high_resolution_clock::now();
            timesM.push_back(duration<double, milli>(end - start).count());
            if (i == 0) {
                cout << "\nDespués de ordenar (MergeSort):\n";
                showSample(data, n);
            }
            deleteCodes(data);
        }
        double muM = mean(timesM);
        double sigmaM = stddev(timesM, muM);
        cout << "MergeSort: (" << muM << " ± " << sigmaM << ") ms\n";
    }

    return 0;
}