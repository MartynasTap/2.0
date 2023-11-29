#pragma once
#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setw;
using std::left;
using std::right;
using std::setprecision;
using std::nth_element;
using std::rand;
using std::srand;
using std::getline;
using std::ifstream;
using std::stringstream;
using std::swap;
using std::list;
using std::remove_if;

class Studentas
{
private:
    string Vardas_;
    string Pavarde_;
    vector<int> ND_;
    int Egzaminas_;
    double rez_vid_;
    double rez_med_;
public:
    Studentas() : ND_(0){ };
    void setVar(std::string);
    void setPav(std::string);
    void setEgz(int);
    void setND(int);
    void EmptyND();
    string getVar() const { return Vardas_; }
    string getPav() const { return Pavarde_; }
    int getEgz() const { return Egzaminas_; }
    int GautiDydi() const { return ND_.size();}
    double gautiSuma() const {return std::accumulate(ND_.begin(), ND_.end(), 0.0);}
    int gautiNari(int i) const { return ND_.at(i);}
    void setVid(double);
    void setMed(double);
    double getVid() const { return rez_vid_; }
    double getMed() const { return rez_med_; }
    void sorting(int);
    ~Studentas() {};
};
bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgza(const Studentas&, const Studentas&);
void iv_ir_tikr(auto& a);
int ar_tinkamas_paz(int a);
int ar_tinkamas_pasirinkimas(int a);
void ivedimas(Studentas& Temp);
void galutinis_vid(Studentas& Temp);
void galutinis_med(Studentas& Temp);
void atsitiktiniai(Studentas& Temp);
unsigned int zodziai(string const& str);
void isvedimas_i_faila(vector <Studentas>& Temp, string failas);
void rusiavimas(vector <Studentas>& Prad, vector <Studentas>& vargsiukai);
void skaitymas(vector<Studentas>& Temp, int nd, string failas);
bool comparePagalGalutini(const Studentas& x, const Studentas& y);
void isvedimas_sufailu(vector<Studentas>& Temp);
int ar_daugiau0(int a);
void isvedimas(Studentas& Temp, bool galutinis);
bool comparePagalVarda(const Studentas& x, const Studentas& y);
#endif // MYLIB_H_INCLUDED