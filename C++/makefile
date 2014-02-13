CPP = g++
C11 = -std=c++11

all:
#skip

#STL
for_each : ./STL/for_each.cpp
	$(CPP) -o $@ $<
pair : ./STL/pair.cpp
	$(CPP) -o $@ $<
to_upper_or_lower : ./STL/to_upper_or_lower.cpp
	$(CPP) -o $@ $<

#algorthm
closest_pair_problem : ./algorithm/closest_pair_problem.cpp
	$(CPP) -o $@ $< $(C11)
BFS : ./algorithm/BFS.cpp
	$(CPP) -o $@ $<
DFS : ./algorithm/DFS.cpp
	$(CPP) -o $@ $<

clean:
	rm -rf *.o
