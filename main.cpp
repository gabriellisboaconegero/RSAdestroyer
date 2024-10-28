#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Acha fatores primos do número em O(sqrt(n))
vector<ll> factorize(ll n) {
    vector<ll> factors;
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            factors.push_back(i);
        }
    }
    if (n > 1)
        factors.push_back(n);

    return factors;
}

// Acha inverso multiplicativo de a mod n em O(log^2(n)) dado que 0 < a < n
// Vide https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Computing_multiplicative_inverses_in_modular_structures
ll inverse(ll a, ll n) {
    ll t = 0;
    ll r = n;
    ll nt = 1;
    ll nr = a;
    ll tmp;

    while (nr != 0) {
        ll q = r / nr;

        tmp = nt;
        nt = t - q*nt;
        t = tmp;

        tmp = nr;
        nr = r - q*nr;
        r = tmp;
    }

    if (r > 1)
        return -1;

    if (t < 0)
        t += n;

    return t;
}

pair<ll,ll> get_p_q(ll n) {
    vector<ll> factors = factorize(n);
    for (auto f : factors)
        cout << f << " ";
    cout << endl;
    // Verifica se tem apenas dos fatores
    if (factors.size() == 2) {
        return make_pair(factors[0], factors[1]);
    }
    return make_pair(0, 0);
}

int main() {
    ll e, n;
    // Lê chave pública
    cin >> e >> n;
    auto [p, q] = get_p_q(n);
    // Significaa que n é inválido (decisão ded projeto)
    if (p == q) {
        cout << "[ERRO]: Chave pública inválida" << endl;
        return 1;
    }

    ll phi_n = (p - 1) * (q - 1);
    ll d = inverse(e, phi_n);
    // Erro se d for ou menor (decisão de projeto)
    if (d <= 0) {
        cout << "[ERRO]: Não foi possível achar d" << endl;
        return 1;
    }

    printf("p: %lld\nq: %lld\ne: %lld\nd: %lld\nn: %lld", p, q, e, d, n);
    return 0;
}
