#include <stdio.h>
#include <string.h>
#define MAX 1000
//

typedef struct {
    char nume[100];
    int numar_stele;
    char tip[100];
} Constelatie;

void meniu() {
    printf("Meniu\n");
    printf("-------\n");
    printf("0. Iesire\n");
    printf("1. Adauga constelatie\n");
    printf("2. Afiseaza toate constelatiile ordonate descrescator dupa nr stelelor\n");
    printf("3. Afiseaza toate constelatiile VIZIBILE cu un nr de stele mai mare decat valoarea introdusa\n");
    printf("4. Crearea unui vector cu lungimile numelor constelatiilor si afisarea acestuia\n");
    printf("-------\n");
}
void adauga_constelatie(Constelatie *c) {
    printf("Nume: ");
    scanf("%s", c->nume);

    printf("Numar stele: ");
    scanf("%d", &c->numar_stele);

    printf("Tip: ");
    scanf("%s", c->tip);
}
void sortare_constelatie(Constelatie v[], int n) {
    Constelatie temp;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (v[i].numar_stele<v[j].numar_stele) {
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
}
void afiseaza_constelatie_vizibila(Constelatie v[], int n, const char *tip_constelatie, int numar_stele) {
    for (int i=0;i<n;i++) {
        if ((strcmp(v[i].tip, tip_constelatie) == 0) && (v[i].numar_stele>numar_stele)) {
            printf("Nume: %s | Stele: %d | Tip: %s\n", v[i].nume, v[i].numar_stele, v[i].tip);
        }
    }
    printf("\n");
}
void afiseaza_constelatie(Constelatie v[], int n) {
    for (int i=0;i<n;i++) {
        printf("Nume: %s | Stele: %d | Tip: %s\n", v[i].nume, v[i].numar_stele, v[i].tip);
    }
    printf("\n");
}
void length_nume_constelatii(Constelatie v[], int n, int lungimi[]) {
    for (int i=0;i<n;i++) {
        lungimi[i]=strlen(v[i].nume);
    }
}
void afiseaza_lungimi_constelatii(int v[], int n) {
    for (int i=0;i<n;i++) {
        printf("Lungimea numelui constelatiei %d este: %d \n", i, v[i]);
    }
    printf("\n");
}

int main(void) {
    int opt;
    Constelatie constelatii[MAX];
    int lungimi[MAX];
    int count=0;
    do {
        meniu();
        scanf("%d", &opt);
        switch (opt) {
            case 0:
                printf("Iesire\n");
                break;
            case 1:
                if (count < MAX) {
                    printf("Adauga constelatie\n");
                    adauga_constelatie(&constelatii[count]);
                    count++;
                }
                else {
                    printf("Lista e plina!\n");
                }
                break;
            case 2:
                sortare_constelatie(constelatii, count);
                afiseaza_constelatie(constelatii, count);
                break;
            case 3:
                int numar;
                scanf("%d", &numar);
                afiseaza_constelatie_vizibila(constelatii, count, "v", numar);
                break;
            case 4:
                length_nume_constelatii(constelatii, count, lungimi);
                afiseaza_lungimi_constelatii(lungimi, count);
                break;
            default:
                printf("Optiune invalida!\n");
                break;
        }
    } while (opt);
    return 0;
}