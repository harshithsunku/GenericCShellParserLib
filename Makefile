CC=gcc
CFLAGS=-g -Wall
INCLUDES=-I .
CLILIB=libcli.a
TARGET:main ${CLILIB}
OBJ=cmd_hier.o parser.o serialize.o string_util.o clistd.o clicbext.o
main:main.o ${CLILIB}
	@echo "Building final executable"
	@ ${CC} ${CFLAGS} ${INCLUDES} main.o -o main -L . -lcli -lreadline -lpthread -lrt
cmd_hier.o:cmd_hier.c
	@echo "Building cmd_hier.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} cmd_hier.c -o cmd_hier.o
parser.o:parser.c
	@echo "Building parser.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} parser.c -o parser.o
serialize.o:serialize.c
	@echo "Building serialize.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} serialize.c -o serialize.o
string_util.o:string_util.c
	@echo "Building string_util.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} string_util.c -o string_util.o
clistd.o:clistd.c
	@echo "Building clistd.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} clistd.c -o clistd.o
clicbext.o:clicbext.c
	@echo "Building clicbext.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} clicbext.c -o clicbext.o
main.o:main.c
	@echo "Building testapp.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} main.c -o main.o
${CLILIB}: ${OBJ}
	@echo "Building Library ${CLILIB}"
	ar rs ${CLILIB} ${OBJ}
clean:
	rm -f main
	rm -f *.o
	rm -f ${CLILIB}
	rm -f CMD_HIST_RECORD_FILE.txt
