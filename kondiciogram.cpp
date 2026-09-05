#include <math.h>
#include <iostream>

using namespace std;

// Cpp 7 - kondiciogram se vstupem pres args

// promenne pro datum narozeni (argv[1])
int dn = 0, mn = 0, rn = 0;
// promenne pro cilove datum vypoctu (argv[2])
int dc = 0, mc = 0, rc = 0;
// dalsi potrebne promenne
long jd_naroz, jd_cil, dny_celkem;
double fyz, emo, inte;

#define PI 3.14159265358979323846

/// funkce pro vypocet Julianskeho dne (pocet dni od r. 4713 pr.n.l.)
long spocti_juliansky_den(int r, int m, int d) {
long ja, jm, jy;

if (m > 2) {
jy = r;
jm = m + 1;
} else {
jy = r - 1;
jm = m + 13;
}

long jd = (long)(365.25 * jy) + (long)(30.6001 * jm) + d + 1720995L;

// korekce pro Gregoriansky kalendar
if (d + 31L * (m + 12L * r) >= (15 + 31L * (10 + 12L * 1582))) {
ja = (long)(0.01 * jy);
jd += 2 - ja + (long)(0.25 * ja);
}
return jd;
}

int main(int argc, char* argv[]) {

cout<<endl<<"--- VYPOCET KONDICIOGRAMU (BIORYTMY) ---"<<endl;

// kontrola, zda uzivatel zadal oba potrebne argumenty
// argc musi byt 3 (jmeno programu + argv[1] + argv[2])
if (argc < 3) {	
cout<<endl<<"zadejte dva datumy ve formatu DDMMRRRR"<<endl<<endl;
cout<<"kondiciogram datum_narozeni cilove_datum"<<endl;
cout<<"kondiciogram 28031971 09122026"<<endl;
system("pause");
return 1;
}

// naparsovani prvniho argumentu (datum narozeni) sscanf()
int nacteno_nar = sscanf(argv[1], "%2d%2d%4d", &dn, &mn, &rn);

// naparsovani druheho argumentu (cilove datum)
int nacteno_cil = sscanf(argv[2], "%2d%2d%4d", &dc, &mc, &rc);

// kontrola spravnosti formatu obou dat
if (nacteno_nar != 3 && nacteno_cil != 3) {
cout<<"neplatny format obouch dat, pouzijte:"<<endl;
cout<<"kondiciogram DDMMRRRR DDMMRRRR"<<endl;
system("pause");
return 1;
}

if (nacteno_nar !=3 ){
cout<<"neplatny format data narozeni, pouzijte:"<<endl;
cout<<"kondiciogram DDMMRRRR "<<argv[2]<<endl;
system("pause");
return 1;
}

if (nacteno_cil !=3 ){
cout<<"neplatny format ciloveho data, pouzijte:"<<endl;
cout<<"kondiciogram "<<argv[1]<<" DDMMRRR"<<endl;
system("pause");
return 1;
}

// vypis nactenych hodnot pro overeni
cout<<"narozeni datum : "<<dn<<"."<<mn<<"."<<rn<<endl;
cout<<"cilove datum   : "<<dc<<"."<<mc<<" "<<rc<<endl;

// vypocet dnu
jd_naroz = spocti_juliansky_den(rn, mn, dn);
jd_cil = spocti_juliansky_den(rc, mc, dc);
dny_celkem = jd_cil - jd_naroz;

if (dny_celkem < 0) {
cout<<"cilove datum je pred datem narozeni"<<endl;
system("pause");
return 1;
}

// vypocet jednotlivych cyklu (vysledek v rozsahu -100% az +100%)
fyz  = sin(2.0 * PI * dny_celkem / 23.0) * 100.0;
emo  = sin(2.0 * PI * dny_celkem / 28.0) * 100.0;
inte = sin(2.0 * PI * dny_celkem / 33.0) * 100.0;

// vystup vysledku
printf("----------------------------------------\n");
printf("presny pocet dnu mezi daty je: %ld\n", dny_celkem);
printf("----------------------------------------\n");
printf("fyzicka kondice:      %6.1f %%\n", fyz);
printf("emocionalni kondice:  %6.1f %%\n", emo);
printf("intelektualni kondice: %6.1f %%\n", inte);
printf("----------------------------------------\n");

// upozorneni na kriticke dny (kdyz cyklus prochazi nulou)
cout<<"upozorneni na kriticke dny ( blizko 0% )"<<endl;
if (fabs(fyz) < 10.0)  cout<<"pozor na fyzickou zatez (fyzicka nula)"<<endl;
if (fabs(emo) < 10.0)  cout<<"mozna emotivni nestabilita (emocionalni nula)"<<endl;
if (fabs(inte) < 10.0) cout<<"horsi soustredeni a pamet (intelektualni nula)"<<endl;

if (fabs(fyz) >= 10.0 && fabs(emo) >= 10.0 && fabs(inte) >= 10.0) {
cout<<"zadne kriticke stavy pro tento den"<<endl;
}

system("pause");
return 0;
}

