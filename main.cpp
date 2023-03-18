#include <iostream>
#include "Skup.h"
#include "Rec.h"
#include "Stih.h"
#include "Strofa.h"
#include "Katren.h"


int main() {

	Rec r1("U");
	Rec r2("meni");
	Rec r3("cvile");
	Rec r4("duse");
	Rec r5("miliona");
	Rec r6("Moj");
	Rec r7("svaki");
	Rec r8("uzdah");
	Rec r9("svaka");
	Rec r10("suza");
	Rec r11("bona");
	Rec r12("Zena");
	Rec r13("leptir");
	Rec r14("miliona");
	Rec r15("bombona");
	Skup sap("Pera");

	Stih s1;
	Stih s2;
	Stih s3;

	s1 += r1;
	s1 += r2;
	s1 += r3;
	s1 += r4;
	s1 += r5;
	s2 += r6;
	s2 += r7;
	s2 += r8;
	s2 += r9;
	s2 += r10;
	s2 += r11;
	s3 += r12;
	s3 += r13;
	s3 += r14;
	s3 += r15;

	Katren k;
	-k;
	k += s3;
	k += s2;
	k += s1;
	k += s2;

	cout << k << endl << endl;



	return 0;
}