.PHONY: run-all build clean
run-all: ; $(MAKE) -C src/cpp run-all
build:   ; $(MAKE) -C src/cpp build
clean:   ; $(MAKE) -C src/cpp clean
