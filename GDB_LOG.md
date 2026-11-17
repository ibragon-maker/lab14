# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:

Backtrace inside `Hangman::Hangman` (paste it):

Backtrace inside `Game::Game` (paste it):

Where `finish` returned to:

Order of destructor breakpoints when the program ended:

Construction order and destruction order, as read from the backtraces:

### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:

## Week 14 (Lab 14)

Each partner writes their own section. Put your name here: Ibrahim Gonzalez

### Binary search

Breakpoint, `display low`, `display mid`, `display high`, and the values after three `next` iterations (paste them):
(gdb) break binary_search_name
Breakpoint 1 at 0x9291: file src/sorting.cpp, line 129.
(gdb) run
(gdb) display low
(gdb) display mid
(gdb) display high
(gdb) next
1: low = 0
3: mid = 4
2: high = 7
(gdb) next
1: low = 5
3: mid = 6
2: high = 7
(gdb) next
1: low = 5
3: mid = 5
2: high = 5

The conditional stop you set (`condition N low > high`) and what it caught: 
(gdb) condition 1 low > high
(gdb) continue

Loop iterations you counted versus the comparison count the program reported:
Loop iterations observed in GDB: 3 iterations.
Comparison count reported by program: 3 comparisons.
The number of loop iterations matched the total comparison count because each iteration of the binary search loop performed one equality check and one ordering check against the target name, incrementing the counter synchronously with the halving of the search range.

### Insertion sort

The `watch comparisons` stops: the counter and the array position after you skipped the first 50 stops with `ignore`:

One count you read in the debugger, and the number the program reported:
