
#include "micron/micron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

volatile long counter;

float timekeeper(Schedule * sched, long total, void (*func)(Schedule *, long)) {
  long count, elapsed;
  struct timeval start, end;

  count = total;
  while (1) {
      gettimeofday(&start, NULL);
      func(sched, count);
      gettimeofday(&end, NULL);
      elapsed = end.tv_usec - start.tv_usec;
      elapsed += 1000000 * (end.tv_sec - start.tv_sec);
      if (elapsed > 1000000)
          break;
      count *= 2;
  }
  return 1000000.0 * count / elapsed;
}


static void
func1(Schedule *sched, void *data) {
  while (counter > 0) {
    mc_yield(sched);
  }
}

static void
func2(Schedule *sched, void *data) {
  while (counter > 0) {
    mc_yield(sched);
  }
}

static void
test(Schedule *sched, long total) {
  int co1 = mc_new(sched, NULL, func1);
  int co2 = mc_new(sched, NULL, func2);
  counter = total;
  while(counter-- > 0) {
    mc_resume(sched, co1);
    mc_resume(sched, co2);
  }
}

int
main(int argc, char *argv[]) {
  int i = 0;
  long mc_total = 1;
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-t") == 0) {
      if (++i < argc) mc_total = atoi(argv[i]);
    }
  }

  if (mc_total < 10000) {
    printf("It's too small! It will be set with 10000.\r\n\r\n");
    mc_total = 10000;
  }

  Schedule * sched = mc_init();
  float es = timekeeper(sched, mc_total, test) / 1000000.0;
  printf("yield: %.2f\r\n", es);
  
  mc_destroy(sched);
  sched = NULL;
  return 0;
}

/*
MIT License

Copyright (c) 2016 Tomas Lyu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
