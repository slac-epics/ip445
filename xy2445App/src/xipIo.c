/*******************************************************************************

Project:
    IndustryPack Driver Interface for EPICS

File:
    xipIo.c

Copied xipIoParse() from original drvXy9660.c file
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "xipIo.h"


char *strdupn( const char *ct, size_t n )
{
  char *duplicate;

  duplicate = (char *)malloc(n+1);
  if( !duplicate )
    return NULL;

  memcpy(duplicate, ct, n);
  duplicate[n] = '\0';

  return duplicate;
}

int xipIoParse( char *str, xipIo_t *ptr, char flag )
{
  char *name;
  char *end;

  if( str == NULL || ptr == NULL )
    return 1;

  while( !isalnum(*str) )
  {
    if( *str++ == '\0')
      return 1;
  }

  name = str;

  str = strpbrk(str, " ");
  if( str == NULL || *str == '\0' )
    return 1;

  ptr->name = strdupn(name, str - name);
  if( ptr->name == NULL )
    return 1;

  if( flag == 'A' )
  {
    end = strchr(str,'C');
    if( end )
    {
      str = end + 1;
      sscanf(str,"%d", &ptr->channel);
    }
    else
      return 1;
  }
  else if( flag == 'B' )
  {
    end = strchr(str,'P');
    if( end )
    {
      str = end + 1;
      sscanf(str,"%d", &ptr->port);
      end = strchr(str,'B');
      if( end )
      {
        str = end + 1;
        sscanf(str,"%d", &ptr->bit);
      }
      else
        return 1;
    }
    else
      return 1;
  }
  return(0);
}
