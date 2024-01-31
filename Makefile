EXE	= astext

CFILES	= $(wildcard src/*.c)
OFILES	= $(CFILES:src/%.c=src/%.o)

LFLAGS	=
CFLAGS	= -Iinclude


default:	all
all:		$(EXE)


$(EXE):		$(OFILES)
	$(CC) $^ $(LFLAGS) -o $@

src/%.o:	src/%.c
	$(CC) $^ $(CFLAGS) -c -o $@


.PHONY:		clean
clean:
	-rm -vf $(OFILES) $(EXE)
