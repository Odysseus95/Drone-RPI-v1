#
# Makefile pour generer la bibliotheque de fonctions de configuration
#



all: libconfig.a


#
# La cible de nettoyage
#

clean: 
	rm -f core *.o libconfig.a

#
# Les cibles pour la bibliotheque
#

config.o: config.c config.h
 
libconfig.a: config.o
	rm -f $@
	$(CLIB) $@ $+
