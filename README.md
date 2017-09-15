**Fract_ol**
=======

## Install Instructions
- <i class="icon-folder-open"></i> Navigate to the desired directory and run in your shell:
<kbd>git clone https://github.com/youngalou/fract_ol.git</kbd>
- <i class="icon-folder-open"></i> Enter the repository you just cloned and run:
<kbd>make</kbd>

## Fractals
You should at this point have and executable called **fractol** in your repo.
Run the program with: <kbd>./fractol [-MJS]</kbd>
- **Mandelbrot Set** <kbd>./fractol -M</kbd>
The Mandelbrot set is the set of complex numbers $c$ for which the function $f_c(z) = z^2 + C$ does not diverge when iterated from $z = 0$, i.e., for which the sequence $f_c(0)$, $f_c(f_c(0))$, etc., remains bounded in absolute value.
![Mandelbrot Fractal](http://www.fractalposter.com/images/mandelbrot_set_02_969_720_480.jpg)
- **Julia Set**<kbd>./fractol -J</kbd>
Let $f(z)$ be a complex rational function from the plane into itself, that is, $f(z) = p(z)/q(z)$, where $p(z)$ and $q(z)$ are complex polynomials. Then there is a finite number of open sets F1, ..., Fr, that are left invariant by $f(z)$ and are such that:
1. The union of the $F_i$'s is dense in the plane and
2. $f(z)$ behaves in a regular and equal way on each of the sets $F_i$.
![Julia Fractal](http://nuclear.mutantstargoat.com/articles/sdr_fract/julia_dust_big.png)
- **Sierpinski Carpet**<kbd>./fractol -S</kbd>
The Sierpinski carpet is a plane fractal first described by Wacław Sierpiński in 1916. The carpet is one generalization of the Cantor set to two dimensions. The technique is based on subdividing a shape into smaller copies of itself, removing one or more copies, and continuing recursively.
![Sierpinski Carpet](http://paulbourke.net/fractals/carpet/hadamard.gif)

## Functions
This fractal exploration program implements a lot of cool tricks I picked up along the way.
- **Color Sliders**
Using the numpad enables the user to change the rgb values of the display intuitively. The button layout is structured in the form 3 sliders for each of the 3 component colors.
	- Use <kbd>1</kbd>, <kbd>4</kbd>, and <kbd>7</kbd> to decrease red, green, and blue values respectively.
	- Use <kbd>2</kbd>, <kbd>5</kbd>, and <kbd>8</kbd> to increase red, green, and blue values respectively.
	- Use <kbd>3</kbd>, <kbd>6</kbd>, and <kbd>9</kbd> to zero red, green, and blue values respectively.
	- <kbd>clear</kbd> button will at any time reset the color sliders to default.
	
--- | &darr; | &uarr; | 0
--- | --- | --- | ---
**B** | <kbd>7</kbd> | <kbd>8</kbd> | <kbd>9</kbd>
**G** | <kbd>4</kbd> | <kbd>5</kbd> | <kbd>6</kbd>
**R** | <kbd>1</kbd> | <kbd>2</kbd> | <kbd>3</kbd>

- **Zoom**
Point the mouse anywhere in the window and:
<kbd>scroll &uarr;</kbd> to zoom in.
<kbd>scroll &darr;</kbd> to zoom out.

- **Translation**
Use <kbd>w</kbd><kbd>a</kbd><kbd>s</kbd><kbd>d</kbd> to move camera throughout the fractal in an immersive manner.

- **Reset**
Hit the <kbd>tab</kbd> button at any time to reset the explorer to the original zoom and position.

- **Iterations**
The <kbd>-</kbd> and <kbd>+</kbd> keys on the numpad will modify the maximum number of iterations each pixel will undergo in it's calculation to determine whether that complex number is bounded or unbounded. (Basically modifies the resolution, but also highly impacts processing speed)

- **Lock Fractal**
Only applies to the Julia set. By hitting <kbd>space</kbd> you will toggle fractal lock, locking the current Julia pattern in-place, allowing you to move you mouse and explore the fractal freely. Hitting again will release the lock and allow you to pick another pattern. (Reset before unlocking is recommended.)
