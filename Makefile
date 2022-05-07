CC              = gcc

PREFIX          = /usr/local
APPLICATIONS    = /usr/share/applications

all: timetaken clean

timetaken: timetaken.c
	$(CC) -o $@ $^

install: timetaken
	mkdir -p $(PREFIX)/bin
	cp timetaken $(PREFIX)/bin/timetaken
	chmod +x $(PREFIX)/bin/timetaken

uninstall:
	rm -f $(PREFIX)/bin/timetaken

clean:
	rm -f *.o 

.PHONY: install uninstall clean
