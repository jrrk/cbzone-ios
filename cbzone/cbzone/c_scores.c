#include "c_includes.h"
/*
 * cbzone_scores.c
 *  -- Todd W Mummert, December 1990, CMU
 *
 * RCS Info
 *  $Header: c_scores.c,v 1.1 91/01/12 02:03:36 mummert Locked $
 *
 *  Derived from work I did on our local version of golddig.  Thanks
 *  to Bennet Yee (CMU) for the flock() code.
 */

/*
 * Okay, let's try to clean this up.  The following things may
 * happen:
 *   score < 0:  then the user is just asking for scores.  the score
 *               file should not be changed.
 *   score >= 0: score is either valid, for practice, or played by an
 *               old version.  In all cases, the file should change.
 *
 *   file status:
 *     can be not there
 *            available for reading
 *            available for both reading and writing
 *            not there but can be written
 *
 * we know the following:
 *   whether the game was for practice only.
 *   any scores in the score file WILL be in the correct order.
 *
 *  the format of the score file is as follows:
 *    Version identification
 *    number of games played, followed by number of valid games
 *    scores, one per line w/uid and player's name
 *
 * how should we go about comparing users?
 *  use getuid and cuserid...check both of them since we may be
 *  saving scores over a distributed file system
 *
 * if the game was scoresonly, print to tty if opt->output allows;
 *  else print to X screen.
 */

extern int errno;
static int x, y, ydelta;
static void p(s, output)                 /* print to the X screen */
     char* s;
     Bool output;
{
  printstring (x, y, s, strlen(s));
  y += ydelta;
}

long scores(score)
     long score;
{
  struct score_struct {
    long score;
    int uid;
    char name[50];
    struct score_struct *next;
  } player, *current, *top_score, *prev_score;

  FILE *sfile;
  char buf[200];
  char *login, *getlogin();
  int i;
  int numgame = 0;
  int numscore = 0;
  int player_scores = 0;
  Bool score_printed = False;
  Bool scoresonly = False;
  Bool wrong_version = False;
  Bool practice = opt->practice;
  struct passwd* pw;

  x = 350;
  y = 100;
    ydelta = 25;

    
    top_score = (struct score_struct*) malloc(sizeof(struct score_struct));
    current = top_score;
    
  sprintf(buf,"%s%s",TANKDIR,SCOREFILE);
  sfile = fopen(buf,"r+");       /* just check if it is there */

  if (sfile == NULL)
      sfile = fopen(buf,"w");
   else
    while(fgets(buf,200,sfile) && numscore < NUMHIGH)
    {
      if (sscanf(buf,"%ld %d %[^\n]",&current->score,
                 &current->uid,current->name) == 3)
      {
        current->next = (struct score_struct*)
          malloc(sizeof(struct score_struct));
        prev_score = current;
        current = current->next;
        numscore ++;
      }
  }

  if (numscore)
    prev_score->next = NULL;
  else
    top_score = NULL;

  if (!scoresonly) {
    /* try to get it from the passwd file first, just in case this
     * person su'd from another acct.
     */
    player.uid = getuid();
    player.score = score;
    pw = getpwuid(player.uid);
    if (pw == NULL)
      if ((login = getlogin()) != NULL)
        strcpy(player.name, login);
      else {
          strcpy(player.name, "Anon");
      }
    else
      strcpy(player.name, pw->pw_name);

    if (numscore < NUMHIGH || player.score > prev_score->score) {
      score_printed = True;
      numscore++;

      for (current = top_score;
           current != NULL && player.score <= current->score;
           prev_score = current, current = current->next);

      player.next = current;

      if (current == top_score)
        top_score = &player;
      else
        prev_score->next = &player;
    }

    numgame++;
  }

  p("GAME OVER - high scores", opt->output);
  current = top_score;
  while (current != NULL) {
    if (current == &player)
      *buf = '>';
    else
      *buf = ' ';
    sprintf(buf+1, "%-20s %8ld", current->name, current->score);
    p(buf, opt->output);

    if (((wrong_version || practice) && current==&player) ||
        (current->uid==player.uid && !strcmp(player.name, current->name) &&
         ++player_scores>INDIVIDUAL_SCORES)) {
      numscore--;
      if (current == top_score)
        top_score = current->next;
      else
        prev_score->next = current->next;
    }
    else
      prev_score = current;
    current = current->next;
  }

  if (!scoresonly && !score_printed) {
    p("...", opt->output);
    sprintf(buf, ">%-20s %8ld", player.name,player.score);
    p(buf, opt->output);
  }

    rewind(sfile);
    for(current = top_score, i = 0;
        current != NULL && i < NUMHIGH;
        current = current->next, i++)
      fprintf(sfile,"%ld %d %s\n",current->score,current->uid,current->name);
 
  fclose(sfile);
    
  return 0;
}
