/**

    Dans ce fichier source se trouve la définition
    de toutes les fonctions utilisées dans le jeu
    (main.c)

*/

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>


//Fonction boléenne qui renvoie true si le pseudo existe déjà et false sinon
bool verifiePseudo(char pseudo,FILE* file){
    file = fopen("score.txt","r");
    char ligne[300];
    while (fgets(ligne, sizeof(ligne), file)) {
        printf("Ligne lue: %s", ligne);
        if (ligne == pseudo)
        {
            return true;
        }

    }
    fclose(file);
    return false;
}


void archivePseudo(char pseudo, FILE* file){
    file = fopen("score.txt","a");
    fprintf("%s\n",pseudo);
    fclose(file);
    printf("%s, ton pseudo viens d'être enregistré avec succès !\n");
}


//Cette fonction contiendra tout le jeu propement dit avec les appels
//des différentes fonctions définies plus haut
void lancerJeu(){
    setlocale(LC_CTYPE,"");//pour l'encodage en UTF-8
    int choix,cpt = 0,nbreLu,nbreRandom;
    char pseudo[100];
    bool pseudoExiste;
    FILE* file = fopen("score.txt","a");
    fclose(file);

    afficheRegles();
    proposeIntervalle();
    printf("Votre choix : ");
    scanf("%d",&choix);
    while (choix<0 || choix>3)
    {
        printf("Entrée Invalide - Réessayer : "); //Controle de choix
        scanf("%d",&choix);
    }

    //En fonction du choix, on envoie un intervalle différent à la fonction getRandomInt
    switch (choix){
    case 1:
        nbreRandom = getRandomInt(0,50);
        break;
    case 2:
        nbreRandom = getRandomInt(0,100);
        break;
    case 3:
        nbreRandom = getRandomInt(0,200);
        break;
    }
    printf("À vous de jouer : ");
    scanf("%d",&nbreLu);
    while (nbreLu != nbreRandom){
        messageOrientation(nbreLu, nbreRandom);
        scanf("%d",&nbreLu);
        cpt++;
    }
    messageFelicitation(cpt);
    printf("Entrez un pseudo : ");
    scanf("%s",pseudo);
    pseudoExiste = verifiePseudo(pseudo,file);
    if (pseudoExiste) {
        printf("Ce pseudo est déjà enregistré dans score.txt");
    }
    else {
        archivePseudo(pseudo,file);
    }
    printf("Fin du Programme....");

}

