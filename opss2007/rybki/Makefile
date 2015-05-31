
# project: rybki
#    file: Makefile
# licence: GNU General Public Licence
#  author: Krzysztof Garus <bajcik@kolos.math.uni.lodz.pl>
#          http://kolos.math.uni.lodz.pl/~bajcik/

NAME = rybki
VERSION = 0.1
FULL = $(NAME)-$(VERSION)

CC = gcc
#CFLAGS = -s -O2
CFLAGS = -ggdb

$(NAME): $(NAME).o
	gcc -o $(NAME) $(NAME).o

$(NAME).o: $(NAME).c
	gcc -o $(NAME).o -c $(CFLAGS) $(NAME).c

dist:
	mkdir $(FULL)
	cp $(NAME).c COPYING README ChangeLog Makefile $(FULL)
	tar czvf $(FULL).tar.gz $(FULL)
	rm -r $(FULL)

clean:
	rm -f *.o $(NAME)


