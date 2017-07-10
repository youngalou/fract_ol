**Fract_ol**
=======

## Install Instructions
> - <i class="icon-folder-open"></i> Navigate to the desired directory and run in your shell:
> <kbd>git clone https://github.com/youngalou/fract_ol.git</kbd>
> - <i class="icon-folder-open"></i> Enter the repository you just cloned and run:
> <kbd>make</kbd>

## Usage
You should at this point have and executable called **fractol** in your repo.
Run the program with: <kbd>./fractol [-MJS]</kbd>
> - **Mandelbrot Set** <kbd>./fractol -M</kbd>
![Mandelbrot Fractal](http://www.fractalposter.com/images/mandelbrot_set_02_969_720_480.jpg)
 The Mandelbrot set is the set of complex numbers $c$ for which the function $f_c(z) = z^2 + C$ does not diverge when iterated from $z = 0$, i.e., for which the sequence $f_c(0)$, $f_c(f_c(0))$, etc., remains bounded in absolute value.
> - **Julia Set**<kbd>./fractol -J</kbd>
![Julia Fractal](http://nuclear.mutantstargoat.com/articles/sdr_fract/julia_dust_big.png)
Let $f(z)$ be a complex rational function from the plane into itself, that is, $f(z) = p(z)/q(z)$, where $p(z)$ and $q(z)$ are complex polynomials. Then there is a finite number of open sets F1, ..., Fr, that are left invariant by $f(z)$ and are such that:
>1. The union of the $F_i$'s is dense in the plane and
>2. $f(z)$ behaves in a regular and equal way on each of the sets $F_i$.
> - **Sierpinski Carpet**<kbd>./fractol -S</kbd>
![Sierpinski Carpet](http://paulbourke.net/fractals/carpet/hadamard.gif)
The Sierpinski carpet is a plane fractal first described by Wacław Sierpiński in 1916. The carpet is one generalization of the Cantor set to two dimensions. The technique is based on subdividing a shape into smaller copies of itself, removing one or more copies, and continuing recursively.
