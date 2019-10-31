#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    //cryptage_text();
    read_file();
    return 0;
}





void cryptage_text(){
    FILE *fich = fopen("fichier.txt", "r");
    FILE *fich2 = fopen("fichier2.txt", "w+");
    FILE *fich3 = fopen("fichier3.txt", "w+");
    // declarations

    int caract_actual = 0;
    int new_caract;
    int key_len = 7;
    int place = 0;
    char key[] = "bonjour";
    char buffer[256];

    /*****************************/


    if (fich != NULL){

        while (caract_actual != EOF){

              if (caract_actual != '\n')
                {
                    caract_actual = fgetc(fich);
                    printf("\nBEFORE: %c", caract_actual);
                    new_caract = crypt_letter(caract_actual, place, key_len, key);

                   if (new_caract <= 32)
                   {
                     new_caract +=32;
                   }

                    printf("\nAFTER: %c", new_caract);
                    //printf("\nDECODED: %c", crypt_letter(new_caract, place, key_len, key));

                    fputc(new_caract,fich2);
                    fputc(crypt_letter(new_caract, place, key_len, key), fich3);
                    place++;
                }
        }

        fclose(fich);
        fclose(fich2);
    }

}


int crypt_letter(int caract_initial, int place, int key_len, char key[]) // the function that crypts letters
{
    int crypted_letter;
    double  k = exp(place);
    int int_k = (int) k;
    //print("%d", int_k);

    crypted_letter = caract_initial^key[(int_k % key_len)];
    return crypted_letter;
}

void decode()
{

}






int read_file() // here i m trying to re build the function don look for it
{
    FILE* fichier = NULL;
    FILE* fichier2 = NULL;
    int caractereActuel = 0;

    fichier = fopen("fichier.txt", "r");
    fichier2 = fopen("fichier2.txt", "w+");



    int caract_actual = 0;
    int new_caract;
    int key_len = 7;
    int place = 0;
    char key[] = "bonjour";
    char buffer[256];




    if (fichier != NULL)
    {

        do
        {
            caractereActuel = fgetc(fichier);
            printf("%c", caractereActuel);


        } while (caractereActuel != EOF);

        fclose(fichier);
    }






    return 0;
}



