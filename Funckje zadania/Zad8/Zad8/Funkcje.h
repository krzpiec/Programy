#pragma once
#ifndef Funkcje_hpp
#define Funckje_hpp


std::vector<int> myvec;
std::vector<int> myvec1;
std::vector<int> result;
std::vector<int> primes;
std::vector<int> primes1;
std::vector<int> primesmerge;
std::vector<int> ciag;
std::vector<int> primesrepet;
std::vector<int> ciag2;
const int ile = 6;
const int min = 2;
const int max = 20;
int prime1 = 0;

std::vector<int> fill(std::vector<int>& myvec, const int N, const int min, const int max);

std::vector<int> merge(const std::vector<int>& myvec, const std::vector<int>& myvec1, std::vector<int>& result);

std::vector<int> usunpowt(std::vector<int>& myvec);

std::vector<int> sort(std::vector<int>& myvec);

std::vector<int> prime(const std::vector<int>& myvec, std::vector<int>& prime);

void reverse(std::vector<int>& myvec);

void print(const std::vector<int>& myvec, const int N);

std::vector<int> repetition(std::vector<int>& myvec, std::vector<int>& myvec1, std::vector<int>& result);

int liczba(std::vector<int> myvec, int& liczba);

std::vector<int> generate(std::vector<int>& ciag, const int N);

#endif
