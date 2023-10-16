/*-
 * Copyright (c) 2023, Collin Funk
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <config.h>

#include <langinfo.h>
#include <locale.h>
#include <stddef.h>
#include <stdlib.h>

char *
nl_langinfo (nl_item item)
{
  switch (item)
    {
    case CODESET:
      /* Latin 1 */
      return "ISO-8859-1";
    case D_T_FMT:
      return "%a %b %e %H:%M:%S %Y";
    case D_FMT:
      return "%m/%d/%y";
    case T_FMT:
      return "%H:%M:%S";
    case T_FMT_AMPM:
      return "%I:%M:%S %p";
    case AM_STR:
      return "AM";
    case PM_STR:
      return "PM";
    case DAY_1:
      return "Sunday";
    case DAY_2:
      return "Monday";
    case DAY_3:
      return "Tuesday";
    case DAY_4:
      return "Wednesday";
    case DAY_5:
      return "Thursday";
    case DAY_6:
      return "Friday";
    case DAY_7:
      return "Saturday";
    case ABDAY_1:
      return "Sun";
    case ABDAY_2:
      return "Mon";
    case ABDAY_3:
      return "Tue";
    case ABDAY_4:
      return "Wed";
    case ABDAY_5:
      return "Thu";
    case ABDAY_6:
      return "Fri";
    case ABDAY_7:
      return "Sat";
    case MON_1:
      return "January";
    case MON_2:
      return "February";
    case MON_3:
      return "March";
    case MON_4:
      return "April";
    case MON_5:
      return "May";
    case MON_6:
      return "June";
    case MON_7:
      return "July";
    case MON_8:
      return "August";
    case MON_9:
      return "September";
    case MON_10:
      return "October";
    case MON_11:
      return "November";
    case MON_12:
      return "December";
    case ABMON_1:
      return "Jan";
    case ABMON_2:
      return "Feb";
    case ABMON_3:
      return "Mar";
    case ABMON_4:
      return "Apr";
    case ABMON_5:
      return "May";
    case ABMON_6:
      return "Jun";
    case ABMON_7:
      return "Jul";
    case ABMON_8:
      return "Aug";
    case ABMON_9:
      return "Sep";
    case ABMON_10:
      return "Oct";
    case ABMON_11:
      return "Nov";
    case ABMON_12:
      return "Dec";
    case ERA:
      return "";
    case ERA_D_FMT:
      return "";
    case ERA_D_T_FMT:
      return "";
    case ERA_T_FMT:
      return "";
    case ALT_DIGITS:
      return "";
    case RADIXCHAR:
      return localeconv ()->decimal_point;
    case THOUSEP:
      return localeconv ()->thousands_sep;
    case YESEXPR:
      return "^[yY]";
    case NOEXPR:
      return "^[nN]";
    case CRNCYSTR:
      return "-";
    default:
      return "";
    }
}
