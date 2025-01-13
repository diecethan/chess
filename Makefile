STD=-std=c++20
OPT=-g
CPP=g++
TMPMAKE=tmpMake
CPPFLAGS=${STD} ${OPT}
CFLAGS=${OPT}

# Define source and object files
CHESSSRCS = chess.cpp board.cpp knight.cpp rook.cpp bishop.cpp queen.cpp king.cpp pawn.cpp
CHESSOBJS = $(CHESSSRCS:.cpp=.o)

ALL = chess

all: $(CHESSOBJS) $(ALL)

chess: $(CHESSOBJS)
	$(CPP) -o $@ $(CPPFLAGS) $(CHESSOBJS)

%.o: %.cpp
	$(CPP) -c $(CPPFLAGS) $<

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
chess.o: piece.h pawn.h rook.h knight.h bishop.h queen.h king.h board.h
board.o: piece.h pawn.h rook.h knight.h bishop.h queen.h king.h board.h
knight.o: piece.h knight.h
rook.o: piece.h rook.h
bishop.o: piece.h bishop.h
queen.o: piece.h queen.h
king.o: piece.h king.h
pawn.o: piece.h pawn.h