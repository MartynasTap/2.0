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
    Studentas() : ND_(0),rez_med_(0),rez_vid_(0),Egzaminas_(0){};
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
    friend std::istream& operator>>(std::istream& in, Studentas& a) {
        in >> a.Vardas_ >> a.Pavarde_;
        return in;
    }
    /*friend std::istream& operator>>(std::istream& in, Studentas& a) {
        in >> a.Vardas_ >> a.Pavarde_;
        while (1)
        /*{
            int nd;
            in >> nd;
            a.ND_.push_back(nd);
            char ch = getchar();
            if (ch == '\n')
            {
                a.Egzaminas_ = nd;
                a.ND_.pop_back();
                break;*/
            /* }
        }
        return in;
    }*/
    friend std::ostream& operator<<(std::ostream& out, const Studentas& a) {
        out << std::fixed;
        out << setw(15) << left <<  a.Vardas_ << setw(15) << left << a.Pavarde_ << setw(17) << left << setprecision(2) << a.rez_vid_ << setw(17) << left << setprecision(2) << a.rez_med_ << "\n";
        return out;
    }
    Studentas(const Studentas&);
    Studentas& operator=(const Studentas& s);
    ~Studentas() { ND_.clear();};
};
bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgza(const Studentas&, const Studentas&);
void iv_ir_tikr(auto& a);
int ar_tinkamas_paz(int a);
int ar_tinkamas_pasirinkimas(int a);
void galutinis_vid(Studentas& Temp);
void galutinis_med(Studentas& Temp);
unsigned int zodziai(string const& str);
void rusiavimas(vector <Studentas>& Prad, vector <Studentas>& vargsiukai);
bool comparePagalGalutini(const Studentas& x, const Studentas& y);
int ar_daugiau0(int a);
bool comparePagalVarda(const Studentas& x, const Studentas& y);

void ivedimas(Studentas& Temp);
void ivedimas(Studentas& Temp, int nd);
void ivedimas(vector<Studentas>& Temp, int nd, string failas);

void isvedimas(Studentas& Temp, float galutinis); //paprastas
void isvedimas(vector<Studentas>& Temp); //nuskaicius is failo
void isvedimas(vector <Studentas>& Temp, string failas); //i faila

#endif // MYLIB_H_INCLUDED