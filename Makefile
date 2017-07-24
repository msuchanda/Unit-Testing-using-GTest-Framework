CPPFLAGS += -Wall -O3 -std=gnu++11 -w -g

TaskLDFLAGS = -lpthread
TimeLDFLAGS = -lm -lrt

TARGETS= NTRU-PRE
all: $(TARGETS)

MAINDEPS= binint.o\
binmat.o\
binvect.o\
mempool.o\
nbtheory.o\
dtstruct.o\
transfrm.o\
distrgen.o\
lwecrypt.o\
lwepre.o\
il2n.o\
utilities.o
#\
#ideals.o\
#inttypes.o\
#pubkeylp.o

#sipher-v10-01-debug: $(MAINDEPS) debug.o
#	$(CC) -o $@ $^ $(TaskLDFLAGS) $(TimeLDFLAGS)

NTRU-PRE: $(MAINDEPS) Source.o
	$(CXX) -o $@ $^ $(TaskLDFLAGS) $(TimeLDFLAGS)

NTRU-PRE-Key: $(MAINDEPS) Source_key.o
	$(CXX) -o $@ $^ $(TaskLDFLAGS) $(TimeLDFLAGS)

.PHONEY: apidocs
apidocs:
	doxygen lbcrypto-doxy-config

.PHONEY: cleandocs
cleandocs:
	rm -rf apidocs

.PHONEY: publishapi
publishapi: apidocs
	rm -rf /opt/doxygen/arms-nfd && mv apidocs/html /opt/doxygen/arms-nfd

.PHONEY: clean
clean: cleandocs
	rm -f *.o $(TARGETS) *~ .depends

.PHONEY: depends
depends: .depends
.depends:
	@echo -n "Generating dependencies..."
	@gcc -E -MM *.o > $@
	@echo "Done."



############# GTEST MAKE FUNCTIONS ##############
#@Author: Suchanda Mukherjee.
#@Last Edited: 1:39 AM, 08/18/2015.

TESTTARGETINT = UnitTestBinInt.o
TESTSOURCEINT = UnitTestBinInt.cpp

TESTTARGETVECT = UnitTestBinVect.o
TESTSOURCEVECT = UnitTestBinVect.cpp

TESTTARGETMAT = UnitTestBinMat.o
TESTSOURCEMAT = UnitTestBinMat.cpp

LINKERTARGETS = /usr/src/gtest/src/gtest_main.cc
TESTFLAGS = -lgtest -lpthread

.PHONEY: test
test: 
	@echo -n "\nCreating Unit Test Files for BigBinaryInteger...\n"
	$(CXX) $(CPPFLAGS) -L $(LINKERTARGETS) -o $(TESTTARGETINT) $(TESTSOURCEINT) $(TESTFLAGS)
	@echo -n "\nCreating Unit Test Files for BigBinaryVector...\n"
	$(CXX) $(CPPFLAGS) -L $(LINKERTARGETS) -o $(TESTTARGETVECT) $(TESTSOURCEVECT) $(TESTFLAGS)
	@echo -n "\nCreating Unit Test Files for BigBinaryMatrix...\n"
	$(CXX) $(CPPFLAGS) -L $(LINKERTARGETS) -o $(TESTTARGETMAT) $(TESTSOURCEMAT) $(TESTFLAGS)
	@echo -n "\nUnit test built, run with command \"./$(TESTTARGETINT)\", \"./$(TESTTARGETVECT)\", \"./$(TESTTARGETMAT)\"\n\n"

.PHONEY: cleantest
cleantest:
	@echo -n "\nRemoving Unit Test Files...\n\n"
	rm -rf $(TESTTARGETINT)
	rm -rf $(TESTTARGETVECT)
	rm -rf $(TESTTARGETMAT)
	@echo -n "\nUnit test files removed successfully, compile again with \"make test\" command\n\n"

############# END OF GTEST MAKE FUNCTIONS ##############



-include .depends
