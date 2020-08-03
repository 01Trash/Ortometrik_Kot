#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	double A0, A1, A2, A10, A11, A20, Saga, Yukari, Elipsoit, N_TG03;
	double N_Fark, Ni_TG03, H;

		/// Bilinenleri isteyelim.
	/* İkinci dereceden yüzey polinom değişkenleri; Aoo, Ao1, A02, A10, A11, A20;
	Z(X,Y) = A00  + A01 Y + A02 Y2 + A10 X + A11 XY + A20 X2 */
	printf("A0 değerini giriniz: ");
	scanf("%lf", &A0);
	printf("A1 değerini giriniz: ");
	scanf("%lf", &A1);
	printf("A2 değerini giriniz: ");
	scanf("%lf", &A2);
	printf("A10 değerini giriniz: ");
	scanf("%lf", &A10);
	printf("A11 değerini giriniz: ");
	scanf("%lf", &A11);
	printf("A20 değerini giriniz: ");
	scanf("%lf", &A20);
	// Koordinat değerleri; Sağa ve Yukarı değerler
	printf("Sağa değerini giriniz: ");
	scanf("%lf", &Saga);
	printf("Yukarı değerini giriniz: ");
	scanf("%lf", &Yukari);
	// Elipsoit değeri; h
	printf("Elipsoit değerini giriniz: ");
	scanf("%lf", &Elipsoit);
	// Jeoid ondülasyonu; N_TG03
	printf("Jeoid ondülasyonu değerini giriniz: ");
	scanf("%lf", &N_TG03);

		/// Bilinmeyenlerin hesaplanması.
	printf("\n\t=== Hesap sonuçları! === \n");
	/* Jeoid ondülasyon farkı; N_Fark
	N_Fark = A0 + (A1 * Yukari) + (A2 * (Yukari^2)) + (A10 * Saga) + (A11 * Saga * Yukari) + (A20 * (Saga^2)); */
	N_Fark = A0 + (A1 * Yukari) + (A2 * pow(Yukari, 2)) + (A10 * Saga) + (A11 * Saga * Yukari) + (A20 * pow(Saga, 2));
	printf("Jeoid ondülasyon farkı değeri: %f\n", N_Fark);
	/* İyileştirilmiş jeoit ondülasyonu; Ni_TG03
	Ni_TG03 = N_TG03 + N_Fark; */
	Ni_TG03 = N_TG03 + N_Fark;
	printf("İyileştirilmiş jeoit ondülasyonu değeri: %f\n", Ni_TG03);
	/* Ortometrik yükseklik; H
	H = Elipsoit - Ni_TG03; */
	H = Elipsoit - Ni_TG03;
	printf("Ortometrik yükseklik değeri: %f\n", H);

	return 0;
}
