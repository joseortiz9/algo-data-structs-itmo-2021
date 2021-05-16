//
// Created by joseortiz9 on 06/05/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define parent(i) ((int)(i) - 1) >> 1
#define left(i) (((int)(i) << 1) + 1)
#define right(i) (((int)(i) << 1) + 2)

using namespace std;

struct segment {
    int a, b, index;
    bool free;
    struct segment *l, *r;

    segment(segment *l, segment *r, int a, int b, int index, bool free) {
        this->a = a;
        this->b = b;
        this->index = index;
        this->free = free;
        this->l = l;
        this->r = r;
        if (l) l->r = this;
        if (r) r->l = this;
    }
    void rem() {
        if (l) l->r = r;
        if (r) r->l = l;
    }
};

const int sz = 100000;

int N, M;
int length = 0;
segment *h[sz], *r[sz];

void swp(int a, int b) {
    segment * t;
    t = h[a];
    h[a] = h[b];
    h[b] = t;
    h[a]->index = a;
    h[b]->index = b;
}

int len(segment *seg) {
    return seg->b - seg->a + 1;
}

int better(int a, int b) {
    return len(h[a]) > len(h[b]);
}

void down(int a) {
    for (;;) {
        int b = a;
        if (left(b) < length && better(left(b), a)) {
            a = left(b);
        }
        if (right(b) < length && better(right(b), a)) {
            a = right(b);
        }
        if (a != b) swp(a, b);
        else break;
    }
}

void up(int a) {
    for (;a && better(a, parent(a));) {
        swp(a, parent(a));
        a = parent(a);
    }
}

void push(segment *seg) {
    seg->index = length;
    h[length] = seg;
    up(length++);
}

void pop(int a) {
    swp(a, --length);
    up(a); down(a);
}

void add(int x, int i) {
    if (!length || len(h[0]) < x)
        cout << -1 << "\n";
    else {
        segment *seg = h[0];
        cout << seg->a << "\n";
        r[i] = new segment(seg->l, seg, seg->a, seg->a+x-1, -1, 1);
        seg->a += x;
        if (len(seg))
            down(seg->index);
        else {
            seg->rem();
            swp(0, --length); down(0);
            delete seg;
        }
    }
}

void remove(int x) {
    segment *seg = r[x];
    if (!seg) return;
    segment *sl = seg->l, *sr = seg->r;
    if (sl && !sl->free && sr && !sr->free) {
        sl->b = sr->b;
        up(sl->index);
        seg->rem();
        delete seg;
        pop(sr->index);
        sr->rem();
        delete sr;
    } else if (sl && ! sl->free) {
        sl->b = seg->b;
        up(sl->index);
        seg->rem();
        delete seg;
    } else if (sr && !sr->free) {
        sr->a = seg->a;
        up(sr->index);
        seg->rem();
        delete seg;
    } else {
        seg->free = 0;
        push(seg);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> M;
    h[0] = new segment(0, 0, 1, N, length++, 0);
    for (int i = 0; i < M; i++) {
        int val; cin >> val;
        if (val > 0) add(val, i);
        else remove(-++val);
    }
    return 0;
}