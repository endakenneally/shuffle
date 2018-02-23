#include <stdio.h>
#include <string.h>
#include <time.h>

int enterArtists(char artists[4][40],int numOfArtists);
void printArtists(char artists[4][40]);
int enterSongs(char songs[4][40], int numOfSongs, char artists[4][40], int index);
void printSongs(char songs[4][40]);
void copySongs(char songs[4][4][40], char tmpsongs[4][40], int index);
void sortArtists(char artists[4][40]);
void output(char artists[4][40], char songs[4][4][40], int numOfSongs, int index);
int putin(char list[24][40], char songs[4][40], int numOfSongs, int index);
void shuffle(char list[24][40], int numOfSongs);

int main()
{
  int i,j,b = 0;
  int counter = 0;
  char artists[4][40];
  int numOfArtists = 0;
  int numOfSongs1 = 0;
  int numOfSongs2 = 0;
  int numOfSongs3 = 0;
  int numOfSongs4 = 0;
  int totalSongs;
  char list[24][40];

  srand(time(NULL));

  numOfArtists=enterArtists(artists, numOfArtists);
  //printArtists(artists);

  //printf("The number of artists is %d", numOfArtists);
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

  if(numOfArtists > 0)
  {
    numOfSongs1 = enterSongs(songs1, numOfSongs1, artists, 0);
  }
  if(numOfArtists > 1)
  {
    numOfSongs2 = enterSongs(songs2, numOfSongs2, artists, 1);
  }
  if(numOfArtists > 2)
  {
    numOfSongs3 = enterSongs(songs3, numOfSongs3, artists, 2);
  }
  if(numOfArtists > 3)
  {
    numOfSongs4 = enterSongs(songs4, numOfSongs4, artists, 3);
  }

  totalSongs = numOfSongs1+numOfSongs2+numOfSongs3+numOfSongs4;

  copySongs(songs,songs1,0);
  copySongs(songs,songs2,1);
  copySongs(songs,songs3,2);
  copySongs(songs,songs4,3);

  printf("Sorted list of songs: \n");

  if(numOfArtists > 0)
  {
    output(artists, songs, numOfSongs1, 0);
  }
  if(numOfArtists > 1)
  {
    output(artists, songs, numOfSongs2, 1);
  }
  if(numOfArtists > 2)
  {
    output(artists, songs, numOfSongs3, 2);
  }
  if(numOfArtists > 3)
  {
    output(artists, songs, numOfSongs4, 3);
  }

  int index = putin(list, songs1, numOfSongs1, 0);
  index = putin(list, songs2, numOfSongs2, index);
  index = putin(list, songs3, numOfSongs3, index);
  index = putin(list, songs4, numOfSongs4, index);
  index = putin(list, songs1, numOfSongs1, index);
  index = putin(list, songs2, numOfSongs2, index);
  index = putin(list, songs3, numOfSongs3, index);
  index = putin(list, songs4, numOfSongs4, index);

  for(int i = 0; i < index; i++)
  {
    printf("%s", list[i]);
  }

  printf("\n\n\n\n");

  shuffle(list, index);

  for(int i = 0; i < index; i++)
  {
    printf("%s", list[i]);
  }

  return 0;
}

int enterArtists(char artists[4][40], int numOfArtists)
{
  int i;

  for(i = 0; i < 4;i++)
  {
    printf("Please input an Artist: ");
    fgets(artists[i], 40, stdin);
    if(artists[i][0] == 'z')
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

int enterSongs(char songs[4][40], int numOfSongs, char artists[4][40], int index)
{
  int i, j;
  char tmp[40];

  for(i = 1; i < 4;i++)
  {
    printf("Please input song %d for artist %s: ", i, artists[index]);
    fgets(songs[i], 40, stdin);
    if(songs[i][0] == 'z')
    {
      break;
    }
    numOfSongs++;
  }

  for(j = 1; j < 4 ; j++)
  {
    for(i = 1; i < 4; i++)
    {
      if(strcmp(songs[j],songs[i])<0)
      {
        strcpy(tmp,songs[j]);
        strcpy(songs[j],songs[i]);
        strcpy(songs[i],tmp);
      }
    }
  }
  return numOfSongs;
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

void output(char artists[4][40], char songs[4][4][40], int numOfSongs, int index)
{
  int i;
    printf("%s", artists[index]);
    for(i = 1; i < numOfSongs+1; i++)
    {
      printf("    -   %s", songs[index][i]);
    }
}

void shuffle(char list[24][40], int index)
{
  int i,j,swap[40];

  for(i = 0; i <index; i++)
  {
    j = rand()%(i+1);
    if(j!=1)
    {
      strcpy(swap,list[j]);
      strcpy(list[j], list[i]);
      strcpy(list[i], swap);
    }
  }
}

int putin(char list[24][40], char songs[4][40], int numOfSongs, int index)
{
  for(int i = 0; i < numOfSongs;i++)
  {
    strcpy(list[index], songs[i+1]);
    index++;
  }
  return index;
}
