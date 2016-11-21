#include<stdlib.h>
#include<gmp.h>

mpz_t *radixqtoInt(long int c, mpz_t bits[], mpz_t radix){
	long int i = 0;
	mpz_t *num = (mpz_t *)malloc(sizeof(mpz_t));
	mpz_init(*num);
	mpz_set_ui(*num, 0);
	mpz_t temp, x;
	mpz_init(temp);
	mpz_init(x);
	mpz_set_ui(x, 1);
	while(i < c){
		mpz_mul(temp, bits[i], x);
		mpz_add(*num, *num, temp);
		mpz_mul(x, x, radix);
		i++;
	}
	mpz_clear(x);
	mpz_clear(temp);
	return num;
}

