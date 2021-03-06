# Fract_ol

## Overview
The object of this project was to create a fractal explorer program using a minimal graphics library which has functions capable of doing things like creating windows and changing pixel colors. To make the program user friendly and visually appealing, a few criteria were necessary to follow:
1. Intuitive Controls
	- Moving mouse to modify the Julia set.
	- Zooming in and out directly from mouse position.
	- Moving view through fractal immersively.
2. Flexible Resolution & Color Pallet
	- Ability to change resolution during run-time.
	- Precise customization of component colors.
3. Optimization
	- Image placement of all pixels *after* individual calculations.
	- Implementation of parallel computation (multithreading) for further optimization.

## Install
- <i class="icon-folder-open"></i> Navigate to the desired directory and run in your shell:
`git clone https://github.com/youngalou/fract_ol.git`
- <i class="icon-folder-open"></i> Enter the repository you just cloned and run:
`make`

## Fractals
You should at this point have and executable called **fractol** in your repo.
Run the program with: `./fractol [-MJS]`
### Mandelbrot Set `./fractol -M`
The Mandelbrot set is the set of complex numbers $c$ for which the function $f_c(z) = z^2 + C$ does not diverge when iterated from $z = 0$, i.e., for which the sequence $f_c(0)$, $f_c(f_c(0))$, etc., remains bounded in absolute value.
![Mandelbrot Fractal](http://www.fractalposter.com/images/mandelbrot_set_02_969_720_480.jpg)
### Julia Set `./fractol -J`
Let $f(z)$ be a complex rational function from the plane into itself, that is, $f(z) = p(z)/q(z)$, where $p(z)$ and $q(z)$ are complex polynomials. Then there is a finite number of open sets F1, ..., Fr, that are left invariant by $f(z)$ and are such that:
1. The union of the $F_i$'s is dense in the plane and
2. $f(z)$ behaves in a regular and equal way on each of the sets $F_i$.
![Julia Fractal](http://nuclear.mutantstargoat.com/articles/sdr_fract/julia_dust_big.png)
### Sierpinski Carpet `./fractol -S`
The Sierpinski carpet is a plane fractal first described by Wacław Sierpiński in 1916. The carpet is one generalization of the Cantor set to two dimensions. The technique is based on subdividing a shape into smaller copies of itself, removing one or more copies, and continuing recursively.
![Sierpinski Carpet](http://paulbourke.net/fractals/carpet/hadamard.gif)

## Functions
This fractal exploration program implements a lot of cool tricks I picked up along the way.
### Color Sliders
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

### Zoom
Point the mouse anywhere in the window and:
<kbd>scroll &uarr;</kbd> to zoom in.
<kbd>scroll &darr;</kbd> to zoom out.

### Translation
Use <kbd>w</kbd><kbd>a</kbd><kbd>s</kbd><kbd>d</kbd> to move camera throughout the fractal in an immersive manner.

### Reset
Hit the <kbd>tab</kbd> button at any time to reset the explorer to the original zoom and position.

### Iterations
The <kbd>-</kbd> and <kbd>+</kbd> keys on the numpad will modify the maximum number of iterations each pixel will undergo in it's calculation to determine whether that complex number is bounded or unbounded. (Basically modifies the resolution, but also highly impacts processing speed)

### Lock Fractal
Only applies to the Julia set. By hitting <kbd>space</kbd> you will toggle fractal lock, locking the current Julia pattern in-place, allowing you to move your mouse and explore the fractal freely. Hitting again will release the lock and allow you to pick another pattern. (Reset before unlocking is recommended.)
