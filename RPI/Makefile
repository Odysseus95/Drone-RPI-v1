#
# Makefile
#

#
# Constantes pour la compilation des programmes
#

export CC = gcc
export LD = gcc
export CLIB = ar crs
export CFLAGS = -g -Wall -DDEBUG
export EXEC = Drone

#
# Constantes liees au projet
#

DIRS= src/libconfig src

#
# La cible generale
#

all: $(patsubst %, _dir_%, $(DIRS))

$(patsubst %,_dir_%,$(DIRS)):
	cd $(patsubst _dir_%,%,$@) && make

#
# La cible de nettoyage
#

clean: $(patsubst %, _clean_%, $(DIRS))

$(patsubst %,_clean_%,$(DIRS)):
	cd $(patsubst _clean_%,%,$@) && make clean
