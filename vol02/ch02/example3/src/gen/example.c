// Generated by `wit-bindgen` 0.34.0. DO NOT EDIT!
#include "example.h"
#include <stdlib.h>
#include <string.h>

// Imported Functions from `vscode:example/vscode`

__attribute__((__import_module__("vscode:example/vscode"), __import_name__("show-information-message")))
extern void __wasm_import_vscode_example_vscode_show_information_message(uint8_t *, size_t);

// Exported Functions from `example`


// Canonical ABI intrinsics

__attribute__((__weak__, __export_name__("cabi_realloc")))
void *cabi_realloc(void *ptr, size_t old_size, size_t align, size_t new_size) {
  (void) old_size;
  if (new_size == 0) return (void*) align;
  void *ret = realloc(ptr, new_size);
  if (!ret) abort();
  return ret;
}

// Helper Functions

void example_string_set(example_string_t *ret, const char*s) {
  ret->ptr = (uint8_t*) s;
  ret->len = strlen(s);
}

void example_string_dup(example_string_t *ret, const char*s) {
  ret->len = strlen(s);
  ret->ptr = (uint8_t*) cabi_realloc(NULL, 0, 1, ret->len * 1);
  memcpy(ret->ptr, s, ret->len * 1);
}

void example_string_free(example_string_t *ret) {
  if (ret->len > 0) {
    free(ret->ptr);
  }
  ret->ptr = NULL;
  ret->len = 0;
}

// Component Adapters

void vscode_example_vscode_show_information_message(example_string_t *message) {
  __wasm_import_vscode_example_vscode_show_information_message((uint8_t *) (*message).ptr, (*message).len);
}

__attribute__((__export_name__("run")))
void __wasm_export_example_run(void) {
  example_run();
}

// Ensure that the *_component_type.o object is linked in

extern void __component_type_object_force_link_example(void);
void __component_type_object_force_link_example_public_use_in_this_compilation_unit(void) {
  __component_type_object_force_link_example();
}
