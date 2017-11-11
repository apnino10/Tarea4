*.png : *.txt Plots.py
	python Plots.py

*.txt : a.out
	./a.out

a.out : Onda.c
	gcc -lm Onda.c

