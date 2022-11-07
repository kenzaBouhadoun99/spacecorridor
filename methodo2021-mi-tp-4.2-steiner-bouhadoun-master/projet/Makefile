CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = sdl2-light.h monde.h graphique.h constantes.h sdl2-ttf-light.h
SRC = main.c sdl2-light.c monde.c graphique.c sdl2-ttf-light.c
OBJ = $(SRC:%.c=%.o)

INCTEST = monde.h constantes.h sdl2-light.h test.h
SRCTEST = monde.c sdl2-light.c test.c
OBJTEST = $(SRCTEST:%.c=%.o)

PROG = spacecorridor

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

spacecorridor: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

test: $(OBJTEST)
	gcc $(CFLAGS) $(OBJTEST) $(LDFLAGS) -o $@

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html
