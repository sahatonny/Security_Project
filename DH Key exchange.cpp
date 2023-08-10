
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


long long bin_pow(long long base, long long power, long long mod)
{
    if(power == 0)
        return 1;

    else if(power % 2 == 1)
    {
        long long p1 = base % mod;
        long long p2 = (bin_pow(base, power-1, mod)) % mod;
        return (p1 * p2) % mod;
    }
    else if(power % 2 == 0)
    {
        long long p1 = (bin_pow(base, power/2, mod)) % mod;
        return (p1 * p1) % mod;
    }
}

int main()
{
long long int P, G, x, a, y, b, ka, kb;

//A prime number P; a primitive root for P, G; private key for Alice, a; private key for Bob, b is taken
cout << "Enter P, G, a, b: " << endl;
cin >> P >> G >> a >> b ;

//cout << "The value of P : " << P << endl;
//cout << "The value of G : " << G << endl;


//cout << "The private key a for Alice : " << a << endl;

x = bin_pow(G, a, P); // gets the generated public key



//cout << "The private key b for Bob : " << b << endl;

y = bin_pow(G, b, P); // gets the generated public key

// Generating the secret key after the exchange
// of keys
ka = bin_pow(y, a, P); // Secret key for Alice
kb = bin_pow(x, b, P); // Secret key for Bob
cout << "Secret key for the Alice is : " << ka << endl;

cout << "Secret key for the Bob is : " << kb << endl;

return 0;
}
