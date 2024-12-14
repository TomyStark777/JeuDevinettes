#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "mesFonctions.h"

void afficheRegles(){

    printf("Règles : \n");
    printf("\tAu début du jeu, vous devez choisir un intervalle. \n");
    printf("\tUn nombre appartenant à cet intervalle sera alors généré.\n");
    printf("\tVotre Objectif sera de trouver ce nombre en faisant le \n\tmoins de tentatives possibles.\n\n\n");

}


// Prends en paramètre un intervalle et retourne un nombre aléatoirement
//généré et appartenant à cet intervalle
int getRandomInt(int bornInf, int bornSup){
    int randomInt;
    srand(time(NULL));
    randomInt = (rand()%bornSup + bornInf);
    printf("Nombre Random = %d\n",randomInt);
    return randomInt;
}

//Menu qui affiche les différents intervalle par défaut
void proposeIntervalle(){
    printf("- Intervalle par défaut : \n");
    printf("\t1.Facile   : Entre 0 et 20\n");
    printf("\t2.Normale  : Entre 0 et 100\n");
    printf("\t3.Difficile: Entre 0 et 200\n");
}

//Procédure qui affiche un message d'orientation pour aider l'utilisateur
//à trouver le nombre généré par la machine
void messageOrientation(int nbreLu, int nbreRandom){
    if (nbreLu < nbreRandom){
        printf("- %d est Plus Petit que le Nombre Secret\n",nbreLu);
    }
    else if(nbreLu > nbreRandom){
        printf("- %d est Plus Grand que le Nombre Secret\n",nbreLu);
    }
    else{
        printf("Entrée Invalide ou Non prise en charge\n");
    }
}


//Procédure qui affiche un "grade" au joueur en fonction du nombre
//de tentatives effectuées
void messageFelicitation(int nbreDeTentatives){
    printf("Félicitations, Vous avez trouvé le Nombre Secret après %d tentatives\n",nbreDeTentatives);
    if (nbreDeTentatives >= 1 && nbreDeTentatives <= 3){
        printf("Vous êtes un Super Voyant\n");
    }
    else if (nbreDeTentatives >= 4 && nbreDeTentatives <= 6){
        printf("Vous êtes un Sage Voyant\n");
    }
    else if(nbreDeTentatives >= 7 && nbreDeTentatives <= 9){
        printf("Vous êtes un Apprenti Voyant\n");
    } else {
        printf("Vous êtes un Voyant Pusillanime\n");
    }
}