#include <stdio.h>
#include <string.h>

typedef struct movie {
    char name[32];
    int ranking;
} movie_t; 

movie_t* fill_movie(movie_t* m) {
    strcpy(m->name, "BE ALL YOU CAN BE !");
    m->ranking = 1;
}

int main() {
    movie_t mymovie;
    movie_t* mp;
    mp = fill_movie(&mymovie);
    printf("name = %s\n", mp->name); 
    printf("ranking = %d\n", mp->ranking);
    return 0;
}
