// PingPongOS - PingPong Operating System
// Prof. Carlos A. Maziero, DINF UFPR
// Versão 1.1 -- Julho de 2016

// Teste do escalonador por prioridades dinâmicas

#include <stdio.h>
#include <stdlib.h>
#include "ppos.h"

task_t Pang, Peng, Ping, Pong, Pung ;

// corpo das threads
void Body (void * arg)
{
  int i ;

  printf ("%s: inicio (eet: %d)\n", (char *) arg, task_get_eet(NULL)) ;

  for (i=0; i<task_get_eet(NULL); i++)
  {
    printf ("%s: %d, ret: %d\n", (char *) arg, i, task_get_ret(NULL)) ;
    task_yield ();
  }
  printf ("%s: fim\n", (char *) arg) ;
  task_exit (0) ;
}

int main (int argc, char *argv[])
{
  printf ("main: inicio\n");

  ppos_init () ;

  task_create (&Pang, Body, "    Pang") ;
  task_set_eet(&Pang, 10);
//  task_setprio (&Pang, 0);

  task_create (&Peng, Body, "        Peng") ;
//  task_setprio (&Peng, 2);
  task_set_eet(&Peng, 5);

  task_create (&Ping, Body, "            Ping") ;
//  task_setprio (&Ping, 4);
  task_set_eet(&Ping, 10);

  task_create (&Pong, Body, "                Pong") ;
//  task_setprio (&Pong, 6);
  task_set_eet(&Pong, 15);

  task_create (&Pung, Body, "                    Pung") ;
//  task_setprio (&Pung, 8);
  task_set_eet(&Pung, 7);

  task_join(&Pang);
  task_join(&Peng);
  task_join(&Ping);
  task_join(&Pong);
  task_join(&Pung);

  printf ("main: fim\n");
  exit (0) ;
}
