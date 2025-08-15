#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10005

typedef long long ll;

typedef struct {
    ll dinh, trong_so;
} Canh;

ll so_dinh, so_canh;
ll do_thi[MAX][MAX];
bool chon[MAX];      

ll prim() {
    ll tong_trong_so = 0;
    ll key[MAX];
    for (ll i = 1; i <= so_dinh; i++) {
        key[i] = LLONG_MAX;
        chon[i] = false;
    }
    key[1] = 0;

    for (ll i = 1; i <= so_dinh; i++) {
        ll u = -1;
        for (ll v = 1; v <= so_dinh; v++) {
            if (!chon[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        chon[u] = true;
        tong_trong_so += key[u];

        for (ll v = 1; v <= so_dinh; v++) {
            if (do_thi[u][v] && !chon[v] && do_thi[u][v] < key[v]) {
                key[v] = do_thi[u][v];
            }
        }
    }
    return tong_trong_so;
}

void giai_quyet() {
    scanf("%lld %lld", &so_dinh, &so_canh);
    for (ll i = 1; i <= so_dinh; i++) {
        for (ll j = 1; j <= so_dinh; j++) {
            do_thi[i][j] = (i == j) ? 0 : LLONG_MAX;
        }
    }
    for (ll i = 0; i < so_canh; i++) {
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        do_thi[u][v] = do_thi[v][u] = w;
    }
    printf("%lld\n", prim());
}

int main() {
    giai_quyet();
    return 0;
}
