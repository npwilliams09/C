/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by Nathan Williams
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int daysFrom (int month, int day, int leapYear);
int date (int month, int leapYear);

 
int main (int argc, char *argv[]) {
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
 
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
 
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
 
   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
   int dayOfWeek;
 
   dayOfWeek = (doomsday + daysFrom(month, day, leapYear)) % 7;
 
   return (dayOfWeek);
   return EXIT_SUCCESS;
}

int daysFrom (int month, int day, int leapYear) {
   int daysFrom;
   int dateM;
   
   dateM = date(month, leapYear);
   
   if (day >= dateM) {
      daysFrom = (day - dateM) % 7;
   } else 
   
   if (day < dateM) {
      daysFrom = 7 - ((dateM - day) % 7);
   }
   return (daysFrom);
   return EXIT_SUCCESS;
}

int date (int month, int leapYear) {
   int dateM;
   
   if (month == DECEMBER) {
      dateM = 12; 
   } else
   
   if (month == NOVEMBER) {
      dateM = 7;
   } else
   
   if (month == OCTOBER) {
      dateM = 10;
   } else
   
   if (month == SEPTEMBER) {
      dateM = 5;
   } else
   
   if (month == AUGUST) {
      dateM = 8;
   } else
   
   if (month == JULY) {
      dateM = 11;
   } else
   
   if (month == JUNE) {
      dateM = 6;
   } else
   
   if (month == MAY) {
      dateM = 9;
   } else
   
   if (month == APRIL) {
      dateM = 4;
   } else
   
   if (month == MARCH) {
      dateM = 7;
   } else
   
   if ((month == FEBRUARY) && (leapYear == TRUE)) {
      dateM = 29;
   } else
   
   if ((month == FEBRUARY) && (leapYear == FALSE)) {
      dateM = 28;
   } else
   
   if ((month == JANUARY) && (leapYear == TRUE)) {
      dateM = 4;
   } else
   
   if ((month == JANUARY) && (leapYear == FALSE)) {
      dateM = 3;
   } else 
   dateM = 0;
   
   return (dateM);
   return EXIT_SUCCESS; 
}
