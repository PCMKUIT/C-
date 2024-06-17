#include <iostream>
#include <bits/stdc++.h>

void continued_fraction(mpz_t *cf, const mpz_t e, const mpz_t n, size_t &size) {
    mpz_t r;
    mpz_init(r);
    mpz_set(r, e);
    mpz_t q;
    mpz_init(q);
    mpz_t t;
    mpz_init_set(t, n);
    
    size = 0;
    while (mpz_cmp_ui(t, 0) != 0) {
        mpz_fdiv_q(q, r, t);
        mpz_set(cf[size], q);
        size++;
        mpz_mod(r, r, t);
        mpz_swap(r, t);
    }
    
    mpz_clear(r);
    mpz_clear(q);
    mpz_clear(t);
}

void convergents(mpz_t *num, mpz_t *den, const mpz_t *cf, size_t size) {
    mpz_set_ui(num[0], 0);
    mpz_set_ui(num[1], 1);
    mpz_set_ui(den[0], 1);
    mpz_set_ui(den[1], 0);
    
    mpz_t temp_num;
    mpz_t temp_den;
    mpz_init(temp_num);
    mpz_init(temp_den);
    
    for (size_t i = 2; i <= size; i++) {
        mpz_mul(temp_num, cf[i - 1], num[i - 1]);
        mpz_add(num[i], temp_num, num[i - 2]);
        
        mpz_mul(temp_den, cf[i - 1], den[i - 1]);
        mpz_add(den[i], temp_den, den[i - 2]);
    }
    
    mpz_clear(temp_num);
    mpz_clear(temp_den);
}

bool wiener_attack(mpz_t d, const mpz_t n, const mpz_t e) {
    size_t size = mpz_sizeinbase(e, 2) + mpz_sizeinbase(n, 2);
    mpz_t *cf = new mpz_t[size];
    for (size_t i = 0; i < size; i++) {
        mpz_init(cf[i]);
    }
    
    continued_fraction(cf, e, n, size);
    
    mpz_t *num = new mpz_t[size + 1];
    mpz_t *den = new mpz_t[size + 1];
    for (size_t i = 0; i <= size; i++) {
        mpz_init(num[i]);
        mpz_init(den[i]);
    }
    
    convergents(num, den, cf, size);
    
    bool found = false;
    mpz_t k, phi, b, temp, p, q;
    mpz_init(k);
    mpz_init(phi);
    mpz_init(b);
    mpz_init(temp);
    mpz_init(p);
    mpz_init(q);
    
    for (size_t i = 2; i <= size; i++) {
        mpz_set(k, num[i]);
        mpz_set(d, den[i]);
        
        if (mpz_cmp_ui(k, 0) == 0) continue;
        
        mpz_mul(temp, d, e);
        mpz_sub_ui(phi, temp, 1);
        
        if (mpz_mod_ui(temp, phi, k) != 0) continue;
        
        mpz_fdiv_q(phi, phi, k);
        
        mpz_set_ui(temp, 4 * n);
        mpz_sub(temp, phi, temp);
        
        mpz_mul_ui(temp, temp, temp);
        mpz_t sqrt_temp;
        mpz_init(sqrt_temp);
        mpz_sqrt(sqrt_temp, temp);
        
        mpz_add(b, sqrt_temp, phi);
        mpz_fdiv_q_ui(b, b, 2);
        
        mpz_mul(temp, b, b);
        mpz_sub(temp, temp, n);
        mpz_sqrt(q, temp);
        
        mpz_sub(p, b, q);
        mpz_add(q, b, q);
        
        if (mpz_mul(temp, p, q), mpz_cmp(temp, n) == 0) {
            found = true;
            break;
        }
        
        mpz_clear(sqrt_temp);
    }
    
    for (size_t i = 0; i < size; i++) {
        mpz_clear(cf[i]);
    }
    delete[] cf;
    
    for (size_t i = 0; i <= size; i++) {
        mpz_clear(num[i]);
        mpz_clear(den[i]);
    }
    delete[] num;
    delete[] den;
    
    mpz_clear(k);
    mpz_clear(phi);
    mpz_clear(b);
    mpz_clear(temp);
    mpz_clear(p);
    mpz_clear(q);
    
    return found;
}

int main() {
    mpz_t n, e, d;
    mpz_init_set_str(n,9395961204846866284187583026426312253577984040425791431680367991141865893589423173729890633469241219372321733741631787601378407581339922076754605883131673 , 10); 
    mpz_init_set_str(e, 65537, 10); 
    mpz_init(d);
    
    if (wiener_attack(d, n, e)) {
        gmp_printf("Found d: %Zd\n", d);
    } else {
        std::cout << "Attack failed" << std::endl;
    }
    
    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(d);
    
    return 0;
}
