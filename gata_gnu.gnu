set terminal x11
set xlabel "Alpha"
set ylabel "SUM"
set grid 
set style data lines
set zero 1e-100
#set title "RK"
#set logscale xy
#set yrange [-4e+09:5e+9]
#set xrange [65000:2600000]

plot "GATASAN2.dat" using 2:4 with l
pause -1 