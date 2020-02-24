# Scale font and line width (dpi) by changing the size! It will always display stretched.
set terminal svg size 400,300 enhanced fname 'arial'  fsize 10 butt solid
set output 'out.svg'

# Key means label...
set key inside bottom right
set xlabel 'KiloBytes'
set ylabel 'Time in nanosecond'
set title 'Access Time Graph'
plot  "data.txt" using ($1/1024):2 title 'KB' with lines
