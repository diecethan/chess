STD=-std=c++20
OPT=-g
CPP=g++
TMPMAKE=tmpMake
CPPFLAGS=${STD} ${OPT}
CFLAGS=${OPT}

%.o: %.cpp
	$(CPP) -c $(CPPFLAGS) $<

%: %.cpp
	$(CPP) -o $@ $(CPPFLAGS) $<

CHESSSRCS = chess.cpp
CHESSOBJS = $(CHESSSRCS:.cpp=.o)

ALL = chess

all: $(CHESSOBJS) $(ALL)

clean:
	/bin/rm -f $(CHESSOBJS) $(ALL)
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(CHESSSRCS)
	/bin/rm -f $(TMPMAKE)
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $(TMPMAKE)
	echo '# DEPENDENTS' >> $(TMPMAKE)
	$(CPP) -MM $+ >> $(TMPMAKE)
	/bin/mv -f $(TMPMAKE) Makefile

# DEPENDENTS
chess.o: piece.h knight.h