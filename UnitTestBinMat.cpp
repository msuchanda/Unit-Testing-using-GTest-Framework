/////////////////////////////////////////
//@Author: Suchanda Mukherjee
//@Last Edited: 1:39 AM 08/18/2015
/////////////////////////////////////////
#include <gtest/gtest.h>
#include <iostream>
#include "binint.h"
#include "binint.cpp"
#include "binvect.h"
#include "binvect.cpp"
#include "binmat.h" 
#include "binmat.cpp"
#include "mempool.h"
#include "mempool.cpp"
#include "dtstruct.h"
#include "dtstruct.cpp"
#include "inttypes.h" 
#include "nbtheory.h"
#include "nbtheory.cpp"
#include "utilities.h"
#include "utilities.cpp"
#include "ideals.h" 
#include "lwepre.h"
#include "lwepre.cpp"
#include "transfrm.h"
#include "transfrm.cpp"
#include "il2n.h"
#include "il2n.cpp" 
#include "lwecrypt.h"
#include "lwecrypt.cpp"
#include "distrgen.cpp"
#include "pubkeylp.h"


using namespace std;
using namespace lbcrypto;


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



/*
EXPECT_EQ (expected, actual) verifies expected == actual.
Compares two integer values
*/





/*---------------------------------------	TESTING METHODS OF BINMAT CLASS		--------------------------------------------*/


/*--------------TESTING METHOD KRONECKER PRODUCT FOR ALL CONDITIONS---------------------------*/


/*TEST(binmat_method_kronecker, test_kronecker_product){
	
	BigBinaryMatrix a(3,3);	

	a.SetValAtIndex(0,0,"4");
	a.SetValAtIndex(0,1,"9");
	a.SetValAtIndex(0,2,"6");
	a.SetValAtIndex(1,0,"3");
	a.SetValAtIndex(1,1,"7");
	a.SetValAtIndex(1,2,"4");
	a.SetValAtIndex(2,0,"8");
	a.SetValAtIndex(2,1,"2");
	a.SetValAtIndex(2,2,"5");

	BigBinaryMatrix b(3,3);

	b.SetValAtIndex(0,0,"12");
	b.SetValAtIndex(0,1,"15");
	b.SetValAtIndex(0,2,"9");
	b.SetValAtIndex(1,0,"4");
	b.SetValAtIndex(1,1,"6");
	b.SetValAtIndex(1,2,"23");
	b.SetValAtIndex(2,0,"45");
	b.SetValAtIndex(2,1,"56");
	b.SetValAtIndex(2,2,"8");


	BigBinaryMatrix c(9,9);
	c = a.KroneckerProduct(b);

	int i,j;
	usint rindex, cindex;
	int expectedResult[9,9] = {};

	for (rindex=0;rindex<9;rindex++){
		for(cindex=0;cindex<9;cindex++)		
		{
			cout << "\n"<< rindex <<","<< cindex <<":"<<(c.GetValAtIndex(rindex,cindex)).ConvertToInt()<<"\n";
			EXPECT_EQ(expectedResult[i][j], (c.GetValAtIndex(rindex,cindex)).ConvertToInt());
		}
	}	
}*/



/*--------------TESTING METHOD MODADD FOR ALL CONDITIONS---------------------------*/


/*TEST(binmat_method_modadd, test_binmat_modadd){
	BigBinaryMatrix a(3,3);	

	a.SetValAtIndex(0,0,"4");
	a.SetValAtIndex(0,1,"9");
	a.SetValAtIndex(0,2,"6");
	a.SetValAtIndex(1,0,"3");
	a.SetValAtIndex(1,1,"7");
	a.SetValAtIndex(1,2,"4");
	a.SetValAtIndex(2,0,"8");
	a.SetValAtIndex(2,1,"2");
	a.SetValAtIndex(2,2,"5");

	BigBinaryMatrix b(3,3);

	b.SetValAtIndex(0,0,"12");
	b.SetValAtIndex(0,1,"15");
	b.SetValAtIndex(0,2,"9");
	b.SetValAtIndex(1,0,"4");
	b.SetValAtIndex(1,1,"6");
	b.SetValAtIndex(1,2,"23");
	b.SetValAtIndex(2,0,"45");
	b.SetValAtIndex(2,1,"56");
	b.SetValAtIndex(2,2,"8");

	a.SetModulus("7");
	
	BigBinaryMatrix c(a.ModAdd(b));


	int i,j;
	usint rindex, cindex;
	int expectedResult[3][3] = {{2,3,1},{0,6,6},{4,2,6}};

	for (rindex=0;rindex<3;rindex++){
		for(cindex=0;cindex<3;cindex++)		
		{
			cout << "\n"<< rindex <<","<< cindex <<":"<<(c.GetValAtIndex(rindex,cindex)).ConvertToInt()<<"\n";
			EXPECT_EQ(expectedResult[i][j], (c.GetValAtIndex(rindex,cindex)).ConvertToInt());
		}
	}		
}*/



/*--------------TESTING METHOD MODSUB FOR ALL CONDITIONS---------------------------*/


/*TEST(binmat_method_modsub,test_binmat_modsub){
	BigBinaryMatrix a(3,3);	

	a.SetValAtIndex(0,0,"14");
	a.SetValAtIndex(0,1,"19");
	a.SetValAtIndex(0,2,"16");
	a.SetValAtIndex(1,0,"13");
	a.SetValAtIndex(1,1,"17");
	a.SetValAtIndex(1,2,"44");
	a.SetValAtIndex(2,0,"78");
	a.SetValAtIndex(2,1,"92");
	a.SetValAtIndex(2,2,"55");

	BigBinaryMatrix b(3,3);

	b.SetValAtIndex(0,0,"12");
	b.SetValAtIndex(0,1,"15");
	b.SetValAtIndex(0,2,"9");
	b.SetValAtIndex(1,0,"4");
	b.SetValAtIndex(1,1,"6");
	b.SetValAtIndex(1,2,"23");
	b.SetValAtIndex(2,0,"45");
	b.SetValAtIndex(2,1,"56");
	b.SetValAtIndex(2,2,"8");

	a.SetModulus("7");

	BigBinaryMatrix c(3,3);
	c = a.ModSub(b);

	int i,j;
	usint rindex, cindex;
	int expectedResult[3][3] = {{2,4,0},{2,4,0},{5,1,5}};

	for (rindex=0;rindex<3;rindex++){
		for(cindex=0;cindex<3;cindex++)		
		{
			cout << "\n"<< rindex <<","<< cindex <<":"<<(c.GetValAtIndex(rindex,cindex)).ConvertToInt()<<"\n";
			EXPECT_EQ(expectedResult[i][j], (c.GetValAtIndex(rindex,cindex)).ConvertToInt());
		}
	}		
}*/

/*---------------------------------------	END OF TEST CODES	-------------------------------------------------------*/

