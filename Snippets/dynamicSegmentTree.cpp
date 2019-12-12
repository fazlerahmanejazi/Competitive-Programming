const int N = 1e18+13;
const int NUM_ELEM = 2e5;
const int NUM_QUERIES = 2e5;


struct Node {
	Node *lp, *rp;
	int sum;
};
inline int eval(Node* p) {
	return p ? p->sum : 0LL;
}

const int bufSize = NUM_ELEM * 63;
Node buf[bufSize];
Node *newNode() {
	static auto ptr = buf;
	return ptr++;
}

int getSum(Node* cur, int l, int r, int x, int y) {
	if (!cur || x > r || y < l) return 0;
    if (x <= l && r <= y) {
        return cur->sum;
    }
    int m = (l + r) / 2;
    return getSum(cur->lp, l, m, x, y) + getSum(cur->rp, m + 1, r, x, y);
}
void update(Node*& cur, int l, int r, int pos, int val) {
	if (!cur) cur = newNode();
	if (l == r) {
		cur->sum = val;
	} else {
		int m = (l + r) / 2;
		if (pos <= m) {
			update(cur->lp, l, m, pos, val);
		} else {
			update(cur->rp, m + 1, r, pos, val);
		}
		cur->sum = eval(cur->lp) + eval(cur->rp);
	}
}
Node *root;
