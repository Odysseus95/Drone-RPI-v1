#
# Makefile pour generer l'executable
#

OBJS = main.o
LIBS = -lpthread
LOCAL_LIBS  = -L libconfig  -L libthread
LOCAL_LIBS += -lconfig  -lthrd
CFLAGS     += -I libconfig -I libthread

#
# Cible generale
#

all: main

#
# La cible de nettoyage
#

clean: 
	rm -f core *.o $(EXEC) 

#
# Les cibles pour l'executable
#

main: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LOCAL_LIBS) $(LIBS)


main.o: main.c


