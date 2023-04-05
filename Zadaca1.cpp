#include <iostream>
using namespace std;

class Oblik {
    public:
        static int count; 
        Oblik() {
            count++;
        }
        virtual double plostina() = 0; 
        virtual double volumen() {
            return 0; 
        }
};

int Oblik::count = 0; 

class DvoDimenzionalni : public Oblik {
    public:
        double x, y;
        DvoDimenzionalni() {
            x = 0;
            y = 0;
        }
        DvoDimenzionalni(double a, double b) {
            x = a;
            y = b;
        }
        double plostina() override {
            return x * y;
        }
};

class TroDimenzionalni : public Oblik {
    public:
        double x, y, z;
        TroDimenzionalni() {
            x = 0;
            y = 0;
            z = 0;
        }
        TroDimenzionalni(double a, double b, double c) {
            x = a;
            y = b;
            z = c;
        }
        double plostina() override {
            return 2 * (x * y + x * z + y * z);
        }
        double volumen() override {
            return x * y * z;
        }
};

class Pravoagolnik : public DvoDimenzionalni {
    public:
        Pravoagolnik() : DvoDimenzionalni() {}
        Pravoagolnik(double a, double b) : DvoDimenzionalni(a, b) {}
};

class Kvadrat : public DvoDimenzionalni {
    public:
        Kvadrat() : DvoDimenzionalni() {}
        Kvadrat(double a) : DvoDimenzionalni(a, a) {}
};

class Paralelopiped : public TroDimenzionalni {
    public:
        Paralelopiped() : TroDimenzionalni() {}
        Paralelopiped(double a, double b, double c) : TroDimenzionalni(a, b, c) {}
};

class Kocka : public TroDimenzionalni {
    public:
        Kocka() : TroDimenzionalni() {}
        Kocka(double a) : TroDimenzionalni(a, a, a) {}
};

int main() {
    Oblik *objekt;
    objekt = new Pravoagolnik(2, 3);
    cout << "Povrshina na pravoagolnik: " << objekt->plostina() << endl;
    delete objekt;

    objekt = new Kvadrat(4);
    cout << "Povrshina na kvadrat: " << objekt->plostina() << endl;
    delete objekt;
objekt = new Paralelopiped(2, 3, 4);
cout << "Povrshina na paralelopiped: " << objekt->plostina() << endl;
cout << "Volumen na paralelopiped: " << objekt->volumen() << endl;
delete objekt;

objekt = new Kocka(5);
cout << "Povrshina na Kocka: " << objekt->plostina() << endl;
cout << "Volumen na Kocka: " << objekt->volumen() << endl;
delete objekt;

cout << "Vkupno oblik instanci: " << Oblik::count << endl;

return 0;
}
