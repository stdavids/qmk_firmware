
QMK := source $(CURDIR)/pyenv/bin/activate && qmk

KB := gmmk/pro/rev1/ansi
KM := stdavids


compile: | pyenv
	cd ../ && $(QMK) compile -kb $(KB) -km $(KM)

setup: | pyenv
	cd ../ && $(QMK) setup

clean:
	rm -f ../$(subst /,_,$(KB))_$(KM).bin

pyenv:
	python3 -m venv $@
	source $@/bin/activate && pip install qmk
