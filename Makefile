CXX = /bin/g++
CXXFLAGS =
INCFLAGS =
DEFS = -DYY_NEVER_INTERACTIVE
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(DEFS) -c $< -o $@ 

OBJS = sql_lex.o sql.tab.o gen_sql.o cancelDdl.o

.PHONY : clean

all:cancel_ddl

cancel_ddl:$(OBJS) 
	$(CXX) $(OBJS) -o $@

clean:
	rm -rf *.o
	rm -rf cancel_ddl

