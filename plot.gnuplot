#!/usr/bin/env gnuplot

set term pngcairo;
set output "out.png"
set datafile separator ";";

set xlabel "Condition probability"

plot "out.csv" using 1:2 with lines title "cmov", \
     "out.csv" using 1:3 with lines title "branch";
