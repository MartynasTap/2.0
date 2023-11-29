#include "mylib.h"
void Studentas::setVar(string vardas_)
{
    Vardas_ = vardas_;
}
void Studentas::setPav(string pavarde_)
{
    Pavarde_ = pavarde_;
}
void Studentas::setEgz(int egzaminas_)
{
    Egzaminas_ = egzaminas_;
}
void Studentas::setND(int nd) {
    ND_.push_back(nd);
}
void Studentas::setMed(double med) {
    rez_med_ = med;
}
void Studentas::setVid(double vid) {
    rez_vid_ = vid;
}
void Studentas::sorting(int j) {
    sort(ND_.begin(), ND_.end());
}
bool palyg(Studentas& Temp) {
    return (Temp.getVid() < 5);
}
void Studentas::EmptyND()
{
    ND_.clear();
}
void iv_ir_tikr(auto& a) {
    cin >> a;
    do {
        try {
            if (cin.fail()) { throw std::runtime_error("Ivedete netinkama duomeni"); }
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << endl << "Veskite duomeni dar karta: ";
            cin >> a;
        }
    } while (std::cin.fail() == true);
}
int ar_tinkamas_paz(int a) {
    do {
        try {
            if (a < 0 || a>10) { throw std::invalid_argument("Pazymiai gali buti tik tarp 0 ir 10"); }
        }
        catch (const std::invalid_argument& e) {
            cout << e.what();
            cout << endl << "Veskite pazymi dar karta: ";
            iv_ir_tikr(a);
        }
    } while ((a < 0 || a>10) == true);
    return a;
}

int ar_tinkamas_pasirinkimas(int a) {
    do {
        try {
            if (a == 1 || a == 0) { break; }
            else { throw std::invalid_argument("Pasirinkimai yra tik 1 arba 0"); }
        }
        catch (const std::invalid_argument& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << endl << "Veskite pasirinkima dar karta: ";
            iv_ir_tikr(a);
        }
    } while ((a == 1 || a == 0) == false);
    return a;
}
int ar_daugiau0(int a) {
    do {
        try {
            if (a > 0) { break; }
            else { throw std::invalid_argument("Turi buti bent 1"); }
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
            cout << endl << "Veskite skaiciu dar karta: ";
            iv_ir_tikr(a);
        }
    } while (a > 0 == false);
    return a;
}
bool comparePagalPavarde(const Studentas& x, const Studentas& y)
{
	return x.getPav() < y.getPav();
}
bool comparePagalEgza(const Studentas& x, const Studentas& y)
{
	return x.getEgz() < y.getEgz();
}
bool comparePagalGalutini(const Studentas& x, const Studentas& y)
{
    return x.getVid() < y.getVid();
}
bool comparePagalVarda(const Studentas& x, const Studentas& y)
{
    return x.getVar() < y.getVar();
}
void ivedimas(Studentas& Temp) {
    cout << "Iveskite varda ir pavarde: ";
    string a, b;
    cin >> a >> b;
    Temp.setVar(a);
    Temp.setPav(b);
    int i = 0;
    while (1) {
        int paz, n;
        cout << "Iveskite " << i + 1 << " pazymi: ";
        iv_ir_tikr(paz);
        paz = ar_tinkamas_paz(paz);
        Temp.setND(paz);
        cout << "Jei viska ivedete, parasykite 1: ";
        iv_ir_tikr(n);
        if (n == 1) { break; }
        i++;
    }
    cout << "Iveskite egzamina: ";
    int c;
    iv_ir_tikr(c);
    Temp.setEgz(c);
}
void galutinis_vid(Studentas& Temp) {
    Temp.setVid(Temp.gautiSuma() / Temp.GautiDydi());
    Temp.setVid((Temp.getVid() * 0.4) + (Temp.getEgz() * 0.6));
}
void galutinis_med(Studentas& Temp) {
    if (Temp.GautiDydi() == 1) { Temp.setMed(Temp.gautiNari(0));}
    else {
        int f;
        Temp.sorting(1);
        if (Temp.GautiDydi() % 2 == 0) {
            f = Temp.GautiDydi() / 2;
            Temp.setMed((static_cast<double>(Temp.gautiNari(f - 1)) + Temp.gautiNari(f)) / 2);
        }

        else {
            f = Temp.GautiDydi() / 2;
            Temp.setMed(Temp.gautiNari(f));
        }
    }
    Temp.setMed((Temp.getMed() * 0.4) + (Temp.getEgz() * 0.6));
}
void atsitiktiniai(Studentas& Temp) {
    cout << "Iveskite varda ir pavarde: ";
    string a,b;
    Temp.setVar(a); Temp.setPav(b);
    int n;
    cout << "Iveskite, kiek studentas turejo namu darbu: ";
    iv_ir_tikr(n);
    ar_daugiau0(n);
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        int k = 1 + (rand() % 10);
        Temp.setND(k);
    }
    Temp.setEgz(1 + (rand() % 10));
}
unsigned int zodziai(string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}
void skaitymas(vector<Studentas>& Temp, int nd, string failas) {
    int temp,eg;
    int stud = 0;
    string buff;
    ifstream fr;
    try
    {
        fr.open(failas);
        if (!fr)
            throw std::runtime_error("FAILAS NERASTAS!");
        getline(fr >> std::ws, buff);
        nd = zodziai(buff) - 3;
        while (true)
        {
            Temp.resize(Temp.size() + 1);
            string a,b;
            fr >> a;
            Temp.at(stud).setVar(a);
            if (fr.eof())
            {
                Temp.pop_back();
                break;
            }
            fr >> b;
            Temp.at(stud).setPav(b);
            for (int i = 0; i < nd; i++)
            {
                fr >> temp;
                Temp.at(stud).setND(temp);
            }
            fr >> eg;
            Temp.at(stud).setEgz(eg);
            stud += 1;
        }
        fr.close();
    }
    catch (...) {}
}
void isvedimas_sufailu(vector<Studentas>& Temp) {
    printf("%-15s%-15s%-17s%-17s\n", "Vardas", "Pavarde", "Galutinis (Vid.)", "Galutinis (Med.)");
    printf("----------------------------------------------------------------\n");
    for (auto& a : Temp) {
        cout << setw(15) << left << a.getVar() << setw(15) << left << a.getPav();
        printf("%-17.2f%-17.2f\n", a.getVid(), a.getMed());
    }
}
void isvedimas(Studentas& Temp, bool galutinis) {
    cout << setw(15) << left << Temp.getVar() << setw(15) << left << Temp.getPav();
    printf("%-16.2f%-16s\n", galutinis, &Temp);
}
void isvedimas_i_faila(vector <Studentas>& Temp, string failas) {
    std::ofstream fr;
    fr.open(failas);
    fr << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.)" << setw(17) << left << "Galutinis (Med.)" << endl;
    fr << "----------------------------------------------------------------" << endl;
    for (auto& a : Temp) {
        fr << setw(15) << left << a.getVar() << setw(15) << left << a.getPav();
        fr << std::fixed;
        fr << setw(17) << left << setprecision(2) << a.getVid() << setw(17) << left << setprecision(2) << a.getMed() << endl;
    }
    fr.close();
}
void rusiavimas(vector <Studentas>& Prad, vector <Studentas>& vargsiukai) {
    int i = 0;
    do {
        i++;
    } while (Prad.at(i).getVid() < 5);
    vargsiukai.reserve(i);
    int j = Prad.size() - i;
    for (int f = 0; f < i; f++) {
        vargsiukai.push_back(Prad.at(f));
    }
    Prad.erase(remove_if(Prad.begin(), Prad.end(),palyg),Prad.end());
    Prad.shrink_to_fit();
}