# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: numarare trenuri

run-p1:
	./numarare
run-p2:
	./trenuri
run-p3:
	./p3
run-p4:
	./p4

numarare: numarare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
trenuri: trenuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: p3.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: p4.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f numarare trenuri
