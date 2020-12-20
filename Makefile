CC      := clang
CCFLAGS := -Wall -std=c11

all: clean bin lib

bin:
	$(CC) $(CCFLAGS) -o vocabulary vocabulary.c
	chmod +x vocabulary

lib:
	$(CC) $(CCFLAGS) -shared -fPIC -o vocabulary.so vocabulary.c

test: all
	cd ./testscripts && \
	python3 tc_runner.py && \
	python3 tc_report.py && \
	xdg-open $(readlink -f ./results/report.html)

clean:
	rm -f vocabulary
	rm -f vocabulary.so
	rm -rf testscripts/tmp/*
	rm -rf testscripts/results/*

