#ifndef WHATEVER_HPP
#define WHATEVER_HPP
template <typename A>
void swap(A a, A b) {
	A tmp = a;
	a = b;
	b = tmp;
}
template <typename B>
B min(B a, B b) {
	if (a > b)
		return b;
    return a;
}
template <typename C>
C max(C a, C b) {
	if (a > b)
		return a;
	return b;
}

#endif