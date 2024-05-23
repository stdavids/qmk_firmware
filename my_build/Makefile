
QMK := source $(CURDIR)/pyenv/bin/activate && qmk

KB := gmmk/pro/rev1/ansi
KM := stdavids


compile: | pyenv
	cd ../ && $(QMK) compile -kb $(KB) -km $(KM)

setup: | pyenv
	cd ../ && $(QMK) setup

pyenv:
	python3 -m venv $@
	source $@/bin/activate && pip install qmk
