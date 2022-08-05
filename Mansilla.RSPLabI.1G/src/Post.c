#include <stdio.h>
#include <stdlib.h>
#include "Post.h"

ePost* Post_new(){

	ePost* eBuffer = (ePost*) malloc(sizeof(ePost));

	if(eBuffer != NULL )
	{
		//si el return es false libero memoria asignada y retorna null
		if( !(Post_setId(eBuffer, 0) &&
				Post_setUser(eBuffer, "")&&
				Post_setLikes(eBuffer, 0)&&
				Post_setDislikes(eBuffer, 0)&&
				Post_setFollowers(eBuffer, 0)
				))
		{
			free(eBuffer);
			eBuffer = NULL;
		}
	}
	return eBuffer;
}

// id, user, likes, dislikes, followers
ePost* Post_newParametros(char* idStr, char* userStr, char* likesStr,
						  char* dislikesStr, char* followersStr) {

	ePost* eBuffer = Post_new();
	if(eBuffer == NULL)
	{
		printf("rompe en newParametros\n");
	}

	if(eBuffer != NULL )
	{
		//si el return es false libero memoria asignada y retorna null
		if( !(Post_setIdString(eBuffer, idStr) &&
				Post_setUser(eBuffer, userStr)&&
				Post_setLikesString(eBuffer, likesStr)&&
				Post_setDislikesString(eBuffer, dislikesStr)&&
				Post_setFollowersString(eBuffer, followersStr)
				))
		{
			free(eBuffer);
			eBuffer = NULL;
		}
	}
	return eBuffer;
}


int Post_setId(ePost* pElement, int id) {

	int retorno = 0;
	if(pElement != NULL && id >= 0)
	{
		pElement->id = id;
		retorno = 1;
	}
	return retorno;
}


int Post_setIdString(ePost* pElement, char* idStr) {

	int retorno = 0;
	if(pElement != NULL && idStr != NULL)
	{
		pElement->id = atoi(idStr);
		retorno = 1;
	}
	return retorno;
}

int Post_getId(ePost* pElement, int* id){

	int retorno = 0;
	if(pElement != NULL && id != NULL)
	{
		*id = pElement->id;
		retorno = 1;
	}
	return retorno;
}


int Post_setLikes(ePost* pElement, int likes) {

	int retorno = 0;
	if(pElement != NULL && likes >= 0)
	{
		pElement->likes = likes;
		retorno = 1;
	}
	return retorno;
}


int Post_setLikesString(ePost* pElement, char* likes) {

	int retorno = 0;
	if(pElement != NULL && likes != NULL)
	{
		pElement->likes = atoi(likes);
		retorno = 1;
	}
	return retorno;
}

int Post_getLikes(ePost* pElement, int* likes){

	int retorno = 0;
	if(pElement != NULL && likes != NULL)
	{
		*likes = pElement->likes;
		retorno = 1;
	}
	return retorno;
}


int Post_setDislikes(ePost* pElement, int dislikes) {

	int retorno = 0;
	if(pElement != NULL && dislikes >= 0)
	{
		pElement->dislikes = dislikes;
		retorno = 1;
	}
	return retorno;
}


int Post_setDislikesString(ePost* pElement, char* dislikes) {

	int retorno = 0;
	if(pElement != NULL && dislikes != NULL)
	{
		pElement->dislikes = atoi(dislikes);
		retorno = 1;
	}
	return retorno;
}

int Post_getDislikes(ePost* pElement, int* dislikes){

	int retorno = 0;
	if(pElement != NULL && dislikes != NULL)
	{
		*dislikes = pElement->dislikes;
		retorno = 1;
	}
	return retorno;
}


int Post_setFollowers(ePost* pElement, int followers) {

	int retorno = 0;
	if(pElement != NULL && followers >= 0)
	{
		pElement->followers = followers;
		retorno = 1;
	}
	return retorno;
}


int Post_setFollowersString(ePost* pElement, char* followers) {

	int retorno = 0;
	if(pElement != NULL && followers != NULL)
	{
		pElement->followers = atoi(followers);
		retorno = 1;
	}
	return retorno;
}

int Post_getFollowers(ePost* pElement, int* followers){

	int retorno = 0;
	if(pElement != NULL && followers != NULL)
	{
		*followers = pElement->followers;
		retorno = 1;
	}
	return retorno;
}

int Post_setUser(ePost* pElement, char* user){

	int retorno = 0;

	if(pElement != NULL && user != NULL )
	{
		strcpy(pElement->user, user);
		retorno = 1;
	}
	return retorno;
}

int Post_getUser(ePost* pElement, char* user) {

	int retorno = 0;
	if(pElement != NULL && user != NULL)
	{
		strcpy(user, pElement->user);
		retorno = 1;
	}
	return retorno;
}