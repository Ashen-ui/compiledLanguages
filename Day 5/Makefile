compiler = gcc
params = -Wall -Wextra
input = main.c payment.c save.c
output = $(input:.c=.o)
prjName = PM

all: $(prjName)

$(prjName): $(output)
	$(compiler) $(params) -o $@ $^

%.o: %.c
	$(compiler) $(params) -c -o $@ $<

clear:
	rm -f $(output) $(prjName)

.PHONY: all clear