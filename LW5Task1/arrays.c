int minim(int* a, int n) {
	int k = *a;
	for (int i = 1; i < n; i++)
		if (*(a + i) < k)
			k = *(a + i);
	return k;
}
void move(int* a, int* n, int s){
	for (int i = s; i < (*n) - 1; i++)
		*(a + i) = *(a + i + 1);
	(*n)--;
	
}