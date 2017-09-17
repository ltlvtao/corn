#include "micron/micron.h"
#include <stdio.h>

#define STACK_SIZE 128 * 1024

struct Schedule {
  char stack[STACK_SIZE];
};

Schedule *
mc_init(){
  return NULL;
}

void
mc_destroy(Schedule *sche){

}

int
mc_new(Schedule *sche, void *ctx, mc_callback cb){
  return 0;
}

void
mc_resume(Schedule *sche, int co_id){

}

void
mc_yield(Schedule *sche){

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
