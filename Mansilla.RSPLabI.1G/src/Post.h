#ifndef POST_H_
#define POST_H_

typedef struct {
	//id, user, likes, dislikes, followers
	int id;
	char user[50];
	int likes;
	int dislikes;
	int followers;
}ePost;

#endif /* POST_H_ */


ePost* Post_new();
ePost* Post_newParametros(char* idStr, char* userStr, char* likesStr, char* dislikesStr, char* followersStr) ;


int Post_setId(ePost* pElement, int id) ;
int Post_setIdString(ePost* pElement, char* idStr);
int Post_getId(ePost* pElement, int* id);
int Post_setLikes(ePost* pElement, int likes);
int Post_setLikesString(ePost* pElement, char* likes) ;
int Post_getLikes(ePost* pElement, int* likes);
int Post_setDislikes(ePost* pElement, int dislikes);
int Post_setDislikesString(ePost* pElement, char* dislikes);
int Post_getDislikes(ePost* pElement, int* dislikes);
int Post_setFollowers(ePost* pElement, int followers);
int Post_setFollowersString(ePost* pElement, char* followers) ;
int Post_getFollowers(ePost* pElement, int* followers);
int Post_setUser(ePost* pElement, char* user);
int Post_getUser(ePost* pElement, char* user);
