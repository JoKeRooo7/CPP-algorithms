## Bernoulli trials (imitation of coin tosses).
<hr>

## main_alg.cpp

This program performs a coin toss experiment. Performs <code>N</code> experiments <code>M</code> times. The array <code>f[N+1]</code> tracks the dropout of the <code>i</code> answer book for <em><code>0 = i = N</code></em> and then outputs a histogram of the experiment results. Every 10 drops are indicated by an asterisk.
The number of tails is approximated by the normal distribution function.

## Compilation

Use <code>g++ -Wall -Werror -Wextra main_alg.cpp </code> to compile the program in the terminal.

## Launch

<code>./a.out 28 1000</code> - Linux, Ubuntu, macOS 
<code>./a.exe 28 1000</code> - Windows
28 is the number of experiments(N).
1000 is the number of tosses in one experiment(M).