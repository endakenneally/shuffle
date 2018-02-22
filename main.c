#include <stdio.h>
#include <string.h>

void enterArtists(char artists[4][40]);
void printArtists(char artists[4][40]);
void enterSongs(char songs[4][40]);
void printSongs(char songs[4][40]);
void copySongs(char songs[4][4][40], char tmpsongs[4][40], int index);
void sortArtists(char artists[4][40]);

int main()
{
  int i,j,index,b = 0;
  char artists[4][40];

  enterArtists(artists);
  //printArtists(artists);

  sortArtists(artists);
  printArtists(artists);

  char songs[4][4][40];
  char songs1[4][40];
  char songs2[4][40];
  char songs3[4][40];
  char songs4[4][40];

  // Used to associate the songs with the artists
  songs1[0][0] = '1';
  songs2[0][0] = '2';
  songs3[0][0] = '3';
  songs4[0][0] = '4';

  enterSongs(songs1);
  enterSongs(songs2);
  enterSongs(songs3);
  enterSongs(songs4);

  copySongs(songs,songs1,0);
  copySongs(songs,songs2,1);
  copySongs(songs,songs3,2);
  copySongs(songs,songs4,3);
  //printSongs(songs1);

  return 0;
}

void enterArtists(char artists[4][40])
{
  int i;

  for(i = 0; i < 4;i++)
  {
    printf("Please input an Artist: ");
    fgets(artists[i], 40, stdin);
  }
}

void printArtists(char artists[4][40])
{
  int i, b;

  for(b = 0; b < 4;b++)
  {
    for(i = 0; i < (strlen(artists[b]));i++)
    {
      printf("%c", artists[b][i]);
    }
    printf("\n");
  }
}

void printSongs(char songs[4][40])
{
  int i, b;

  for(b = 1; b < 4;b++)
  {
    for(i = 0; i < (strlen(songs[b]));i++)
    {
      printf("%c", songs[b][i]);
    }
    printf("\n");
  }
}

void enterSongs(char songs[4][40])
{
  int i;

  for(i = 1; i < 4;i++)
  {
    printf("Please input song %d for artist %d: ", i, (songs[0][0]-48));
    fgets(songs[i], 40, stdin);
  }
}

void copySongs(char songs[4][4][40], char tmpsongs[4][40], int index)
{
  int i;
  for(i = 0; i < 4; i++)
  {
    strcpy(songs[index][i],tmpsongs[i]);
  }
}

void sortArtists(char artists[4][40])
{
  int i, j;
  char tmp[40];

  for(j = 0; j < 4 ; j++)
  {
    for(i = 0; i < 4; i++)
    {
      if(strcmp(artists[j],artists[i])< 0)
      {
        strcpy(tmp,artists[j]);
        strcpy(artists[j],artists[i]);
        strcpy(artists[i],tmp);
      }
    }
  }
}
