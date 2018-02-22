#include <stdio.h>
#include <string.h>

int enterArtists(char artists[4][40],int numOfArtists);
void printArtists(char artists[4][40]);
int enterSongs(char songs[4][40], int numOfSongs[]);
void printSongs(char songs[4][40]);
void copySongs(char songs[4][4][40], char tmpsongs[4][40], int index);
void sortArtists(char artists[4][40]);
void output(char artists[4][40], char songs[4][4][40]);

int main()
{
  int i,j,index,b = 0;
  char artists[4][40];
  int numOfArtists;

  enterArtists(artists, numOfArtists);
  //printArtists(artists);

  sortArtists(artists);
  //printArtists(artists);

  int numOfSongs[numOfArtists];

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

  enterSongs(songs1, numOfSongs);
  enterSongs(songs2, numOfSongs);
  enterSongs(songs3, numOfSongs);
  enterSongs(songs4, numOfSongs);

  copySongs(songs,songs1,0);
  copySongs(songs,songs2,1);
  copySongs(songs,songs3,2);
  copySongs(songs,songs4,3);

  /*
  printf("%s", songs[0][1]);
  printf("%s", songs[0][2]);
  printf("%s", songs[0][3]);
  */

  output(artists, songs);

  return 0;
}

int enterArtists(char artists[4][40], int numOfArtists)
{
  int i;

  for(i = 0; i < 4;i++)
  {
    printf("Please input an Artist: ");
    fgets(artists[i], 40, stdin);
    if(artists[i][0] == '\n')
    {
      break;
    }
      numOfArtists++;
  }
  //printf("NUmber of artists is %d", numOfArtists);
  return numOfArtists;
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

int enterSongs(char songs[4][40], int numOfSongs[])
{
  int i, j;
  char tmp[40];

  for(i = 1; i < 4;i++)
  {
    printf("Please input song %d for artist %d: ", i, (songs[0][0]-48));
    fgets(songs[i], 40, stdin);
  }

  for(j = 0; j < 4 ; j++)
  {
    for(i = 0; i < 4; i++)
    {
      if(strcmp(songs[j],songs[i])<0)
      {
        strcpy(tmp,songs[j]);
        strcpy(songs[j],songs[i]);
        strcpy(songs[i],tmp);
      }
    }
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

void output(char artists[4][40], char songs[4][4][40])
{
  int i,j;

  printf("Sorted list of songs: \n");
  for(j = 0; j < 4; j++)
  {
    printf("%s", artists[j]);
    for(i = 1; i < 4; i++)
    {
      printf("    -   %s", songs[j][i]);
    }
  }
}
