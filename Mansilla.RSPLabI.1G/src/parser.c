#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Post.h"

// id_peli,titulo,genero,duracion
int parser_PostFromText(FILE* pFile, LinkedList* this) {

    int retorno = 0;

    char basura1[1000];
    char basura2[50];
    char basura3[50];
    char basura4[50];
    char basura5[50];

    char id[50];
	char user[50];
	char likes[50];
	char dislikes[50];
	char followers[50];

    ePost* eBuffer = NULL;

    if(pFile != NULL && this != NULL)
    {
//    	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],",
    	fscanf(pFile, "%s\n",
    			basura1
				);
//		printf("%s",basura);

    	do
        {
    		if(feof(pFile))
    		{
    			break;
    		}
    		// id,user,likes,dislikes,followers1,
            retorno = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
            		               id, user, likes, dislikes, followers);

            if(retorno!=5)
            {
                printf("Error al cargar datos\n");
                exit(1);
            }
            else
            {
            	eBuffer = Post_newParametros(id, user, likes, dislikes, followers);

                if( eBuffer != NULL)
                {
                    retorno = ll_add(this, eBuffer);
                }
            }

            // verificacion de carga
//			printf("%-s | %-s| %-s| %-s| %-s\n",
//					id,
//					user,
//					likes,
//					dislikes,
//					followers
//			);

        }while(!feof(pFile));
    	retorno = 1;
    }
    return retorno;
}
