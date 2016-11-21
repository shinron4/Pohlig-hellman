#include<stdlib.h>
#include<gmp.h>

mpz_t *crt(long int n, mpz_t a[], mpz_t m[]){
	mpz_t M;
	mpz_init(M);
	mpz_set_ui(M, 1);
	long int i;
	for(i = 0l; i < n; i++)
		mpz_mul(M, M, m[i]);
	mpz_t Mi, *x = (mpz_t *)malloc(sizeof(mpz_t));
	mpz_init(Mi);
	mpz_init(*x);
	mpz_set_ui(*x, 0);
	for(i = 0l; i < n; i++){
		mpz_div(Mi, M, m[i]);
		mpz_mul(a[i], a[i], Mi);
		mpz_invert(Mi, Mi, m[i]);
		mpz_mul(a[i], a[i], Mi);
		mpz_add(*x, *x, a[i]);
	}
	mpz_mod(*x, *x, M);
	mpz_clear(M);
	mpz_clear(Mi);
	return x;
}
