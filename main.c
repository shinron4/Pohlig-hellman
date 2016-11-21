#include<stdio.h>
#include<stdlib.h>
#include<gmp.h>

int main(){
	long int m, i, power;
	char p[1024];
	mpz_t Zp, alpha, n, beta, *num, *crt(long int, mpz_t [], mpz_t []), *pohlig_hellman(mpz_t, mpz_t, mpz_t, mpz_t, mpz_t, long int);
	mpz_init(Zp);
	mpz_init(alpha);
	mpz_init(n);
	mpz_init(beta);
	printf("Enter p for group Zp: ");	
	scanf("%s", p);
	mpz_set_str(Zp, p, 10);
	printf("Enter alpha: ");
	scanf("%s", p);
	mpz_set_str(alpha, p, 10);
	printf("Enter order of alpha: ");
	scanf("%s", p);
	mpz_set_str(n, p, 10);
	printf("Enter beta: ");
	scanf("%s", p);
	mpz_set_str(beta, p, 10);
	printf("Enter the number of prime factors: ");
	scanf("%ld", &m);
	mpz_t *pf = (mpz_t *)malloc(m * sizeof(mpz_t));
	mpz_t *a = (mpz_t *)malloc(m * sizeof(mpz_t));
	for(i = 0; i < m; i++){
	 	printf("Enter the prime factor %ld and it's power: ", i + 1);
		scanf("%s %ld", p, &power);
		mpz_init(pf[i]);
		mpz_init(a[i]);
		mpz_set_str(pf[i], p, 10);
		num = pohlig_hellman(Zp, alpha, n, beta, pf[i], power);
		mpz_set(a[i], *num);
		mpz_clear(*num);
		mpz_pow_ui(pf[i], pf[i], power);
	}
	printf("Answer to the given DLP instance is :");
	mpz_out_str(stdout, 10, *crt(m, a,pf));
	printf("\n");
	mpz_clear(Zp);
	mpz_clear(alpha);
	mpz_clear(n);
	mpz_clear(beta);
	return 0;
}
