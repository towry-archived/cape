#include "kvec.h"
#include "khash.h"
#include <stdio.h>

#ifdef TEST_KLIB

struct obj {
  int id;
};
typedef struct obj* objptr;

KHASH_MAP_INIT_STR(32, const char *)

int main() {
  objptr a, b;
	int ret, is_missing;
	khiter_t k;
	khash_t(32) *h = kh_init(32);
	k = kh_put(32, h, "d", &ret);
	kh_value(h, k) = "haha";

	printf("%d\n%d\n", k, ret);

	printf("%s\n", kh_value(h, 1));

	return 0;
}

#endif
