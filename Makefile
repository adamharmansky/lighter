all:
	cc lighter.c -o lighter `pkg-config --cflags --libs gtk+-3.0`
run: all
	./lighter
install: all
	cp lighter /bin/lighter
	cp lighter.desktop /usr/share/applications/
