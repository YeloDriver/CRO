all: bin/hanoi

bin/hanoi: obj/main.o obj/hanoi.o obj/pile.o
	gcc.exe -o $@ $^

obj/main.o: include/pile_type.h include/pile.h include/hanoi.h
#     gcc.exe -o obj/main.o -c src/main.c

obj/hanoi.o: include/pile.h include/hanoi.h
#     gcc.exe -o obj/hanoi.o -c src/hanoi.c

obj/pile.o: include/pile.h include/pile_type.h
#     gcc.exe -o obj/pile.o -c src/pile.c

obj/%.o: src/%.c
	gcc.exe -Wall -Iinclude -o $@ -c $<

clean:
	rm -f obj/*

mrproper: clean
	rm bin/*