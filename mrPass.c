/*
 *  Mr Pass.  Brain the size of a planet!
 *
 *  Proundly Created by Richard Buckland
 *  Share Freely Creative Commons SA-BY-NC 3.0. 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "mechanicalTurk.h"

action decideAction (Game g) {
	action nextAction;
	int me = getWhoseTurn (g);
	int numMTV = getStudents (g, me, STUDENT_MTV);

	int numMJ = getStudents (g, me, STUDENT_MJ);

	int numMMONEY = getStudents (g, me, STUDENT_MMONEY);

	if (numMTV >= 1 && numMJ >= 1 && numMMONEY >= 1) {
		nextAction.actionCode = START_SPINOFF;
	} 


   
   
   nextAction.actionCode = PASS;
   
   return nextAction;
}
