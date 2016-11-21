#include<stdlib.h>
#include<gmp.h>

mpz_t *findBits(mpz_t Zp, mpz_t delta, mpz_t alpha, mpz_t x, mpz_t q){
	mpz_t *i = (mpz_t *)malloc(sizeof(mpz_t));
	mpz_init(*i);
	mpz_set_ui(*i, 0);
	mpz_t temp;
	mpz_init(temp);
	while(mpz_cmp(*i, q) < 0){
		mpz_mul(temp, *i, x);
		mpz_powm(temp, alpha, temp, Zp);
		if(mpz_cmp(temp, delta) == 0)
			break;
		mpz_add_ui(*i, *i, 1);
	}
	mpz_clear(temp);
	return i;
}

mpz_t *pohlig_hellman(mpz_t Zp, mpz_t alpha, mpz_t n, mpz_t beta, mpz_t q, long  int c){
	long int j = 0;
	mpz_t x, y, *b, betaj, qc, *radixqtoInt(long int c, mpz_t [], mpz_t);
	mpz_init(x);
	mpz_init(y);
	mpz_init(betaj);
	mpz_init(qc);
	mpz_set(betaj, beta);
	mpz_div(x, n, q);
	mpz_set(y, x);
	mpz_powm(qc, alpha, x, Zp);
	mpz_t  alphaInv;
	mpz_init(alphaInv);
	mpz_invert(alphaInv, alpha, Zp);
	mpz_t delta, temp;
	mpz_init(delta);
	mpz_init(temp);
	mpz_t *bits = (mpz_t *)malloc(c * sizeof(mpz_t));
	while(j < c){
		mpz_powm(delta, betaj, y, Zp);
		b = findBits(Zp, delta, alpha, x, q);
		mpz_set(bits[j], *b);
		mpz_clear(*b);
		mpz_pow_ui(temp, q, j);
		mpz_mul(temp, temp, bits[j]);
		mpz_powm(temp, alphaInv, temp, Zp);
		mpz_mul(betaj, betaj, temp);
		mpz_div(y, y, q);
		j++;
	}
	mpz_clear(x);
	mpz_clear(y);
	mpz_clear(qc);
	mpz_clear(betaj);
	mpz_clear(alphaInv);
	mpz_clear(delta);
	mpz_clear(temp);
	b = radixqtoInt(c, bits, q);
	for(j = 0; j < c; j++)
		mpz_clear(bits[j]);
	return b;
}
