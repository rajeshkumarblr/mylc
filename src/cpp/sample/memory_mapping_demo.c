#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Global variables for segment demonstration
int global_var = 42;
int uninitialized_global;
void *global_heap_ptr = NULL;

// Structure to hold information about active stack frames
struct StackFrameInfo {
  const char *func_name;
  void *rbp;
  void *rsp;
  void *param_addr;
  const char *param_name;
  void *local_addr;
  const char *local_name;
};

// Helper function to read the stack pointer (RSP/ESP)
void *get_rsp() {
  void *rsp;
#if defined(__x86_64__)
  __asm__("mov %%rsp, %0" : "=r"(rsp));
#elif defined(__i386__)
  __asm__("mov %%esp, %0" : "=r"(rsp));
#else
  int local_var;
  rsp = (void *)&local_var; // Fallback
#endif
  return rsp;
}

// Helper function to read the frame pointer (RBP/EBP)
void *get_rbp() { return __builtin_frame_address(0); }

// Function declarations so we can print their addresses
void function_A(int a, struct StackFrameInfo *frames, int num_frames);
void function_B(int b, struct StackFrameInfo *frames, int num_frames);
void function_C(int c, struct StackFrameInfo *frames, int num_frames);
void function_D(int c, struct StackFrameInfo *frames, int num_frames);
int main(int argc, char *argv[]);

// Function to print the memory map diagram
void print_memory_map(struct StackFrameInfo *frames, int num_frames) {
  char line_buf[128];

  printf("====================================================================="
         "===\n");
  printf("                       DYNAMIC MEMORY MAP DIAGRAM                    "
         "   \n");
  printf("====================================================================="
         "===\n");
  printf(" [ OS Kernel Space ] (Highest memory addresses)\n");
  printf("  |\n");
  printf("  v\n");
  printf(" ===================================================================="
         "====\n");
  printf("  THE CALL STACK (Grows downwards from High to Low addresses)\n");
  printf(" ===================================================================="
         "====\n");

  // Print stack frames starting from main() (highest address) to function_C()
  // (lowest)
  for (int i = 0; i < num_frames; i++) {
    struct StackFrameInfo f = frames[i];
    printf(
        "  +------------------------------------------------------------+\n");

    snprintf(line_buf, sizeof(line_buf), " STACK FRAME #%d: %s", i + 1,
             f.func_name);
    printf("  |%-60s|\n", line_buf);

    snprintf(line_buf, sizeof(line_buf), "   (RBP/Frame Pointer)  --> %p",
             f.rbp);
    printf("  |%-60s|\n", line_buf);

    printf("  |%-60s|\n", ""); // Empty row inside box for spacing

    if (f.param_name) {
      snprintf(line_buf, sizeof(line_buf),
               "   Parameter: %-13s Address: %p (val: %d)", f.param_name,
               f.param_addr, *(int *)f.param_addr);
      printf("  |%-60s|\n", line_buf);
    }
    if (f.local_name) {
      snprintf(line_buf, sizeof(line_buf),
               "   Local Var: %-13s Address: %p (val: %d)", f.local_name,
               f.local_addr, *(int *)f.local_addr);
      printf("  |%-60s|\n", line_buf);
    }

    printf("  |%-60s|\n", ""); // Empty row inside box for spacing

    snprintf(line_buf, sizeof(line_buf), "   (RSP/Stack pointer)  --> %p",
             f.rsp);
    printf("  |%-60s|\n", line_buf);

    printf(
        "  +------------------------------------------------------------+\n");
    if (i < num_frames - 1) {
      printf("        | (linked to next frame on stack)\n");
      printf("        v\n");
    }
  }

  printf("  |\n");
  printf("  v  [Free Stack Space / Unallocated Stack Space]\n");
  printf("  ...\n");
  printf("  ^  [Free Heap Space / Unallocated Heap Space]\n");
  printf("  |\n");

  printf("  +------------------------------------------------------------+\n");
  printf("  |%-60s|\n", " THE HEAP Segment (grows upwards from Low to High)");
  if (global_heap_ptr) {
    snprintf(line_buf, sizeof(line_buf),
             "   Variable: heap_var      Address: %p (val: %d)",
             global_heap_ptr, *(int *)global_heap_ptr);
    printf("  |%-60s|\n", line_buf);
  } else {
    printf("  |%-60s|\n", "   No active allocations");
  }
  printf("  +------------------------------------------------------------+\n");

  printf("  |\n");
  printf("  v\n");

  printf("  +------------------------------------------------------------+\n");
  printf("  |%-60s|\n", " DATA / BSS SEGMENTS (Global & Static Variables)");
  snprintf(line_buf, sizeof(line_buf),
           "   Initialized:   global_var           Address: %p",
           (void *)&global_var);
  printf("  |%-60s|\n", line_buf);
  snprintf(line_buf, sizeof(line_buf),
           "   Uninitialized: uninit_global        Address: %p",
           (void *)&uninitialized_global);
  printf("  |%-60s|\n", line_buf);
  printf("  +------------------------------------------------------------+\n");

  printf("  |\n");
  printf("  v\n");

  printf("  +------------------------------------------------------------+\n");
  printf("  |%-60s|\n",
         " CODE / TEXT SEGMENT (Read-Only Machine Instructions)");
  snprintf(line_buf, sizeof(line_buf),
           "   Function Address of main():         %p", (void *)main);
  printf("  |%-60s|\n", line_buf);
  snprintf(line_buf, sizeof(line_buf),
           "   Function Address of function_A():   %p", (void *)function_A);
  printf("  |%-60s|\n", line_buf);
  snprintf(line_buf, sizeof(line_buf),
           "   Function Address of function_B():   %p", (void *)function_B);
  printf("  |%-60s|\n", line_buf);
  snprintf(line_buf, sizeof(line_buf),
           "   Function Address of function_C():   %p", (void *)function_C);
  printf("  |%-60s|\n", line_buf);
  printf("  +------------------------------------------------------------+\n");

  printf(" [ Low Addresses ] (Lowest memory addresses)\n");
  printf("====================================================================="
         "===\n\n");
}

void function_D(int d, struct StackFrameInfo *frames, int num_frames) {
  int local_D = 555;

  // Record current stack frame details for function_C
  frames[num_frames].func_name = "function_D()";
  frames[num_frames].rbp = get_rbp();
  frames[num_frames].rsp = get_rsp();
  frames[num_frames].param_addr = &d;
  frames[num_frames].param_name = "c";
  frames[num_frames].local_addr = &local_D;
  frames[num_frames].local_name = "local_D";

  printf("\n>>> INSIDE function_C(c=%d) -> Stack depth is now 2 frames:\n", d);
  print_memory_map(frames, num_frames + 1);
}

void function_C(int c, struct StackFrameInfo *frames, int num_frames) {
  int local_C = 444;

  // Record current stack frame details for function_C
  frames[num_frames].func_name = "function_C()";
  frames[num_frames].rbp = get_rbp();
  frames[num_frames].rsp = get_rsp();
  frames[num_frames].param_addr = &c;
  frames[num_frames].param_name = "c";
  frames[num_frames].local_addr = &local_C;
  frames[num_frames].local_name = "local_C";

  printf("\n>>> INSIDE function_C(c=%d) -> Stack depth is now 4 frames:\n", c);
  print_memory_map(frames, num_frames + 1);
}

void function_B(int b, struct StackFrameInfo *frames, int num_frames) {
  int local_B = 333;

  // Record current stack frame details for function_B
  frames[num_frames].func_name = "function_B()";
  frames[num_frames].rbp = get_rbp();
  frames[num_frames].rsp = get_rsp();
  frames[num_frames].param_addr = &b;
  frames[num_frames].param_name = "b";
  frames[num_frames].local_addr = &local_B;
  frames[num_frames].local_name = "local_B";

  printf("\n>>> INSIDE function_B(b=%d) -> Stack depth is now 3 frames:\n", b);
  print_memory_map(frames, num_frames + 1);

  // Call function_C
  function_C(300, frames, num_frames + 1);
}

void function_A(int a, struct StackFrameInfo *frames, int num_frames) {
  int local_A = 222;

  // Record current stack frame details for function_A
  frames[num_frames].func_name = "function_A()";
  frames[num_frames].rbp = get_rbp();
  frames[num_frames].rsp = get_rsp();
  frames[num_frames].param_addr = &a;
  frames[num_frames].param_name = "a";
  frames[num_frames].local_addr = &local_A;
  frames[num_frames].local_name = "local_A";

  printf("\n>>> INSIDE function_A(a=%d) -> Stack depth is now 2 frames:\n", a);
  print_memory_map(frames, num_frames + 1);

  // Call function_B
  function_B(200, frames, num_frames + 1);
}

int main(int argc, char *argv[]) {
  (void)argv; // Suppress unused parameter warning
  int main_local = 111;

  // Allocate memory on the Heap for demonstration
  global_heap_ptr = malloc(sizeof(int));
  if (global_heap_ptr) {
    *(int *)global_heap_ptr = 999;
  }

  // Set up an array to keep track of active stack frames
  struct StackFrameInfo frames[4];

  // Record current stack frame details for main()
  frames[0].func_name = "main()";
  frames[0].rbp = get_rbp();
  frames[0].rsp = get_rsp();
  frames[0].param_addr = &argc;
  frames[0].param_name = "argc";
  frames[0].local_addr = &main_local;
  frames[0].local_name = "main_local";

  printf("====================================================================="
         "===\n");
  printf("         STARTING CALL STACK STACKING DEMONSTRATION                  "
         "   \n");
  printf("====================================================================="
         "===\n");
  printf(">>> INSIDE main() -> Stack depth is 1 frame:\n");
  print_memory_map(frames, 1);

  // Call function_A
  function_A(100, frames, 1);

  // Call function_D
  function_D(200, frames, 1);

  // Clean up allocated heap memory
  if (global_heap_ptr) {
    free(global_heap_ptr);
  }

  return 0;
}