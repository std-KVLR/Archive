/* GNU Chess 5.0 - epd.c - EPD position definition code
   Copyright (c) 1999-2002 Free Software Foundation, Inc.

   GNU Chess is based on the two research programs 
   Cobalt by Chua Kong-Sian and Gazebo by Stuart Cracraft.

   GNU Chess is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GNU Chess is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU Chess; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Contact Info: 
     bug-gnu-chess@gnu.org
*/
/*
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "common.h"

#define EPDCLOSE 1

short ReadEPDFile (const char *file, short op)
/****************************************************************************
 *
 *  Reads in an EPD file.  The first call will read the first EPD line,
 *  the second call will read the 2nd line and so on.   To improve
 *  performance, the file is never closed.  Closing of the file happens
 *  only on 2 conditions:  (i) A ReadEPDFile failed because there is no 
 *  more lines to read.  (ii) A called to ReadEPDFile to explicitly 
 *  request that the file is closed (op = EPDCLOSE);
 *  If op == 2, then we work silently.
 *
 ****************************************************************************/
{
   static FILE *fp = NULL;
   char line[MAXSTR];

   /*  If first time through, must open file  */
   if (fp == NULL)
   {
      fp = fopen (file, "r");
      if (fp == NULL)
      {
         printf ("Error opening file %s\n", file);
         return (false);
      }
   }

   /*  Is this a close request? */
   if (op == EPDCLOSE)   
   { 
      fclose (fp);
      fp = NULL;
      return (false);
   }

next_line:
   /*  Okay, we read in an EPD entry  */
   fgets (line, MAXSTR-1, fp);
   if (!feof(fp)) 
   {
      int ret = ParseEPD (line);

      /* For now just ignore malformed lines */
      if (ret != EPD_SUCCESS) goto next_line;
      if (op != 2)
         printf ("