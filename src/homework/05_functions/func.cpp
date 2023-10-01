//add include statements 
#include "func.h"

//add function code here
double get_gc_content(const string& dna) {
    int gc_count = 0;
    for (char nucleotide : dna) {
        if (nucleotide == 'G' || nucleotide == 'C') {
            gc_count++;
        }
    }
    return static_cast<double>(gc_count) / dna.length();
}

string reverse_string(const string& dna) {
    string reversed_dna = dna;
    int length = reversed_dna.length();
    for (int i = 0; i < length / 2; i++) {
        char temp = reversed_dna[i];
        reversed_dna[i] = reversed_dna[length - i - 1];
        reversed_dna[length - i - 1] = temp;
    }
    return reversed_dna;
}

string get_dna_complement(const string& dna) {
    string complemented_dna = dna;
    for (char& nucleotide : complemented_dna) {
        if (nucleotide == 'A') {
            nucleotide = 'T';
        } else if (nucleotide == 'T') {
            nucleotide = 'A';
        } else if (nucleotide == 'C') {
            nucleotide = 'G';
        } else if (nucleotide == 'G') {
            nucleotide = 'C';
        }
    }
    // Reverse the string after complementing
    int length = complemented_dna.length();
    for (int i = 0; i < length / 2; i++) {
        char temp = complemented_dna[i];
        complemented_dna[i] = complemented_dna[length - i - 1];
        complemented_dna[length - i - 1] = temp;
    }
    return complemented_dna;
}