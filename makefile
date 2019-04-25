all: euler.dat rk4.dat leapfrog.dat graficas.png 

%.png: %.dat graficas.png 
	python3 graficador.py

%.dat: a.out
	./a.out

a.out: incomplete.cpp
	g++ incomplete.cpp 

clean:
	rm -rf *.x *.dat *.png
