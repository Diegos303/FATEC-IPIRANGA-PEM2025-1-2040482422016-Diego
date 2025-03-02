///////////////////////////////////////
/////Diego Souza///////////////////////
//////////////////////////////////////

#include <stdio.h>
#include <string.h>

int main() {
    int i, c, j;
    float nota[4], notap, notam, media;
    float notaac[5], notapac, notamac, mediaac;
    float notapp[10], notappp, notampp, mediapp;
    float notaeb[3], notapeb, notameb, mediaeb;
    char nomes[50][50],tempnome[50]; 
    float mediasf[50], tempme;   

    printf("Digite o numero de candidatos: ");
    scanf("%d", &c);

    if (c > 50) {
        printf("Numero de candidatos ultrapassou o numero permitido.\n");
        return 1;
    }

    for (j = 0; j < c; j++) {
        media = 0; 

        printf("Digite o nome do candidato %d: ", j + 1);
        scanf("%s", nomes[j]);

    
        for (i = 0; i < 4; i++) {
            printf("Digite a nota %d de PE: ", i + 1);
            scanf("%f", &nota[i]);
        }

        notap = nota[0];
        notam = nota[0];
        for (i = 1; i < 4; i++) {
            if (nota[i] < notap) {
                notap = nota[i]; 
            }
            if (nota[i] > notam) {
                notam = nota[i];
            }
        }
        media = (nota[0] + nota[1] + nota[2] + nota[3] - notam - notap) / 2;
        printf("A media de PE do candidato %d e: %.2f\n", j + 1, media);

        
        for (i = 0; i < 5; i++) {
            printf("Digite a nota %d de AC: ", i + 1);
            scanf("%f", &notaac[i]);
        }
        notapac = notaac[0]; 
        notamac = notaac[0]; 
        for (i = 1; i < 5; i++) {
            if (notaac[i] < notapac) {
                notapac = notaac[i]; 
            }
            if (notaac[i] > notamac) {
                notamac = notaac[i];
            }
        }
         mediaac = (notaac[0] + notaac[1] + notaac[2] + notaac[3] + notaac[4] - notamac - notapac) / 3;
        printf("A media de AC do candidato %d e: %.2f\n", j + 1, mediaac);

    
        for (i = 0; i < 10; i++) {
            printf("Digite a nota %d de PP: ", i + 1);
            scanf("%f", &notapp[i]);
        }
        notappp = notapp[0]; 
        notampp = notapp[0]; 
        for (i = 1; i < 10; i++) {
            if (notapp[i] < notappp) {
                notappp = notapp[i]; 
            }
            if (notapp[i] > notampp) {
                notampp = notapp[i];
            }
        }
        mediapp = (notapp[0] + notapp[1] + notapp[2] + notapp[3] + notapp[4] + notapp[5] + notapp[6] + notapp[7] + notapp[8] + notapp[9] - notampp - notappp) / 8;
        printf("A media de PP do candidato %d e: %.2f\n", j + 1, mediapp);

        for (i = 0; i < 3; i++) {
            printf("Digite a nota %d de EB: ", i + 1);
            scanf("%f", &notaeb[i]);
        }
        notapeb = notaeb[0]; 
        notameb = notaeb[0]; 
        for (i = 1; i < 3; i++) {
            if (notaeb[i] < notapeb) {
                notapeb = notaeb[i]; 
            }
            if (notaeb[i] > notameb) {
                notameb = notaeb[i];
            }
        }
        mediaeb = (notaeb[0] + notaeb[1] + notaeb[2] - notameb - notapeb) / 1;  
        printf("A media de EB do candidato %d e: %.2f\n", j + 1, mediaeb);

        mediasf[j] = (media * 0.3) + (mediaac * 0.1) + (mediapp * 0.4) + (mediaeb * 0.2);
    }

    
    for (i = 0; i < c - 1; i++) {
        for (j = i + 1; j < c; j++) {
            if (mediasf[i] < mediasf[j]) {
                
                tempme = mediasf[i];
                mediasf[i] = mediasf[j];
                mediasf[j] = tempme;
           
                strcpy(tempnome, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], tempnome);
            }
        }
    }

    printf("\nAs 15 melhores medias:\n");
    if (c>15) {
        c = 15;
    }
    for (i = 0; i < c; i++) {
        printf("%d - %s: %.2f\n", i + 1, nomes[i], mediasf[i]);
    }

    return 0;
}
