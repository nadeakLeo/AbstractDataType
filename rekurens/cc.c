void DelAll (List * L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (IsListEmpty(*L)) { /* Basis - 0 */

	} else { /* Rekurens */
		P = (*L);
		(*L) = Tail(*L);
		Next(P) = Nil;
		Dealokasi(&P);
		DelAll(L);
	}
}

void DelP (List * L, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (IsListEmpty(*L)) { /* Basis - 0 */
		
	} else if (FirstElmt(*L) == X) { /* Basis Ketemu */
		P = (*L);
		(*L) = Tail(*L);
		Next(P) = Nil;
		Dealokasi(&P);
	} else { /* Rekurens */
		DelP(Tail(L),X);
	}
}