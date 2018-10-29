#ifndef D_HEXCONVERT_H_INCLUDED
#define D_HEXCONVERT_H_INCLUDED
void displayInBase (int n, int base)
{
	if(n>0)
	{
		// µİ¹éµ÷ÓÃ
		displayInBase(n/base,base);
		cout << n % base;
	}
}


#endif // D_HEXCONVERT_H_INCLUDED
